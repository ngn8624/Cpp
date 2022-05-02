#include <iostream>
#include <type_traits>

// ���ø��� �̿��Ͽ� 
// type_traits ���̺귯��
// ���ø� ��Ÿ �Լ� ����, Ÿ�� �ڵ鸵
// ���ø� ��Ÿ �Լ���, ��� �Լ��� �ƴ����� ��ġ �Լ� ó�� �����ϴ� ���ø� Ŭ�������� �̾߱� �մϴ�. 
// �̵��� ��Ÿ �Լ��� ������ ������ �Լ����� ���� ���� ������ ����������, 
// ��Ÿ �Լ��� Ÿ�Կ� ���� ������ �����Ѵٴ� ���� ���� �ٸ��ϴ�.
// ���ø� : �����Ͽ� Ÿ�Կ� ���� ���𰡸� �Ѵ�.
// ���� �߿��� ���� ���ø� ��Ÿ �Լ����� ������ �Լ��� �ƴ϶�� �� 
// () ��ſ� <> �� ���� �Լ� ���ڰ� �ƴ� ���ø� ���ڸ� ����
// ��) is_void Ŭ����
// is_class, is_integer, is_


using std::cout;
using std::endl;


template<typename T> // 
struct is_pointer
{
    static const bool value = false;
};

// ���ø� Ư��ȭ, �κ� Ư��ȭ
template<typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};

///////////////////////////////


template<typename T>
void foo(T t)
{
    cout << is_pointer<T>::value << endl;
}

////////////////////////////////////////

template<typename T>
struct remove_pointer
{
    using type = T;
};

template<typename T>
struct remove_pointer<T*>
{
    using type = T;
};

///////////////////////////////////////////////////


template<typename T>
struct add_pointer
{
    using type = T*;
};

template<typename T>
struct add_pointer<T&>
{
    using type = T*;
};

int main()
{
    cout << std::boolalpha;
    //{
    //    // ������ Ÿ���� Ÿ�Կ� ���õ� ����� ����
    //    //cout << "int* : " << std::is_pointer<int*>::value << endl;
    //    //cout << "int : " << std::is_pointer<int>::value << endl;


    //    //cout << "struct is_pointer : " << is_pointer<int*>::value << endl;
    //    //cout << "struct is_pointer : " << is_pointer<int>::value << endl; // ���ø� Ư��ȭ�� ���� true

    //    // �� ����ұ�?
    //    // ���ø� ����, �Ű�����(T t)�� � Ÿ������ �𸦶�
    //    int num = 0;
    //    int* pNum = &num;

    //    foo(num);
    //    foo(pNum);

    //    cout << "=======" << endl;
    //}
    //{
    //    int num = 0;
    //    std::add_pointer<int>::type pNum = &num;
    //    //std::add_pointer_t<int> pNum1 = &num; //�� �Ʒ� ����
    //    *pNum = 10;
    //    cout << "*pNum  :  " << *pNum << endl;
    //    foo(pNum); // true 

    //    std::remove_pointer<int*>::type n = *pNum;  // integer
    //    cout << "n  :  " << n << endl;
    //    foo(n); // false

    //    cout << is_pointer<remove_pointer<int*>>::value << endl; // false

    //    cout << "=======" << endl;
    //}
    {
        add_pointer<int>::type num0;
        cout << "num0 : " << typeid(num0).name() << endl;

        add_pointer<int*>::type num1;
        cout << "num1 : " << typeid(num1).name() << endl;

        add_pointer<int&>::type num2; // Ư��ȭ
        cout << "num2 : " << typeid(num2).name() << endl;
    }
}