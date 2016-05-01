/* Динамический полиморфизм.
Объект класса хранит действительную ( REAL a ) и мнимую ( IMAGE b*i ) часть
комплексного числа z = a + b*i.
*/

#include "Complex.h"
#include <locale>
#include <Windows.h>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

int menu(Numbers** &, int &);
void createCopy(Numbers** &, int &, int);
void showTable(Numbers** &, int);
void deleteAll(Numbers** &, int);

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");

    Complex::setSize();    
    system("cls");
    while (menu(Complex::getArray(), Complex::getSize())==TRUE);
    return 0;
}

int menu(Numbers** &objectArray, int &size)                                 // вывод таблицы объектов и меню
{
    system("cls");

    showTable(objectArray, size);

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
        Complex::createObj(objectArray, size);
        break;
    }
    case ENTER:                                                         // --------выбрать один элемент---------
    {
        int number;
        cout<<"Укажите номер строки: ";
        cin>>number;
        int countObjects = Complex::getCounter();                       // количество объектов в массиве
        if (!(number>=size)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ввести данные комплексного числа"<<endl;
            if (objectArray[number]!=NULL)
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
                if (objectArray[number]!=NULL)                          // если указатель не равер нулю
                    objectArray[number]->edit();                        // то его можно изменить,
                else                                                    //
                    Complex::createObj(objectArray, size, number);      // а иначе создать
                break;
            case DEL:                                                   // --------удаление указателя на объект---------
                Complex::del(objectArray[number]);
                break;
            case SPACEBAR:                                              // --------настроить конструктор копирования---------
                if (objectArray[number]!=NULL)
                    createCopy(objectArray, size, number);
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
        deleteAll(objectArray, size);
        return FALSE;
        break;
    }
    return TRUE;
}

void createCopy(Numbers** &arr, int &size, int elementToCopy)               // скопировать объект
{
    if (Complex::getCounter()==size)                                        // если количество объектов равно размеру массива
        Complex::grow(arr, size);                                           // то его нужно увеличить
    for (int i = 0; i<size; i++)
    {
        if (arr[i]==NULL)                          	                        // если указатель нулевой, то
        {                                                                   // 
            arr[i] = new Complex(*arr[elementToCopy]);                    	// создать в этой ячейке объект
            return;
        }
    }
    return;
}

void showTable(Numbers** &arr, int size)                                    // вывод таблицы объектов
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // если указатель не равен нулю
        {
            (*arr[i]).showObject();                                         // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Numbers** &arr, int size)                // удаление массива
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                           // удаление объектов массива
    }
    delete[] arr;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    _getch();
    return;
}
