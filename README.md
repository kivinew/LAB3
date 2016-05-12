# LAB3
Лабораторная работа № 3. Динамический полиморфизм.

Часть 1. Разработка абстрактного класса.

Согласно варианту задания, разработайте структуру абстрактного класса, который объявляет собой минимально необходимый интерфейс. Например, для класса «матрица» - мы получим класс абстрактной матрицы, который даже может не инкапсулировать никаких данных.
Минимальный интерфейс включает в себя: функции ввода и вывода.

Например:

class AbstractTime
{
public:
	virtual void Edit()    = 0;
	virtual void Show()    = 0;
};

Часть 2. Разработайте производный класс (согласно варианту задания по работам №1, №2), осуществив его наследование от разработанного абстрактного класса, с реализацией всех чисто виртуальных функций.

Например, это класс времени:

class Time :  public AbstractTime

…….

Этот класс будет основным, в его реализации можно использовать разработку по предыдущим лабораторным работам. Методы, добавленные в работе №2 (перегружающие операторы), включать в данный класс не нужно. Разработку класса можно разбить на два этапа. 

На первом, класс должен включить в себя:

1)	Поля-данные, для хранения значений (Hour, Min, Sec).

2)	Реализации виртуальных функций ввода и вывода.

На втором этапе мы реализуем механизм хранения. Добавляем в класс:

1)	Static ДИНАМИЧЕСКИЙ массив указателей на объекты БАЗОВОГО (абстрактного) класса.

2)	Статические переменные для хранения размера массива и числа заполненных ячеек.

3)	Статические функции:

         -добавления указателя (типа Abstract) на объект данного класса.
         
         -удаление элемента с заданным номером
         
         -обход всего массива с вызовом функции Show().

Часть 3. Разработка пользовательского интерфейса.

Идея построения – цикл меню, аналогично работе №1, здесь достаточно представить следующие возможности:

-создание нового объекта (и автоматическое добавление его в массив)

-ввод новых значений для объекта с заданным номером

-удаление по логическому номеру

-просмотр всего массива

ПРИМЕЧАНИЕ: для этих операций используются разработанные static методы.

