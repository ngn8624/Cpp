// 포인터 - 문자열과의 관계
// 상수란 변하지 않는 값을 말합니다. 상수에는 리터럴 상수와 기호 상수가 있습니다. 상수와 변수의 차이점은 상수는 상수값이 변할 수 없지만, 변수는 변할 수 있습니다
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    {
        // 문자 배열(문자열)을 포인터로 가리킴
        char str0[] = "abcd";
        char* str1 = str0;

        cout << str0 << endl;
        cout << str1 << endl;
    }
    {
        // 문자열 리터럴
        const char* str2 = "hello";
        cout << "str2 " << str2 << endl;
        cout << "*str2 " << *str2 << endl;

        cout << typeid("hello").name() << endl;
    }
    {
        char str0[100] = "abcd";
        char* str1 = str0;
        const char* str2 = "hello";

        cout << strlen(str2) << endl;
        strcpy(str0, str2);
        cout << str0 << endl;

        cout << strcmp(str0, str2) << endl;
    }
}