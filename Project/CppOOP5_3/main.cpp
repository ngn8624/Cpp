#include <iostream>
#include <memory>


using std::cout;
using std::endl;


class RAII
{
public:
    int* i;
    RAII()
    {
        i = new int;
    }
    ~RAII()
    {
        cout << "~RAII" << endl;
        delete i;
    }
};

class Test
{
public:
    ~Test() { cout << "~Test" << endl; }
};

void func()
{
    throw "exception";
}

int main()
{
    // ���� �߻��� �޸� ���� �ȵǴ� ���
    try
    {
        Test i1; // 
        Test* i2 = new Test; // �Ҹ��� ȣ�� ����
        //delete i2;
        int* i = new int; // *i �� �޸� leak �߻�
        func();
    }
    //catch (const char* e)
    //{
    //    cout << e << endl;
    //}

    // RAII ����...
    //int* i = nullptr;
    //try
    //{
    //    i = new int;
    //    func();
    //    delete i;
    //}
    //catch (const char* e)
    //{
    //    delete i;
    //    cout << e << endl;
    //}



    //try
    //{
    //    //RAII ����� Resource Acquisition Is Initialization�� ���ڷ�, ���ҽ� ȹ���� �ʱ�ȭ
    //    RAII raii;
    //    func();
    //} // ���� ����鼭 RAII�� �Ҹ��ڰ� ȣ��Ǹ鼭 ���ο� �Ҵ��� ���� ��ü�� �����ȴ� // scope �� �̿��Ͽ� ����
    //catch (const char* e)
    //{
    //    cout << e << endl;
    //}


    try
    {
        // unique_ptr�� �̿��� �����Ҵ翡 ���� RAII�� ����� �� �ִ�
        std::unique_ptr<Test> test(new Test());
        
        func();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
}