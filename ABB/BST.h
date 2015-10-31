//
//  BST.h
//  ABB
//
//  Created by Zareek Galvan on 3/10/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#ifndef ABB_BST_h
#define ABB_BST_h

#include <stack>
#include <queue>

class BST{
private:
    nodeT *root;
    void preorden(nodeT *r);
    void inorden(nodeT *r);
    void orden(nodeT *r, int arr[], int &i);
    void postorden(nodeT *r);
    void borraTodo(nodeT *r);
    int next(nodeT *r);
    int prev(nodeT *r);
    int howManyChildren(nodeT *r);
    int cuenta(nodeT *r);
    void printL(nodeT *r);
    int findHeight(nodeT *r);
    void nivelxnivel(nodeT *r);
    void width(nodeT *r, int count[], int level);
    int getMax(int arr[], int n);
    void copyTree(nodeT *r, nodeT *sr);
    
public:
    BST();
    BST(const BST& t);
    ~BST();
    bool isEmpty();
    bool add(int d);
    bool find(int d);
    bool del(int d);
    void print(int n);
    int count();
    void printLeaves();
    int height();
    int wherelevelIam(int d);
    void ancestors(int d);
    int max_width();
    void nearst_relative(int d, int d2);
    void nearest_relative(int d, int d2);
    bool operator==(BST t);
    queue<int> toQueue();

};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    borraTodo(root);
}

void BST::borraTodo(nodeT *r)
{
    if (r != NULL)
    {
        borraTodo(r->getLeft());
        borraTodo(r->getRight());
        delete r;
    }
}

bool BST::isEmpty()
{
    return (root == NULL);
}

bool BST::find(int d)
{
    nodeT *aux = root;
    while (aux != NULL)
    {
        if (aux->getData() == d)
        {
            return true;
        }
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    }
    return false;
}

bool BST::add(int d)
{
    nodeT* father = NULL;
    nodeT* aux = root;
    while (aux != NULL)
    {
        if (aux->getData() == d)
        {
            return false;
        }
        father = aux;
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    }
    if (father == NULL)
    {
        root = new nodeT(d);
    }
    else{
        if (father->getData() > d)
        {
            father->setLeft(new nodeT(d));
        }
        else
        {
            father->setRight(new nodeT(d));
        }
    }
    return true;
}

void BST::print(int n)
{
    switch (n)
    {
        case 1: preorden(root);
            break;
        case 2: inorden(root);
            break;
        case 3: postorden(root);
            break;
        case 4: printL(root);
            break;
        case 5: nivelxnivel(root);
            break;
            
    }
    cout << endl;
}

void BST::preorden(nodeT *r)
{
    if (r!= NULL)
    {
        cout << r->getData() << " ";
        preorden(r->getLeft());
        preorden(r->getRight());
    }
}

void BST::inorden(nodeT *r)
{
    if (r!= NULL)
    {
        inorden(r->getLeft());
        cout << r->getData() << " ";
        inorden(r->getRight());
    }
}

