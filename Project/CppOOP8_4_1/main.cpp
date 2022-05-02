#include <iostream>
#include <map>

// 연관 컨테이너의 특징은 정해진 정렬 기준으로 자료 입력과 동시에 모든 자료가 정렬된다. 
// BST(binary search tree)구조로 되어 있으며 복잡도는 검색, 입력, 삭제, 이터레이터 이동(하나 이동) 모두 O(log n) 이다.
// map, set, mulset, multimap
// root가 있다.
// root 는 좌측에는 root > left subtree
// root 는 우측에는 root < right subtree


using std::cout;
using std::endl;


int main()
{
    // Key, Value, 트리 기반, 삽입 삭제 O(log n)
    // Key 가 Value에 맵핑(대응)된다

    std::map<int, std::string> m;
    m[1] = "a";

    cout << m[1] << endl; // 이렇게 조회
    cout << m[2] << endl; // 첨자 연산 조회 시 Value가 없는 경우 Value의 기본 값이 나오게 됨
    cout << m.size() << endl; // 2


    // map의 원소는 std::pair
    std::map<int, std::string> m0{
        {1, "1"}, // 이거만 쓰자...
        std::pair<int, std::string>(2, "2"),
        std::make_pair(3, "3")
    };

    // 항상 Key 값으로 정렬이 되어 있다
    for (const std::pair<int, std::string>& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    cout << "==========" << endl;

    std::map<int, std::string> m1{
        {3,"1"},{2,"2"},{1,"3"}
    };
    // 사실 상 pair는 std::pair<int, std::string> 이 아니라 std::pair<const int, std::string>
    // key 값은 const 임!!
    // Tree에서 Key는 바뀌면 안 되기 때문
    for (const std::pair<int, std::string>& pair : m1) // 실제로 pair의 타입이 다르기 때문에 형변환이 일어남 // int 값이 아주아주 크다면, 형변환이 일어나 key값에 영향을 준다. const int 로 써주자!!
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const std::pair<const int, std::string>& pair : m1) // 실제로 const가 있는 pair가 맞는 표현
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const auto& pair : m1) // 실수를 방지 하기 위해 auto를 사용
    {
        cout << pair.first << ":" << pair.second << endl; // 마우스 가져다가보아라... const int
    }
    cout << "==========" << endl;

    m0.insert({3, "10"}); // 있는 상황에 insert

    cout << m0[3] << endl; // fail. 10이 아닌 3이 출력
    m0[3] = "10";
    cout << m0[3] << endl; // key 3 에 10이 들어감
    
    cout << "==========" << endl;

    for (const auto& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }



}