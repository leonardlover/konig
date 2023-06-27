#include "QuadTree.h"
#include <iostream>

QuadTree::QuadTree(int xBound, int yBound) { // qt´s canvas is initialized from -x,-y to x,y
    root = new Node(-xBound, -yBound, xBound, yBound, nullptr);
    pointCount = 0;
    nodeCount = 1;
}

int QuadTree::totalPoints(void) {
    return pointCount;
}

int QuadTree::totalNodes(void) {
    return nodeCount;
}

void QuadTree::insert(Point p) {
    insertAt(root, p);
}

void QuadTree::insertAt(Node *node, Point p) {
    if(!node->contains(p)) { // if the point is not contained in the node, return
        return;
    }
    if(node->isDivided()) {
        for(int i = 0; i < 4; i++) {
            insertAt(node->getChild(i), p);
        }
    } else {
        if(!node->isPainted()) {
            node->setPoint(p);
            node->setColor(true);
            pointCount++;
        }
        else {
            node->subdivide(node->getPoint());
            node->setPoint(Point());
            node->setColor(false);
            nodeCount += 4;
        
            for(int i = 0; i < 4; i++) {
                insertAt(node->getChild(i), p);
            }
        }
    }
    /*
    if(!node->isPainted()) { // if this node is empty, insert the point
            node->setPoint(p);
            node->setColor(true);
            pointCount++;
    } else { // if is not, divide and try inserting into its 4 children, only one is going to accept the point
        if(p->x() == node->getPoint()->x() && p->y() == node->getPoint()->y()) { // don't insert duplicated nodes
            return;
        }
        if(!node->isDivided()) {
            node->subdivide(node->getPoint());
            node->setPoint(nullptr);
            node->setColor(false);
            nodeCount += 4;
        }
        for(int i = 0; i < 4; i++) {
            insertAt(node->getChild(i), p);
        }
    }*/
    return;
}

vector<Point> QuadTree::list(void) {
    vector<Point> v;
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