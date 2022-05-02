//std array

#include <iostream>
#include <array>

using namespace std;

int main()
{
    {
        // int�� 5�� �ִ� C++ ��Ÿ�� �迭 ����
        // ���������� ���� �迭�� ������ �ִ�
        // �ʱ�ȭ�� �� �Ǿ� ������ ������ ��
        array<int, 5> arr0;

        // �⺻������ �ʱ�ȭ(int�� ��� �⺻���� 0)
        array<int, 5> arr1{};

        // arr2[0], arr2[1]�� ���� ���� �ǰ� ������ ������ �⺻������ �ʱ�ȭ(int�� ��� �⺻���� 0)
        array<int, 5> arr2{ 0, 1 };
    }
    {
        array<int, 5> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        //cout << arr[-1] << endl; // release ���� �� ���� �߻� �� �� �� ����(���� ���� ���� �ൿ)
        //cout << arr.at(-1) << endl; // ���� ��� �� ���� ���� (std::out_of_range)
    }
    {
        // �迭 ������ ���ϱ�
        int arr0[] = { 1, 2, 3 };
        cout << sizeof(arr0) / sizeof(int) << endl;
        cout << sizeof(arr0) / sizeof(arr0[0]) << endl;

        array<int, 3> arr1 = { 1, 2, 3 };
        cout << "arr1.size() : " << arr1.size() << endl;
    }
    {
        // �迭�� ���� ��, ���� �� ���� ���ϱ�
        array<int, 3> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        cout << "arr.front() : " << arr.front() << endl;

        cout << arr[arr.size() - 1] << endl;
        cout << arr.back() << endl;
    }
    {
        array<int, 5> arr0{ 1, 2, 3, 4, 5 };
        array<int, 5> arr1{ 5, 4, 3, 2, 1 };

        // ��ȯ
        arr0.swap(arr1);
        cout << "arr0[0] :  "  << arr0[0] << endl;


        // ���� ����
        arr0 = arr1;

        // �� ����� ����
        if (arr0 == arr1)
        {

        }
        if (arr0 > arr1)
        {

        }
        if (arr0 < arr1)
        {

        }
    }
    {
        array<int, 5> arr{ 1, 2, 3, 4, 5 };
        cout << arr.data()[0] << endl; // ���� ���� �迭�� ����
    }
}