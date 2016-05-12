/* ПРОИЗВОДНЫЙ КЛАСС */
#pragma once
#include "Numbers.h"

class Complex: public Numbers
{
    static Numbers** arrPtr;
    static int arrSize;
    static const double pi;
    static int counter;
    double real, image;
public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    virtual ~Complex();

    double mod();
    double arg();
    static void createArr();
    static Numbers** getArr();
    static void setSize();
    static int getSize();
    static void reSize();
    static void add(int);
    virtual void edit();
    virtual void show();
    static void showAll();
    static void del(int num);
    static int getCounter();

    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
};
