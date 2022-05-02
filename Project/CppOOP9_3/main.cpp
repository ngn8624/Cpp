#include <iostream>
#include <functional>
#include <set>

void foo(std::function<void(void)> func) // 이렇게 파라미터를 강제를 할때 잘 사용할 수 있다.
{
    func();
}

void goo(int value)
{
    std::cout << value << std::endl;
}

struct Func // 사실 람다는 함수객체
{
    int value;
    void operator()() const // mutable 시 함수 객체 삭제 됨
    {

    }
};

struct Test
{
    int num = 10;
    auto func()
    {
        return [num = num] { // 캡쳐하는 위치에서 초기화 // this(주소값) 를 캡쳐해야하기때문에 안된다. 
            return num;
        };
    }
};

int main()
{
    // 기본적인 lambda의 형태
    [/*캡쳐*/](/*파라메터*/) /*반환형*/
    {
    };
    []() -> int // 반환형 잘 안쓰임
    {
    };

    // 파라미터 없는 것
    //auto func = []
    //{
    //};
    //func();

    //파라미터 있는 것
    //auto func = [](int value)
    //{
    //};
    //func(1);
    {
        int values = 10;
        [values]()
        {
            std::cout << values << std::endl;
        }(); // () 이거 있어야함 // ()는 바로 실행 시킴 // 임시적인 클로져 객체가 생성 바로 실행
    }
    std::cout << "1=================" << std::endl;
    {
        int values = 10;
        [](int values)
        {
            std::cout << values << std::endl;
        }(values);
    }
    std::cout << "2=================" << std::endl;
    {
        //int value = 10;
        //auto func = [](int param)
        //{
        //    std::cout << param << std::endl;
        //};
        //foo(func); //넘겨줄 수 없음
        //foo(goo); //넘겨줄 수 없음
        int value = 10;
        auto func = [value]() // &value 가능
        {
            std::cout << value << std::endl;
        };
        foo(func); //넘겨줄 수 있음
    }

    std::cout << "3=================" << std::endl;
    {
        int value = 10;
        foo([value]() // 캡쳐해서 넘겨줄 수 있음
            {
                goo(value);
            });
        foo([&value]() // 참조로 캡쳐
            {
                goo(value);
            });

        foo([value]() mutable // 함수객체에서 const를 삭제
            {
                value = 20;
                goo(value);
            });
        std::cout << "value :  " << value << std::endl;

    }
    std::cout << "4=================" << std::endl;

    {
        int value = 10;
        Func func;
        func.value = value; // capture
        foo(func); // 람다의 사용은 이것과 유사함


        int num = 10;
        auto func0 = [num]() mutable
        {
            ++num;
            return num;
        };
        // 일반적으로 함수 호출 시 내부의 값이 변하게 되면 의도하지 않은 상황이 발생할 수 있다. 때문에 기본적으로 mutable이 아님 // 값을 못 바꿈 const // 
        std::cout << func0() << std::endl; // 11
        std::cout << func0() << std::endl; // 12

        std::cout << "5=================" << std::endl;
        {
            int num0 = 10;
            int num1 = 20;

            [=]() // 모든 녀석을 값으로 캡쳐 가능
            {
            };

            [&]() // 모든 변수를 참조로 캡쳐 가능
            {
                // 레퍼렌스는 수정가능
            };

            auto func = [=, &num0]()
            {
                num0 = 20;
                return num0 + num1;
            };

            std::cout << func() << std::endl;
        }
        std::cout << "6=================" << std::endl;

        void (*f)(int) = [](int) {};  // 캡쳐 없는 람다는 함수 포인터와 호환 됨

        auto f0 = [](int) {};  // 선언 시 auto 사용
        std::function<void(int)> f1 = [](int) {}; // 선언 시 std::function 사용

        auto f2 = [](auto value) // Generic 람다
        {
            return value;
        };
        std::cout << f2(1) << std::endl;
        std::cout << f2('1') << std::endl;

        auto f3 = []<typename T>(T value) // 템플릿 람다, C++20
        {
            return value;
        };
        std::cout << f3(1) << std::endl;
        std::cout << f3('1') << std::endl;
    }
    std::cout << "7=================" << std::endl;
    auto func = [](const int& x, const int& y)
    {
        return x > y;
    };
    std::set<int, decltype(func)>  s(func);
    s.insert(1);
    s.insert(2);
    s.insert(3);

    for (int num : s)
    {
        std::cout << num << std::endl;
    }
}