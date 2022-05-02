// ���� ����, ���� ����

#include <iostream>
#include "Animal.h"

using namespace std;


class A
{
public:
    int num;
};


class B : public A
{

};


A operator+(const A& x, const A& y)
{
    A a;
    a.num = x.num + y.num;
    return a;
}

B operator+(const B& x, const B& y)
{
    B b;
    b.num = x.num * y.num;
    return b;
}


void func(int x) // ������ �� �Լ� �̸��� ���� name mangling, ���� ����
{
}

void func(int x, int y) // ������ �� �Լ� �̸��� ���� name mangling, ���� ����
{
}


void foo(Animal* animal)
{
    animal->eat(); // ���� ����, �������̵�, ���� ���� �� animal�� ���� Ÿ���� �� �� �ְ� �׿� �´� eat�� ȣ�����ش�
    animal->walk(); // ���� ����, ������ Ÿ�ӿ� �� �� �ִ� 'Animal' �� ���� �׻� �ѹ� 
}



int main()
{
    // ���� ����, static binding
    // ������ �ð��� ����
    // ����) �����ε�

    // ���� ����, dynamic binding
    // ��Ÿ�ӿ� ����
    // ����) �������̵�
    
    B b0, b1;
    b0.num = 10;
    b1.num = 20;

    A& a0 = b0;
    A& a1 = b1;

    // �����δ� a0, a1 �� �� B class������ �ڷ����� A�̱� ������ A+A�� ���ε� �ȴ�. �����ε��� ���� ����
    // ���� a0, a1�� ����Ű�� Ÿ���� ��Ÿ�ӿ� �� �� �ִ�.
    A a2 = a0 + a1; 
    cout << a2.num << endl; // 30

    Animal* animal = new Dog;
    foo(animal);


    class A { int a; };
    class B { int a; virtual ~B() {} };

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl; // virtual �Լ��� �� ���� ������ ����� �þ��. �����Լ� ���̺��� ����Ű�� ������ �߰�
    // �θ� �ڽ� ���踦 �̿��� �������� �̿��ϴ� ���(Parent *p = new Child)
    // virtual �Լ����� ���� �Լ� ���̺� ��ϵǰ� ���� �� ������ Ÿ���� ���� �Լ��� �������� �ʰ�
    // ���� �Լ� ���̺� �ִ� �Լ��� �����Ѵ�.
}