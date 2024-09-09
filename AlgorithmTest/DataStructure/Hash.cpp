//
//  Hash.cpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-08.
//

#include "Hash.hpp"
#include <iostream>
using namespace std;

Hash::~Hash()
{
    if( m_pTable )
    {
        delete [] m_pTable;
    }
    m_SlotCount = 0;
}

int Hash::getIndex( int key )
{
    return key % m_SlotCount;
}

void Hash::insert( int key )
{
    int index = getIndex( key );
    m_pTable[ index ].insertAtHead( key );
    
}
DLinkNode* Hash::find( int key )
{
    int index = getIndex( key );
    auto node = m_pTable[index].find( key );
    return node;
}

void Hash::remove( int key )
{
    int index = getIndex( key );
    m_pTable[index].deleteKey( key );
}

void Hash::print()
{
    cout<<"Hash("<<getSize()<<"):"<<endl;
    for( int i = 0 ; i < m_SlotCount; i++ )
    {
        if( m_pTable[i].getSize() != 0 )
        {
            cout<<"["<<i<<"]";
            m_pTable[i].print();
        }
        
    }
    cout<<endl;
    
}

int Hash::getSize()
{
    int size = 0;
    for( int i = 0 ; i < m_SlotCount; i++ )
    {
        size += m_pTable[i].getSize();
    }
    
    return size;
}

void hashInsert( Hash& hash, std::initializer_list<int> list )
{
    auto it = list.begin();
    for( ; it != list.end(); ++it )
    {
        hash.insert( *it );
    }
}

void testHash()
{
    //test create
    Hash hash(13);
    
    hashInsert( hash, {1, 100, 23, 99, 23, 11});
    hash.print();
    
    hash.remove(23 );
    hash.remove( 100 );
    
    hash.print();
    
    auto node = hash.find(23);
    node->print();
    
    
    //test 
}
