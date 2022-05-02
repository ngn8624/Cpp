// enum
// enum�� ������� �迭�ϰ� struct�� ��ġ���� ���� ���� ������ �Ű������� �� �� �ִ� ���� ����
// enum class�� �� ��ȯ�� �������� �������� �Ǿ� �������� �Ǽ��� �߻��� ���׸� �����ϰ��� �ϴ� ���� ������ enum�� ������ �ִ� ������ ������ �ذ�
// unscoped enum�� ��쿡�� ���漱���� �� �� �������� scoped enum�� ��� �̰� ���������鼭 �ҽ� ���ϰ��� dependency�� �ٿ��� ��� ������ �ణ ���������ν� ����� ���� �ҽ� �ڵ��� ���������� ���� �� �ִٴ� ����

#include <iostream>

using namespace std;

enum Color
{
    // ���� ���������� ������ ù ������ 0�� �ǰ� ���ķ� 1�� ����
    Red, Green, Blue, SIZE 
};

struct ColorStruct
{
    int red;
    int green;
    int blue;
};

enum TextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum CircleAttribute
{
    //Bold = 1 // Unscoped Enum �� ��� TextAttribute::Bold �� �̸��� ���ļ� ����� �� ����.
};


enum struct ScopedTextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum class ScopedCircleAttribute
{
    Bold = 1 // ScopedEnum�� �̸��� ���ĵ� ����
};

enum Overflow
{
    Value0 = 100000000000
};

enum NotOverflow : uint64_t
{
    Value1 = 100000000000
};

int main()
{
    {
        // �ּ����� RGB Index�� ǥ��
        // 0 : Red, 1 : Green, 2 :Blue
        int colors[3] = { 255, 128, 64 };

        cout << "Red : " << colors[0] << endl;
        cout << "Green : " << colors[1] << endl;
        cout << "Blue : " << colors[2] << endl;

        // ����� RGB Index�� ǥ��
        const int red = 0;
        const int green = 1;
        const int blue = 2;

        cout << "Red : " << colors[red] << endl;
        cout << "Green : " << colors[green] << endl;
        cout << "Blue : " << colors[blue] << endl;

        // Unscoped enum �� �̿��Ͽ� RGB Index�� ǥ��
        cout << "Red : " << colors[Red] << endl;
        cout << "Green : " << colors[Green] << endl;
        cout << "Blue : " << colors[Blue] << endl;
    }

    {
        int colors[SIZE] = { 255, 128, 64 };
        // Unscoped enum �� �̿��Ͽ� RGB ���� ���
        int total = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            total += colors[i];
        }

        int avg0 = total / SIZE;
        cout << avg0 << endl;

        // Struct�� �̿��Ͽ� RGB ���� ���
        ColorStruct cs = { 255, 128, 64 };
        int avg1 = (cs.red + cs.green + cs.blue);
        cout << avg1 << endl;
    }
    {
        // BitFlag ��� // bitset Ŭ����
        int textAttrs = 0;
        textAttrs |= Bold;
        textAttrs |= Underline;

        cout << textAttrs << endl;
        if (textAttrs & Underline)
            cout << "Underline" << endl;
    }
    {
        Bold;
        TextAttribute::Bold; // ���� �����ؼ� ��� ����
        ScopedTextAttribute::Bold; // ���� ������ �ݵ�� �ؾ� �Ѵ�.

        cout << Bold << endl;
        cout << TextAttribute::Bold << endl;
        cout << (int)ScopedTextAttribute::Bold << endl; // ��Ÿ��, �Ͻ������� ���������� ��ȯ���� �ʴ´�
        // Unscoped enumeration ���� Scoped enumeration ����� ���� �ȴ�
    }
    {
        cout << Overflow::Value0 << endl;
        cout << NotOverflow::Value1 << endl;
    }
    {
        Color color = Color::Red; // ������ ���
        if (color == Color::Red) // �񱳹�
        {
            cout << "Red" << endl;
        }
    }
    {
        Color color = (Color)0; // ������ enum���� ��ȯ
        if (color == Color::Red) 
        {
            cout << "Red" << endl;
        }
    }
}
