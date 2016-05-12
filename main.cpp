/* ������������ ����������� */

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

Numbers** arrayPtr;                  // ^^^^^^^^^^^^^ ������
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

int menu()                                      // ����� ������� �������� � ����
{
    int countObjects = Complex::getCounter();
    system("cls");
    Complex::showAll();
    cout<<"\tENTER    - ����� ��������"
        <<"\tESC      - ����� �� ���������"<<endl;
    while (!_kbhit());
    int choice;
    choice = _getch();
    switch (choice)
    {
    case ONE:                                   // ---------�������� ������---------
    {
        break;
    }
    case ENTER:                                 // --------������� ���� �������---------
    {
        int number;
        cout<<"������� ����� ������: ";
        cin>>number;
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ������ ������ ������������ �����"<<endl;
            if (arrayPtr[number]!=NULL)
            {
                cout<<"DELETE   - ������� ����������� �����"<<endl
                    <<"SPACEBAR - ����������� ����������� �����"<<endl;
            }
            cout<<"��� ������ ������� ����� ������ �������"<<endl;
            while (!_kbhit());                  // �������� ������ �������
            choice = _getch();                  // ���������� ������!!!  1) �������� ������
            if (choice>83) choice = _getch();   //                       2) �������� ��� �������
            switch (choice)
            {
            case ENTER:                         // ------�������� ������-------
                if (arrayPtr[number]!=NULL)     // ���� ��������� �� ����� ����
                    arrayPtr[number]->edit();   // �� ��� ����� ��������,
                else                            // 
                    Complex::add(number);       // � ����� �������
                break;
            case DEL:                           // --------�������� ��������� �� ������---------
                Complex::del(number);
                break;
            }
        }
        else
        {
            cout<<"����� �� ������� �������!\n";
            _getch();
        }
        break;
    }
    case ESC:                                   // ---------����� �� ���������---------
        deleteAll();
        return FALSE;
        break;
    }
    return TRUE;
}

void deleteAll()                                // �������� �������
{
    int size = Complex::getSize();
    for (int i = 0; i<size; i++)
    {
        Complex::del(i);                        // �������� �������� �������
    }
    delete[] arrayPtr;                          // �������� �������
    cout<<"������ �����"<<endl;
    return;
}
