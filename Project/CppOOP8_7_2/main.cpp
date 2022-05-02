#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <array>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <execution>

using std::cout;
using std::endl;


int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 3, 2, 1 };
    // 실제로 지우지 않고 지워야 하는 원소들만큼 앞으로 당긴다, 사이즈는 그대로
    // 1, 3, 4, 3, ?, ?
    auto iter = std::remove(v.begin(), v.end(), 2); // 

    // erase 를 해야 지워진다
    v.erase(iter, v.end());

    for (auto num : v)
    {
        cout << num << endl;
    }


    std::cout << "====================================" << std::endl;
    // remove 가 범용적이어야 하기 때문에 array 등에도 사용해야한다
    // array 경우 정적 배열이기 때문에 사이즈를 조절할 수 없음
    std::array<int, 7> v111{ 1, 2, 3, 4, 3, 2, 1 };
    auto iters = std::remove(v111.begin(), v111.end(), 2);

    for (auto num : v111)
    {
        cout << num << endl;
    }

    std::cout << "====================================" << std::endl;
    std::list<int> l{ 1, 2, 3, 4, 3, 2, 1 };
    l.remove(2); // list는 멤버 변수로 가지고 있고 erase 까지 한다. 

    for (auto num : l)
    {
        cout << num << endl;
    }
    std::cout << "====================================" << std::endl;
    std::set<int> s{ 1, 2, 3, 4, 3, 2, 1 };
    // std::remove(s.begin(), s.end(), 2);  // 안 됨 // 순서 대로 1234

    for (auto iter = s.begin(); iter != s.end();) // ++iter 없어야한다.  // 1, 2,3,4 => 1이 지나고 2가 나오면iter가 나오고 뒤 안함. ++ 안함
    {
        if (*iter == 2)
            iter = s.erase(iter);
        else
            ++iter;
    }
    for (auto num : s)
        std::cout << num << endl;
    std::cout << "====================================" << std::endl;
    int nums[] = { 1,2,3,4 };
    // std::remove(std::begin(nums), std::end(nums), 2); 위 아래 같음
    std::remove(nums, nums + 4, 2);
    for (int num : nums)
    {
        cout << num << endl;
    }
    std::cout << "====================================" << std::endl;
    int nums1[] = { 1,2,3,4 };
    int nums2[std::size(nums1)];
    std::copy(std::begin(nums1), std::end(nums1), nums2);
    for (int num : nums2)
    {
        cout << num << endl;
    }
    std::cout << "====================================" << std::endl;
    std::vector<int> nums3 = { 1,2,3,4 };
    std::vector<int> nums4(nums3.size());
    //std::vector<int> nums4; 사이즈 없으면 안된다....
    std::copy(std::begin(nums3), std::end(nums3), nums4.begin());
    for (int num : nums4)
    {
        cout << num << endl;
    }

    std::cout << "사이즈 없으면 안된다====================================" << std::endl;
    std::vector<int> nums5 = { 1,2,3,4 };
    std::vector<int> nums6;
    /*std::copy(std::begin(nums5), std::end(nums5), nums6.begin());*/ //이건안됨
    std::copy(std::begin(nums5), std::end(nums5), std::back_inserter(nums6));
    for (int num : nums6)
    {
        cout << num << endl;
    }
    std::cout << "iterator====================================" << std::endl;
    std::vector<int> num7 = {1,2,3,4};
    std::set<int> num8;

    std::copy(std::begin(num7), std::end(num7), std::inserter(num8, num8.begin()));

    for (int num : num8)
        std::cout << num << std::endl;

    std::cout << "iota================numeric====================" << std::endl;
    std::vector<int> v2(10);
    std::iota(v2.begin(), v2.end(), 0); // 0 부터 오름차순으로 증가한다
    for (auto num : v2)
    {
        cout << num << endl;
    }
    std::sort(v2.begin(), v2.end(), std::greater<int>());
    for (auto num : v2)
    {
        cout << num << endl;
    }

    std::cout << "iota================execution====================" << std::endl;
    std::vector<int> v3(100000000);
    std::iota(v3.begin(), v3.end(), 0); // 0 부터 오름차순으로 증가한다
    std::sort(std::execution::par,v3.begin(), v3.end(), std::greater<int>()); // execution::par // par 는 코어를 여러개 // seq 는 넣으나 안넣으나 똑같음
    //std::sort(v3.begin(), v3.end(), std::greater<int>());
    std::cout << v3[0] << endl;
}