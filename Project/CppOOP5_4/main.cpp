#include <iostream>

using std::cout;
using std::endl;


// �Ҹ��ڴ� �⺻������ noexcept �Լ�

void func() noexcept // �ش� �Լ������� ���ܰ� ���� �ʴ´ٰ� ����, �����Ϸ��� ����ȭ �� �� �ִ�
{
    throw 1; // noexcept ������ �Լ����� throw �ȴٰ� �ϴ��� try catch�� ó���� �� ����
}

int main()
{
    try
    {
        func();
    }
    catch (int e)
    {
        cout << e << endl;
    }

    // ��� STL �Լ������� noexcept�� ������ �Լ��� �������� �ʴ� ��� ���� �ս��� ���� �� �ִ�
}