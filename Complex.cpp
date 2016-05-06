﻿#include "Complex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;
int Complex::arrSize;
Numbers* Complex::arrPointers = new Complex;

Complex::Complex(): real(0.), image(0.)                                 // конструктор по умолчанию
{
    objNum = ++num;
    counter++;
}

Complex::Complex(double re, double im): real(re), image(im)             // конструктор с параметрами
{
    objNum = ++num;
    counter++;
}

Complex::Complex(const Complex &obj): real(obj.real), image(obj.image)  // конструктор копирования
{
    objNum = ++num;
    counter++;
}

Complex::~Complex()                                                     // деструктор
{
    counter--;
}

void Complex::setSize()
{
    cout<<"Введите количество объектов: ";
    cin>>arrSize;
    if (arrSize==0)
        arrSize = 1;
    return;
}

int Complex::getSize()                                                  // вернуть размер
{
    return arrSize;
}

Numbers* Complex::getArray()                                           // вернуть массив
{
    return arrPointers;
}

int Complex::getCounter()                                               // возврат количества объектов
{
    return counter;
}

int Complex::getNum()                                                   // возврат номера объекта
{
    return objNum;
}

void Complex::createObj(Numbers* &arr, int &size, int elementNumber)        // создать объект
{
    if (Complex::getCounter()==size)                                        // если количество объектов равно размеру массива
        //Complex::grow(arrPointers, arrSize);                              // то его нужно увеличить
    for (int i = elementNumber; i<size; i++)
    {
        if (arr+i == NULL)                          	                    // если указатель нулевой, то
        {                                                                   // 
            arr[i] = Complex::add();                                        // создать в этой ячейке объект
            arr[i].edit();
            return;
        }
    }
    return;
}

void Complex::edit()                                                // редактирование объекта
{
    cin>>*this;
    return;
}

Complex Complex::add()                             // создать указатель типа Numbers
{                                                   // на объект типа Complex
    Complex* newPtr = new Complex(1.,1.);
    return *newPtr;
}

void Complex::del(Numbers* obj)                                        // удаление объекта
{
    delete obj;
    obj = NULL;
    return;
}

//void Complex::grow(Complex* &arr, int size)       // увеличение массива указателей в два раза
//{
//    int newSize;                                    // новый размер массива
//    newSize = size*2;
//    Complex* newArr = new Complex[newSize];         // новый массив
//    for (int i = 0; i<newSize; i++)
//    {
//        if (i<size)                                 // значения элементов старого массива
//            newArr[i] = arr[i];                     // присваиваем элементам нового
//        else
//            newArr[i] = NULL;
//    }
//    delete[] arr;                                   // удалён старый массив
//    arr = newArr;                                   // и его указателю присвоен новый
//    size = newSize;
//    return;
//}

void Complex::show()                                              // вывод объекта
{
    cout<<*this<<endl;
    return;
}

double Complex::mod()                                                   // модуль |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // аргумент arg Z
{
    if (real>0) return atan(image/real);
    if (real<0)
    {
        if (image>0) return pi+atan(image/real);
        if (image<0) return -pi+atan(image/real);
        if (image==0) return pi;
    }
    if (real==0)
    {
        if (image>0) return pi/2;
        if (image<0) return -pi/2;
    }
    return 0;
}

ostream & operator << (ostream &out, Complex &obj)                              // cout<<
{
    out<<"Z = "<<obj.real<<" + "<<obj.image<<"i      ";
    return out;
}

istream & operator>>(istream &in, Complex &obj)                                 // cin>>
{
    cout<<"введите real =     \b\b\b\b";
    in>>obj.real;
    cout<<"введите image =     \b\b\b\b";
    in>>obj.image;
    return in;
}