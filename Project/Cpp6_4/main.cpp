// string

#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        string str = "abcd";
        cout << str << endl;
        cout << str[0] << endl;
        cout << str[1] << endl;
        cout << str[2] << endl;
        cout << str[3] << endl;
    }
    {
        string str;
        //getline(cin, str);
        cin >> str; // ���� ������ ����
    }
    {
        string str0("abc");
        string str1("abc");

        // �� ����
        if (str0 == str1)
            cout << "Compareable" << endl;

        // ���̱�
        str0 += str1;
        //str0.append(str1);


        // ������ ���ϱ�
        str0.size();
        str1.length();
    }
    {
        string str0("abc");
        string str1("abc");

        // C ��Ÿ�� ���ڿ� ��� // ������ 0 ��ȯ
        int rtValue = strcmp(str0.c_str(), str0.c_str());
            cout << "rtValue  " << rtValue << endl;
        if (rtValue)
            cout << "==" << endl;

    }
    {
        // �ٸ� Ÿ���� ���ڿ��� ��ȯ
        string str0 = to_string(123);
        string str1 = to_string(123.3);
    }
    {
        // ���ڿ��� �ٸ� Ÿ������ ��ȯ
        int i = stoi("1");
        float f = stof("1.1");
        cout << typeid(i).name() << endl;
        cout << typeid(f).name() << endl;
    }
    {
        // ���� ���ڱ��� �Է� �ޱ�
        // "a b"�� ���� �߰��� ������ �־ "a b"�� �� ����
        string str;
        getline(cin, str);
    }


}