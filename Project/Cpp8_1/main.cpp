//����

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    {
        int num0 = 10;
        int& num1 = num0;  // ���� // c++ 
        int* num2 = &num0; // ������

        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        num0 = 20;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        num1 = 30;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        *num2 = 40;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;
    }
    {
        int num0 = 10;
        // �ʱ�ȭ �� �� ����Ű�� �༮�� ���� ��, �ٲ� �� ����
        int& num1 = num0;
 
        

        int num2 = 20;

        // num2�� ���� ������, num2�� ����Ű�� �� �� ����.
        num1 = num2;
    }
    {
        vector<int> vec0;
        vector<int>& vec1 = vec0;  // ����
        vector<int>* vec2 = &vec0; // ����
    }
    {
        int* num0 = new int(12);
        int& num1 = *num0;

        cout << num0 << endl;
        cout << num1 << endl;

        delete num0;

        // ������ ���۷��� ��� �� ����
        //cout << num1 << endl;
    }
    {
        int num0 = 10;
        int& num1 = num0;
        int* const num2 = &num0; // �̷��� �ϸ� ������ �������

        int num3 = 20;

        // ����ó�� �ʱ�ȭ ���� ����Ű�� �༮�� �ٲ� �� ���� �ȴ�
        //num2 = &num3;
    }

}