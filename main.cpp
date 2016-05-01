/* ������������ �����������.
������ ������ ������ �������������� ( REAL a ) � ������ ( IMAGE b*i ) �����
������������ ����� z = a + b*i.
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

int menu(Numbers** &objectArray, int &size)                                 // ����� ������� �������� � ����
{
    system("cls");

    showTable(objectArray, size);

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
        Complex::createObj(objectArray, size);
        break;
    }
    case ENTER:                                                         // --------������� ���� �������---------
    {
        int number;
        cout<<"������� ����� ������: ";
        cin>>number;
        int countObjects = Complex::getCounter();                       // ���������� �������� � �������
        if (!(number>=size)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ������ ������ ������������ �����"<<endl;
            if (objectArray[number]!=NULL)
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
                if (objectArray[number]!=NULL)                          // ���� ��������� �� ����� ����
                    objectArray[number]->edit();                        // �� ��� ����� ��������,
                else                                                    //
                    Complex::createObj(objectArray, size, number);      // � ����� �������
                break;
            case DEL:                                                   // --------�������� ��������� �� ������---------
                Complex::del(objectArray[number]);
                break;
            case SPACEBAR:                                              // --------��������� ����������� �����������---------
                if (objectArray[number]!=NULL)
                    createCopy(objectArray, size, number);
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
        deleteAll(objectArray, size);
        return FALSE;
        break;
    }
    return TRUE;
}

void createCopy(Numbers** &arr, int &size, int elementToCopy)               // ����������� ������
{
    if (Complex::getCounter()==size)                                        // ���� ���������� �������� ����� ������� �������
        Complex::grow(arr, size);                                           // �� ��� ����� ���������
    for (int i = 0; i<size; i++)
    {
        if (arr[i]==NULL)                          	                        // ���� ��������� �������, ��
        {                                                                   // 
            arr[i] = new Complex(*arr[elementToCopy]);                    	// ������� � ���� ������ ������
            return;
        }
    }
    return;
}

void showTable(Numbers** &arr, int size)                                    // ����� ������� ��������
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<size; i++)
    {
        cout<<i<<": ";
        if (arr[i]!=NULL)                                                   // ���� ��������� �� ����� ����
        {
            (*arr[i]).showObject();                                         // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Numbers** &arr, int size)                // �������� �������
{
    for (int i = 0; i<size; i++)
    {
        Complex::del(arr[i]);                           // �������� �������� �������
    }
    delete[] arr;                                       // �������� �������
    cout<<"������ �����"<<endl;
    _getch();
    return;
}
