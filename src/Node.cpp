#include "Point.h"
#include "Node.h"

// TODO
Node::Node(int tl, int tr, int bl, int br, Node *p) 
{
    above = new Point(tl, tr);
    below = new Point(bl, br);
    point = nullptr;
    color = false;
    parent = p;
    *children = {nullptr};
    divided = false;
}

void Node::insert(Point *p) 
{
    this->point = p;
}

void Node::subdivide(void) 
{
    Node *topLeft = new Node(above->x(), above->y(), below->x()/2, below->y()/2, this);
    this->children[0] = topLeft;
    Node *topRight = new Node(below->x()/2, above->y(), below->x(), below->y()/2, this);
    this->children[1] = topRight;
    Node *bottomLeft = new Node(above->x(), below->y()/2, below->x()/2, below->y(), this);
    this->children[2] = bottomLeft;
    Node *bottomRight = new Node(below->x()/2, below->y()/2, below->x(), below->y(), this);
    this->children[3] = bottomRight;
    divided = true;
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

void Node::paint(void) 
{
    color = true;
}

Point* Node::getPoint(void) 
{
    return point;
}

bool Node::contains(Point *p) 
{
    return(p->x() >= this->above->x() && p->x() < this->below->x() &&
           p->y() >= this->above->y() && p->y() < this->below->y());
}