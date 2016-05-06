// ����������� �����

#include "Numbers.h"

class Complex: virtual public Numbers
{
    const double static pi;
    static int counter;                                         // ������� ��������
    static int num;                                             // 
    int objNum;                                                 // ����� �������
    double real, image;
    static Numbers* arrPointers;                               // ���������� ������� ����������
    static int arrSize;                                         // ������ �������

public:
    Complex();
    Complex(double, double);
    Complex(const Complex &);
    ~Complex();
    double mod();
    double arg();
    /*-----------------------------------------------------*/
    static void setSize();
    static int getSize();
    static Numbers* getArray();
    static Complex add();
    static void del(Numbers*);
    //static void grow(Complex* &, int);
    static void createObj(Numbers* &, int &, int elementNumber=0);
    virtual void edit();
    virtual void show();
    static int getCounter();
    int getNum();
    /*-----------------------------------------------------*/
    friend ostream & operator << (ostream &out, Complex &obj);
    friend istream & operator >> (istream &in, Complex &obj);
};
