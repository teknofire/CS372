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

#include <algorithm>
using std::remove_if;

#include <memory>
using std::unique_ptr;
using std::make_unique;

#include "space_object.h"

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

bool deleteSpaceObject(unique_ptr<SpaceObject> &p)
{
    return p->getHealth() <= 0;
}

int main(int argc, const char * argv[])
{
    vector<unique_ptr<SpaceObject>> v;
    v.push_back(make_unique<Asteroid>(4));
    v.push_back(make_unique<Bullet>(0));
    
    for(auto &i:v)
    {
        i->print();
        cout << endl;
    }

    int deathhealth=0;
    
    v.erase(
        remove_if(v.begin(), v.end(),
                  [=](auto const &p) { return p->getHealth() <= deathhealth; }
        ),
        v.end()
    );

    for(auto &i:v)
    {
        i->print();
        cout << endl;
    }
}


//    for(auto i = v.begin(); i!=v.end(); ++i)
//        if((*i)->getHealth() <= 0)
//        {
//            delete *i;
//            i = v.erase(i);
//        }
    
//    const vector<int> l{1,2,13,4,5};
//    
////    for(auto i=l.begin();i!=l.end();++i)
////        cout << *i << " ";
//    
//    for(auto i:l)
//        cout << i << " ";
//    
//    cout << endl;
//    
//    cout << "Max: " << maxValue(l) << endl;
//    
//    cout << add(1, 10.05) << endl;
//    
//    
//    return 0;
//}
