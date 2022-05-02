//������ ����

#include <iostream>
#include <stdio.h>

using namespace std;


void swap0(int& px, int& py)
{
    int temp = px;
    px = py;
    py = temp;
}


struct Weapon
{
    int price;
    int power;
};


void upgrade(Weapon& weapon)
{
    weapon.power += 10;
    weapon.price += 10;
}

void print(const Weapon& weapon) // const�� ���� ���ο��� ���� ���� �ʴ´�
{
    cout << weapon.power << endl;
    cout << weapon.price << endl;
}

int squarev(int value)
{
    return value * value;
}

int squaref(const int& ref)
{
    return ref * ref;
}


int& func0()
{
    int num = 0;
    return num; // �����ϴ�. num�� ���� ��
}


int& func1(Weapon& weapon)
{
    return weapon.power;
}

int main()
{
    {
        int x = 10, y = 20;
        swap0(x, y);

        cout << "swap0 : " << x << endl;
        cout << "swap0 : " << y << endl;
    }

    {
        int x = 10, y = 20;
        // swap0(x, y); Ǯ���

        int& px = x;
        int& py = y;

        int temp = px;
        px = y;
        py = temp;

        cout << x << endl;
        cout << y << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        upgrade(weapon);
        print(weapon);
    }
    {
        int num;
        cin >> num; // num�� ���۷����� �Ѱ��ֱ� ������ scanfó�� num�� �ּҷ� �Ѱ����� �ʾƵ� �ȴ�
        int num2;
        cout << "==" << endl;
        scanf_s("%d", &num2);
    }
    {
        int nums[] = { 1, 2, 3, 4 };
        for (int num : nums)
        {
            num = 0; // nums�� ���� �� �ٲ��
        }

        for (int& num : nums)
        {
            num = 0; // nums�� ���� �ٲ��
        }

        for (const int& num : nums)
        {
            // num = 0; // nums�� ���� �ٲ� �� ����. ���۷����� �Ѱ�� ������ ���ɿ� �����ϴ�
        }
    }
    {
        int x = 10;
        cout << squarev(10.1) << endl;

        // ��� ������ ȣȯ�� �Ǵ� Ÿ���� �ӽ� ��ü�� �����ؼ� ����Ű�� �Ѵ�.
        // �� ��� 10.1�� double ���̰� squaref�� ref�� const int& �̱� ������
        // 10 �ӽ� ��ü�� ���������.
        // ��� ���� Ÿ���� �ִ��� �Ϲ� �� Ÿ�԰� ȣȯ�� �ǵ��� �ϰ� ���� �ǵ�
        cout << squaref(10.1) << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        func1(weapon) = 30; // �̷� �͵� �ȴ�
        cout << "weapon.power" << weapon.power << endl;
        cout << "weapon.price" << weapon.price << endl;

        weapon.power = 50;
        cout << "weapon.power" << weapon.power << endl;
        cout << "weapon.price" << weapon.price << endl;
    }
}