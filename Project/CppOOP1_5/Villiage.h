#pragma once

#include <vector>

//#include "person.h" // ��� ���� include�� �ּ�ȭ ����


class Person; // ���� ����
class Villiage
{
private:
    // ���� ������ ���ؼ��� �����ͳ� ���۷��� ���̾�� ��.
    // �����ͳ� ���۷����� ����� �˷����ֱ� ����
    std::vector<Person*> persons;
public:
    void add(Person* person);
};

 