// ����
#include <iostream>
#include <string>

#define SQUARE(X) X*X

using namespace std;


int sum(int, int);
int main(int argc, char* argv[])
{
    SQUARE(1);

    int total = 0;
    for (int i = 0; i < argc; ++i)
    {
        string arg(argv[i]);
        int num = stoi(arg);
        total = sum(total, num);
    }
    cout << total << endl;
}


// 1. ����
// 2. Developer �Է�
// 3. Developer Command Prompt for VS 2019 ����
// 4. cd �� �̿��Ͽ� main.cpp ������ ��η� �̵�


// ������ �� ����
// 1. cl main.cpp util.cpp
// 2. main.exe 10 20 30
// 3. del *.obj
// 4. del main.exe


// 1. cl main.cpp
// �� ��, sum �Լ��� ã�� �� ����, obj ������ ���� ��

// 1. cl util.cpp
// �� ��, main �Լ��� ã�� �� ����, obj ������ ���� ��


// 1. cl main.cpp util.cpp /c
// main.obj, util.obj ������ ���� �Ǿ�����. /c�� �����ϸ� �ϰڴٴ� �ǹ�
// 2. link main.obj util.obj
// main.exe ����

// obj�� �����Ǿ��ٴ� ���� �������� �Ǿ��ٴ� ���� �ǹ�
// ������ �� ��ŷ ������ �ִµ� main.cpp, util.cpp�� ���� ������ ������ �ϸ� ��ŷ���� ����

// 1. link main.obj 
// sum �Լ��� ã�� �� ����



// 1. cl main.cpp /P
// main.i ����, ��ó���� ��
// iostream ���ϵ��� main.cpp �� �ٿ����� ����� ����
// SQUARE�� ���� ��ó�� ��ũ�ε� ��ü�� ��
