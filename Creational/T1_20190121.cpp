//
//  T1_20190121.cpp
//  DesignPattern
//
//  Created by shadot on 2019/1/21.
//  Copyright © 2019 shadot. All rights reserved.
//

#include "T1_20190121.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////

Singleton1* Singleton1::GetInstance()
{
    static Singleton1 instance;
    return &instance;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//懒汉式
Singleton2* Singleton2::m_pSingleton = nullptr;

Singleton2* Singleton2::GetInstance()
{
    if (m_pSingleton == nullptr){
        
        //std::lock_guard<mutex> lock(m_mutex); //会自动释放的锁
        
        if (m_pSingleton == nullptr){
            m_pSingleton = new Singleton2();
        }
    }
    
    return m_pSingleton;
}

void Singleton2::DestoryInstance()
{
    if (m_pSingleton)
    {
        delete m_pSingleton;
        m_pSingleton = nullptr;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

//饿汉式
Singleton3* Singleton3::m_pSingleton = new Singleton3();

Singleton3* Singleton3::GetInstance()
{
    return m_pSingleton;
}

void Singleton3::DestoryInstance()
{
    if (m_pSingleton)
    {
        delete m_pSingleton;
        m_pSingleton = nullptr;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 Singleton::GC Singleton::GC::gc; // 重要
 
 int main()
 {
    Singleton *pSingleton1 = Singleton::GetInstance();
    Singleton *pSingleton2 = Singleton::GetInstance();
 
    cout << (pSingleton1 == pSingleton2) << endl;
 
    return 0;
 }
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
