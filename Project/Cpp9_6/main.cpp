// ����Ʈ �Ű�����

#include <iostream>

using namespace std;


int pow0(int base, int exp = 2)
{
    int result = 1;
    for (int i = 0; i < exp; ++i)
    {
        result *= base;
    }
    return result;
}


int pow1(int base = 2, int exp = 2)
{
    return pow0(base, exp);
}


int pow2(int base, int exp)
{
    return pow0(base, exp);
}

int pow2(int, int = 2);

int foo();

struct Person
{
    float weight;
    float height;
};


Person p{ 67.f, 175.f };

void goo(Person p0 = p)
{
    cout << p0.weight << endl;
    cout << p0.height << endl;
}

void hoo(Person p0 = Person{ 30.0f, 30.0f })
{
    goo(p0);
}


void print(Person* p0 = nullptr)
{
    if (p0)
    {
        cout << p0->weight << endl;
        cout << p0->height << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }
}

int main()
{
    cout << pow0(2, 10) << endl;
    cout << pow0(2) << endl;  // exp�� ����Ʈ �Ű�����

    cout << pow1() << endl; // base, exp �� �� ����Ʈ �Ű�����

    cout << pow2(2) << endl;  // �Լ� ������Ÿ�Կ� ���� ����Ʈ �Ű�����
    cout << foo() << endl; // �Լ� ������Ÿ�Կ� ���� ����Ʈ �Ű�����

    goo();
    goo(Person{ 74.f, 183.f });

    hoo();


    print();  // invalid 
    Person p{ 74.f, 183.f };
    print(&p);
}