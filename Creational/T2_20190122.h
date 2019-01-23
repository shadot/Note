//
//  T2_20190122.h
//  DesignPattern
//
//  Created by shadot on 2019/1/22.
//  Copyright © 2019 shadot. All rights reserved.
//

#ifndef T2_20190122_h
#define T2_20190122_h

#include <iostream>

using namespace std;

//
//C++简单工厂模式
//

//抽象产品
class ICar
{
public:
    virtual string Name() = 0; //汽车名称
};

//具体产品A
class ACar : public ICar
{
public:
    string Name(){
        return "ACar";
    }
};

//具体产品B
class BCar : public ICar
{
public:
    string Name(){
        return "BCar";
    }
};

//工厂
class Factory
{
public:
    enum TYPE {A, B};
    
    ICar* CreateCar(TYPE type){
        ICar* car = nullptr;
        
        switch (type) {
            case A:
                car = new ACar();
                break;
                
            case B:
                car = new BCar();
                break;
                
            default:
                break;
        }
        
        return car;
    }
};

#endif /* T2_20190122_h */
