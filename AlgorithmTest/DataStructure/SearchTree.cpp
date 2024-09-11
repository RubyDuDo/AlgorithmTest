//
//  SearchTree.cpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-10.
//

#include "SearchTree.hpp"

void CSearchTree::insert(  int key )
{
    auto p = new BTreeNode( key );
    if( m_root == nullptr )
    {
        m_root = p;
        return;
    }
    
    auto pParent = m_root;
    auto pCur = m_root;
    while( pCur != nullptr )
    {
        pParent = pCur;
        if( key <= pCur->m_key )
        {
            pCur = pCur->m_left;
        }
        else{
            pCur = pCur->m_right;
        }
    }
    
    if( key < pParent->m_key )
    {
        pParent->m_left = p;
    }
    else{
        pParent->m_right = p;
    }
    
    p->m_parent = pParent;
    
}

void CSearchTree::transplant( BTreeNode* u, BTreeNode* v)
{
    if( u->m_parent == nullptr )
    {
        m_root = v;
        v->m_parent = nullptr;
        return;
    }
    else if( u == u->m_parent->m_left )
    {
        u->m_parent->m_left = v;
    }
    else{
        u->m_parent->m_right = v;
    }
    
    if( v != nullptr )
    {
        v->m_parent = u->m_parent;
    }
    
    u->m_parent = nullptr;
    
    //todo: clear u
    
}

BTreeNode* CSearchTree::remove( int key )
{
    auto z = search( m_root,  key );
    if( !z ) return z;
    
    if( z->m_left == nullptr )
    {
        transplant( z, z->m_right);
    }
    else if( z->m_right == nullptr )
    {
        transplant( z , z->m_left );
    }
    else{
        auto y = getMinNode( z->m_right );
        if( y != z->m_right)
        {
            transplant( y,  y->m_right );
            y->m_right = z->m_right;
            y->m_right->m_parent = y;
        }
        transplant( z , y );
        y->m_left = z->m_left;
        y->m_left->m_parent = y;
    }
    
    return z;
    
}

BTreeNode* CSearchTree::getMinNode( BTreeNode* node )
{
    if( node == nullptr )
    {
        return nullptr;
    }
    
    auto p = node;
    while( true )
    {
        if( p->m_left == nullptr )
        {
            return p;
        }
        else{
            p = p->m_left;
        }
    }
}

BTreeNode* CSearchTree::getMaxNode(BTreeNode* node )
{
    if( node == nullptr )
    {
        return nullptr;
    }
    
    auto p = node;
    while( true )
    {
        if( p->m_right == nullptr )
        {
            return p;
        }
        else{
            p = p->m_right;
        }
    }
}

int CSearchTree::getMin( BTreeNode* node )
{
    auto p = getMinNode( node );
    if( p == nullptr )
    {
        return -1;
    }
    else{
        return p->m_key;
    }
}

int CSearchTree::getMax(BTreeNode* node )
{
    auto p = getMaxNode( node );
    if( p == nullptr )
    {
        return -1;
    }
    else{
        return p->m_key;
    }
}

BTreeNode* CSearchTree::search( BTreeNode* node, int key )
{
    auto p = node;
    while( p != nullptr )
    {
        if( p->m_key == key )
        {
            return p;
        }
        else if( key <= p->m_key)
        {
            p = p->m_left;
        }
        else{
            p = p->m_right;
        }
    }
    
    return nullptr;
}

BTreeNode* CSearchTree::treeSearch( BTreeNode* node, int key )
{
    if( node == nullptr )
    {
        return nullptr;
    }
    
    if( key == node->m_key )
    {
        return node;
    }
    else if( key < node->m_key )
    {
        return treeSearch( node->m_left, key );
    }
    else{
        return treeSearch( node->m_right, key );
    }
}

BTreeNode* CSearchTree::iterativeTreeSearch( BTreeNode* node, int key )
{
    auto p = node;
    while( p != nullptr )
    {
        if( p->m_key == key )
        {
            return p;
        }
        else if( key <= p->m_key)
        {
            p = p->m_left;
        }
        else{
            p = p->m_right;
        }
    }
    
    return nullptr;
    
}

