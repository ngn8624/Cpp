#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm> // sort
#include <functional> // greater

// STL : 프로그램에 필요한 자료구조와 알고리즘을 Template로 제공하는 라이브러리
// STL에서 컨테이너(container)는 같은 타입의 여러 객체를 저장하는 일종의 집합
// 컨테이너는 클래스 템플릿으로, 컨테이너 변수를 선언할 때 컨테이너에 포함할 요소의 타입을 명시할 수 있습니다.
// 컨테이너에는 복사 생성과 대입을 할 수 있는 타입의 객체만을 저장할 수 있습니다.
// 또한, 컨테이너는 요소의 추가 및 제거를 포함한 다양한 작업을 도와주는 여러 멤버 함수를 포함

//1. 시퀀스 컨테이너(sequence container) : vector, deque, list, forwad_list : 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 가장 일반적인 컨테이너
//2. 연관 컨테이너(associative container) : set, multiset, map, multimap : ordered associative container : 데이터를 일정 규칙에 따라 조직화하여 저장하고 관리하는 컨테이너
//                                          Unordered_set..... :            Unordered associative container
//3. 컨테이너 어댑터(adapter container) : stack, queue, priority_queue : 간결함과 명료성을 위해 인터페이스를 제한한 시퀀스나 연관 컨테이너의 변형, 
//                                                                      단, 반복자를 지원하지 않으므로 STL 알고리즘에서는 사용할 수 없습니다

using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vector;
        vector.push_back(10);
        vector.push_back(20);
        vector.push_back(-1);

        // 넣어주는 순서대로 출력, Sequence Container
        cout << "vector" << endl;
        for (int num : vector)
            cout << num << endl;


        std::set<int> set;
        set.insert(10);
        set.insert(20);
        set.insert(-1);

        // 정렬된 순서대로 출력, Ordered Associative Container
        cout << "set" << endl;
        for (int num : set)
            cout << num << endl;
        
        //-1
        //10
        //20

        std::unordered_set<int> uset;
        uset.insert(10);
        uset.insert(20);
        uset.insert(-1);

        // 순서보장이 안됨, Unordered Associative Container
        cout << "unordered set" << endl;
        for (int num : uset)
            cout << num << endl;

        // 순서가 출력할때마다 바뀜

    }
    {
        cout << "=========" << endl;
        std::vector<int> nums{ 1, 2, 3, 4 };

        // 순회 방법 1.
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << endl;
        }
        cout << endl;

        // 순회 방법 2.
        for (int num : nums)
        {
            cout << num << endl;
        }
        cout << endl;

        // 순회 방법 3.
        // 이터레이터는 포인터 사용법과 호환이 됨
        for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) // [begin, end) : 포함, 미포함
        {
            cout << *iter << endl;
        }
    }
    {
        cout << "=========" << endl;
        std::vector<int> nums{ 10, 1, 2, 3, 4 };

        // 알고리즘을 사용하여 정렬
        // sort(start, end)를 이용하여 [start, end) 의 범위에 있는 인자(element)를 오름차순(default)으로 정렬해주는 함수

        std::sort(nums.begin(), nums.end()); 
        
        for (int num : nums)
            cout << num << endl;
    }

    {
        // 내림차순
        cout << "=========" << endl;
        std::vector<int> nums{ 10, 1, 2, 3, 4 };
        sort(nums.begin(), nums.end(), std::greater<int>());
        for (int num : nums)
            cout << num << endl;
    }
}