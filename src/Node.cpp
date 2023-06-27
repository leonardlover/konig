#include <cmath>
#include <iostream>
#include "Box.h"
#include "Node.h"

using namespace std;

Node::Node(Box bx, Node *par) : boundary(bx), point(Point(0.0, 0.0))
{
    boundary = bx;
    parent = par;
    children.resize(4, nullptr);
    isLeaf = false;
}

Node::~Node(void)
{
    for (auto &c : children)
        if (c != nullptr)
            delete c;
}

void Node::insert(Point p, long long &pointCount, long long &nodeCount)
{
    if (!boundary.contains(p) || isLeaf)
        return;

    // TODO calcular upper bound correcta
    if (abs((boundary.getUpper()).x - (boundary.getLower()).x) <= 0.5) {
        point = p;
        isLeaf = true;
        pointCount++;
        return;
    }

    nodeCount += divide();

    for (int i = 0; i < children.size(); i++) {
        if ((children[i]->bound()).contains(p)) {
            children[i]->insert(p, pointCount, nodeCount);
            break;
        }
    }
}

int Node::divide(void)
{
    if (children[0] != nullptr)
        return 0;

    Point up = boundary.getUpper();
    Point lo = boundary.getLower();
    Point mi = Point((lo.x + up.x) / 2.0, (lo.y + up.y) / 2.0);

    children[0] = new Node(Box(up, mi), this);
    children[1] = new Node(Box(Point(mi.x, up.y),
                               Point(lo.x, mi.y)), this);
    children[2] = new Node(Box(Point(up.x, mi.y),
                               Point(mi.x, lo.y)), this);
    children[3] = new Node(Box(mi, lo), this);

    return 4;
}

Box Node::bound(void)
{
    return boundary;
}

vector<Node *> Node::childs(void)
{
    return children;
}

bool Node::hasPoint(void)
{
    return isLeaf;
}

Point Node::data(void)
{
    return point;
}

long long Node::region(Box bx, bool aggregate)
{
    if (!boundary.contains(bx))
        return 0;

    if (isLeaf)
        return aggregate ? point.population : 1;

    if (children[0] == nullptr)
        return 0;

    for (int i = 0; i < children.size(); i++)
        if ((children[i]->bound()).contains(bx))
            return children[i]->region(bx, aggregate);

    Point p = bx.getUpper();
    Point q = bx.getLower();
    if ((children[0]->bound()).contains(p) && (children[1]->bound()).contains(q)) {
        double X = ((children[0]->bound()).getLower()).x;
        return children[0]->region(Box(p, Point(X, q.y)), aggregate) +
               children[1]->region(Box(Point(X, p.y), q), aggregate);
    }

    if ((children[2]->bound()).contains(p) && (children[3]->bound()).contains(q)) {
        double X = ((children[2]->bound()).getLower()).x;
        return children[2]->region(Box(p, Point(X, q.y)), aggregate) +
               children[3]->region(Box(Point(X, p.y), q), aggregate);
    }

    if ((children[0]->bound()).contains(p) && (children[2]->bound()).contains(q)) {
        double Y = ((children[0]->bound()).getLower()).y;
        return children[0]->region(Box(p, Point(q.x, Y)), aggregate) +
               children[2]->region(Box(Point(p.x, Y), q), aggregate);
    }

    if ((children[1]->bound()).contains(p) && (children[3]->bound()).contains(q)) {
        double Y = ((children[1]->bound()).getLower()).y;
        return children[1]->region(Box(p, Point(q.x, Y)), aggregate) +
               children[3]->region(Box(Point(p.x, Y), q), aggregate);
    }

    Point r = (children[0]->bound()).getLower();

    return children[0]->region(Box(p, r), aggregate) +
           children[1]->region(Box(Point(r.x, p.y), Point(q.x, r.y)), aggregate) +
           children[2]->region(Box(Point(p.x, r.y), Point(r.x, q.y)), aggregate) +
           children[3]->region(Box(r, q), aggregate);
}
