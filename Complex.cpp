#include "comPlex.h"

Numbers** Complex::arrPtr;
int Complex::arrSize;
int Complex::counter;
const double Complex::pi = 3.14159265359;

Complex::Complex(): real(0.1), image(0.2)                                         // конструктор по умолчанию
{
    counter++;
}

Complex::Complex(double re, double im) : real(re), image(im)                     // конструктор с параметрами
{
    counter++;
}

Complex::Complex(const Complex &obj) : real(obj.real), image(obj.image)          // конструктор копирования
{
    counter++;
}

Complex::~Complex()                                                             // деструктор
{
    counter--;
}

int Complex::getCounter()                                                       // возврат счётчика
{
    return counter;
}

void Complex::createArr()
{
    arrPtr = new Numbers*[arrSize];
    for (int i = 0; i<arrSize; i++)
    {
        arrPtr[i] = NULL;
    }
    return;
}

Numbers** Complex::getArr()
{
    return arrPtr;
}

void Complex::setSize()
{
    cout<<"Введите размер массива: ";
    cin>>arrSize;
    return;
}

void Complex::reSize()
{
    int newSize;                                                // новый размер массива
    newSize = arrSize+2;
    Numbers** newArr;                                           // новый массив
    newArr = new Numbers*[newSize];
    for (int i = 0; i<newSize; i++)
    {
        if (i<arrSize)                                          // значения элементов старого массива
            newArr[i] = arrPtr[i];                              // присваиваем элементам нового
        else
            newArr[i] = NULL;
    }
    delete[] arrPtr;                                            // удалён старый массив
    arrPtr = newArr;                                            // и его указателю присвоен новый
    arrSize = newSize;
    return;
}

int Complex::getSize()
{
    return arrSize;
}

void Complex::add(int num)                                      // добавление объекта Complex
{
    arrPtr[num] = new Complex(1,1);
    return;
}

void Complex::edit()                                            // (virtual)
{
    cin>>*this;
    return;
}

void Complex::del(int num)                                      // удаление объекта
{
    if (arrPtr[num]!=NULL)
    {
        delete arrPtr[num];
        arrPtr[num] = NULL;
    }
    return;
}

void Complex::show()                                            // (virtual)
{
    cout<<*this;
    return;
}

void Complex::showAll()
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (arrPtr[i]!=NULL)                                    // если указатель не равен нулю
        {
            arrPtr[i]->show();                                  // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
    return;
}

double Complex::mod()                                           // Модуль |Z|
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                                   // àðãóìåíò arg Z
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
    return 0.;
}

ostream & operator << (ostream &out, Complex &obj)              // cout<<
{
    out<<"Z="<<obj.real<<"+"<<obj.image<<"*i"<<"\t"<<"|Z|="<<obj.mod()<<"\t";
    if (obj.arg()!=0)
        out<<"arg Z="<<obj.arg()*180/obj.pi<<"\t\n";
    else
        out<<"\t"<<"n/a"<<endl;
    return out;
}

istream & operator>>(istream &in, Complex &obj)                 // cin>>
{
    cout<<"введите real =     \b\b\b\b";
    in>>obj.real;
    cout<<"введите image =     \b\b\b\b";
    in>>obj.image;
    return in;
}
