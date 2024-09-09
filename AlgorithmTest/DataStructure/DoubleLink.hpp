//
//  DoubleLink.hpp
//  AlgorithmPractice
//
//  Created by pinky on 2024-09-08.
//

#ifndef DoubleLink_hpp
#define DoubleLink_hpp

#include <stdio.h>
#include <initializer_list>
#include <iostream>

class DLinkNode
{
public:
    int m_key;
    DLinkNode* m_prev;
    DLinkNode* m_next;
    
    DLinkNode() = default;
    DLinkNode( int key ):m_key(key)
    ,m_prev(nullptr)
    ,m_next(nullptr)
    {
    }
    
    void print()
    {
        std::cout<<m_key<<",";
    }
};

class DLink
{
public:
    DLinkNode* m_head;
    int m_size;
    
public:
    DLink() = default;
    ~DLink();
    DLink(std::initializer_list<int> list );
    //search
    int getSize();
    DLinkNode* find( int key );
    DLinkNode* getTail();
    
    //insert
    void insertAtHead( int key );
    void insertAtTail( int key );
    void insertAfter( int key, DLinkNode* otherNode );
    
    //delete
    void deleteKey( int key );
    void deleteNode( DLinkNode* node );
    
    
    //other
    void reserve();
    void combine( DLink& other );
    void clear();
    
    //debug
    void print();
    
};

void testDLink();

#endif /* DoubleLink_hpp */
