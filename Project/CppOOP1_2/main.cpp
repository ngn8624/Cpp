
//Ŭ������ ��ü

#include <iostream>

using namespace std;

class Player0
{
    int health;
    int power;
};

class Player1
{
public: // ���� ������
    int headlth;
    int power;
};


class Player2
{
public:
    int health;
private:
    int power;
};


class Player3
{
public:
    int _health;
    int _power;
    string _name;

public:
    void attack(Player3& target)
    {
        cout << "Attack " << _name << "->" << target._name << endl;
        target.damaged(_power);
    }

    void damaged(int power)
    {
        _health -= power;
        if (_health <= 0)
            cout << "Died" << _name << endl;
    }
};


class Player4
{
private:
    int _health;
    int _power;
    string _name;

public:
    Player4(int health, int power, string name)
    {
        _health = health;
        _power = power;
        _name = name;
    }

    void attack(Player4& target)
    {
        cout << "Attack " << _name << "->" << target._name << endl;
        target.damaged(_power);
    }

    void damaged(int power)
    {
        _health -= power;
        if (_health <= 0)
            cout << "Died" << _name << endl;
    }
};

int main()
{
    {
        // �⺻������ private
        //Player0 player0{ 100, 200 }; // �� ��

        //Player0 player0;
        //player0.health = 100; // �� ��
    }
    {
        // public���� �������� ����
        Player1 player1{ 100, 200 };
        player1.headlth = 200;
    }
    {
        Player2 player2;
        //player2.power = 300; // �� ��, private
    }
    {
        Player3 david{ 200, 100, "David" };
        Player3 daniel{ 200, 100, "Daniel" };
        
        daniel._health -= 300;
        // daniel�� health�� 0 ���ϰ� �������� �׾��ٴ� �޽����� �߻����� ����
        // ��� ������ �����ϰ� �Ǹ� �̷��� ��ü�� ���Ἲ�� ������ ���°� �߻��� ���ɼ��� ������
    }
    {
        Player4 david{ 200, 100, "David" };
        Player4 daniel{ 200, 100, "Daniel" };
        
        //daniel._health -= 300; // �Ұ����ϴ�
        david.attack(daniel);
        david.attack(daniel);
    }
}

