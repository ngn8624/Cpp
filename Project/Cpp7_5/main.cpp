//nullptr
// null 포인터 값
#include <iostream>

using namespace std;


void func(int n)
{

}

int main()
{
    {
        // 비어있다.
        int* p = nullptr;
        /*int* s = 0;*/
        //int* s = NULL;
        cout << p << endl;
    }
    {
        int* p = new int;
        delete p;
        p = nullptr; // 해제한 이후 nullptr로 초기화

        // 유효한 포인터인지 확인
        if (p != nullptr)
        {
        }
    }
    {
        // C++11 이전의 NULL(0)
        func(NULL); // 호출 됨

        // 호출 안 됨
        //func(nullptr);
    }
    {
        // nullptr의 타입
        std::nullptr_t n = nullptr;

        // nullptr_t의 값은 어떤 형태의 포인터로도 변환 가능
        // std::nullptr_t 타입은 모든 타입의 포인터로 암시적 형 변환이 가능
        int* p = n;
    }
}