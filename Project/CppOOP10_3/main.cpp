#include <iostream>
#include <vector>
#include <numeric>
#include <range/v3/all.hpp>

// git clone https://github.com/Microsoft/vcpkg.git
// .\vcpkg\bootstrap-vcpkg.bat
// vcpkg integrate install
// .\vcpkg.exe install range-v3
// ����� ���� �ʼ�


// iterater ���� �� �߻�ȭ�Ͽ� �����ϰ� ����ϰ� ����
// 

int main()
{

    //{
    //    // sort ��
    //    std::vector<int> v{ 3, 2, 1 };

         //std::sort(v.begin(), v.end());
         //ranges::sort(v);

    //    for (int& i : v)
    //        std::cout << i << std::endl;
    //    std::cout << std::endl;
    //    return 0; 
    //}
    //{
    //    // find ��
    //    std::vector<int> v(10);
    //    std::iota(v.begin(), v.end(), 0);

    //    auto iter = ranges::find(v, 3);
    //    std::cout << *iter << std::endl;

    //    //iter == std::find(v.begin(), v.end(), 3);
    //    //std::cout << *iter << std::endl;
    //    //std::cout << std::endl;

    //    return 0; 
    //}
    {
        // view, lazy evaluation
        // 0 ~ 9���� ���
        for (int num : ranges::views::iota(0, 10))
            std::cout << num << std::endl;

        // 0���� ���Ѵ�
        //for (int num : ranges::views::iota(0))  // ������ ���Ѵ���� ���ڸ� �̸� �������� �ʰ� �ʿ��� �� �����
        //    std::cout << num << std::endl;
        std::cout << std::endl;
    }
    {
        // �ռ�, �������� �̿��Ͽ� �ռ�
        auto r =
            ranges::views::iota(0, 10) |
            ranges::views::reverse |
            ranges::views::filter([](const int& num) {
            return num % 2 == 0;
                }) |
            ranges::views::cycle |
                    ranges::views::take(20);
        for (int num : r) {
            std::cout << num << std::endl;
        }
        std::cout << std::endl;
    }
    {
        // Action, �����̳ʿ� ������ ��
        auto v = ranges::views::iota(0, 20) | ranges::to<std::vector<int>>();
        v |= ranges::actions::reverse | ranges::actions::drop(2);

        std::cout << ranges::views::all(v);
    }
}
