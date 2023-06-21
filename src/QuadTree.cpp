#include "QuadTree.h"
#include <stack>
using namespace std;

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
            insertAt(node->getChild(i), p); // se inserta en los 4 :o
        }
    }
}

Point* QuadTree::list(void) {
    Point* arr = new Point[this->totalPoints()];
    stack<Node*> nodes;
    nodes.push(root);
    unsigned int cont = 0;

    while(!nodes.empty()) {
        Node* x = nodes.top();
        nodes.pop();
        
        if(x->isPainted()) {
            if(x->isDivided()) {
                for (int i = 3; i >= 0; --i)
                    nodes.push(x->getChild(i));
            } 
            
            else
                arr[cont++] = *(x->getPoint());
        }
    }
    return arr;
}

int QuadTree::countRegion(Point p, int d) {

}

int QuadTree::aggregateRegion(Point p, int d) {

}