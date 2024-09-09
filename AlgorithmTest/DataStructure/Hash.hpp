//
//  Hash.hpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-08.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>
#include "DoubleLink.hpp"

class Hash
{
public:
    Hash( int slotCount )
    :m_SlotCount(slotCount )
    ,m_pTable( nullptr )
    {
        if( m_SlotCount <= 0 )
        {
            m_SlotCount = 1;
        }
        
        m_pTable = new DLink[ m_SlotCount ];
        
    }
    
    ~Hash();
    
public:
    int getIndex( int key );
    void insert( int key );
    DLinkNode* find( int key );
    void remove( int key );
    
    //other
    void print();
    
    int getSize();
    
private:
    int m_SlotCount;
    DLink* m_pTable;
    
};

void testHash();

#endif /* Hash_hpp */
