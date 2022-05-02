#include <iostream>

using std::cout;
using std::endl;


double divide(double d, double v)
{
    if (v == 0)
    {
        throw "Dirived by zero"; // ó�� ���� ������ std::terminate ȣ��
    }
    return d / v;
}
 
class Parent {};
class Child : public Parent {};
class Test
{
public:
    ~Test() { cout << "test" << endl; }
};

void func1()
{
    Test t;
    divide(10, 0);
}

void func0()
{
    Test t;
    func1();
}

void terminateFunc()
{
    cout << "terminate" << endl;
}

// �Լ� ��ü�� try�� �� ���� �ִ�
void foo() try
{

}
catch (const char* e)
{

}

int main()
{
    //divide(10,0);
    // abort() ����, 
    // terminate vs abort
    // terminate �� ������ �Լ� ���� ����
    //std::set_terminate(terminateFunc);
    //
    //try
    //{
    //    cout << divide(10, 0) << endl;
    //}
    //catch (const char* e) // ó���� ������ Ÿ��
    //{
    //    cout << e << endl;
    //}
    //catch (...) // ó���� ����Ÿ���� �������� ���� ���� ��
    //{
    //    cout << "..." << endl;
    //}


    //try
    //{
    //    throw Child();
    //}
    //catch (Parent&) // �θ� Ÿ������ ���� �� �ִ�
    //{
    //    cout << "Parent" << endl;
    //}
    //catch (Child&) // catch ������� üũ���ϱ� ������ ���� catch�� ȣȯ�� �Ǳ� ������ ���� catch�� ���� �ȴ�.
    //{
    //    cout << "Child" << endl;
    //}

    try
    {
        func0(); // divide���� ���ܰ� �߻������� ���ܸ� ó���� �� �ִ� ������ �Լ� ������ �ǵ�����
    }
    catch (const char* e)
    {
        cout << e << endl;
        throw; // ���� ���ܸ� rethrow �� �� �ִ�
    }

    //// std::exception�� ����ؼ� ���� ��ü�� ������
    //// ǥ�� ���̺귯���� ���ܵ鵵 std::exception�� �������
    //std::runtime_error; // ǥ�� ���̺귯���� ���� �� �ϳ�
}