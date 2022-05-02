//import std.core;
//import std.memory;
//import std.threading;
import swap; 
#include < iostream>

// command
// cl /experimental:module /std:c++latest /c swap.ixx
// swap.ifc 생성
// swap.obj 생성
// cl /experimental:module /std:c++latest main.cpp swap.obj
// .\main.exe
int main()
{
    // 
    // module은 include 의 많은 단점들을 보완함
    // - 매번 헤더를 소스 파일에 복사/붙여넣기 하는 것
    // - pragam, ifndef 등을 사용하지 않게 됨
    // - 헤더 내부에서 의도하지 않은 것들에 대한 공개
    // 예) chrono는 chrono에 있는데 mutex만 인클루드해줘도 가져온다.
    // 또한 다른 헤더에 똑같은 매크로를 가져오면 뒤에 인클루드된게 가져오게 된다.
    // 실험적이라... 안정적이지 않다.

    // 인스톨러 -> 개별구성요소 -> 모듈 -> 실험적
    // 속성 - c++ 최신
    // 속성 - c/c++ - 코드생성 - dll/md 
    // 속성 - c/c++ - 언어 - 실험적


    /*std::cout << "a" << std::endl;

    std::vector<int> nums{ 1, 2, 3 };
    for (auto num : nums)
    {
        std::cout << num << std::endl;
    }

    std::thread th([] {
        std::cout << "async" << std::endl;
        });

    std::unique_ptr<int> i = std::make_unique<int>(10);
    std::cout << *i << std::endl;
    th.join();*/

    int x = 10, y = 20;
    swap(x,y);
    std::cout << x << std::endl;
    std::cout << y << std::endl;

}
// 주절주절
//자원관리 디자인 패턴
// RAII  자원의 획득은 초기화
// 자원 관리를 스택에 할당한 객체를 통해 수행
// 포인터 '객체' 로 만들어서 자신이 소멸 될 때 자신이 가리키고 있는 데이터도 같이 delete 하게 하면 됩니다
// 자원 (이 경우 메모리) 관리를 스택의 객체 (포인터 객체) 를 통해 수행하게 되는 것입니다.
// 이렇게 똑똑하게 작동하는 포인터 객체를 스마트 포인터(smart pointer)
// auto_ptr : unique_ptr , shared_ptr 
// std::unique_ptr<B> p(new B());
// 가비지 컬렉터 (Garbage Collector - GC) 라 불리는 자원 청소기가 기본적으로 내장
// 가비지 컬렉터의 역할은 프로그램 상에서 더 이상 쓰이지 않는 자원을 자동으로 해제