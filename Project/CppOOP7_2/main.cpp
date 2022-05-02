#include <iostream>
#include <typeinfo>

// Run Time Type Information�� ���ڷ� "����ð��� Ÿ�������� �ĺ�" ������ Ǯ���� �� �ֽ��ϴ�. 
// ��Ȯ�� �ǹ̴�, �����߿� ��� Ŭ���� Ÿ�� �������� ��ü�� �������µ� ������ �ΰ� �ֽ��ϴ�.
// �Ӽ� - ��Ÿ�� ���� ���� ��� - �ƴϿ� �ϰ��


using std::cout;
using std::endl;

class Parent
{
public: // �����Լ� ���̺��� �߿�
    virtual ~Parent() {}
};

class Child : public Parent
{

};


int main()
{
    Parent* p = new Child;

    // ��Ÿ�� ���� ���� ���(RTTI) ���� �ʴ� ��� �Ʒ��� �ڵ尡 ������ ���� �ʴ´�
    // ��Ÿ�ӿ� ���� Ÿ���� �˾ƾ��ϴ� ���
    cout << typeid(*p).name() << endl; // p�� Ÿ���� ��Ÿ�ӿ� �� �� �ִ�
    dynamic_cast<Child*>(p); // p�� ĳ���� ���δ� ��Ÿ�ӿ� �� �� �ִ�.(�ٿ� ĳ����)

    // RTTI �� �����Լ� ���̺� ������ �ִ�.
    // typeid, dynamic_cast �� virtual �Լ��� ���� ��� ����� �������� ���� �� �ִ�.
}