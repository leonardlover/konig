#include <algorithm>
#include <vector>
#include "Box.h"
#include "Node.h"

using namespace std;

Node::Node(Box bx, Node *par)
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

void Node::insert(Point p)
{
    if (!boundary.contains(p) || isLeaf)
        return;

    if (abs((boundary.getUpper()).x - (boundary.getLower()).x) <= 5.625) {
        point = p;
        isLeaf = true;
        return;
    }

    divide();

    for (int i = 0; i < children.size(); i++) {
        if ((children[i]->bound()).contains(p)) {
            children[i]->insert(p);
            break;
        }
    }
}

void Node::divide(void)
{
    Point up = boundary.getUpper();
    Point lo = boundary.getLower();
    Point mi = Point(lo.x / 2.0, lo.y / 2.0);

    if (children[0] == nullptr) {
        children[0] = new Node(Box(up, mi), this);
        children[1] = new Node(Box(Point(mi.x, up.y),
                                   Point(lo.x, mi.y)), this);
        children[2] = new Node(Box(Point(up.x, mi.y),
                                   Point(mi.x, lo.y)), this);
        children[3] = new Node(Box(mi, lo), this);
    }
}

Box Node::bound(void)
{
    return boundary;
}

vector<Node *> childs(void)
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

int Node::region(Box bx, bool aggregate)
{
    return 0;
}
