//
//  Unique.hpp
//  AlgorithmTest
//
//  Created by pinky on 2024-09-08.
//

#ifndef Unique_hpp
#define Unique_hpp

#include <stdio.h>
#include <string>

// 1.1
//only a-z
bool isUnique( const std::string& str);
bool isUniqueNoAdd( const std::string& str );
bool isUniqueNoAdd2( const std::string& str );

void testIsUnique();

//1.4
bool isPalindromePemu( std::string& str );
void testPalindromePemu();

//1.5
void isOneWay( std::string& left, std::string& right );
void testIsOneWay();

//1.6
std::string stringCompression( std::string& str );
void testStringCompression();

void testArraysAndStrings();

#endif /* Unique_hpp */
