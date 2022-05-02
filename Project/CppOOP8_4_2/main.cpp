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

        std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, "10" }); // �����ϴϱ� auto ���
        // pair �� first�� second �� ����
        // bool �� true �ϸ� m.insert({ 3, "10" }) ��ȯ
        cout << result.second << endl; // ���� ����
        cout << result.first->first << endl; // �ش� Key�� ��ġ�ϴ� map�� �ִ� iterator // iterator�� pair�� ����Ŵ -> ������
        cout << result.first->second << endl;

        cout << "bool ===============================" << endl;

        //auto result = m.insert({ 3, "10" });
        //cout << result.second << endl; // ���� ����
        //cout << result.first->first << endl; // �ش� Key�� ��ġ�ϴ� map�� �ִ� iterator // iterator�� pair�� ����Ŵ -> ������
        //cout << result.first->second << endl;


        cout << "C++17���� ===============================" << endl;

        // C++17����
        auto [iter, success] = m.insert({ 3, "20" });
        cout << success << endl;
        cout << iter->first << endl;
        cout << iter->second << endl;

        cout << "C++17���� ��ȸ ===============================" << endl;

        // C++17����
        for (auto& [key, value] : m)
        {
            value = "abc";
        }

        for (auto& [key, value] : m)
        {
            cout << key << "  " << value << endl;
        }

        cout << "���ͷ����� ã�� ===============================" << endl;

        cout << "count(10)  " << m.count(10) << endl; // 10�̶� Ű�� �ִ��� �˻� // ���, ����

        // ���ͷ����� ã��
        if (auto iter = m.find(3); iter != m.end())
        {
            cout << iter->second << endl; // ���ͷ����ͷ� �����
            m.erase(iter);
        }
        m.erase(3); // Ű�� �����
        cout << endl;

        for (auto& [key, value] : m)
        {
            cout << key << "  " << value << endl;
        }

    }
    {
        cout << "multimap===============================" << endl;
        // �ߺ� key ���
        std::multimap<int, std::string> mm{
            {2, "10"},
            {1, "10"},
            {1, "20"},
            {1, "30"},
        };

        for (const auto& [k, v] : mm) // Ű�� ����
        {
            cout << k << ":" << v << endl;
        }

        cout << "===============================" << endl;

        // �׻� ����
        //mm.insert({ 1, "40" });
        std::multimap<int, std::string>::iterator result = mm.insert({ 1, "40" });

        cout << result->first << ":" << result->second << endl;

        cout << "===============================" << endl;

        // ���
        auto lower = mm.lower_bound(1); // key 1�� ���� ù��° value  
        auto upper = mm.upper_bound(1); // key 1�� ���� ������ value �ٷ� ��
        //auto [lower, upper] = mm.equal_range(1); // ���� ����
        for (auto iter = lower; iter != upper; ++iter)
        {
            cout << iter->second << endl;
        }
    }
    {
        cout << "set===============================" << endl;

        // Ʈ�� ����. Key�� ����, ���� �Ǿ� ����
        // Ű�� value �� ����
        // ÷�� ���� ����
        // s[1] = 2;

        std::set<int> s{
            1, 2, 3, 4
        };
        cout << "auto ��ȸ===============================" << endl;
        for (const auto& num : s)
        {
            cout << num << endl;
        }

        cout << "iterator ��ȸ===============================" << endl;
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

        cout << "inset ��ȸ �� =====================" << endl;
        for (iter = s.begin(); iter != s.end(); iter++)
        {
            cout << *iter << endl;;
        }

    }
    {
        cout << "multiset===============================" << endl;
        // Ʈ�� ����. Key�� ����, ���� �Ǿ� ����, �ߺ� ���
        std::multiset<int> ms{
            1, 1, 3, 10, 10, 3
        };
        cout << "multiset ��ȸ===============================" << endl;
        for (const auto& num : ms)
        {
            cout << num << endl;
        }
    }
    {
        // std::less<int> ������ ��� ���� �����ϴ� �Լ� ��ü
        std::set<int, std::less<int>> s;
        std::map<int, std::string, std::less<int>> m;

        std::set<int, std::less<int>> s0{ 3, 10, -1 };
        
        cout << "==============" << endl;
        // ��������
        for (const auto& num : s0)
        {
            cout << num << endl;
        }

        cout << "�̰� ����" << endl;

        std::set<int, std::greater<int>> s1{ 3, 10, -1 };
        // ��������
        for (const auto& num : s1)
        {
            cout << num << endl;
        }

    }
}