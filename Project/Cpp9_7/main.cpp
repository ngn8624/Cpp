// �Լ� �����ε�
#include <iostream>
#include <string>

using namespace std;

int countDigit(int num)
{
    if (num == 0)
        return 1;

    int count = 0;
    while (num)
    {
        num /= 10;
        ++count;
    }
    return count;
}


int countDigit(string num)
{
    return countDigit(stoi(num));
}


//string countDigit(int num)  ��ȯ�������δ� �Լ� �����ε��� �� ��
//{
//
//}


// ������ �� �Լ� �̸��� �ٲ۴�. name decoration, name mangling
// ������ �� � �Լ��� ȣ�� �Ǵ��� ������ �ȴ�. ���� ���ε�
void func(int, int); // func#int-int
void func(char); // func#char

int main()
{
    cout << countDigit(12345) << endl;
    cout << countDigit("12345") << endl;


    // operator<< ��� �Լ��� �Ű������� ����(char �Ǵ� int) �����ε��� �Ǿ��ִ�.
    cout << 'a' << endl;
    cout << (int)'a' << endl;
}