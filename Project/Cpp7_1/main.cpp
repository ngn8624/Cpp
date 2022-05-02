//������
// "���Ծ���" �̶� ������ ���� �տ� ���̸� ���� �������� ���ϵ��� �ϸ�,�ش� ������ ����� ���

#include <iostream>
#include <numeric>

using namespace std;

union Union
{
    int i;
    float f;
    double d;
};

int main()
{
    {
        int num = 100;

        // ������ ����
        // ����ų Ÿ�Կ� *�߰�
        // &�����ڸ� ����Ͽ� num�� �ּҰ��� ����
        int* pointer = &num;


        cout << num << endl; // num ��
        cout << &num << endl; // num�� �ּҰ�
        cout << pointer << endl; // num�� �ּҰ��� pointer�� ������ �ִ�

        cout << *pointer << endl; // ������, dereference, num�� ����
        *pointer = 200;

        cout << num << endl;
        cout << *pointer << endl;
    }
    {
        int num = 123;
        int* pNum0 = &num;
        int* pNum1 = &num;
        int* pNum2 = pNum0;

        cout << &num << endl;
        cout << pNum0 << endl;
        cout << pNum1 << endl;
        cout << pNum2 << endl;
        cout << endl;
        
        cout << num << endl;    // 123
        cout << *pNum0 << endl; // 123
        cout << *pNum1 << endl; // 123
        cout << *pNum2 << endl; // 123
        cout << endl;
        
        num = 100;
        cout << num << endl;    // 100
        cout << *pNum0 << endl; // 100
        cout << *pNum1 << endl; // 100
        cout << *pNum2 << endl; // 100
        cout << endl;
    }
    {
        int* pNum = 0;
        cout << pNum << endl;
        //cout << *pNum << endl; // ���� ���� ���� �ൿ
    }
    {
        Union u;
        int* ip = (int*)&u;
        float* fp = (float*)&u;
        double* dp = (double*)&u;

        u.i = 1;

        cout << u.i << endl;
        cout << *ip << endl; // �޸𸮸� int�� �ؼ�

        cout << u.f << endl;
        cout << *fp << endl; // �޸𸮸� float�� �ؼ�

        cout << u.d << endl;
        cout << *dp << endl; // �޸𸮸� double�� �ؼ�
    }
    {
        // ������ ���� �� const�� ���� �տ� ��ġ�ϴ� ���
        int num0 = 10;
        const int* pNum = &num0;

        int num1 = 20;
        pNum = &num1; // ����

        //*pNum = 30; // �Ұ���, ����Ű�� �༮�� ������ �ٲ� �� ����
    }
    {
        // ������ ���� �� const�� ������ �ٷ� �տ� ��ġ�ϴ� ���
        int num0 = 10;
        int* const pNum = &num0;

        int num1 = 20;
        //pNum = &num1; // �Ұ���

        *pNum = 30; // ����
    }
    {
        int num0 = 10;
        const int* const pNum = &num0;

        int num1 = 20;
        //pNum = &num1; // �Ұ���
        //*pNum = 30; // �Ұ���
    }
}