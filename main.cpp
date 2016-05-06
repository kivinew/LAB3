/* ������������ �����������.*/

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

int menu()                                 // ����� ������� �������� � ����
{
    int countObjects = Complex::getCounter();
    system("cls");
    Complex::setSize();
    createTable(arrPtr);
    showTable(arrPtr);

    cout<<"\t1        - ������� ������� ������� � ������ ������"<<endl                     // ����
        <<"\tENTER    - ������� ������� �������"<<endl
        <<"\tESC      - ����� �� ���������"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
    case ONE:                                                           // ---------�������� ������---------
    {
        break;
    }
    case ENTER:                                                         // --------������� ���� �������---------
    {
        int number;
        cout<<"������� ����� ������: ";
        cin>>number;
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ������ ������ ������������ �����"<<endl;
            if (arrPtr[number]!=NULL)
            {
                cout<<"DELETE   - ������� ����������� �����"<<endl
                    <<"SPACEBAR - ����������� ����������� �����"<<endl;
            }
            cout<<"��� ������ ������� ����� ������ �������"<<endl;
            while (!_kbhit());                                                  // �������� ������ �������
            choice = _getch();                                                  // ���������� ������!!!  1) �������� ������
            if (choice>83) choice = _getch();                                   //                       2) �������� ��� �������
            switch (choice)
            {
            case ENTER:                                                 // ------�������� ������-------
                if (arrPtr[number]!=NULL)                           // ���� ��������� �� ����� ����
                    arrPtr[number]->edit();                        // �� ��� ����� ��������,
                else                                                    //
                    Complex::add();                                     // � ����� �������
                break;
            case DEL:                                                   // --------�������� ��������� �� ������---------
                Complex::del(number);
                break;
            }
        }
        else
        {
            cout<<"����� �� ������� �������!";
            _getch();
        }
        break;
    }
    case ESC:                                                               // ---------����� �� ���������---------
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

void showTable()                            // ����� ������� ��������
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (arrPtr[i]!=NULL)                // ���� ��������� �� ����� ����
        {
            arrPtr[i]->show();              // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
    return;
}

void deleteAll(Numbers** &arrPtr)              // �������� �������
{
    for (int i = 0; i<Complex::getSize(); i++)
    {
        Complex::del(i);                                        // �������� �������� �������
    }
    delete[] arrPtr;                                       // �������� �������
    cout<<"������ �����"<<endl;
    return;
}
