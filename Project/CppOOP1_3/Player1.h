#pragma once
#include <iostream>

using namespace std;


class Player1
{
private:
    int _health;
    int _power;

public:
    Player1(int health = 100, int power = 50) // ����Ʈ �Ķ���͸� �̿��Ͽ� �ߺ� ����
    {
        _health = health;
        _power = power;

        cout << "Player1 " << _health << ", " << _power << endl;
    }
};

void player1()
{
    Player1 player0(100, 50);
    Player1 player1 = Player1(300, 150);
    Player1* player2 = new Player1(400, 250);


    Player1 player3;
    Player1 player4 = Player1();
    Player1* player5 = new Player1();


    Player1 player6(300); // health������ �ʱ�ȭ �� �� ����
}
