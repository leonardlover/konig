#include <stack>
#include "Box.h"
#include "Node.h"
#include "Point.h"
#include "QuadTree.h"

QuadTree::QuadTree(void)
{
    Point up(0.0, 0.0);
    Point lo(360.0, 360.0);
    root = new Node(Box(up, lo), nullptr);
    pointCount = 0;
    nodeCount = 1;
}

QuadTree::~QuadTree(void)
{
    delete root;
    pointCount = 0;
    nodeCount = 0;
}

int QuadTree::totalPoints(void)
{
    return pointCount;
}

int QuadTree::totalNodes(void)
{
    return nodeCount;
}

void QuadTree::insert(Point p)
{
    root->insert(p, pointCount, nodeCount);
}

vector<Point> QuadTree::list(void)
{
    vector<Point> data;
    stack<Node *> traversal;
    traversal.push(root);

    while (!traversal.empty()) {
        Node *v = traversal.top();
        traversal.pop();

        if (v->hasPoint())
            data.push_back(v->data());
        if ((v->childs())[0] == nullptr)
            continue;

        for (int i = (v->childs()).size() - 1; i >= 0; i--)
            traversal.push((v->childs())[i]);
    }

    return data;
}

int QuadTree::countRegion(Point p, double d)
{
    return root->region(Box(Point(max(p.x - d, 0.0), max(p.y - d, 0.0)), Point(min(p.x + d, 360.0), min(p.y + d, 360.0))), false);
}

int QuadTree::aggregateRegion(Point p, double d)
{
        return root->region(Box(Point(max(p.x - d, 0.0), max(p.y - d, 0.0)), Point(min(p.x + d, 360.0), min(p.y + d, 360.0))), true);
    }
