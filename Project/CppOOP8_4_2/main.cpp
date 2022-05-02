#include <iostream>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;


for (int num : arr)
{

}

int main()
{
    {
        cout << std::boolalpha;

        //std::map<int, std::string> m;
        std::map<int, std::string> m{ {1, "1"},{2,"2"},{3,"3"}};
        std::array<int, 5> aaa{1,2,3,4,5};
        int a = aaa.size;

    std:array<int> a = new int(3);

        std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, "10" }); // 복잡하니까 auto 사용
        // pair 면 first와 second 가 있음
        // bool 이 true 하면 m.insert({ 3, "10" }) 반환
        cout << result.second << endl; // 성공 여부
        cout << result.first->first << endl; // 해당 Key에 일치하는 map에 있는 iterator // iterator는 pair를 가르킴 -> 역참조
        cout << result.first->second << endl;

        cout << "bool ===============================" << endl;

        //auto result = m.insert({ 3, "10" });
        //cout << result.second << endl; // 성공 여부
        //cout << result.first->first << endl; // 해당 Key에 일치하는 map에 있는 iterator // iterator는 pair를 가르킴 -> 역참조
        //cout << result.first->second << endl;


        cout << "C++17부터 ===============================" << endl;

        // C++17부터
        auto [iter, success] = m.insert({ 3, "20" });
        cout << success << endl;
        cout << iter->first << endl;
        cout << iter->second << endl;

        cout << "C++17부터 순회 ===============================" << endl;

        // C++17부터
        for (auto& [key, value] : m)
        {
            value = "abc";
        }

        for (auto& [key, value] : m)
        {
            cout << key << "  " << value << endl;
        }

        cout << "이터레이터 찾기 ===============================" << endl;

        cout << "count(10)  " << m.count(10) << endl; // 10이란 키가 있는지 검사 // 결과, 없다

        // 이터레이터 찾기
        if (auto iter = m.find(3); iter != m.end())
        {
            cout << iter->second << endl; // 이터레이터로 지우기
            m.erase(iter);
        }
        m.erase(3); // 키로 지우기
        cout << endl;

        for (auto& [key, value] : m)
        {
            cout << key << "  " << value << endl;
        }

    }
    {
        cout << "multimap===============================" << endl;
        // 중복 key 허용
        std::multimap<int, std::string> mm{
            {2, "10"},
            {1, "10"},
            {1, "20"},
            {1, "30"},
        };

        for (const auto& [k, v] : mm) // 키만 정렬
        {
            cout << k << ":" << v << endl;
        }

        cout << "===============================" << endl;

        // 항상 성공
        //mm.insert({ 1, "40" });
        std::multimap<int, std::string>::iterator result = mm.insert({ 1, "40" });

        cout << result->first << ":" << result->second << endl;

        cout << "===============================" << endl;

        // 경계
        auto lower = mm.lower_bound(1); // key 1에 대한 첫번째 value  
        auto upper = mm.upper_bound(1); // key 1에 대한 마지막 value 바로 전
        //auto [lower, upper] = mm.equal_range(1); // 위와 같음
        for (auto iter = lower; iter != upper; ++iter)
        {
            cout << iter->second << endl;
        }
    }
    {
        cout << "set===============================" << endl;

        // 트리 구조. Key만 있음, 정렬 되어 있음
        // 키와 value 가 같음
        // 첨자 연산 없음
        // s[1] = 2;

        std::set<int> s{
            1, 2, 3, 4
        };
        cout << "auto 순회===============================" << endl;
        for (const auto& num : s)
        {
            cout << num << endl;
        }

        cout << "iterator 순회===============================" << endl;
        std::set<int>::iterator iter;
        for (iter = s.begin(); iter != s.end(); iter++)
        {
            cout << *iter << endl;
        }
        cout << "s.insert(10)" << endl;
        if (auto [iter, success] = s.insert(10); success)
        {
            cout << *iter << endl; // const int
        }

        cout << "inset 순회 후 =====================" << endl;
        for (iter = s.begin(); iter != s.end(); iter++)
        {
            cout << *iter << endl;;
        }

    }
    {
        cout << "multiset===============================" << endl;
        // 트리 구조. Key만 있음, 정렬 되어 있음, 중복 허용
        std::multiset<int> ms{
            1, 1, 3, 10, 10, 3
        };
        cout << "multiset 순회===============================" << endl;
        for (const auto& num : ms)
        {
            cout << num << endl;
        }
    }
    {
        // std::less<int> 정렬을 어떻게 할지 결정하는 함수 객체
        std::set<int, std::less<int>> s;
        std::map<int, std::string, std::less<int>> m;

        std::set<int, std::less<int>> s0{ 3, 10, -1 };
        
        cout << "==============" << endl;
        // 오름차순
        for (const auto& num : s0)
        {
            cout << num << endl;
        }

        cout << "이게 뭐지" << endl;

        std::set<int, std::greater<int>> s1{ 3, 10, -1 };
        // 내림차순
        for (const auto& num : s1)
        {
            cout << num << endl;
        }

    }
}