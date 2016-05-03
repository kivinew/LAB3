// производный класс
#pragma once
#include "Numbers.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <Windows.h>
using namespace std;

class Complex: public Numbers
{
    const double static pi;
    static int counter;                                         // счЄтчик объектов
    static int num;                                             // 
    int objNum;                                                 // номер объекта
    double real, image;
    static Numbers** arrPointers;                               // объ€вление массива указателей
    static int arrSize;                                         // размер массива

public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    ~Complex();
    double mod();
    double arg();
    /*-----------------------------------------------------*/
    static int arrSize;
    static Numbers** arrPointers;
    static void setSize();
    static int getSize();
    static Numbers** getArray();
    static Numbers* add();
    static void del(Numbers* &);
    static void grow(Numbers** &, int &);
    static void createObj(Numbers** &, int &, int elementNumber=0);
    virtual void edit();
    virtual void show();
    static int getCounter();
    int getNum();
    /*-----------------------------------------------------*/
    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
};
