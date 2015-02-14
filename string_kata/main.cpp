//
//  main.cpp
//  string_kata
//
//  Created by Will Fisher on 2/13/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>
#include <vector>

std::string peek_as_string(std::istream &input, std::string::size_type length = 1)
{
    std::string d = "";
    for(int i=0;i<length;i++)
        d += input.get();
    
    for(auto c:d)
        input.putback(c);
    
    return d;
}

std::string read_delimiter(std::istream &input)
{
    std::ostringstream s;
    
    if (input.peek() == '[')
        input.ignore();
    
    while (input.peek() != ']' && input.peek() != '\n')
        s << (char) input.get();
    
    if (input.peek() == ']')
        input.ignore();
    
    return s.str();
}

std::vector<std::string> get_delimiters(std::istream &input)
{
    std::vector<std::string> delimiters;
    
    delimiters.push_back(",");
    
    if(input.peek() == '/')
    {
        input.ignore();
        input.ignore();
        
        while (input.peek() != '\n')
            delimiters.push_back(read_delimiter(input));
    }
    
    return delimiters;
}

int add(std::string numbers)
{
    
    int value;
    int stringValue = 0;
    std::istringstream input(numbers);
    
    auto delimiters = get_delimiters(input);
    
    while( input >> value )
    {
        if (value < 0)
            throw "negatives not allowed";
        
        if (value <= 1000)
            stringValue += value;
        
        for(auto d:delimiters)
        {
            if (peek_as_string(input, d.length()) == d)
            {
                for(auto i=0;i<d.length();i++)
                    input.ignore();
                break;
            }
        }
    }
    
    return stringValue;
}

TEST_CASE( "basic add") {
    REQUIRE( add("") == 0 );
    REQUIRE( add("1") == 1 );
    REQUIRE( add("2") == 2 );
    REQUIRE( add("1,2") == 3 );
    REQUIRE( add("1,2,3,4,5") == 15 );
    REQUIRE( add("1\n2,3") == 6 );
    REQUIRE( add("//;\n1;2") == 3 );
}
TEST_CASE( "negative add") {
    REQUIRE_THROWS( add("-1,2,10") );
    REQUIRE_THROWS( add("1,2,-10") );
}

TEST_CASE( "advanced add") {
    REQUIRE( add("1,2,1001") == 3 );
    REQUIRE( add("//[;]\n1;2;1001") == 3 );
    REQUIRE( add("//[+][,]\n1+2,3") == 6 );
    REQUIRE( add("//[+][,][_]\n1+2,3_5") == 11 );
    REQUIRE( add("//[***]\n1***2***3***5") == 11 );
    REQUIRE( add("//[***][___]\n1***2___3***5") == 11 );
}