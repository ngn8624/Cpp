#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;

// 
// unordered 류 : hashtable로 구성
// 해시 테이블(hash table), 해시 맵(hash map), 해시 표는 컴퓨팅에서 키를 값에 매핑할 수 있는 구조인, 연관 배열 추가에 사용되는 자료 구조
// 해시테이블은 해시함수를 사용하여 키를 해시값으로 매핑하고, 이 해시값을 색인(인덱스) 또는 주소삼아 데이터를 key와 함께 저장하는 자료구조이다. 단순하게 key - value로 이루어진 자료구조
// 해시 테이블은 해시 함수를 사용하여 색인(index)을 버킷(bucket)이나 슬롯(slot)의 배열로 계산
// 해시 테이블의 기본연산으로는 탐색(Search), 삽입(Insert), 삭제(Delete)
// 해시 테이블은 (Key, Value)로 데이터를 저장하는 자료구조 중 하나로 빠르게 데이터를 검색할 수 있는 자료구조
// Hash 함수(해시 함수) : 해시 함수는 임의의 길이의 문자열을 받아서 고정 문자열로 바꾸어주는 함수
// 해싱이란 임의의 길이의 값을 해시함수(Hash Function)를 사용하여 고정된 크기의 값으로 변환하는 작업을 말한다.
// 해시테이블의 특성상 정렬이 보장되지 않는다

// key: "abc", hash("abc") == 100(이거라고 치자)
// b0, b1, b2, b3 
// 100% 4 == 0 // bucket 이 4개
// key: "cda", hash("cda") == 100(이거라고 치자)
// 100% 4 == 0 // bucket 이 4개

// b0,b1,b2,b3
// b0 -> "abc" -> "cda" 충돌발생
// std::unordered_map<int, std::string, BadHashFunction, 4> um; // 4번째 파라미터가 해결


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
        // 해시 테이블 기반, 삽입, 삭제 O(1)
        std::unordered_map<int, std::string> um{
            {1, "10"},
            {2, "20"},
            {3, "30"},
            {4, "40"},
        };

        // 순서가 보장 안 됨
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
        cout << um.bucket_size(1) << endl; // 한 개의 버켓에 모든 원소가 들어가게 됨. 항상 충돌 O(n) // 100
    }

}
