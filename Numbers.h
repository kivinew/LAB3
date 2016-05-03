// абстрактный класс
class Numbers
{

public:
    virtual ~Numbers() 
    {
        cout<<"Numbers destructor!"<<endl;
        _getch();
    };
    virtual void edit() = 0;
    virtual void show() = 0;
};
