#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;


int divide(double d, double v, double& result)
{
    if (v == 0)
    {
        result = 0;
        return -1;
    }
    result = d / v;
    return 0;
}

int errorCode = 0;
double divide(double d, double v)
{
    if (v == 0)
    {
        errorCode = -1;
        return 0;
    }
    errorCode = 0;
    return d / v;
}

int main()
{
    {
        // ���� �߻� �� ����
        // ������ ����
        // ��������
        // abort �ñ׳� ��ȯ
        //std::abort();

        // ���� �ڵ带 ���� ����
        //exit(123);
    }
    // �Ʒ��� ���� ó�� ����� ���� ó���� ���� ���� �ʴ´�.
    // printf �� ���������� ������ �Ϳ� ���� ���� ��Ȳ�� ó������ �ʰ� �ۼ��ϴ��� ��ġä�� ���� �� �ִ�.
    // ���� ���� �� ���п� ���� ó���� �����ϰ� �ϴ� ��Ŀ������ �ʿ�
    //{
    //    freopen("input.txt", "r", stdout);
    //    // �б� �������� stdout�� ������ �������� �ش� ����(input.txt)�� ����(���)�� �� �� ����
    //    // f9 �ߴ��� ����׽� -1 
    //    int result = printf("%d\n", 10);  // ���� �߻� �� ����
    //    cout << result << endl;

    //    cout << cout.fail(); // ���� �߻� �� �ش� ��ü�� ����
    //}
    

    // �帧�� ��������
    //{
    //    double result;
    //    int errorCode = divide(10, 0, result); // ���� �߻� �� ���� �ڵ�
    //    if (errorCode > 0)
    //    {
    //        cout << result << endl;
    //    }
    //}
    {
        double result = divide(10, 0);
        if (errorCode > 0) // ���������� ����ϴ� ����, ��Ƽ �����忡�� ���� �߻�
        { 
             
        }
    }


}