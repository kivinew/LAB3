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

Numbers** arrPointer;                             //                                 массив
int arrSize;                                    //                           и его размер

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");
    system("cls");

    Complex::setSize();
    Complex::createArr();
    while (menu()==TRUE);
    return 0;
}

int menu()                                      //         вывод таблицы объектов и меню
{
    arrPointer = Complex::getArr();
    arrSize = Complex::getSize();
    int countObjects = Complex::getCounter();
    system("cls");
    Complex::showTable();
    cout<<"\t1          быстрая вставка объекта в пустую строку"<<endl
        <<"\tENTER      выбор элемента"<<endl
        <<"\tESC        выход из программы"<<endl;
    while (!_kbhit());                          //               ожидание выбора клавиши
    int choice;
    choice = _getch();
    switch (choice)
    {
    case ONE:                                   //                       быстрая вставка
    {
        for (int i = 0; i<arrSize; i++)
        {
            if (arrPointer[i]==NULL)
            {
                Complex::add(i);                //                       добавить объект
                return TRUE;
            }
        }
        break;
    }
    case ENTER:                                 //                  выбрать один элемент
    {
        int number;
        cout<<"Укажите номер строки: ";
        cin>>number;
        if (!(number>=arrSize)&&!(number<0))    //  проверка на выход за пределы массива
        {
            cout<<endl<<"ENTER      ввести данные комплексного числа"<<endl;
            if (arrPointer[number]!=NULL)
                cout<<"DELETE     удалить комплексное число"<<endl;
            cout<<"Для отмены нажмите любую другую клавишу"<<endl;
            while (!_kbhit());                  //               ожидание выбора клавиши
            choice = _getch();                  // getch()x2 !!! 1) получаем символ
            if (choice>83) choice = _getch();   //               2) получаем код символа
            switch (choice)
            {
            case ENTER:                         //                       изменить объект
                if (arrPointer[number]!=NULL)   //          если указатель не равер нулю
                    arrPointer[number]->edit(); //                то его можно изменить,
                else                            // 
                    Complex::add(number);       //                       а иначе создать
                break;
            case DEL:                           //          удаление указателя на объект
                Complex::del(number);           //           без проверки на его наличие
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
    case ESC:                                   //                    выход из программы
        deleteAll();                            //             с удалением всего массива
        return FALSE;
        break;
    }
    return TRUE;
}

void deleteAll()                                //                      удаление массива
{
    int size = Complex::getSize();
    for (int i = 0; i<size; i++)
    {
        Complex::del(i);                        //             удаление объектов массива
    }
    delete[] arrPointer;                          //                    удаление массива
    cout<<"Массив удалён"<<endl;
    return;
}
