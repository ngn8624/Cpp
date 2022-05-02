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
    // 예외 발생시 메모리 해제 안되는 경우
    try
    {
        Test i1; // 
        Test* i2 = new Test; // 소멸자 호출 안함
        //delete i2;
        int* i = new int; // *i 는 메모리 leak 발생
        func();
    }
    //catch (const char* e)
    //{
    //    cout << e << endl;
    //}

    // RAII 없이...
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
    //    //RAII 기법는 Resource Acquisition Is Initialization의 약자로, 리소스 획득은 초기화
    //    RAII raii;
    //    func();
    //} // 블럭을 벗어나면서 RAII의 소멸자가 호출되면서 내부에 할당한 동적 객체가 해제된다 // scope 를 이용하여 해제
    //catch (const char* e)
    //{
    //    cout << e << endl;
    //}


    try
    {
        // unique_ptr을 이용해 동적할당에 대한 RAII를 사용할 수 있다
        std::unique_ptr<Test> test(new Test());
        
        func();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
}