void BST::postorden(nodeT *r)
{
    if (r!= NULL)
    {
        postorden(r->getLeft());
        postorden(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::nivelxnivel(nodeT *r)
{
    queue<nodeT*> queue;
    nodeT *aux;
    if (root==NULL)
    {
        cout<<"No hay";
        return;
    }
    queue.push(root);
    while(!queue.empty())
    {
        aux = queue.front();
        queue.pop();
        if (aux!=NULL)
        {
            cout<<aux->getData()<<" ";
            queue.push(aux->getLeft());
            queue.push(aux->getRight());
        }
    }
}

int BST::next(nodeT *r)
{
    nodeT *aux = r->getRight();
    while (aux->getLeft() != NULL)
    {
        aux=aux->getLeft();
    }
    return aux->getData();
}

int BST::prev(nodeT *r)
{
    nodeT *aux = r->getLeft();
    while (aux->getRight() != NULL)
    {
        aux=aux->getRight();
    }
    return aux->getData();
}

int BST::howManyChildren(nodeT *r)
{
    return (r->getLeft()!=NULL?1:0) + (r->getRight()!=NULL?1:0);
}

bool BST::del(int d)
{
    nodeT *father = NULL;
    nodeT *aux = root;
    while (aux != NULL && aux->getData() != d)
    {
        father = aux;
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    }
    if (aux == NULL)
        return false;
    int cont = howManyChildren(aux);
    if (cont == 0)
    {
        if (father == NULL)
        {
            root = NULL;
        }
        else
        {
            if (father->getData() > d)
                father->setLeft(NULL);
            else
                father->setRight(NULL);
        }
        delete aux;
    }
    else if (cont == 1)
    {
        if (father == NULL)
        {
            root = (aux->getLeft()!=NULL)?aux->getLeft():aux->getRight();
        }
        else
        {
            if (father->getData() > d)
            {
                if (aux->getLeft() != NULL)
                {
                    father->setLeft(aux->getLeft());
                }
                else
                {
                    father->setLeft(aux->getRight());
                }
            }
            else
            {
                if (aux->getLeft() != NULL)
                {
                    father->setRight(aux->getLeft());
                }
                else
                {
                    father->setRight(aux->getRight());
                }
            }
            
        }
        delete aux;
    }
    else
    {
        int pred = prev(aux);
        del(pred);
        aux->setData(pred);
    }
    
    return true;
}


int BST::count()
{
    return cuenta(root);
}

int BST::cuenta(nodeT *r)
{
    
    if (r == NULL)
        return 0;
    return 1+cuenta(r->getLeft())+cuenta(r->getRight());
}

void BST::printLeaves()
{
    printL(root);
    cout << endl;
}

void BST::printL(nodeT *r)
{
    if (r != NULL)
    {
        if (r->getLeft() == NULL && r->getRight() == NULL)
        {
            cout << r->getData() << " ";
        }
        printL(r->getLeft());
        printL(r->getRight());
    }
}

int BST::findHeight(nodeT *r)
{
    if (r==NULL)
    {
        return 0;
    }
    return max(findHeight(r->getLeft()),findHeight(r->getRight()))+1;
}

int BST::height()
{
    if (this->isEmpty())
    {
        return -1;
    }
    else
    {
        nodeT *aux = root;
        return findHeight(aux);
    }
    
}

int BST::wherelevelIam(int d)
{
    nodeT *aux = root;
    if (aux==NULL)
    {
        return -1;
    }
    int i=0;
    while (aux != NULL)
    {
        if (aux->getData() == d)
        {
            return i;
        }
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
        i++;
    }
    return -1;
}

void BST::ancestors(int d)
{
    nodeT *aux = root;
    stack<int> stack;
    bool x=false;
    if (aux->getData()==d)
    {
        cout<<"No hay ancestros"<<endl;
        return;
    }
    while (aux != NULL)
    {
        if (aux->getData() == d)
        {
            x=true;
            break;
        }
        stack.push(aux->getData());
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    }
    if (x==false)
    {
        cout<<"No hay ancestros"<<endl;
        return;
    }
    while (!stack.empty())
    {
        cout<<stack.top()<<" ";
        stack.pop();
    }
    cout<<endl;
}

void BST::width(nodeT *r, int *count, int level)
{
    if (r!=NULL)
    {
        count[level]++;
        width(r->getLeft(), count, level+1);
        width(r->getRight(), count, level+1);
    }
}

int BST::max_width()
{
    int w;
    int h=findHeight(root);
    int *c = (int *)calloc(sizeof(int), h);
    int l=0;
    width(root, c, l);
    w = getMax(c,h);
    return w;
}

int BST::getMax(int arr[], int n)
{
    int max=arr[0];
    for (int i=0; i<n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}

//El copy constructor marca error lldb al final del programa, si copia pero al final marca ese error

BST::BST(const BST& t)
{
    copyTree(root, t.root);
}

void BST::copyTree(nodeT *r, nodeT *sr)
{
    if (sr==NULL)
    {
        r=NULL;
    }
    else
    {
        r->setData(sr->getData());
        if (r->getLeft()!=NULL) copyTree(r->getLeft(), sr->getLeft());
        if (r->getRight()!=NULL) copyTree(r->getRight(), sr->getRight());
    }
}

void BST::nearst_relative(int d, int d2)
{
    nodeT *aux = root;
    stack<int> stack;
    bool a=false, b=false;
    while (aux != NULL)
    {
        stack.push(aux->getData());
        if (aux->getData() == d)
        {
            a=true;
            break;
        }
        aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    }
    nodeT *aux2=root;
    int arr[50], c=0;
    while (aux2 != NULL)
    {
        arr[c]=aux2->getData();
        c++;
        if (aux2->getData() == d2)
        {
            b=true;
            break;
        }
        aux2 = (aux2->getData() > d2) ? aux2->getLeft() : aux2->getRight();
    }
    if (a==false || b==false)
    {
        if (a==false && b==false)
        {
            cout<<"No se encontró ningun dato proporcionado"<<endl;
            return;
        }
        else if (a==false && b==true)
        {
            cout<<"No se encontró el dato "<<d<<endl;
            return;
        }
        else if (a==true && b==false)
        {
            cout<<"No se encontró el dato "<<d2<<endl;
            return;
        }
    }
    int x = 0;
    bool f=false;
    while (!stack.empty())
    {
        for (int i=c; i>=0; i--)
        {
            if (stack.top()==arr[i])
            {
                x=stack.top();
                f=true;
                break;
            }
            if (f==true) break;
        }
        stack.pop();
    }
    cout<< x <<endl;
}

void BST::nearest_relative(int d, int d2)
{
    nearst_relative(d, d2);
}

//No sirve el operator ==

//bool BST::operator==(BST t)
//{
//    return true;
//    nodeT *aux = t.root;
//    while (aux!=NULL)
//    {
//        
//    }
//}

void BST::orden(nodeT *r, int arr[], int &i)
{
    if (r!=NULL)
    {
        orden(r->getLeft(), arr, i);
        arr[i]=r->getData();
        i++;
        orden(r->getRight(), arr, i);

    }
}

queue<int> BST::toQueue()
{
    int arr[count()];
    int i=0;
    queue<int> miFila;
    orden(root, arr, i);
    for (int i=0; i<count(); i++)
    {
        miFila.push(arr[i]);
    }
    
    return miFila;
}

#endif
