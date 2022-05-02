//������ - �迭���� ����

#include <iostream>

using namespace std;

int main()
{
    {
        int nums[] = { 1, 2, 3 };
        cout << nums << endl; // �ּ� ���

        int* pNums = nums; // �迭�� �����ͷ� decay(��ȯ�� ����)

        cout << sizeof(nums) << endl;
        cout << sizeof(pNums) << endl; // ���� �Ӽ��� ����

        // �� ���� �ּ� ��
        cout << nums << endl;       // int*, decay �Ǿ���.
        cout << &nums << endl;      // int (*)[3], �� �༮�� Ÿ���� �ٸ�
        cout << &nums[0] << endl;   // int*
        cout << endl;

        cout << typeid(1).name() << endl;       // int
        cout << typeid(nums).name() << endl;    // int [3], typeid�� ����ϸ� decay���� ���� ����� �� Ÿ���� ����
        cout << typeid(&nums).name() << endl;   // int (*)[3]
        cout << typeid(&nums[0]).name() << endl;// int*
    }
    {
        int nums[] = { 1, 2, 3 };
        int* pNums = nums;

        cout << pNums[0] << endl;   // 1
        cout << pNums[1] << endl;   // 2
        cout << pNums[2] << endl;   // 3

        cout << pNums << endl;      // base address + sizeof(int) * 0
        cout << pNums + 1 << endl;  // base address + sizeof(int) * 1
        cout << pNums + 2 << endl;  // base address + sizeof(int) * 2

        cout << *pNums << endl;
        cout << *(pNums + 1) << endl;
        cout << *(pNums + 2) << endl;
    }
    {
        int nums[] = { 1, 2, 3 };
        int* pNums = nums;

        cout << *pNums << endl; // nums[0]
        pNums++;
        cout << *pNums << endl; // nums[1]
    }
}