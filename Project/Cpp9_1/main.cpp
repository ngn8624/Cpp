//�Լ��� �⺻

#include <iostream>

using namespace std;

// ����� ������Ÿ�� ����
int csum(int x, int y);
int cabs0(int x);
int cabs1(int x);


int abssum(int x, int y)
{
    // cabs0, cabs1, csum�� ���� ������ �ʿ��ϴ�.
    // abssum ���忡���� cabs0, cabs1, csum
    int ax = cabs0(x);
    int ay = cabs1(y);
    return csum(ax, ay);
}

int csum(int x, int y)
{
    return x + y;
}

int cabs0(int x)
{
    return x >= 0 ? x : -x;
}

int cabs1(int x)
{
    if (x >= 0)
        return x;
    else
        return -x;
}

void print0(int x, int y)
{
    cout << x << endl;
    if (y < 0)
        return; // �Լ� ���� �� return�� ����� �� �ִ�

    cout << y << endl;
}

void print1(void) // ���ڰ� ���� ��� void�� ������ �� �ִ�
{
    cout << "Hello World" << endl;
}

int main(int argc, char* arvc[])
{
    {
        // main �Լ��� ��ȯ
        // 0 : ���� ����
        // 0�� �ƴ� : ������ ����
        //return 0;
    }
    {
        // ���� �� �Ѱ��� ���� ���
        // 0������ ������ ���ϸ� ���
        for (int i = 0; i < argc; ++i)
        {
            cout << arvc[i] << endl;
        }
    }
    {
        // ����� ���� �Լ� ���
        cout << csum(5, 10) << endl;
        cout << cabs0(10) << endl;
        cout << cabs1(-10) << endl;
    }
}
