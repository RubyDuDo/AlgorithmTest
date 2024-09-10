//
//  DoubleLink.cpp
//  AlgorithmPractice
//
//  Created by pinky on 2024-09-08.
//

#include "DoubleLink.hpp"

#include <utility>
#include <iostream>
using namespace std;

DLink::DLink(std::initializer_list<int> list )
{
    m_size = 0;
    m_head = 0;
    
    if( list.size() == 0 ) return;
    auto it = list.begin();
    for( ; it != list.end(); ++it )
    {
        insertAtHead( *it );
    }
    
    reserve();
    
}

DLink::~DLink()
{
    clear();
}

int DLink::getSize()
{
    return m_size;
}
DLinkNode* DLink::find( int key )
{
    for( auto p = m_head;  p != nullptr; )
    {
        if( p->m_key == key )
        {
            return p;
        }
        
        if( p->m_next == nullptr )
        {
            break;
        }
        else{
            p = p->m_next;
        }
    }
    
    return nullptr;
}

//insert
void DLink::insertAtHead( int key )
{
    auto node = new DLinkNode( key );
    
    if( m_head != nullptr )
    {
        m_head->m_prev = node;
        node->m_next = m_head;
    }
    
    m_head = node;
    m_size++;
    
}

DLinkNode* DLink::getTail()
{
    auto pTail = m_head;
    while( pTail->m_next != nullptr )
    {
        pTail = pTail->m_next;
    }
    
    return pTail;
}
void DLink::insertAtTail( int key )
{
    auto node = new DLinkNode(key);
    
    auto pTail = getTail();
    
    if( pTail == nullptr )
    {
        m_head = node;
    }
    else{
        pTail->m_next = node;
        node->m_prev = pTail;
    }
    
    m_size++;
}

void DLink::insertAfter( int key, DLinkNode* otherNode )
{
    auto node = new DLinkNode(key);
    
    if( otherNode->m_next != nullptr )
    {
        otherNode->m_next->m_prev = node;
        node->m_next = otherNode->m_next;
    }
    
    otherNode->m_next = node;
    node->m_prev = otherNode;
    
    m_size++;
}

//delete
void DLink::deleteKey( int key )
{
    auto pNode = find( key );
    deleteNode( pNode );
}

void DLink::deleteNode( DLinkNode* node )
{
    if( node == nullptr )
        return;
    
    if( node == m_head )
        m_head = node->m_next;
    else{
        node->m_prev->m_next = node->m_next;
        
        if( node->m_next != nullptr )
        {
            node->m_next->m_prev = node->m_prev;
        }
    }
    
    m_size--;
}


//other
void DLink::reserve()
{
    auto pNode = m_head;
    while( pNode != nullptr )
    {
        auto pNext = pNode->m_next;
        if( pNext == nullptr )
        {
            m_head = pNode;
        }
        std::swap( pNode->m_prev, pNode->m_next );
        pNode = pNext;
    }
}

void DLink::combine( DLink& other )
{
    if( other.getSize() == 0 )
    {
        return;
    }
    
    if( getSize() == 0 )
    {
        m_head = other.m_head;
        m_size = other.m_size;
    }
    else{
        auto pTail = getTail();
        if( pTail )
        {
            pTail->m_next = other.m_head;
            m_size += other.m_size;
        }
    }
    
    other.m_head = nullptr;
    other.m_size = 0;
}

void DLink::clear()
{
    for( auto p = m_head; p != nullptr; )
    {
        auto pNext = p->m_next;
        delete p;
        p = pNext;
    }
    
    m_size = 0;
    m_head = nullptr;
}

void DLink::print()
{
    cout<<"DLink("<<m_size<<"):";
    for( auto p = m_head; p != nullptr; p = p->m_next )
    {
        cout<<p->m_key<<",";
    }
    cout<<endl;
    
}

