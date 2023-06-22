#include "QuadTree.h"

QuadTree::QuadTree(int xBound, int yBound) {
    root = new Node(-xBound, -yBound, xBound, yBound, nullptr);
    pointCount = 0;
    nodeCount = 0;
}

int QuadTree::totalPoints(void) {
    return this->pointCount;
}

int QuadTree::totalNodes(void) {
    return this->nodeCount;
}

void QuadTree::insert(Point *p) {
    insertAt(root, p);
}

void QuadTree::insertAt(Node *node, Point *p) {
    if(!node->contains(p)) {
        return;
    }
    if(!node->isPainted()) {
        node->insert(p);
        node->paint();
        pointCount++;
    } else {
        if(!node->isDivided()) {
            node->subdivide();
            nodeCount += 4;
        }
        for(int i = 0; i < 4; i++) {
            insertAt(node->getChild(i), p);
        }
    }
}

vector<Point*> QuadTree::list(void) {
    vector<Point*> v;
    stack<Node*> nodes;
    nodes.push(root);

    while(!nodes.empty()) {
        Node* x = nodes.top();
        nodes.pop(); 

        if(x->isDivided()) {   
            for (int i = 0; i < 4; i++) {
                    nodes.push(x->getChild(i));
            }
        }
        if(x->isPainted()) {
            v.push_back(x->getPoint());
        }
    }
    return v;
}

int QuadTree::countRegion(Point p, int d) {

}

int QuadTree::aggregateRegion(Point p, int d) {

}