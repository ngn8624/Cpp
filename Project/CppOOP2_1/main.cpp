// 산술 연산자 오버로딩 / 비교 연산자 / 관계 연산자

#include <iostream>
#include "vector.h"
#include "vectorf.h"
#include "vectori.h"


using namespace std;




int main()
{
    const Vector v0{ 0, 1, 2 };
    const Vector v1{ 1, 2, 3 };

    const Vector v2 = v0 + v1;  // Vector v2 = v0.operator+(v1);
    const Vector v3 = -v1; // Vector v3 = v1.operator-();

    

    Vector v4 = +v0;
    Vector v5 = -v0;
    Vector v6 = v0 + v1;
    Vector v7 = v0 - v1;
    float v8 = v0 * v1;
    Vector v9 = v0 * 3.0f;
    Vector v10 = v0 / 3.0f;
    Vector v11 = ++v10;
    Vector v12 = v10++;
    Vector v13 = --v10;
    Vector v14 = v10--;

    3.0f * v1; // Vector operator*(float v0, const Vector& v1) 전역함수

    VectorF vf{ 0, 1, 2 };
    VectorI vi{ 0, 1, 2 };

    vf + vi;

    v0.print();
    v1.print();
    v2.print();
    v3.print();
    v4.print();
    v6.print();
    v7.print();
    cout << v8 << endl;
    v9.print();
    v10.print();
    v11.print();
    v12.print();
    v13.print();
    v14.print();
    //vf.print();
    //vi.print();


}
