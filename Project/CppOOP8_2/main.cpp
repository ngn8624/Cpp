#include <iostream>
#include <vector>
#include <deque>
#include <array>
// std:: array 
// std::array ����� ����� ���� �迭(int arr[] = {1,2,3,4,5};)�� ��ü�ϴ� �Ǹ��� ����̴�. 
// ����� ���� �迭���� �޸𸮸� �� ������� ������ �Լ��� ���޽� �����ͷ� �� ��ȯ���� �ʴ� ������ �ְ�, 
// ������ ������ �� �迭 ���̸� ��������� �����ؾ� �Ѵٴ� �ͻ��̴�.

// std::vector
// �������� ���Ҹ� �߰��� �� ������ ũ�Ⱑ �ڵ����� �þ��.
// ���Ҵ��� �Ͼ�� �����Ƿ� ����ϱ� ���� ũ�⸦ �˼� �ִٸ� reserve()�� capacity�� Ȯ���ϰ� �������.

// deque
// deque�� �߰��� ��Ҹ� ��������� �ð����⵵ ����.
// �迭�� ������ ������ ������

using std::cout;
using std::endl;


int main()
{

    //{
    //    std::vector<int> vec{ 1, 2, 3 };
    //    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    //    {
    //        cout << *iter << endl;
    //    }
    //    cout << "vector========" << endl;
    //}
    {
        std::vector<int> vec{ 0,1, 2, 3,4,5,6,7,8,9 };
        vec.push_back(10);
        for (int num : vec)
        {
            cout << &vec[num] << endl;
        }
        std::vector<int> vec1;
        memcpy(&vec1, &vec, sizeof(vec));
        cout << "============" << endl;
        for (int num : vec1)
        {
            cout << num << endl;
        }

        cout << "============" << endl;
        std::array<int,10> arr1 = { 0,1, 2, 3,4,5,6,7,8,9 };
        for (int num : arr1)
        {
            cout << &arr1[num] << endl;
        }
        int arr[10] = { 0,1, 2, 3,4,5,6,7,8,9 };
        
        int a = 1;
        a = 2;
    }
    {
        //std::vector<int> vec{ 1, 2, 3 };
        //std::vector<int>::iterator iter = vec.begin();

        //int& num = vec[0];
        //vec[0] = 10;
        //cout << *iter << endl;
        //cout << num << endl;
        //cout << "iterator========" << endl;
        ////// ���� �߻� (�� �Ʒ� ��������) // ���Ҵ�
        //vec.reserve(vec.capacity() + 1);
        //vec[0] = 100;
        //cout << *iter << endl;
        //cout << num << endl;
        //cout << "========" << endl;
    }
    {
        cout << "========" << endl;
        // ���� �߻� (�� �Ʒ� ��������)
        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        int* num = &vec[0];

        // vector�� ����� ũ�� ��ŭ Ŀ�� �� �� �� �ִٸ� reserve�� �̸� ������
        vec.reserve(vec.capacity() + 1);

        // ���� �ּҰ� �ٸ���.
        cout << num << endl;
        cout << &vec[0] << endl;

        // ��ü�� �ð� ���⵵ O(1), ���Ҵ� �� ���� ������ ���� (�ð� ���⵵ : ????) 
        vec.push_back(10);

        // �ð� ���⵵ O(���)(1)
        vec.pop_back(); // ���� ���� �ڿ� ���� ����

        // ���� �տ� �����߱� ������  O(���)(n), �ڷ� �� �и�
        vec.insert(vec.begin(), 10);

        for (int num : vec)
        {
            cout << "num : " << num << endl;
        }

        cout << vec.size() << endl;
        cout << sizeof(vec) << endl;

        cout << "========" << endl;
        //
        // capacity�� vector�� ���(element)���� ���� �� �ִ� �޸𸮰� �Ҵ�Ǿ� �ִ� ������ �뷮�̴�.
        // size�� ���� ��ȿ�� ���(element)���� ����

        // [1, 2, 3, ?] 
        // size = 3
        // capacity = 4

        // push_back(4)
        // [1, 2, 3, 4]
        // size = 4
        // capacity = 4

        // push_back(5)
        // [1, 2, 3, 4, 5, ?, ?, ?] // �迭�� ���Ҵ�
        // size = 4
        // capacity = 8
    }
    {
        //������ �����ϸ� ���Ҵ� ���Ͼ
        cout << "reserve()_first" << endl;

        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        vec.reserve(vec.capacity() + 1);
        int* num = &vec[0];

        // ���� �ּҰ� ����
        cout << num << endl;
        cout << &vec[0] << endl;
    }
    {
        cout << "deque" << endl;

        std::deque<int> nums;

        // ��ü�� O(1)
        nums.push_front(1);

        cout << nums[0] << endl;
        cout << &nums[0] << endl;

        // ��ü�� O(1)
        nums.push_back(2);

        cout << nums[1] << endl;
        cout << &nums[1] << endl; // cout << &nums[2] << endl; �ּҰ���

        nums.push_front(10);
        cout << nums[2] << endl;
        cout << &nums[2] << endl;

        // �迭�� ������ ������ �ִ�.
        // push_back
        // [0]

        // push_front
        // [1] [0]
        // push_front �� ������ ����� ���ؼ� �迭�� �� �����.
        // [?,?, ?,10] [1,2,3,]

    }



    return 0;
}
