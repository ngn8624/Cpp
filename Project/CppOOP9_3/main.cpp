#include <iostream>
#include <functional>
#include <set>

void foo(std::function<void(void)> func) // �̷��� �Ķ���͸� ������ �Ҷ� �� ����� �� �ִ�.
{
    func();
}

void goo(int value)
{
    std::cout << value << std::endl;
}

struct Func // ��� ���ٴ� �Լ���ü
{
    int value;
    void operator()() const // mutable �� �Լ� ��ü ���� ��
    {

    }
};

struct Test
{
    int num = 10;
    auto func()
    {
        return [num = num] { // ĸ���ϴ� ��ġ���� �ʱ�ȭ // this(�ּҰ�) �� ĸ���ؾ��ϱ⶧���� �ȵȴ�. 
            return num;
        };
    }
};

int main()
{
    // �⺻���� lambda�� ����
    [/*ĸ��*/](/*�Ķ����*/) /*��ȯ��*/
    {
    };
    []() -> int // ��ȯ�� �� �Ⱦ���
    {
    };

    // �Ķ���� ���� ��
    //auto func = []
    //{
    //};
    //func();

    //�Ķ���� �ִ� ��
    //auto func = [](int value)
    //{
    //};
    //func(1);
    {
        int values = 10;
        [values]()
        {
            std::cout << values << std::endl;
        }(); // () �̰� �־���� // ()�� �ٷ� ���� ��Ŵ // �ӽ����� Ŭ���� ��ü�� ���� �ٷ� ����
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
        //foo(func); //�Ѱ��� �� ����
        //foo(goo); //�Ѱ��� �� ����
        int value = 10;
        auto func = [value]() // &value ����
        {
            std::cout << value << std::endl;
        };
        foo(func); //�Ѱ��� �� ����
    }

    std::cout << "3=================" << std::endl;
    {
        int value = 10;
        foo([value]() // ĸ���ؼ� �Ѱ��� �� ����
            {
                goo(value);
            });
        foo([&value]() // ������ ĸ��
            {
                goo(value);
            });

        foo([value]() mutable // �Լ���ü���� const�� ����
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
        foo(func); // ������ ����� �̰Ͱ� ������


        int num = 10;
        auto func0 = [num]() mutable
        {
            ++num;
            return num;
        };
        // �Ϲ������� �Լ� ȣ�� �� ������ ���� ���ϰ� �Ǹ� �ǵ����� ���� ��Ȳ�� �߻��� �� �ִ�. ������ �⺻������ mutable�� �ƴ� // ���� �� �ٲ� const // 
        std::cout << func0() << std::endl; // 11
        std::cout << func0() << std::endl; // 12

        std::cout << "5=================" << std::endl;
        {
            int num0 = 10;
            int num1 = 20;

            [=]() // ��� �༮�� ������ ĸ�� ����
            {
            };

            [&]() // ��� ������ ������ ĸ�� ����
            {
                // ���۷����� ��������
            };

            auto func = [=, &num0]()
            {
                num0 = 20;
                return num0 + num1;
            };

            std::cout << func() << std::endl;
        }
        std::cout << "6=================" << std::endl;

        void (*f)(int) = [](int) {};  // ĸ�� ���� ���ٴ� �Լ� �����Ϳ� ȣȯ ��

        auto f0 = [](int) {};  // ���� �� auto ���
        std::function<void(int)> f1 = [](int) {}; // ���� �� std::function ���

        auto f2 = [](auto value) // Generic ����
        {
            return value;
        };
        std::cout << f2(1) << std::endl;
        std::cout << f2('1') << std::endl;

        auto f3 = []<typename T>(T value) // ���ø� ����, C++20
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