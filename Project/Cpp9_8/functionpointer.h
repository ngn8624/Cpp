#pragma once
#include <iostream>

using namespace std;


int sum(int x, int y)
{
    return x + y;
}


void functionPointer()
{
    // int sum(int x, int y) �� ����ų �� �ִ� �Լ� ������
    int (*f0)(int, int) = &sum; // �Լ��� �ּ�
    int (*f1)(int, int) = sum;  // �Լ��� �̸������� �ּҷ� �� �Ǵ� ���� ���


    cout << "(*f0)(1, 2)" << (*f0)(1, 2) << endl;
    cout << "f0(1, 2)" << f0(1, 2) << endl;  // ������ ���� ���

    int(&f2)(int, int) = sum; // �Լ� ����
    //int (&f3)(int, int) = &sum; // �� ��

    cout << "f2(1, 2)" << f2(1, 2) << endl;
    cout << "(*f2)(1, 2)" << (*f2)(1, 2) << endl; // ���
    cout << "(*sum)(1, 2)" << (*sum)(1, 2) << endl; // ���, �Լ� �ּҰ� �ʿ��� �������� �Ͻ������� �Լ� �ּҷ� ����
}

