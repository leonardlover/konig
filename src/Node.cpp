#include "Point.h"
#include "Node.h"
#include <iostream>

// TODO
Node::Node(int tl, int tr, int bl, int br, Node *p) 
{
    above = Point(tl, tr);
    below = Point(bl, br);
    point = Point();
    color = false;
    parent = p;
    *children = {nullptr};
    divided = false;
}

void Node::setPoint(Point p) 
{
    this->point = p;
}

void Node::subdivide(Point p) 
{
    Node *topLeft = new Node(above.x(), above.y(), below.x()/2, below.y()/2, this);
    children[0] = topLeft;
    Node *topRight = new Node(below.x()/2, above.y(), below.x(), below.y()/2, this);
    children[1] = topRight;
    Node *bottomLeft = new Node(above.x(), below.y()/2, below.x()/2, below.y(), this);
    children[2] = bottomLeft;
    Node *bottomRight = new Node(below.x()/2, below.y()/2, below.x(), below.y(), this);
    children[3] = bottomRight;
    
    for(int i = 0; i<4; ++i) {
        if(children[i]->contains(p)){
            children[i]->setPoint(p);
            divided = true;
            return;
        }
    }
    divided = true;
    return;
}

bool Node::isDivided(void)
{
    return divided;
}

bool Node::isPainted(void) 
{
    return color;
}

Node* Node::getChild(int n) 
{
    return children[n];
}

void Node::setColor(bool c) 
{
    color = c;
}

Point Node::getPoint(void) 
{
    return point;
}

bool Node::contains(Point p) 
{
    return(p.x() >= this->above->x() && p.x() < this->below->x() &&
           p.y() >= this->above->y() && p.y() < this->below->y());
}