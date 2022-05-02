// ������ - ���� �Ҵ�
// ���� ������ �ʴ� ������ ���̳� ���� �������� �����ڿ��� ���� ���ٿ� �־ �Ź� �޸𸮿� �ε��ϰų� ���� �о���̴� �ͺ��� ������ '��������'�� ���� ������ ���ؼ� �����ϴ� ���� ��뵵 ���̰� ȿ���� ���� ���ִ�. 
// �ν��Ͻ� ���� ���� �ٷ� ��밡�� �ϱ� ������ ���α׷� ������ �������� ���Ǵ� �����͵��� ���� �� �� �̿��Ѵ�


#include <iostream>

using namespace std;

int main()
{
    {
        // ���� ����, { } ���� �ȿ����� ���� ����
        int num0 = 0;
        static int num1 = 0;
    }
    {
        for (int i = 0; i < 3; ++i)
        {
            // �ڵ� ���� ����, �ڵ� �Ҵ�, ���� �ȿ��� �Ҵ�, ������ ����� ����
            int num0 = 0;
            // ���� ���� ����, ���� �Ҵ�, ���α׷��� ���� �ǰ� ���� �� �� �Ҵ�, ���� �� �� �� �� ����
            static int num1 = 0;

            ++num0;
            ++num1;

            cout << "num0 : " << num0 << endl;
            cout << "num1 : " << num1 << endl;
        }
    }
    {
        // �ڵ� �ڿ� ����(pNum)�� ���� �Ҵ�� �̸� ���� ����(new int)�� ����Ű�� ��
        int* pNum = new int;

        // �������� ���� �ʿ�
        delete pNum;
    }
    {
        // �޸� ����, Memory Leak
        //while (true)
        //{
        //    int* num = new int;
        //}
    }
    {
        //ũ��
        //int* pNum0 = new int[1];
        int* pNum0 = new int(123);
        int* pNum1 = pNum0;

        cout << *pNum0 << endl; // 123
        delete pNum0;

        // �̹� ������ ������ ����(����)
        //cout << *pNum0 << endl;
        //cout << *pNum1 << endl;


        // ������ ������ �ٽ� ����
        //delete pNum0;
    }
    {
        int* pNum;
        {
            int n = 10;
            pNum = &n; // n�� �ڵ� ���� �����̱� ������ ������ ����� �ڵ����� ����
        }
        // �̹� ������ ������ ������ �ϴ� ����
        //cout << *pNum << endl; 
    }
    {
        // �����Ҵ��� ���� ���� �迭 ���
        int s;
        cin >> s;
        int* arr = new int[s];
        arr[0] = 1;
        cout << arr[0] << endl;

        delete[] arr;
    }
    {
        struct Person
        {
            float weight;
            float height;
        };

        Person* person = new Person{ 74.1f, 180.2f };
        cout << (*person).weight << endl;
        cout << person->weight << endl;

        Person* persons[3] = {
            new Person{56.1f, 174.f},
            new Person{74.2f, 184.f}
        };

        for (Person* person : persons)
        {
            person->weight = 0.0f;
           //(*person).weight = 0.0f;
        }
        
        for (Person* person : persons)
        {
            cout << person->weight << endl; // 0.0f
        }
    }
}