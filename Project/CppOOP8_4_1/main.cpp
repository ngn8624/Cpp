#include <iostream>
#include <map>

// ���� �����̳��� Ư¡�� ������ ���� �������� �ڷ� �Է°� ���ÿ� ��� �ڷᰡ ���ĵȴ�. 
// BST(binary search tree)������ �Ǿ� ������ ���⵵�� �˻�, �Է�, ����, ���ͷ����� �̵�(�ϳ� �̵�) ��� O(log n) �̴�.
// map, set, mulset, multimap
// root�� �ִ�.
// root �� �������� root > left subtree
// root �� �������� root < right subtree


using std::cout;
using std::endl;


int main()
{
    // Key, Value, Ʈ�� ���, ���� ���� O(log n)
    // Key �� Value�� ����(����)�ȴ�

    std::map<int, std::string> m;
    m[1] = "a";

    cout << m[1] << endl; // �̷��� ��ȸ
    cout << m[2] << endl; // ÷�� ���� ��ȸ �� Value�� ���� ��� Value�� �⺻ ���� ������ ��
    cout << m.size() << endl; // 2


    // map�� ���Ҵ� std::pair
    std::map<int, std::string> m0{
        {1, "1"}, // �̰Ÿ� ����...
        std::pair<int, std::string>(2, "2"),
        std::make_pair(3, "3")
    };

    // �׻� Key ������ ������ �Ǿ� �ִ�
    for (const std::pair<int, std::string>& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    cout << "==========" << endl;

    std::map<int, std::string> m1{
        {3,"1"},{2,"2"},{1,"3"}
    };
    // ��� �� pair�� std::pair<int, std::string> �� �ƴ϶� std::pair<const int, std::string>
    // key ���� const ��!!
    // Tree���� Key�� �ٲ�� �� �Ǳ� ����
    for (const std::pair<int, std::string>& pair : m1) // ������ pair�� Ÿ���� �ٸ��� ������ ����ȯ�� �Ͼ // int ���� ���־��� ũ�ٸ�, ����ȯ�� �Ͼ key���� ������ �ش�. const int �� ������!!
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const std::pair<const int, std::string>& pair : m1) // ������ const�� �ִ� pair�� �´� ǥ��
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const auto& pair : m1) // �Ǽ��� ���� �ϱ� ���� auto�� ���
    {
        cout << pair.first << ":" << pair.second << endl; // ���콺 �����ٰ����ƶ�... const int
    }
    cout << "==========" << endl;

    m0.insert({3, "10"}); // �ִ� ��Ȳ�� insert

    cout << m0[3] << endl; // fail. 10�� �ƴ� 3�� ���
    m0[3] = "10";
    cout << m0[3] << endl; // key 3 �� 10�� ��
    
    cout << "==========" << endl;

    for (const auto& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }



}