//��� �Լ� ������
#include <iostream>
#include <functional>

using namespace std;


class Person
{
public:
    void print(int i)
    {
        cout << i << endl;
    }

    static void staticPrint(int i)
    {
        cout << i << endl;
    }
};

int main()
{
    void (Person:: * fn)(int) = &Person::print;

    Person person;
    (person.*fn)(1); // this�� �Ѱ���� ��

    typedef void (Person::* Func0)(int); // typedef �� ����Ͽ� ������ ǥ��
    Func0 fn0 = &Person::print;
    (person.*fn0)(2);

    using Func1 = void (Person::*)(int);
    Func1 fn1 = &Person::print;
    (person.*fn1)(3);

    function<void(Person*, int)> fn2 = &Person::print;
    fn2(&person, 4);


    // static�� �Ϲ� �Լ��� ����
    void (*fn3)(int) = &Person::staticPrint;
    fn3(5);
}