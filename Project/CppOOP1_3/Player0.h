#pragma once
#include <iostream>

using namespace std;


class Player0
{
private:
    int _health;
    int _power;

public:
    Player0()
    {
        // ����Ʈ ������(�Ķ���Ͱ� �� ���� ���� ������)
        // �� ���� �����ڵ� �־����� �ʴ´ٸ� �����Ϸ��� �Ͻ������� ������ش�
        _health = 100;
        _power = 50;
        cout << "Player0 " << _health << ", " << _power << endl;
    }
    Player0(int health, int power)
    {
        _health = health;
        _power = power;

        cout << "Player0 " << _health << ", " << _power << endl;
    }
};

void player0()
{
    Player0 player0(100, 50);
    Player0 player1 = Player0(300, 150);
    Player0* player2 = new Player0(400, 250);


    Player0 player3;
    Player0 player4 = Player0();
    Player0* player5 = new Player0();
}
