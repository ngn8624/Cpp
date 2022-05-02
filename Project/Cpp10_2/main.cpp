// ����
#include <iostream>

using namespace std;


int x = 10;
int getX();

static int y = 10;
int getY();


enum struct RequestType
{
    Login, Register, Update, Delete
};


namespace CompanyA
{
    int num;
}

namespace CompanyB
{
    int num;
}

int main()
{
    {
        // Block scope 
        int a = 0;
        cout << a << endl;
        cout << &a << endl;
        cout << endl;
        {
            static int a = 10; // ��Ͽ� a�� ����Ǿ� ��ܿ��� ����� a�� ������
            cout << a << endl;
            cout << &a << endl;
            cout << endl;
        }

        cout << a << endl;
        cout << &a << endl;  // ���ʷ� ���� �� a, ��� ������ a�� static�̱� ������ ������ �� ���� �ƴ�
        cout << endl;


        if (int num = 1)
        {
            cout << num << endl;
        }

        //num = 1;  ������ �� ����

        if (int num = 0)
        {
            cout << num << endl;
        }
        else
        {
            cout << num << endl; // else������ ������ �� ����
        }


        for (int i = 0; i < 10; ++i)
        {

        }
        // i = 1; // ������ �� ����
    }
    {
        // Global scope
        cout << getX() << endl;
        x = 20;
        cout << getX() << endl;
    }
    {
        // File scope
        cout << getY() << endl;
        y = 20;
        cout << getY() << endl; // ������ ����. 10 ���
    }
    {
        // Enumeration scope
        RequestType::Login;
        RequestType::Update;
        RequestType::Register;
        RequestType::Delete;
    }
    {
        // Namespace scope
        // �̸� �ߺ��� ���ϱ� ���� ���.
        // ���� ��� ���� �������� �ߺ��� ���� �� �ִ�
        CompanyA::num;
        CompanyB::num;

        // using namespace �� ����Ͽ� �ش� namespace�� ������ �� ����
        // using std::cout, cout �� ���� namespace�� ������ 
    }

}