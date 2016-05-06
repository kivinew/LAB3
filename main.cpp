/* ������������ �����������.*/

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

Numbers* objectArray;                                      // ������ ���������� �������� ����
int arrSize;                                                // ������ �������

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleTitleA("Complex numbers. LAB3");

    objectArray = Complex::getArray();                      // ������ �� ������ ������
    Complex::setSize();
    arrSize = Complex::getSize();                           // � ��� ������
    system("cls");
    while (menu()==TRUE);
    return 0;
}

int menu()                                 // ����� ������� �������� � ����
{
    system("cls");

    createTable(objectArray, arrSize);
    showTable(objectArray, arrSize);
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
        Complex::createObj(objectArray, arrSize);
        break;
    }
    case ENTER:                                                         // --------������� ���� �������---------
    {
        int number;
        cout<<"������� ����� ������: ";
        cin>>number;
        int countObjects = Complex::getCounter();                       // ���������� �������� � �������
        if (!(number>=arrSize)&&!(number<0))
        {
            cout<<endl<<"ENTER    - ������ ������ ������������ �����"<<endl;
            if (objectArray+number!=NULL)
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
                if (objectArray+number!=NULL)                          // ���� ��������� �� ����� ����
                    objectArray[number].edit();                        // �� ��� ����� ��������,
                else                                                    //
                    Complex::createObj(objectArray, arrSize, number);      // � ����� �������
                break;
            case DEL:                                                   // --------�������� ��������� �� ������---------
                Complex::del(&objectArray[number]);
                break;
            case SPACEBAR:                                              // --------��������� ����������� �����������---------
                if (objectArray+number!=NULL)
                    createCopy(objectArray, arrSize, number);
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

void createCopy(Numbers* &objectArray, int &arrSize, int elementToCopy)               // ����������� ������
{
    if (Complex::getCounter()==arrSize)                                        // ���� ���������� �������� ����� ������� �������
        //Complex::grow(objectArray, arrSize);                                           // �� ��� ����� ���������
    for (int i = 0; i<arrSize; i++)
    {
        if (objectArray+i==NULL)                          	                        // ���� ��������� �������, ��
        {                                                                   // 
            //Complex obj = objectArray[elementToCopy];
            //*objectArray[i] = new Complex(obj);                    	// ������� � ���� ������ ������
            return;                                                         // ��� �����
        }
    }
    return;
}

void showTable(Numbers* &objectArray, int arrSize)                                    // ����� ������� ��������
{
    cout<<"������ :\t"<<"������ :\t"<<"�������� :\t"<<endl;
    for (int i = 0; i<arrSize; i++)
    {
        cout<<i<<": ";
        if (objectArray+i != NULL)                                                   // ���� ��������� �� ����� ����
        {
            (objectArray+i)->show();                                         // �� ������� ������
        }
        else
            cout<<"empty"<<endl;
    }
}

void deleteAll(Numbers* &objectArray, int arrSize)                // �������� �������
{
    for (int i = 0; i<arrSize; i++)
    {
        Complex::del(objectArray+i);                           // �������� �������� �������
    }
    delete[] objectArray;                                       // �������� �������
    cout<<"������ �����"<<endl;
    //_getch();
    return;
}
