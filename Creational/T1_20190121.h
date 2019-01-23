//
//  T1_20190121.h
//  DesignPattern
//
//  Created by shadot on 2019/1/21.
//  Copyright © 2019 shadot. All rights reserved.
//

#ifndef T1_20190121_h
#define T1_20190121_h

#include <iostream>
#include <mutex>  

using namespace std;

//
//单例模式
//

//////////////////////////////////////////////////////////////////////////////////////////////////////

//01.局部静态变量
class Singleton1
{
public:
    static Singleton1* GetInstance();
    
private:
    Singleton1() {}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

//02.懒汉式 （非多线程安全，需要双检测来保证效率与线程安全性）
class Singleton2
{
public:
    static Singleton2* GetInstance();
    static void DestoryInstance();
    
private:
    Singleton2(){}
    
private:
    static Singleton2* m_pSingleton;
    //static mutex m_mutex; //锁
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

//03.饿汉式 (线程安全)
class Singleton3
{
public:
    static Singleton3* GetInstance();
    static void DestoryInstance();
    
private:
    Singleton3(){}
    
private:
    static Singleton3* m_pSingleton;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
/*
//04.自动释放02.03两种
class Singleton4
{
public:
    static Singleton4* GetInstance();
    static void DestoryInstance();
    
private:
    Singleton4(){}
    
private:
    static Singleton4* m_pSingleton;
    
    class GC{
    public:
        ~GC(){
            if (m_pSingleton)
            {
                delete m_pSingleton;
                m_pSingleton = nullptr;
            }
        }
        static GC gc; //用于释放单例
    };
};
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////



#endif /* T1_20190121_h */
