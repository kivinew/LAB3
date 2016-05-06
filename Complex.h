/* ÏĞÎÈÇÂÎÄÍÛÉ ÊËÀÑÑ */
#include "Numbers.h"

class Complex: virtual public Numbers
{
    static Numbers** arrPtr;                                 //óêàçàòåëè ÁÀÇÎÂÎÃÎ òèïà
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
    static Numbers** getArr();
    static void setSize();
    static int getSize();
    static Complex* add();
    virtual void edit();
    virtual void show();
    static void showAll();
    static void del(int num);
    static int getCounter();

    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator>>(istream &in, Complex &obj);
};
