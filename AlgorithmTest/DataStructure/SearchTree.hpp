//
//  SearchTree.hpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-10.
//

#ifndef SearchTree_hpp
#define SearchTree_hpp

#include <stdio.h>
#include <vector>
class BTreeNode
{
public:
    int m_key;
    BTreeNode* m_left;
    BTreeNode* m_right;
    
    BTreeNode* m_parent;
public:
    BTreeNode() = default;
    BTreeNode( int key )
    :m_key(key)
    ,m_left( nullptr )
    ,m_right( nullptr )
    ,m_parent( nullptr )
    {
        
    }
};


class CSearchTree
{
public:
    BTreeNode* m_root = nullptr;
    
    CSearchTree() = default;

public:
    void transplant( BTreeNode* u, BTreeNode* v);
    
    void insert(  int key );
    BTreeNode* remove( int key );
    static int getMin( BTreeNode* node );
    static int getMax(BTreeNode* node );
    
    static BTreeNode* getMinNode( BTreeNode* node );
    static BTreeNode* getMaxNode(BTreeNode* node );
    
    static BTreeNode* search( BTreeNode* node, int key );
    static BTreeNode* treeSearch( BTreeNode* node, int key );
    static BTreeNode* iterativeTreeSearch( BTreeNode* node, int key );
    
    static BTreeNode* successor( BTreeNode* node );
    static BTreeNode* predecessor( BTreeNode* node );
    
    static void inorderVisit( BTreeNode* node, std::vector<int>& result );
    static void preorderVisit( BTreeNode* node, std::vector<int>& result);
    static void postorderVisit( BTreeNode* node, std::vector<int>& result );
    
};

void testSearchTree();

#endif /* SearchTree_hpp */
