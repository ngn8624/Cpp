// const

#include <iostream>

using namespace std;


class Person
{
private:
    const string _name = "david"; // const ��� ������ �ζ������� �ʱ�ȭ ����
    float _weight;
    float _height;

public:
    Person(const string& name, float weight, float height)
        : _name(name), _weight(weight), _height(height) // const ��� ������ ��� �ʱ�ȭ ����Ʈ���� �ʱ�ȭ ����
    {

    }

    float getWeight(/* const Person* this */) const
    { 

        // const�� ���� ��� �Լ������� this �������� Ÿ��
        // const Person*

        return _weight;
    }

    float getHeight(/* Person* this */)
    {
        // this �������� Ÿ��
        // Person*

        return _height;
    }
};
int main()
{
    const Person person("David", 75.f, 181.f);
    cout << person.getWeight() << endl; // getWeight�� const Person*�� �Ѿ��.
    //cout << person.getHeight() << endl; // getHeight�� const Person*�� �ѱ� �� ����.


    Person *person0 = new Person("Daniel", 57.f, 175.f);
    const Person* person1 = person0; // ��ȯ ����
    //Person* person2 = person1; // ��ȯ �Ұ���
}