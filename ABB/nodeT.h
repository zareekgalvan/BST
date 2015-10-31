
//  nodeT.h
//  ABB
//
//  Created by Zareek Galvan on 3/10/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#ifndef ABB_nodeT_h
#define ABB_nodeT_h

class nodeT
{
private:
    int data;
    nodeT *left;
    nodeT *right;

public:
    nodeT(int data);
    nodeT(int data, nodeT *left, nodeT *right);
    int getData();
    void setData(int data);
    nodeT* getLeft();
    nodeT* getRight();
    void setLeft(nodeT* left);
    void setRight(nodeT *right);
    
};

nodeT::nodeT(int data)
{
    this->data=data;
    this->left = NULL;
    this->right = NULL;
}

nodeT::nodeT(int data, nodeT *left, nodeT *right)
{
    this->data=data;
    this->left = left;
    this->right = left;
}

int nodeT::getData()
{
    return data;
}

void nodeT::setData(int data)
{
    this->data=data;
}

nodeT* nodeT::getLeft()
{
    return left;
}

nodeT* nodeT::getRight()
{
    return right;
}

void nodeT::setLeft(nodeT *left)
{
    this->left=left;
}

void nodeT::setRight(nodeT *right)
{
    this->right=right;
}
#endif
