#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using std::cout;
using std::endl;


// 함수 객체
struct Func
{
    int operator()(int value) const
    {
        return value;
    }
};

int main()
{
    {
        Func func;
        cout << "함수 객체 : " << func(10) << endl;

        // lambda 객체
        auto func0 = []()
        {
            return 10;
        };
        cout << "lambda 객체 : " << func0() << endl;

        int num = 1;
        auto func1 = [num](int value) // num이 캡쳐 됨
        {
            return num + value;
        };
        cout << "num이 캡쳐 됨 : " << func1(10) << endl;
    }
    {
        // 어떠한 문제를 해결하기 위해 정해진 일련의 절차나 방법
        // algorithm의 find 사용
        std::vector<int> v{ 1, 2, 3, 4 };
        if (auto iter = std::find(v.begin(), v.end(), 4); iter != v.end())
        {
            cout << *iter << endl;
        }

        // 멤버 함수의 find 사용
        std::set<int> s{ 1, 2, 3, 4};
        if (auto iter = s.find(4); iter != s.end())
        {
            cout << *iter << endl;
        }

        std::set<int> s11{1,2,3};
        s11.find(2); // O(log(n))

        std::unordered_set<int> us11{ 1,2,3, }; 
        us11.find(3);// O(1)

        auto iter = std::find(v.begin(), v.end(),2); // O(n)

        // 멤버 함수가 있는 경우는 멤버 함수를 사용하자


        // find_if 는 set에도 멤버 함수가 없다. 
        std::vector<int> v1{ 1, 2, 3 };
        auto iters = std::find_if(v1.begin(), v1.end(), [](const int& value) {
            return (value % 2 == 0);
            }); // O(n)
        if (iters != v1.end())
        {
            std::cout << "*iter" << *iter << endl;
        }
    }
}