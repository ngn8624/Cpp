//import std.core;
//import std.memory;
//import std.threading;
import swap; 
#include < iostream>

// command
// cl /experimental:module /std:c++latest /c swap.ixx
// swap.ifc ����
// swap.obj ����
// cl /experimental:module /std:c++latest main.cpp swap.obj
// .\main.exe
int main()
{
    // 
    // module�� include �� ���� �������� ������
    // - �Ź� ����� �ҽ� ���Ͽ� ����/�ٿ��ֱ� �ϴ� ��
    // - pragam, ifndef ���� ������� �ʰ� ��
    // - ��� ���ο��� �ǵ����� ���� �͵鿡 ���� ����
    // ��) chrono�� chrono�� �ִµ� mutex�� ��Ŭ������൵ �����´�.
    // ���� �ٸ� ����� �Ȱ��� ��ũ�θ� �������� �ڿ� ��Ŭ���Ȱ� �������� �ȴ�.
    // �������̶�... ���������� �ʴ�.

    // �ν��緯 -> ����������� -> ��� -> ������
    // �Ӽ� - c++ �ֽ�
    // �Ӽ� - c/c++ - �ڵ���� - dll/md 
    // �Ӽ� - c/c++ - ��� - ������


    /*std::cout << "a" << std::endl;

    std::vector<int> nums{ 1, 2, 3 };
    for (auto num : nums)
    {
        std::cout << num << std::endl;
    }

    std::thread th([] {
        std::cout << "async" << std::endl;
        });

    std::unique_ptr<int> i = std::make_unique<int>(10);
    std::cout << *i << std::endl;
    th.join();*/

    int x = 10, y = 20;
    swap(x,y);
    std::cout << x << std::endl;
    std::cout << y << std::endl;

}
// ��������
//�ڿ����� ������ ����
// RAII  �ڿ��� ȹ���� �ʱ�ȭ
// �ڿ� ������ ���ÿ� �Ҵ��� ��ü�� ���� ����
// ������ '��ü' �� ���� �ڽ��� �Ҹ� �� �� �ڽ��� ����Ű�� �ִ� �����͵� ���� delete �ϰ� �ϸ� �˴ϴ�
// �ڿ� (�� ��� �޸�) ������ ������ ��ü (������ ��ü) �� ���� �����ϰ� �Ǵ� ���Դϴ�.
// �̷��� �ȶ��ϰ� �۵��ϴ� ������ ��ü�� ����Ʈ ������(smart pointer)
// auto_ptr : unique_ptr , shared_ptr 
// std::unique_ptr<B> p(new B());
// ������ �÷��� (Garbage Collector - GC) �� �Ҹ��� �ڿ� û�ұⰡ �⺻������ ����
// ������ �÷����� ������ ���α׷� �󿡼� �� �̻� ������ �ʴ� �ڿ��� �ڵ����� ����