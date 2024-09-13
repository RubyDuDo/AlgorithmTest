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
#define MAX_NUM 128

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

bool isPalindromePemu( std::string& str )
{
    str.erase( std::remove( str.begin(), str.end(), ' '), str.end() );
    cout<<"After erase space :" <<str<<endl;
    
    int chars[MAX_NUM] = {0};
    
    for( int i = 0 ; i < str.length(); i++ )
    {
        chars[ (int)str.at(i) ] += 1;
    }
    
    std::string res = str;
    int oddCount = 0;
    int curIndex = 0;
    int len = str.length();
    char single = ' ';
    for( int i = 0 ; i < MAX_NUM; i++ )
    {
        if( chars[i] == 0 )
        {
            continue;
        }
        
        if( chars[i] % 2 != 0 )
        {
            oddCount += 1;
            if( oddCount > 1 )
            {
                return false;
            }
            else{
                single = char(i);
                int count = chars[i] / 2;
                for( int j = 0 ; j < count; j++ )
                {
                    res.at(curIndex) = char(i);
                    res.at(len - curIndex - 1 ) = char(i);
                    curIndex++;
                }
                res.at( len/2 ) = single;
            }
        }
        else{
            int count = chars[i] / 2;
            for( int j = 0 ; j < count; j++ )
            {
                res.at(curIndex) = char(i);
                res.at(len - curIndex - 1 ) = char(i);
                curIndex++;
            }
        }
    }
    
    cout<<"PalindromePemu:"<< std::string(res) <<endl;
    return true;
}

void testPalindromePemu()
{
    std::string str("taco cat");
    cout<<str<<":"<<endl;
    cout<<isPalindromePemu( str )<<endl;
    
    std::string str1("888999I love evol I");
    cout<<str1<<":"<<endl;
    cout<<isPalindromePemu( str1 )<<endl;
    
    std::string str2("abccba");
    cout<<str2<<":"<<endl;
    cout<<isPalindromePemu( str2 )<<endl;
    
    std::string str3("aaaabccba");
    cout<<str3<<":"<<endl;
    cout<<isPalindromePemu( str3 )<<endl;
}

#include <sstream>
std::string stringCompression( std::string& str )
{
    std::string strRes;
    if( str.length() == 0 )
    {
        return str;
    }
    
    std::stringstream ss;
    
    char cur = str.at(0);
    int count = 1;
    for(int i = 1; i < str.length(); i++ )
    {
        if( str.at(i) == cur )
        {
            count++;
        }
        else{
            ss<< cur;
            if( count > 1 )
                ss<<count;
            cur = str.at(i);
            count = 1;
        }
    }
    
    ss<< cur <<count;
    strRes = ss.str();
    if( strRes.length() < str.length() )
    {
        return strRes;
    }
    else{
        return str;
    }
}


void testStringCompression()
{
    std::string str = "aaabbbbb";
    cout<<str<<":"<<stringCompression( str )<<endl;
    
    std::string str1 = "abcedfff";
    cout<<str1<<":"<<stringCompression( str1 )<<endl;
    
    std::string str2 = "aabbccdd";
    cout<<str2<<":"<<stringCompression( str2 )<<endl;
    
}

bool isIndentity( const std::string& left, int p , const std::string& right, int q )
{
    if( p == left.length() && q == right.length() )
    {
        return true;
    }
        
    for( ; p < left.length() && q < right.length(); p++, q++ )
    {
        if( left.at(p) != right.at(q) )
        {
            return false;
        }
    }
    
    if( p == left.length() && q == right.length() )
    {
        return true;
    }
    else{
        return false;
    }
}

bool isOneWay( const std::string& left, int p , const std::string& right, int q )
{
    if( (p == left.length() && q == right.length() - 1) ||
       p == left.length() -1 && q == right.length() )
    {
        return true;
    }
    
    if( left.at(p) == right.at(q) )
    {
        return isOneWay( left,  p+1,  right ,  q+1);
    }
    else{
        return isIndentity( left,  p+1,  right ,  q+ 1) ||
        isIndentity( left,  p+1, right,  q ) ||
        isIndentity( left, p,  right,  q+1 );
    }
}

bool isOneWay(const  std::string& left, const std::string& right )
{
    return isOneWay( left , 0, right , 0 );
}

#include <cassert>
void testIsOneWay()
{
    cout<<"testIsOneWay"<<endl;
    assert( isOneWay("pale",  "ple") == true );
    assert( isOneWay("pales","pale") == true );
    assert( isOneWay("pale","bale") == true );
    assert( isOneWay("pale","bake") == false) ;
    
}

void testArraysAndStrings()
{
//    testStringCompression();
    
    testIsOneWay();
}
