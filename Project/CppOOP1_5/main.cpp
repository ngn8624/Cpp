// 선언과 정의의 분리/ 전방 선언


#include <iostream>
#include "function.h"
#include "Villiage.h"
#include "person.h"

using namespace std;


void foo1(); // util1.cpp

int main()
{
    func();
    foo1();

    Villiage v;
    v.add(new Person(10, 10, "david"));
}
