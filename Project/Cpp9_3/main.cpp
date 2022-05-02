//������ ����

#include <iostream>

using namespace std;

void swap0(int px, int py)
{
    // �ּ� ���
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
        // swap�� inline���� ���� // �Լ� ȣ�� �� ������ �и��� ��ġ�� ���̺�� �����Ͽ� ����Ǵ� �Ϲ� �Լ��ʹ� �޸� ȣ�� �κ��� �Լ� ��ü �ڵ�� ġȯ�Ͽ� �������Ѵ�.
        int x = 10, y = 20;
        cout << "x1 : " << x << endl;
        cout << "y1 : " << y << endl;

        int temp = x;
        x = y;
        y = temp;

        // ���� �ٲ�
        cout << "x1 : " << x << endl;
        cout << "y1 : " << y << endl;
    }

    {
        int x = 10, y = 20;
        cout << "x2 : " << x << endl;
        cout << "y2 : " << y << endl;

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        swap0(x, y);// ������ �����߱� ������ ���簡 �� ��

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        // ���� �ٲ��� ����
        cout << "x2 : " << x << endl;
        cout << "y2 : " << y << endl;
    }
    {
        int x = 10, y = 20;
        cout << "x3 : " << x << endl;
        cout << "y3 : " << y << endl;

        // swap0 Ǯ���
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

        // ������ ���׷��̵� ���� ����
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // upgrade(weapon); Ǯ���
        Weapon pWeapon = weapon;
        pWeapon.power += 10;
        pWeapon.price += 10;

        // ������ ���׷��̵� ���� ����
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // ������ �����Ͽ� ����
        weapon = upgrade1(weapon);

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
}