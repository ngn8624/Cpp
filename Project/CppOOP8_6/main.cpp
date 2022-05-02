#include <iostream>
#include <vector>
#include <list>
#include "Ranges.h"

// iterator �� container �� ��ȸ
// container�� �˰��� ������ ������
// �ݺ���(iterator)�� ��ü ������ ���α׷��ֿ��� �迭�̳� �׿� ������ �ڷ� ������ ������ ��Ҹ� ��ȸ(traversing)�ϴ� ��ü


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
// �� v�� 2�� ã�� �Լ�
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
        // ���࿡ list��� �ȵȴ�.
        // iterator �������
        // ��ȯ 
        cout << has(v.begin(), v.end(), 1 ) << endl;

        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) 
        {
            *iter *= 2;
        }
        // auto Ű������ ������ begin(), end(), rbegin(), rend() �δ� const_iterator Ÿ���� ���� �� ���ٴ� ��, 
        // ��� �ݺ��ڶ�� �ǹ̷� �տ� c
        for (std::vector<int>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter) // const T& ������ ������ ��ȯ�ϰ� �˴ϴ�. �̰��� const ���þ �ִ� �����̹Ƿ� ������ �� ���� ������ �� ������ �����Ǵ� ȿ��
        {
            //*iter = 10; // const_iterator �̱� ������ ���� �Ұ���
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums0{ 1, 2, 3 };
        std::list<int> nums1{ 1, 2, 3 };

        std::cout << std::boolalpha;
        // ���ͷ����͸� ���� ������ �����̳ʿ� ���� ���� �ڵ带 ���
        std::cout << has(nums0.begin(), nums0.end(), 1) << endl;
        std::cout << has(nums1.begin(), nums1.end(), 4) << endl;
        std::cout << std::endl;
    }

    cout << "=========================================================" << endl;
    {
        // Range based for loop ���� ���ͷ����� �������̽��� �̿��Ѵ�
        // (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) 
        for (int num : Ranges(0, 3))
        {
            std::cout << num << endl;
        }
    }
}

