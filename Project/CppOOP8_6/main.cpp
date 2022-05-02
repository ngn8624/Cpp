#include <iostream>
#include <vector>
#include <list>
#include "Ranges.h"

// iterator 는 container 를 순회
// container와 알고리즘 사이의 접착제
// 반복자(iterator)는 객체 지향적 프로그래밍에서 배열이나 그와 유사한 자료 구조의 내부의 요소를 순회(traversing)하는 객체


using std::cout;
using std::endl;


template<typename TIterator, typename T>
bool has(TIterator begin,TIterator end, T value)
{
    for (auto iter = begin; iter != end; ++iter)
    {
        if (*iter == value)
            return true;
    }
    return false;
}

//bool has(std::vector<int>::iterator begin, std::vector<int>::iterator end, int value)
//{
//    for (auto iter = begin; iter != end; ++iter)
//    {
//        if (*iter == value)
//            return true;
//    }
//    return false;
//}
//
// 예 v의 2를 찾는 함수
bool has(std::vector<int>&v, int value)
{
    for (int num : v)
    {
        if (num == value)
            return true;
    }
    return false;
}



int main()
{
    {
        std::cout << std::boolalpha;
        std::vector<int> v{ 1, 2, 3 };
        cout << has(v, 2) << endl;
        // 만약에 list라면 안된다.
        // iterator 사용하자
        // 변환 
        cout << has(v.begin(), v.end(), 1 ) << endl;

        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) 
        {
            *iter *= 2;
        }
        // auto 키워드의 문제는 begin(), end(), rbegin(), rend() 로는 const_iterator 타입을 받을 수 없다는 것, 
        // 상수 반복자라는 의미로 앞에 c
        for (std::vector<int>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter) // const T& 형태의 참조를 반환하게 됩니다. 이것은 const 지시어가 있는 변수이므로 역참조 된 값을 변경할 수 없도록 방지되는 효과
        {
            //*iter = 10; // const_iterator 이기 떄문에 변경 불가능
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums0{ 1, 2, 3 };
        std::list<int> nums1{ 1, 2, 3 };

        std::cout << std::boolalpha;
        // 이터레이터를 통해 이종의 컨테이너에 대해 같은 코드를 사용
        std::cout << has(nums0.begin(), nums0.end(), 1) << endl;
        std::cout << has(nums1.begin(), nums1.end(), 4) << endl;
        std::cout << std::endl;
    }

    cout << "=========================================================" << endl;
    {
        // Range based for loop 역시 이터레이터 인터페이스를 이용한다
        // (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) 
        for (int num : Ranges(0, 3))
        {
            std::cout << num << endl;
        }
    }
}

