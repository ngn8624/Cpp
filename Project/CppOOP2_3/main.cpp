//��Ʈ ������ �����ε�

#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;


class String
{
private:
    char* _chars;


public:
    String(const char* chars) : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    bool operator!() const
    {
        return strlen(_chars) == 0;
    }

    bool operator||(bool b) const
    {
        return strlen(_chars) > 0 || b;
    }
};

bool func()
{
    cout << "func" << endl;
    return true;
}

// �� ������ �����ε��� �����ؾ��Ѵ�
int main()
{
    String s("");
    if (!s) // �ȴ�
    {

    }

    //if (s) // �� �ȴ�
    //{

    //}


    String s0("abc");
    if (s0 || func()) // s0�� true�� �� ������ func�� ���� �ȴ�. (Short-circuit evaluation �� ��)
    {// s0, func()�� �� ���� ������ �� �ȴ�. (|| �� �����ε������μ� ������ ����Ʈ�� �ƴϰ� ��)
        cout << "!!" << endl;
    }
    // && �����ε��� || �����ε��� ���� �������� ������ �ִ�
}