#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using std::cout;
using std::endl;


// �Լ� ��ü
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
        cout << "�Լ� ��ü : " << func(10) << endl;

        // lambda ��ü
        auto func0 = []()
        {
            return 10;
        };
        cout << "lambda ��ü : " << func0() << endl;

        int num = 1;
        auto func1 = [num](int value) // num�� ĸ�� ��
        {
            return num + value;
        };
        cout << "num�� ĸ�� �� : " << func1(10) << endl;
    }
    {
        // ��� ������ �ذ��ϱ� ���� ������ �Ϸ��� ������ ���
        // algorithm�� find ���
        std::vector<int> v{ 1, 2, 3, 4 };
        if (auto iter = std::find(v.begin(), v.end(), 4); iter != v.end())
        {
            cout << *iter << endl;
        }

        // ��� �Լ��� find ���
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

        // ��� �Լ��� �ִ� ���� ��� �Լ��� �������


        // find_if �� set���� ��� �Լ��� ����. 
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