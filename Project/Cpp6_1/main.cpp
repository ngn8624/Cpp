// �迭

#include <iostream>

using namespace std;

int main()
{
    {
        // bool�� 31�� �ִ� �迭
        bool attendanceBook[31];
        // bool, bool, bool ... bool (*31)

        attendanceBook[0];  // �迭�� �� �� �� (0)
        attendanceBook[30]; // �迭�� �� �� �� (SIZE - 1)

        attendanceBook[-1]; // ���� ���� ���� �ൿ, ���� (������ ��)
        attendanceBook[31]; // ���� ���� ���� �ൿ, ������ �ʰ� (������ ��)
    }
    {
        int arraySize;
        cin >> arraySize;

        // ������ �迭 ����� ������ �� ����
        //  bool attedanceBook[arraySize]; 
    }
    {
        // ����� �̿��� �迭 ������
        const int arraySize = 31;
        bool attendanceBook[arraySize];

        // ����� �ٲ� �� ����.
        //arraySize = 1;
    }
    {
        // ��ũ�θ� �̿��� �迭 ������
#define ARRAY_SIZE 31
        bool attendanceBook[ARRAY_SIZE];
    }
    {
        int nums[3];
        cout << nums[0] << endl; // �ʱ�ȭ�� �� �ż� ������ ���� ���´�.
    }
    {
        // �迭�� �� ����
        int nums[3];
        nums[0] = 10;
        nums[1] = 10;
        nums[2] = 10;
    }
    {
        // �ʱ�ȭ ����Ʈ
        int nums[3] = { 1, 2, 3 };
    }
    {
        int nums[3] = { 1 }; // 1 ���ķδ� 0���� ä������.
    }
    {
        int nums[]{ 1, 2 }; // ������ ��� ���� ������ �ʱ�ȭ �� �־��� ������ ���� �迭

        // �迭 ��ü�� ������
        cout << sizeof(nums) << endl;

        // �迭 ������ ����
        cout << sizeof(nums) / sizeof(int) << endl;
    }
    {
        // �迭 ��ȸ
        int nums[]{ 1, 2, 3, 4 };
        int size = sizeof(nums) / sizeof(int);
        for (int i = 0; i < size; ++i)
        {
            cout << nums[i] << endl;
        }

        int i = 0;
        while (i < size)
        {
            cout << nums[i] << endl;
            i++;
        }
    }
    {
        // �迭 �� �� ���ϱ� 
        int nums[3];
        int nSize = size(nums);
        cout << nSize << endl;
    }
    {
        // �迭 ����
        int nums0[3] = { 0, 1, 2 };
        int nums1[3];

        // ���� �� ��
        // nums1 = nums0;

        // ��ȸ�� �̿��� ����
        for (int i = 0; i < 3; ++i)
        {
            nums1[i] = nums0[i];
        }

        // �Լ��� �̿��� ����
        memcpy(nums1, nums0, sizeof(nums0));
        //cout << "nums1 : " << *nums1 << endl;
        memcpy(&nums1, &nums0, sizeof(nums0));
        //cout << "nums1 : " << *nums1 << endl;
        copy(nums0, nums0 + 3, nums1);
    }
    {
        // Ȧ���� �ݺ� �Ǿ� �ִ� �� ���� �� ���ϱ�
        int nums[] = { 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 1, 2, 3 };
        int result = 0;
        for (int i = 0; i < size(nums); ++i)
        {
            result ^= nums[i];
        }

        cout << result << endl; // 4
    }
    {
        int nums[]{ 5, 4, 3, 1, 7, 4, 3, 5, 6, 1, 2 };
        for (int i = 0; i < size(nums); ++i)
        {
            for (int j = 0; j < size(nums) - i - 1; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < size(nums); ++i)
        {
            cout << nums[i] << endl;
        }
    }
}