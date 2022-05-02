#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;

// 
// unordered �� : hashtable�� ����
// �ؽ� ���̺�(hash table), �ؽ� ��(hash map), �ؽ� ǥ�� ��ǻ�ÿ��� Ű�� ���� ������ �� �ִ� ������, ���� �迭 �߰��� ���Ǵ� �ڷ� ����
// �ؽ����̺��� �ؽ��Լ��� ����Ͽ� Ű�� �ؽð����� �����ϰ�, �� �ؽð��� ����(�ε���) �Ǵ� �ּһ�� �����͸� key�� �Բ� �����ϴ� �ڷᱸ���̴�. �ܼ��ϰ� key - value�� �̷���� �ڷᱸ��
// �ؽ� ���̺��� �ؽ� �Լ��� ����Ͽ� ����(index)�� ��Ŷ(bucket)�̳� ����(slot)�� �迭�� ���
// �ؽ� ���̺��� �⺻�������δ� Ž��(Search), ����(Insert), ����(Delete)
// �ؽ� ���̺��� (Key, Value)�� �����͸� �����ϴ� �ڷᱸ�� �� �ϳ��� ������ �����͸� �˻��� �� �ִ� �ڷᱸ��
// Hash �Լ�(�ؽ� �Լ�) : �ؽ� �Լ��� ������ ������ ���ڿ��� �޾Ƽ� ���� ���ڿ��� �ٲپ��ִ� �Լ�
// �ؽ��̶� ������ ������ ���� �ؽ��Լ�(Hash Function)�� ����Ͽ� ������ ũ���� ������ ��ȯ�ϴ� �۾��� ���Ѵ�.
// �ؽ����̺��� Ư���� ������ ������� �ʴ´�

// key: "abc", hash("abc") == 100(�̰Ŷ�� ġ��)
// b0, b1, b2, b3 
// 100% 4 == 0 // bucket �� 4��
// key: "cda", hash("cda") == 100(�̰Ŷ�� ġ��)
// 100% 4 == 0 // bucket �� 4��

// b0,b1,b2,b3
// b0 -> "abc" -> "cda" �浹�߻�
// std::unordered_map<int, std::string, BadHashFunction, 4> um; // 4��° �Ķ���Ͱ� �ذ�


struct BadHashFunction
{
    std::size_t operator()(const int& key) const
    {
        return key;
    }
};

int main()
{
    {
        // �ؽ� ���̺� ���, ����, ���� O(1)
        std::unordered_map<int, std::string> um{
            {1, "10"},
            {2, "20"},
            {3, "30"},
            {4, "40"},
        };

        // ������ ���� �� ��
        for (const auto& [key, value] : um)
        {
            cout << key << ":" << value << endl;
        }

    }
    {
        std::unordered_map<int, std::string, BadHashFunction> um;
        for (int i = 0; i < 100; ++i)
        {
            um[i] = i;
        }
        for (const auto& [key, value] : um)
        {
            cout << key << ":" << value << endl;
        }
        cout << "===========" << endl;
        cout << um.bucket_count() << endl;
        cout << um.bucket_size(0) << endl; // 0
        cout << um.bucket_size(1) << endl; // �� ���� ���Ͽ� ��� ���Ұ� ���� ��. �׻� �浹 O(n) // 100
    }

}