BTreeNode* CSearchTree::successor( BTreeNode* node )
{
    if( node == nullptr )
    {
        return nullptr;
    }
    
    if( node->m_right )
    {
        return getMinNode( node->m_right );
    }
    else{
        auto p = node;
        //find the first node which is the left node of its parent, and the parent is the successor
        //if there is no such node ,then return nullptr
        while( p != nullptr )
        {
            if( p->m_parent == nullptr )
            {
                return nullptr;
            }
            
            if( p->m_parent->m_left == p )
            {
                return p->m_parent;
            }
            else{
                p = p->m_parent;
            }
        }
        return nullptr;
    }
}

BTreeNode* CSearchTree::predecessor( BTreeNode* node )
{
    if( node == nullptr )
    {
        return nullptr;
    }
    
    if( node->m_left )
    {
        return getMaxNode( node->m_left );
    }
    else{
        auto p = node;
        //find the first node which is the left node of its parent, and the parent is the successor
        //if there is no such node ,then return nullptr
        while( p != nullptr )
        {
            if( p->m_parent == nullptr )
            {
                return nullptr;
            }
            
            if( p->m_parent->m_right == p )
            {
                return p->m_parent;
            }
            else{
                p = p->m_parent;
            }
        }
        return nullptr;
    }
}

void CSearchTree::inorderVisit( BTreeNode* node, std::vector<int>& result )
{
    if( node == nullptr )
    {
        return;
    }
    
    inorderVisit( node->m_left, result );
    result.push_back( node->m_key);
    inorderVisit( node->m_right, result );
}

void CSearchTree::preorderVisit( BTreeNode* node,std::vector<int>& result )
{
    if( node == nullptr )
    {
        return;
    }
    
    result.push_back( node->m_key);
    preorderVisit( node->m_left, result );
    preorderVisit( node->m_right, result );
    
}
void CSearchTree::postorderVisit( BTreeNode* node,std::vector<int>& result )
{
    if( node == nullptr )
    {
        return;
    }
    
    postorderVisit( node->m_left, result );
    postorderVisit( node->m_right, result );
    result.push_back( node->m_key);
    
    
}

#include <iostream>
using namespace std;
void print(std::vector<int>& result, const std::string& str )
{
    cout<<str<<":";
    for( int i = 0 ; i < result.size(); i++ )
    {
        cout<<result[i]<<",";
    }
    cout<<endl;
    
}

void testSearchTree()
{
    CSearchTree tree;
    
    tree.insert(  10);
    tree.insert(  4);
    tree.insert(  17);
    tree.insert( 1);
    tree.insert(  5);
    tree.insert( 16);
    tree.insert(  21);
    
    std::vector<int> result;
    CSearchTree::inorderVisit( tree.m_root,  result);
    print(result,"Inorder");
    result.clear();
    CSearchTree::preorderVisit( tree.m_root,  result);
    print(result,"Preorder");
    result.clear();
    CSearchTree::postorderVisit( tree.m_root,  result);
    print(result,"Postorder");
    
    int min = CSearchTree::getMin( tree.m_root );
    int max = CSearchTree::getMax( tree.m_root );
    cout<<"Min:"<<min<<"___Max:"<<max<<endl;
    
    auto p = CSearchTree::successor( tree.m_root );
    auto p2= CSearchTree::predecessor( tree.m_root->m_right->m_left );
    auto p3= CSearchTree::predecessor( tree.m_root->m_left->m_left );
    cout<<"Find successor 10:"<<p->m_key<<endl;
    cout<<"Find predecessor 16:"<<p2->m_key<<endl;
    
    if( p3 )
    {
        cout<<"Find predecessor 1:"<<p3->m_key<<endl;
    }
    else{
        cout<<"Find predecessor 1: Not exist"<<endl;
    }
    
    
//    result.clear();
//    auto pr = tree.remove( 16);
//    CSearchTree::inorderVisit( tree.m_root,  result);
//    print(result,"Inorder");
//    pr = tree.remove( 1);
//    result.clear();
//    CSearchTree::inorderVisit( tree.m_root,  result);
//    print(result,"Inorder");
    
//    result.clear();
//    auto pr = tree.remove( 4);
//    CSearchTree::inorderVisit( tree.m_root,  result);
//    print(result,"Inorder");
//    pr = tree.remove( 17);
//    result.clear();
//    CSearchTree::inorderVisit( tree.m_root,  result);
//    print(result,"Inorder");
    
    result.clear();
    auto pr = tree.remove( 10);
    CSearchTree::inorderVisit( tree.m_root,  result);
    print(result,"Inorder");
    pr = tree.remove( 21);
    result.clear();
    CSearchTree::inorderVisit( tree.m_root,  result);
    print(result,"Inorder");
    
    
    
}
