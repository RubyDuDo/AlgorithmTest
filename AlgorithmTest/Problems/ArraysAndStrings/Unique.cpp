//
//  Unique.cpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-08.
//

#include "Unique.hpp"
#include <iostream>
using namespace std;

#define MAX_CHAR_NUM 26

//O(n), n is the number of possible characters
bool isUnique( const std::string& str)
{
    if( str.length() > MAX_CHAR_NUM)
    {
        return false;
    }
    
    bool bChar[ MAX_CHAR_NUM ] = {false};
    
    for( int i = 0 ; i < str.length(); i++ )
    {
        int index = int(str.at(i)) - int('a');
        if( bChar[index] == true )
        {
            return false;
        }
        else{
            bChar[index] = true;
        }
    }
    
    return true;
}

//O(n^2), n is the number of possible characters
bool isUniqueNoAdd( const std::string& str )
{
    if( str.length() > MAX_CHAR_NUM)
    {
        return false;
    }
    
    for( int i = 0 ; i < str.length(); i++ )
    {
        for( int j = i+1; j < str.length(); j++ )
        {
            if( str.at(i) == str.at(j) )
            {
                return false;
            }
        }
    }
    return true;
}

//use quick sort first,(has stack cost)
//or heap sort
//compare every with its next
bool isUniqueNoAdd2( const std::string& str )
{
    if( str.length() > MAX_CHAR_NUM)
    {
        return false;
    }
    
    //todo
    return false;
}

void testIsUnique()
{
    std::string str = "iamyourmammy";
    cout<<str<<":"<<isUnique( str )<<endl;
    
    str = "abcdefghijk";
    cout<<str<<":"<<isUnique( str )<<endl;
}
