//����� �⺻ ����

#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base" << endl;
    }

    Base(int num) : num(num)
    {
        cout << "Base(" << num << ")" << endl;
    }

    virtual ~Base() // �θ� Ŭ������ �� ���ɼ��� �ִ� �༮���� �Ҹ��ڴ� virtual�� �߰����ش�
    {
        cout << "~Base" << endl;
    }

    int num;

    void func()
    {
        cout << num << endl;
    }

private:
    int priNum;

protected:
    int proNum;
};


class Derived : public Base
{
public:
    // �����ڸ� ����ϰ� ���� ��� using�� �̿��Ѵ�.
    //using Base::Base;

    Derived() // �θ� �����ڸ� �������� ������ �θ��� ����Ʈ �����ڸ� �������ش�.
    {
        cout << "Derived" << endl;
    }

    Derived(int num) : Base(num) // �ڽ� �����ڿ��� � �θ� �����ڸ� ȣ������ �������ش�
    {
        cout << "Derived(" << num << ")" << endl;
    }

    ~Derived()
    {
        cout << "~Derieved" << endl;
    }

    void foo()
    {
        // �θ��� ����� ����
        func();
        this->func();

        num += 20;
        func();

        //this->priNum = 20; private ���� �θ𿡼� ���� �Ʊ� ������ ���� �Ұ�, �޸𸮿��� ����
        this->proNum = 30; // protected�� �ڽĿ��� ���� ��
    }

    void func1()
    {

    }
};


void func(Base& b)
{

}


int main()
{
    Base b;
    b.num = 10;
    b.func();

    Derived d; // �θ��� �����ڰ� ���� ȣ�� �ȴ�. 
    d.num = 20;  // �θ��� num
    d.func(); // �θ��� func
    d.foo();

    //d.priNum = 20; // private���� �θ𿡼� ���� �Ǿ ����� �� ����
    //d.proNum = 30; // protected�� �θ𿡼� ���� �Ǿ ����� �� ����

    // �θ� Ŭ������ �ڽ� Ŭ������ ����ų �� �ִ�
    Base* base = new Derived;

    // �ڽ� �ı��ڰ� ���� ȣ��ȴ�.
    delete base;

    // �θ� �ڽ��� ����ų �� �ֱ� ������ �θ� Ŭ������ Ÿ������ ������ �Ķ���Ϳ� �ڽ� ��ü�� �Ѱ��� �� �ִ�
    func(d);

    

}