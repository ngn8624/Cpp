// void ������

#include <iostream>

using namespace std;

int main()
{
    {
        // ���� ���·� ������ �� ����
        //void p;
    }
    {
        int num = 10;
        int* p = &num;

        // void* �� �ٸ� ���������� ����ų �� ����
        void* vp = p;

        // �����͸� � ���·� �ٷ��� �ϴ��� �� �� ��� �Ұ���
        //cout << *vp << endl;
        
        // �ٸ� ������ ��ȯ ����
        p = (int*)vp;
    }
    {
        int nums[] = { 1, 2, 3 };
        void* vp = nums;

        // �� �ȴ�
        //*(vp + 1);
    }
    {
        // ��� �Ǵ� ��
        // malloc�� �޸𸮸� �Ű������� ũ�⸸ŭ�� �Ҵ��Ѵ�. �� ��� sizeof(int) * 3 ��ŭ
        // malloc �Լ� �ȿ����� Ÿ���� �� �� ���� ũ�⸸ �˱� ������ void*�� ��ȯ ��
        int* p = (int*)malloc(sizeof(int) * 3);

        // ��� Ÿ���� �����Ҵ� �� ������ ���� �Ǿ�� �ϴ� void*�� �Ű� ������ �޴´�.
        free(p);
    }
}