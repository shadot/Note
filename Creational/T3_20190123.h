//
//  T3_20190123.h
//  DesignPattern
//
//  Created by shadot on 2019/1/23.
//  Copyright © 2019 shadot. All rights reserved.
//

#ifndef T3_20190123_h
#define T3_20190123_h

//C++工厂方法模式

#include <iostream>

using namespace std;

class ICar{
public:
    virtual string Name() = 0;
};

class ConcreteCarA : public ICar{
public:
    string Name(){
        return "CarA";
    }
};

class ConcreteCarB : public ICar{
public:
    string Name(){
        return "CarB";
    }
};

class IFactory{
public:
    virtual ICar* CreateCar() = 0;
};

class ConcreteFactoryA : public IFactory{
public:
    ICar* CreateCar(){
        return new ConcreteCarA();
    }
};

class ConcreteFactoryB : public IFactory{
public:
    ICar* CreateCar(){
        return new ConcreteCarB();
    }
};

#endif /* T3_20190123_h */
