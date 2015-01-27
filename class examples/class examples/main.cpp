//
//  main.cpp
//  class examples
//
//  Created by will on 1/26/15.
//  Copyright (c) 2015 will. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;


template <typename Container>
auto maxValue(const Container &c) -> typename std::remove_reference<decltype(c.front())>::type
{
    auto biggest = c.front();
    for(const auto &x : c)
    {
        if(x>biggest)
            biggest = x;
        
    }
    return biggest;
}
template <typename T, typename R>
auto add(T t, R r) -> decltype(t+r)
{
    return t+r;
}

int main(int argc, const char * argv[]) {
    const vector<int> l{1,2,13,4,5};
    
//    for(auto i=l.begin();i!=l.end();++i)
//        cout << *i << " ";
    
    for(auto i:l)
        cout << i << " ";
    
    cout << endl;
    
    cout << "Max: " << maxValue(l) << endl;
    
    cout << add(1, 10.05) << endl;
    
    
    return 0;
}
