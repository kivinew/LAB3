/* Динамический полиморфизм.*/

#include "Complex.h"
#include <locale>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

int menu();
void createTable(Numbers** &);
void showTable(Numbers** &);
void deleteAll(Numbers** &);

Numbers** arrPtr = Complex::getArr();
int arrSize = Complex::getSize();

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");

    system("cls");
    while (menu()==TRUE);
    return 0;
}

int menu()                                 // вывод таблицы объектов и меню
{
    int countObjects = Complex::getCounter();
    system("cls");
    Complex::setSize();
    createTable(arrPtr);
    showTable(arrPtr);

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
        break;
    }
    case ENTER:                                                         // --------выбрать один элемент---------
    {
        int number;
        cout<<"Укажите номер строки: ";
        cin>>number;
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ввести данные комплексного числа"<<endl;
            if (arrPtr[number]!=NULL)
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
                if (arrPtr[number]!=NULL)                           // если указатель не равер нулю
                    arrPtr[number]->edit();                        // то его можно изменить,
                else                                                    //
                    Complex::add();                                     // а иначе создать
                break;
            case DEL:                                                   // --------удаление указателя на объект---------
                Complex::del(number);
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
        deleteAll(arrPtr);
        return FALSE;
        break;
    }
    return TRUE;
}

void createTable()
{
    for (int i = 0; i<arrSize; i++)
        arrPtr[i] = Complex::add();
    return;
}

void showTable()                            // вывод таблицы объектов
{
    cout<<"Объект :\t"<<"Модуль :\t"<<"Аргумент :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (arrPtr[i]!=NULL)                // если указатель не равен нулю
        {
            arrPtr[i]->show();              // то выводим объект
        }
        else
            cout<<"empty"<<endl;
    }
    return;
}

void deleteAll(Numbers** &arrPtr)              // удаление массива
{
    for (int i = 0; i<Complex::getSize(); i++)
    {
        Complex::del(i);                                        // удаление объектов массива
    }
    delete[] arrPtr;                                       // удаление массива
    cout<<"Массив удалён"<<endl;
    return;
}
