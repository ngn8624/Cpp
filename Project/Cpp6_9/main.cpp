//range-based- for

#include <iostream>
#include <array>

using namespace std;

struct Person
{
    float weight;
    float height;
};

int main()
{
    {
        // C��Ÿ�� �迭, ���� ��� ���
        int nums[5] = { 1, 2, 3, 4, 5 };
        for (int i = 0; i < 5; ++i)
        {
            cout << nums[i] << endl;
        }

        // Range based for
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
    {
        // C++ ��Ÿ�� �迭, ���� ��� ���
        array<int, 5> nums = { 1, 2, 3, 4, 5 };
        for (int i = 0; i < 5; ++i)
        {
            cout << "���� ��� ��� : " << nums[i] << endl;
        }

        // Range based for
        for (int num : nums)
        {
            cout << "Range based for : " << num << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // ��ȸ�ϸ鼭 ����
        for (int i = 0; i < 2; ++i)
        {
            persons[i].weight = 0.f;
        }

        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // ��ȸ�ϸ鼭 ����
        for (Person person : persons)
        {
            person.weight = 0.f;
        }

        // ���� ���� ����
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // ��ȸ�ϸ鼭 ����, ����(���۷���)
        for (Person& person : persons)
        {
            person.weight = 0.f;
        }

        // ���� ��
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        for (int i = 0; i < 2; ++i)
        {
            cout << &persons[i] << endl;
        }

        cout << endl;
        for (Person person : persons)
        {
            cout << &person << endl; // �ּ� ���� �ٸ���
        }

        cout << endl;
        for (Person& person : persons)
        {
            cout << &person << endl;
        }
    }
    {
        int nums[3] = { 1, 2, 3 };
        for (int num : nums)
        {
            num = 0; // �� �ٲ�
        }
        for (int num : nums)
        {
            cout << num << endl;
        }

        for (int& num : nums) // ����(���۷���)
        {
            num = 0; // �ٲ�
        }
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
}