//
//  main.cpp
//  ABB
//
//  Created by Zareek Galvan on 3/10/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#include <iostream>
using namespace std;
#include "nodeT.h"
#include "BST.h"

int main()
{
    BST miArbol;
    miArbol.add(14);
    miArbol.add(10);
    miArbol.add(18);
    miArbol.add(2);
    miArbol.add(5);
    miArbol.add(24);
    miArbol.add(16);
    miArbol.add(17);
    miArbol.add(23);
    cout<<miArbol.max_width()<<" "<<miArbol.count()<<endl;
    queue<int> queue=miArbol.toQueue();
    while (!queue.empty())
    {
        cout<<queue.front()<<" ";
        queue.pop();
    }
    cout<<endl;
}

