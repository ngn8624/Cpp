#include <iostream>

using std::cout;
using std::endl;


enum Unscoped
{
    A, B
};

enum class Scoped2
{
    C, D
};

enum class Scoped : long long
{
    A, B = 10000000000
};

///////
//std::ostream& operator<<(std::ostream& os, const Scoped& value)
//{
//    // underlying_type  �� ���� Ÿ���� �˾Ƴ�
//    using t = typename std::underlying_type<Scoped>::type;
//    cout << "static_cast<t>(value) : " << static_cast<t>(value);
//    return os;
//}

///////
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const T& value)
//{
//    // underlying_type  �� ���� Ÿ���� �˾Ƴ�
//    using t = typename std::underlying_type<Scoped>::type;
//    cout << "static_cast<t>(value) : " << static_cast<t>(value);
//    return os;
//}



//////
template<typename T>
struct is_scoped_enum
{
    // enum �ε� int�� ��ȯ�� ���� ������ Scoped
    static const bool value = std::is_enum<T>::value && !std::is_convertible<T, int>::value;
};

// SFINAE(Substitution failure is not an erro) �̿�
template<typename T, typename std::enable_if<is_scoped_enum<T>::value, int>::type = 0>
std::ostream& operator<<(std::ostream& os, const T& value)
{
    // underlying_type  �� ���� Ÿ���� �˾Ƴ�
    using t = typename std::underlying_type<T>::type;
    cout << static_cast<t>(value);
    return os;
}





int main()
{
    cout << std::boolalpha;


    ////
    //cout << A << endl;
    //cout << Unscoped::A << endl; // Unscoped:: �����൵ �ȴ�

    ////
    //cout << Scoped2::C << endl;

    ////
    //cout << Scoped::B << endl;

    ////
    //cout << "==========" << endl;

    ////
    //cout << static_cast<int>(Scoped::B) << endl; // overflow
    ////

    cout << static_cast<std::underlying_type<Scoped>::type>(Scoped::B) << endl;
    cout << Scoped::A << endl;
    cout << Unscoped::B << endl;

}