#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm> // sort
#include <functional> // greater

// STL : ���α׷��� �ʿ��� �ڷᱸ���� �˰����� Template�� �����ϴ� ���̺귯��
// STL���� �����̳�(container)�� ���� Ÿ���� ���� ��ü�� �����ϴ� ������ ����
// �����̳ʴ� Ŭ���� ���ø�����, �����̳� ������ ������ �� �����̳ʿ� ������ ����� Ÿ���� ����� �� �ֽ��ϴ�.
// �����̳ʿ��� ���� ������ ������ �� �� �ִ� Ÿ���� ��ü���� ������ �� �ֽ��ϴ�.
// ����, �����̳ʴ� ����� �߰� �� ���Ÿ� ������ �پ��� �۾��� �����ִ� ���� ��� �Լ��� ����

//1. ������ �����̳�(sequence container) : vector, deque, list, forwad_list : �����͸� �������� �����ϸ�, Ư���� �����̳� ��Ģ�� ���� ���� �Ϲ����� �����̳�
//2. ���� �����̳�(associative container) : set, multiset, map, multimap : ordered associative container : �����͸� ���� ��Ģ�� ���� ����ȭ�Ͽ� �����ϰ� �����ϴ� �����̳�
//                                          Unordered_set..... :            Unordered associative container
//3. �����̳� �����(adapter container) : stack, queue, priority_queue : �����԰� ��Ἲ�� ���� �������̽��� ������ �������� ���� �����̳��� ����, 
//                                                                      ��, �ݺ��ڸ� �������� �����Ƿ� STL �˰��򿡼��� ����� �� �����ϴ�

using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vector;
        vector.push_back(10);
        vector.push_back(20);
        vector.push_back(-1);

        // �־��ִ� ������� ���, Sequence Container
        cout << "vector" << endl;
        for (int num : vector)
            cout << num << endl;


        std::set<int> set;
        set.insert(10);
        set.insert(20);
        set.insert(-1);

        // ���ĵ� ������� ���, Ordered Associative Container
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

        // ���������� �ȵ�, Unordered Associative Container
        cout << "unordered set" << endl;
        for (int num : uset)
            cout << num << endl;

        // ������ ����Ҷ����� �ٲ�

    }
    {
        cout << "=========" << endl;
        std::vector<int> nums{ 1, 2, 3, 4 };

        // ��ȸ ��� 1.
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << endl;
        }
        cout << endl;

        // ��ȸ ��� 2.
        for (int num : nums)
        {
            cout << num << endl;
        }
        cout << endl;

        // ��ȸ ��� 3.
        // ���ͷ����ʹ� ������ ������ ȣȯ�� ��
        for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) // [begin, end) : ����, ������
        {
            cout << *iter << endl;
        }
    }
    {
        cout << "=========" << endl;
        std::vector<int> nums{ 10, 1, 2, 3, 4 };

        // �˰����� ����Ͽ� ����
        // sort(start, end)�� �̿��Ͽ� [start, end) �� ������ �ִ� ����(element)�� ��������(default)���� �������ִ� �Լ�

        std::sort(nums.begin(), nums.end()); 
        
        for (int num : nums)
            cout << num << endl;
    }

    {
        // ��������
        cout << "=========" << endl;
        std::vector<int> nums{ 10, 1, 2, 3, 4 };
        sort(nums.begin(), nums.end(), std::greater<int>());
        for (int num : nums)
            cout << num << endl;
    }
}