// ��ȯ ������ �����ε�, ��ȯ ������

#include <iostream>
#include "BadPerson.h"
#include "GoodPerson.h"

using namespace std;



int func(int x)
{
    return x; // ����
}

int main()
{
    int a = 1;
    int b = a; // ���� ������
    a = b;  // ���� ������

    func(a); // ����


    //BadPerson badPerson0{ 46.f, 153.f, "David Daehee Kim" };
    //BadPerson badPerson1 = badPerson0;
    //BadPerson badPerson2;
    //badPerson2 = badPerson0;

    //badPerson0.print();
    //badPerson1.print();
    //badPerson2.print();

    GoodPerson goodPerson0 = { 46.f, 153.f, "David Daehee Kim" };
    GoodPerson goodPerson1 = goodPerson0;
    GoodPerson goodPerson2;
    goodPerson2 = goodPerson0;

    goodPerson0.print();
    goodPerson1.print();
    goodPerson2.print();


}