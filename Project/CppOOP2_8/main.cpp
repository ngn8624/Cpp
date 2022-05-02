//ȣ�� ������ �����ε�, �Լ� ��ü

#pragma warning(disable: 4996)
#include <iostream>


using namespace std;


class String
{
private:
    char* _chars;

public:
    /* explicit */ String(const char* chars) // explicit �� ������� ������ �Ͻ������� ����ȯ�� �ȴ�.
        : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    /* explicit */ String(const char* s0, const char* s1)
        : _chars(new char[strlen(s0) + strlen(s1) + 1])
    {
        _chars[0] = '\0';
        strcat(_chars, s0);
        strcat(_chars, s1);
    }

    /* explicit */ String(std::initializer_list<const char*> strs)
        : _chars(nullptr)
    {
        size_t size = 0;
        for (const char* str : strs)
        {
            size += strlen(str);
        }
        _chars = new char[size + 1];
        _chars[0] = '\0';

        for (const char* str : strs)
        {
            strcat(_chars, str);
        }
    }

    ~String()
    {
        delete[] _chars;
    }

    // �� ������ �����ε� ��� bool ��ȯ �����ڸ� ����غ���
    /* explicit */ operator bool() const // explicit �� ���ٸ� �Ͻ������ε� ����ȯ�� ����������
    {
        return strlen(_chars) > 0;
    }

    void print() const
    {
        cout << _chars << endl;
    }
};


void func(String s)
{
    s.print();
}

int main()
{
    String s0 = "abc"; // �Ͻ��� ��ȯ
    s0.print();

    func("abc"); // �Ͻ��� ��ȯ

    String s1{ "abc", "efg" };
    s1.print();

    String s2{ "a", "b", "c", "d" };
    s2.print();

    String s3 = "a";
    bool result = s3; // ��ȯ ������
    cout << result << endl;

    if (s3) // ��ȯ ������
    {
        s3.print();
    }

    String s4 = "";
    result = s4;
    cout << result << endl;

    if (s4)
    {
        s4.print();
    }
}