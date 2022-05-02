//값으로 전달

#include <iostream>

using namespace std;

void swap0(int px, int py)
{
    // 주소 출력
    //cout << "px addr : " << &px << endl;
    //cout << "py addr : " << &py << endl;

    int temp = px;
    px = py;
    py = temp;
}

struct Weapon
{
    int price;
    int power;
};

void upgrade0(Weapon weapon)
{
    weapon.power += 10;
    weapon.price += 10;
}

Weapon upgrade1(Weapon weapon)
{
    weapon.power += 10;
    weapon.price += 10;
    return weapon;
}

int main()
{
    {
        // swap을 inline으로 수행 // 함수 호출 시 별도로 분리된 위치의 레이블로 점프하여 실행되는 일반 함수와는 달리 호출 부분을 함수 전체 코드로 치환하여 컴파일한다.
        int x = 10, y = 20;
        cout << "x1 : " << x << endl;
        cout << "y1 : " << y << endl;

        int temp = x;
        x = y;
        y = temp;

        // 값이 바뀜
        cout << "x1 : " << x << endl;
        cout << "y1 : " << y << endl;
    }

    {
        int x = 10, y = 20;
        cout << "x2 : " << x << endl;
        cout << "y2 : " << y << endl;

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        swap0(x, y);// 값으로 전달했기 때문에 복사가 안 됨

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        // 값이 바뀌지 않음
        cout << "x2 : " << x << endl;
        cout << "y2 : " << y << endl;
    }
    {
        int x = 10, y = 20;
        cout << "x3 : " << x << endl;
        cout << "y3 : " << y << endl;

        // swap0 풀어쓰기
        int px = x;
        int py = y;

        int temp = px;
        px = py;
        py = temp;

        cout << "x3 : " << x << endl;
        cout << "y3 : " << y << endl;

        cout << "px3 : " << px << endl;
        cout << "py3 : " << py << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        upgrade0(weapon);

        // 실제로 업그레이드 되지 않음
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // upgrade(weapon); 풀어쓰기
        Weapon pWeapon = weapon;
        pWeapon.power += 10;
        pWeapon.price += 10;

        // 실제로 업그레이드 되지 않음
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // 값으로 전달하여 수정
        weapon = upgrade1(weapon);

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
}