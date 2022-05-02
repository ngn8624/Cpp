#include <iostream>
#include <typeinfo>

// Run Time Type Information의 약자로 "실행시간에 타입정보를 식별" 정도로 풀이할 수 있습니다. 
// 정확한 의미는, 실행중에 기반 클래스 타입 포인터의 실체를 밝혀내는데 목적을 두고 있습니다.
// 속성 - 런타임 형식 정보 사용 - 아니요 일경우


using std::cout;
using std::endl;

class Parent
{
public: // 가상함수 테이블이 중요
    virtual ~Parent() {}
};

class Child : public Parent
{

};


int main()
{
    Parent* p = new Child;

    // 런타임 형식 정보 사용(RTTI) 하지 않는 경우 아래의 코드가 실행이 되지 않는다
    // 런타임에 실제 타입을 알아야하는 경우
    cout << typeid(*p).name() << endl; // p의 타입은 런타임에 알 수 있다
    dynamic_cast<Child*>(p); // p의 캐스팅 여부는 런타임에 알 수 있다.(다운 캐스팅)

    // RTTI 는 가상함수 테이블에 정보가 있다.
    // typeid, dynamic_cast 는 virtual 함수가 없는 경우 제대로 동작하지 않을 수 있다.
}