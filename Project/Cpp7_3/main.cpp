// ������ - ���ڿ����� ����
// ����� ������ �ʴ� ���� ���մϴ�. ������� ���ͷ� ����� ��ȣ ����� �ֽ��ϴ�. ����� ������ �������� ����� ������� ���� �� ������, ������ ���� �� �ֽ��ϴ�
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    {
        // ���� �迭(���ڿ�)�� �����ͷ� ����Ŵ
        char str0[] = "abcd";
        char* str1 = str0;

        cout << str0 << endl;
        cout << str1 << endl;
    }
    {
        // ���ڿ� ���ͷ�
        const char* str2 = "hello";
        cout << "str2 " << str2 << endl;
        cout << "*str2 " << *str2 << endl;

        cout << typeid("hello").name() << endl;
    }
    {
        char str0[100] = "abcd";
        char* str1 = str0;
        const char* str2 = "hello";

        cout << strlen(str2) << endl;
        strcpy(str0, str2);
        cout << str0 << endl;

        cout << strcmp(str0, str2) << endl;
    }
}