// абстрактный класс
class Numbers
{

public:
    virtual ~Numbers() {};
    virtual void edit() = 0;
    virtual void showObject() = 0;
};
