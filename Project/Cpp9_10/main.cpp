// �ζ���

#include <iostream>

using namespace std;

// �Լ� ȣ�� ����� �ٿ���
// ���� ���� ����� Ŀ�� �� ����
// �׻� �����Ϸ��� �ζ���ȭ �������� ����
inline int square(int x)
{
    return x * x;
}


// ��ó���� �̿��� �ζ���.
// ������ �߻��� �� ������ C++�� inline ������ ���
#define SQUARE(X) X*X


int main()
{
    int x = square(10);
    cout << x << endl;

    int y = 10;
    cout << SQUARE(++y) << endl; // �ǵ�ġ ���� ��� �߻�
}