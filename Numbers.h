// абстрактный класс
#pragma once
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
using namespace std;
class Numbers
{

public:
    virtual ~Numbers() 
    {
        cout<<"Numbers destructor!"<<endl;
    };
    virtual void edit() = 0;
    virtual void show() = 0;
};
