#include <iostream>
#include <type_traits>

// 템플릿을 이용하여 
// type_traits 라이브러리
// 템플릿 메타 함수 제공, 타입 핸들링
// 템플릿 메타 함수란, 사실 함수는 아니지만 마치 함수 처럼 동작하는 탬플릿 클래스들을 이야기 합니다. 
// 이들이 메타 함수인 이유는 보통의 함수들은 값에 대해 연산을 수행하지만, 
// 메타 함수는 타입에 대해 연산을 수행한다는 점이 조금 다릅니다.
// 템플릿 : 컴파일에 타입에 관한 무언가를 한다.
// 가장 중요한 점은 템플릿 메타 함수들은 실제론 함수가 아니라는 점 
// () 대신에 <> 를 통해 함수 인자가 아닌 템플릿 인자를 전달
// 예) is_void 클래스
// is_class, is_integer, is_


using std::cout;
using std::endl;


template<typename T> // 
struct is_pointer
{
    static const bool value = false;
};

// 템플릿 특수화, 부분 특수화
template<typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};

///////////////////////////////


template<typename T>
void foo(T t)
{
    cout << is_pointer<T>::value << endl;
}

////////////////////////////////////////

template<typename T>
struct remove_pointer
{
    using type = T;
};

template<typename T>
struct remove_pointer<T*>
{
    using type = T;
};

///////////////////////////////////////////////////


template<typename T>
struct add_pointer
{
    using type = T*;
};

template<typename T>
struct add_pointer<T&>
{
    using type = T*;
};

int main()
{
    cout << std::boolalpha;
    //{
    //    // 컴파일 타임의 타입에 관련된 기능을 제공
    //    //cout << "int* : " << std::is_pointer<int*>::value << endl;
    //    //cout << "int : " << std::is_pointer<int>::value << endl;


    //    //cout << "struct is_pointer : " << is_pointer<int*>::value << endl;
    //    //cout << "struct is_pointer : " << is_pointer<int>::value << endl; // 템플릿 특수화로 인해 true

    //    // 왜 사용할까?
    //    // 템플릿 사용시, 매개변수(T t)가 어떤 타입인지 모를때
    //    int num = 0;
    //    int* pNum = &num;

    //    foo(num);
    //    foo(pNum);

    //    cout << "=======" << endl;
    //}
    //{
    //    int num = 0;
    //    std::add_pointer<int>::type pNum = &num;
    //    //std::add_pointer_t<int> pNum1 = &num; //위 아래 같음
    //    *pNum = 10;
    //    cout << "*pNum  :  " << *pNum << endl;
    //    foo(pNum); // true 

    //    std::remove_pointer<int*>::type n = *pNum;  // integer
    //    cout << "n  :  " << n << endl;
    //    foo(n); // false

    //    cout << is_pointer<remove_pointer<int*>>::value << endl; // false

    //    cout << "=======" << endl;
    //}
    {
        add_pointer<int>::type num0;
        cout << "num0 : " << typeid(num0).name() << endl;

        add_pointer<int*>::type num1;
        cout << "num1 : " << typeid(num1).name() << endl;

        add_pointer<int&>::type num2; // 특수화
        cout << "num2 : " << typeid(num2).name() << endl;
    }
}