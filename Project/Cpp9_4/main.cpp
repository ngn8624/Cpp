//�ּҷ� ����

#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

void swap0(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void scan(int* n)
{
    *n = 10;
}

struct Weapon
{
    int price;
    int power;
};

void upgrade(Weapon* pWeapon)
{
    (*pWeapon).price += 10;
    pWeapon->power += 10;
}


void print(const Weapon *weapon)
{
    cout << weapon->price << endl;
    cout << weapon->power << endl;
}

void func0(int nums[4]) // ������ �������̴�. �迭�� �ƴ�
{
    cout << typeid(nums).name() << endl;

    for (int i = 0; i < 4; ++i)
    {
        int num = nums[i];
        cout << num << endl;
    }
}

void func1(int argc, char** argv)
{

}

void func2(int argc, char(*argv)[5])
{

}

int main(int argc, char* argv[])
{
    {
        // ������ ����
        int x = 10;
        int* px = &x;

        cout << x << endl;
        cout << *px << endl;

        x = 20;
        cout << x << endl;
        cout << *px << endl;

        *px = 30;
        cout << x << endl;
        cout << *px << endl;
    }
    {
        int x = 10, y = 20;
        cout << x << endl;
        cout << y << endl;

        // �����ͷ� �ϴ� ��ȯ�ȴ�
        swap0(&x, &y);

        cout << x << endl;
        cout << y << endl;
    }
    {
        int x = 10, y = 20;
        cout << x << endl;
        cout << y << endl;

        //swap0(&x, &y); Ǯ�� ����
        // �ּ� ���� ���� �ȴ�
        int* px = &x;
        int* py = &y;

        int temp = *px;
        *px = *py;
        *py = temp;

        cout << x << endl;
        cout << y << endl;
    }
    {
        int i;
        scanf("%d", &i);  // �ּҰ����� �Ѱ���� ����, i�� �Լ� ���ο��� �����ϱ� ����
    }
    {
        int n = 0;
        scan(&n);
        cout << n << endl; // ����ȴ�. ������ �ѱ�� ���� �� ��
    }
    {
        Weapon weapon{ 10, 20 };
        upgrade(&weapon);

        cout << weapon.price << endl;
        cout << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        // ���������� const �����ͷ� �޾ұ� ������
        // ȣ���ϴ� ���忡���� �ٲ��� �ʾ��� �Ŷ�� ������ �� �ִ�.
        print(&weapon);
    }
    {
        int nums[4] = { 1, 2, 3, 4 };
        func0(nums);
    }
    {
        // ������ argv�� char** �̴�. �迭�� �ƴϴ�
        cout << typeid(argv).name() << endl; 
    }
    {
        func1(argc, argv);

        char strs[][5] = { "abcd", "efgh" };
        //func1(2, strs);
        func2(2, strs);
    }
}

// �޸� ���
// char**
// |�ּ�|�ּ�|�ּ�|�ּ�|
//   |
//   -> "cpp9_4.ext"

// chat[2][5]
// |"abcd\0"|"efgh\0"|