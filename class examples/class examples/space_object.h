//
//  space_object.h
//  class examples
//
//  Created by will on 1/30/15.
//  Copyright (c) 2015 will. All rights reserved.
//

#ifndef __class_examples__space_object__
#define __class_examples__space_object__

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class SpaceObject
{
public:
    SpaceObject(int h):_health(h)
    { }
    virtual ~SpaceObject() = default;
    virtual void print() const = 0;
    
    int getHealth() const {
        return _health;
    }
private:
    int _health;
};

class Asteroid : public SpaceObject
{
public:
    using SpaceObject::SpaceObject;
    
    virtual void print() const override
    {
        cout << "Asteroid";
    }
};

class Bullet : public SpaceObject
{
public:
    using SpaceObject::SpaceObject;
    
    virtual void print() const override
    {
        cout << "Bullet";
    }
};

#endif /* defined(__class_examples__space_object__) */
