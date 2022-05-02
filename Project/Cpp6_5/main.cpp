//struct

#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    struct Person
    {
        float height;
        float weight;
        char name[10];
        short grade;
    };

    {
        Person person;
        person.height = 174.2f;
        person.weight = 67.8f;
        person.grade = 1;

        strcpy_s(person.name, 10, "David");

        cout << person.height << endl;
        cout << person.weight << endl;
        cout << person.grade << endl;
        cout << person.name << endl;
    }
    {
        Person person{ 174.2f,67.8f, "David", 1 };

        cout << person.height << endl;
        cout << person.weight << endl;
        cout << person.grade << endl;
        cout << person.name << endl;
    }
    {
        // �̸����� �ʱ�ȭ. C++ 2x �̻�
        //Person person{ .height = 174.2f, .weight= 67.8f, .name= "David", .grade=1 };

        //cout << person.height << endl;
        //cout << person.weight << endl;
        //cout << person.grade << endl;
        //cout << person.name << endl;
    }
    {
        // struct �� ��� ������ ������
        struct EyeSight
        {
            float left;
            float right;
        };
        struct Person
        {
            float height;
            float weight;
            char name[10];
            short grade;
            EyeSight eyeSight;
        };

        Person person{ 174.2f, 67.3f, "David", 1, {1.1f, 1.0f} };

        cout << person.height << endl;
        cout << person.weight << endl;
        cout << person.grade << endl;
        cout << person.name << endl;
        cout << person.eyeSight.left << endl;
        cout << person.eyeSight.right << endl;

        // �迭�� ���ο� �־ ���簡 ��
        Person person1 = person;

        // �񱳴� �� ��
        //person == person1;
    }
    {
        Person persons[5];
        persons[0].grade = 1;

        cout << persons[0].grade << endl; // 1

        Person person1 = persons[1]; // person0 �� persons[1]�� �ƴ϶� ������ ���̴�.
        person1.grade = 5; // ���纻�� grade�� ����

        cout << person1.grade << endl;    // 5
        cout << persons[1].grade << endl; // ���� ���� ���� �ൿ

        Person &person2 = persons[2]; // ���纻�� �ƴ� ���۷���(���� ���)
        person2.grade = 5; 

        cout << person2.grade << endl;    // 5
        cout << persons[2].grade << endl; // 5
    }
    {

        cout << "=========================== << endl;
        // strcut �� ������
        struct Person0
        {
            float height;   // 4
            float weight;   // 4
            char name[10];  // 10
            short grade;    // 2
        };
        cout << sizeof(Person0) << endl;
        // height, weight, name, grade
        //   4   ,   4   ,  10 ,   2

        struct Person1
        {
            float height;   // 4
            short grade;    // 2
            float weight;   // 4
            char name[10];  // 10
        };
        cout << sizeof(Person1) << endl;
        // height, grade, weight, name
        //    4  ,  2(2),    4  ,  10  (2)  = 24
        
        struct alignas(16) Person2
        {
            float height;   // 4
            short grade;    // 2
            float weight;   // 4
            char name[10];
        };
        cout << alignof(Person0) << endl;
        cout << alignof(Person1) << endl;
        cout << alignof(Person2) << endl;
    }
}