void testDLink()
{
    //test init
    cout<<"Test Init"<<endl;
    DSLink link = {1,5,3};
    link.print();
    
    //test add
    cout<<"Test Insert"<<endl;
    link.insertAtHead( 9 );
    link.insertAtTail( 7);
    auto pNode = link.find( 5 );
    link.insertAfter( 0, pNode );
    link.print();
    
    cout<<"Test delete"<<endl;
    link.deleteKey( 9 );
    link.deleteKey( 7 );
    link.deleteKey( 5 );
    link.print();
    
    cout<<"Test Combine"<<endl;
    DSLink link2 = { 9, 7, 5 };
    DSLink link3 = {};
    
    link.combine( link2 );
    link.print();
    link2.print();
    cout<<"Empty combine"<<endl;
    
    link.combine( link3 );
    link3.combine( link );
    link.print();
    link3.print();
    
    
}

DSLink::DSLink()
{
    m_size = 0;
    m_head.m_prev = &m_head;
    m_head.m_next = &m_head;
}

DSLink::~DSLink()
{
    clear();
}

DSLink::DSLink(std::initializer_list<int> list ):DSLink()
{
    for(auto it = list.begin(); it != list.end(); ++it )
    {
        insertAtTail( *it );
    }
}

//search
int DSLink::getSize()
{
    return m_size;
}

DLinkNode* DSLink::find( int key )
{
    m_head.m_key = key;
    auto p = m_head.m_next;
    while( true )
    {
        if( p->m_key == key )
        {
            break;
        }
        else{
            p = p->m_next;
        }
    }
    
    if( p == &m_head )
    {
        return nullptr;
    }
    else{
        return p;
    }
    
}
DLinkNode* DSLink::getTail()
{
    return m_head.m_prev;
}

//insert
void DSLink::insertAtHead( int key )
{
    auto node = new DLinkNode(key);
    insertAfter( key, &m_head );
    
}

void DSLink::insertAtTail( int key )
{
    insertAfter( key, m_head.m_prev );
    
}
void DSLink::insertAfter( int key, DLinkNode* otherNode )
{
    auto node = new DLinkNode(key);
    
    otherNode->m_next->m_prev = node;
    node->m_next = otherNode->m_next;
    
    otherNode->m_next = node;
    node->m_prev = otherNode;
    m_size++;
}

//delete
void DSLink::deleteKey( int key )
{
    auto node = find( key );
    deleteNode( node );
    
}
void DSLink::deleteNode( DLinkNode* node )
{
    if( node == nullptr )
        return;
    
    node->m_prev->m_next = node->m_next;
    node->m_next->m_prev = node->m_prev;
    
    m_size--;
}


//other
void DSLink::reserve()
{
    auto p = m_head.m_next;
    while( p != &m_head )
    {
        std::swap( p->m_prev, p->m_next );
    }
    
    std::swap( m_head.m_prev, m_head.m_next );
    
}
void DSLink::combine( DSLink& other )
{
    if( other.getSize() == 0 )
    {
        return;
    }
    else if( getSize() == 0 )
    {
        m_head = other.m_head;
    }
    
    m_head.m_prev->m_next = other.m_head.m_next;
    other.m_head.m_next->m_prev = m_head.m_prev;
    
    other.m_head.m_prev->m_next = &m_head;
    m_head.m_prev = other.m_head.m_prev;
    
    m_size += other.m_size;
    other.m_head.m_prev = &other.m_head;
    other.m_head.m_next = &other.m_head;
    other.m_size = 0;
}


void DSLink::clear()
{
    for( auto p = m_head.m_next; p != &m_head; )
    {
        auto pNext = p->m_next;
        delete p;
        p = pNext;
    }
    
    m_head.m_prev = &m_head;
    m_head.m_next = &m_head;
    
    m_size = 0;
}

void DSLink::print()
{
    cout<<"DLink("<<m_size<<"):";
    for( auto p = m_head.m_next; p != &m_head; p = p->m_next )
    {
        cout<<p->m_key<<",";
    }
    cout<<endl;
    
}
