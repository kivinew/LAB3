/* Динамический полиморфизм.*/

#include "Complex.h"
#include <locale>
#include <Windows.h>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

int menu();
void createTable(Numbers* &, int &);
void createCopy(Numbers* &, int &, int);
void showTable(Numbers* &, int);
void deleteAll(Numbers* &, int);

Numbers* objectArray;                                      // массив указателей базового типа
int arrSize;                                                // размер массива

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");

    objectArray = Complex::getArray();                      // достаём из класса массив
    Complex::setSize();
    arrSize = Complex::getSize();                           // и его размер
    system("cls");
    while (menu()==TRUE);
    return 0;
}

int menu()                                 // вывод таблицы объектов и меню
{
    system("cls");

    createTable(objectArray, arrSize);
    showTable(objectArray, arrSize);
    cout<<"\t1        - быстрая вставка объекта в пустую строку"<<endl                     // меню
        <<"\tENTER    - выбрать элемент таблицы"<<endl
        <<"\tESC      - выход из программы"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
    case ONE:                                                           // ---------вставить объект---------
    {
        Complex::createObj(objectArray, arrSize);
        break;
    }
    case ENTER:                                                         // --------выбрать один элемент---------
    {
        int number;
        cout<<"Укажите номер строки: ";
        cin>>number;
        int countObjects = Complex::getCounter();                       // количество объектов в массиве
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ввести данные комплексного числа"<<endl;
            if (objectArray+number!=NULL)
            {
                cout<<"DELETE   - удалить комплексное число"<<endl
                    <<"SPACEBAR - скопировать комплексное число"<<endl;
            }
            cout<<"Для отмены нажмите любую другую клавишу"<<endl;
            while (!_kbhit());                                                  // ожидание выбора клавиши
            choice = _getch();                                                  // вызывается дважды!!!  1) получаем символ
            if (choice>83) choice = _getch();                                   //                       2) получаем код символа
            switch (choice)
            {
            case ENTER:                                                 // ------изменить объект-------
                if (objectArray+number!=NULL)                          // если указатель не равер нулю
                    objectArray[number].edit();                        // то его можно изменить,
                else                                                    //
                    Complex::createObj(objectArray, arrSize, number);      // а иначе создать
                break;
            case DEL:                                                   // --------удаление указателя на объект---------
                Complex::del(&objectArray[number]);
                break;
            case SPACEBAR:                                              // --------настроить конструктор копирования---------
                if (objectArray+number!=NULL)
                    createCopy(objectArray, arrSize, number);
                break;
            }
        }
        else
        {
            cout<<"Выход за пределы массива!";
            _getch();
        }
        break;
    }
    case ESC:                                                               // ---------выход из программы---------
        deleteAll(objectArray, arrSize);
        return FALSE;
        break;
    }
    return TRUE;
}

void createTable(Numbers *&objectArray, int &arrSize)
{
    for (int i = 0; i<arrSize; i++)
        objectArray[i] = Complex::add();
}

void createCopy(Numbers* &objectArray, int &arrSize, int elementToCopy)               // скопировать объект
{
    if (Complex::getCounter()==arrSize)                                        // если количество объектов равно размеру массива
        //Complex::grow(objectArray, arrSize);                                           // то его нужно увеличить
    for (int i = 0; i<arrSize; i++)
    {
        if (objectArray+i==NULL)                          	                        // если указатель нулевой, то
        {                                                                   // 
            //Complex obj = objectArray[elementToCopy];
            //*objectArray[i] = new Complex(obj);                    	// создать в этой ячейке объект
            return;                                                         // как копию
        }
    }
    return;
}

void showTable(Numbers* &objectArray, int arrSize)                                    // вывод таблицы объектов
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (objectArray+i != NULL)                                                   // если указатель не равен нулю
        {
            (objectArray+i)->show();                                         // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Numbers* &objectArray, int arrSize)                // удаление массива
{
    for (int i = 0; i<arrSize; i++)
    {
        Complex::del(objectArray+i);                           // удаление объектов массива
    }
    delete[] objectArray;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    //_getch();
    return;
}
