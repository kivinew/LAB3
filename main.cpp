/* Динамический полиморфизм */

#include "Complex.h"
#include <locale>
#define ESC         27
#define SPACEBAR    32
#define ONE         49
#define TWO         50
#define ENTER       13
#define DEL         83 

int menu();
void deleteAll();

Numbers** arrayPtr;                  // ^^^^^^^^^^^^^ массив
int arrSize;

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");

    system("cls");

    Complex::setSize();
    Complex::createArr();
    arrayPtr = Complex::getArr();
    arrSize = Complex::getSize();
    while (menu()==TRUE);
    return 0;
}

int menu()                                      // вывод таблицы объектов и меню
{
    int countObjects = Complex::getCounter();
    system("cls");
    Complex::showAll();
    cout<<"\tENTER    - выбор элемента"
        <<"\tESC      - выход из программы"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
    case ONE:                                   // ---------вставить объект---------
    {
        break;
    }
    case ENTER:                                 // --------выбрать один элемент---------
    {
        int number;
        cout<<"Укажите номер строки: ";
        cin>>number;
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ввести данные комплексного числа"<<endl;
            if (arrayPtr[number]!=NULL)
            {
                cout<<"DELETE   - удалить комплексное число"<<endl
                    <<"SPACEBAR - скопировать комплексное число"<<endl;
            }
            cout<<"Для отмены нажмите любую другую клавишу"<<endl;
            while (!_kbhit());                  // ожидание выбора клавиши
            choice = _getch();                  // вызывается дважды!!!  1) получаем символ
            if (choice>83) choice = _getch();   //                       2) получаем код символа
            switch (choice)
            {
            case ENTER:                         // ------изменить объект-------
                if (arrayPtr[number]!=NULL)     // если указатель не равер нулю
                    arrayPtr[number]->edit();   // то его можно изменить,
                else                            // 
                    Complex::add(number);       // а иначе создать
                break;
            case DEL:                           // --------удаление указателя на объект---------
                Complex::del(number);
                break;
            }
        }
        else
        {
            cout<<"Выход за пределы массива!\n";
            _getch();
        }
        break;
    }
    case ESC:                                   // ---------выход из программы---------
        deleteAll();
        return FALSE;
        break;
    }
    return TRUE;
}

void deleteAll()                                // удаление массива
{
    int size = Complex::getSize();
    for (int i = 0; i<size; i++)
    {
        Complex::del(i);                        // удаление объектов массива
    }
    delete[] arrayPtr;                          // удаление массива
    cout<<"Массив удалён"<<endl;
    return;
}
