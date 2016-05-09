/* œ–Œ»«¬ŒƒÕ€…  À¿—— */
#include "Numbers.h"

class Complex: virtual public Numbers
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
    static Numbers** getArr();
    static void setSize();
    static int getSize();
    static void reSize();
    static void add();
    void edit();
    void show();
    static void showAll();
    static void del(int num);
    static int getCounter();

    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
};
