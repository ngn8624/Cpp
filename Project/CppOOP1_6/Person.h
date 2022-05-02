#pragma once
#include <iostream>

using namespace std;


class Person
{
private:
    float weight;
    float height;
    string name;

public:
    Person(float weight, float height, const string& NAME)
        : weight(weight), height(height), name(NAME)
    {
        // �̸��� ���� ��� this�� ���� ����
        weight; // �Ķ���� weight
        this->weight; // ��� ���� weight


        // �̸��� ���� �ʱ� ������ this ���� ����
        name; // ��� ���� name 
        this->name; // ��� ���� name
    }

    void loseWeight(float weight)
    {
        // �Ʒ��� ���� ����
        this->height;
        height;

        this->height -= weight;
        if (this->weight < 0)
            this->weight = 0;
    }

    float getBMI()
    {
        float s = weight / (height * 100 * height * 100);
        return s;
    }


    Person& complete(Person& person)
    {
        if (this->getBMI() < person.getBMI())
            return *this; // this�� ��ȯ
        else
            return person;
    }


    void doCeremony()
    {
        cout << name << " win!!" << endl;
    }
};


void personFunc()
{
    Person david(33.3f, 172.3f, "david");
    Person daniel(58.3f, 172.3f, "daniel");

    daniel.complete(david).doCeremony();
}
