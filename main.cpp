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
void showTable();
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
    showTable();
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
                if (arrayPtr[number]!=NULL)       // ���� ��������� �� ����� ����
                    arrayPtr[number]->edit();     // �� ��� ����� ��������,
                else                            //
                    Complex::add();             // � ����� �������
                break;
            case DEL:                           // --------�������� ��������� �� ������---------
                Complex::del(number);
                break;
            }
        }
        else
        {
            cout<<"����� �� ������� �������!";
            cout<<"arrSize="<<arrSize;
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

void showTable()                                // ����� ������� ��������
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (arrayPtr[i]!=NULL)                    // ���� ��������� �� ����� ����
        {
            ((Complex*)arrayPtr[i])->show(); 
            
            //arrayPtr[i]->show();                  // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
    return;
}

void deleteAll()                                // �������� �������
{
    for (int i = 0; i<Complex::getSize(); i++)
    {
        Complex::del(i);                        // �������� �������� �������
    }
    delete[] arrayPtr;                              // �������� �������
    cout<<"������ �����"<<endl;
    return;
}
