#include "QuadTree.h"

QuadTree::QuadTree(int xBound, int yBound) {
    root = new Node(0, 0, xBound, yBound, nullptr);
    pointCount = 0;
    nodeCount = 0;
}

int QuadTree::totalPoints(void) {

}

int QuadTree::totalNodes(void) {

}

void QuadTree::insert(Point *p) {
    insertAt(root, p);
}

void QuadTree::insertAt(Node *node, Point *p) {
    if(!node->isFull()) {
        node->insert(p);
        node->paint();
    } else {
        if(!node->isDivided()) {
            node->subdivide();
        }
        for(int i = 0; i < 4; i++) {
            insertAt(node->getChild(i), p);
        }
    }
}

Point* QuadTree::list(void) {

}

int QuadTree::countRegion(Point p, int d) {

}

int QuadTree::aggregateRegion(Point p, int d) {

}