#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

// node: 매듭, 절, 집합점, 중심점, 트리(tree) 구조에서 데이터의 상하위 계층을 나타내는 위치의 항목
// deque 컨테이너는 vector 컨테이너와 기능과 동작이 가장 비슷한 컨테이너로 시퀀스 컨테이너이며 배열기반 컨테이너이다.
// 둘중에 차이점은 메모리 블록 할당 정책이다.
// vector의 장점이나 단점인 하나의 메모리 블록 할당 정책은 배열처럼 정수 연산만으로 원소에 접근하고 빠르게 값을 읽고 쓸 수 있다.
// 하지만 새로운 원소가 추가될 때 메모리 재할당과 이전 원소 복사 문제가 발생하여 성능이 저하될 수 있다.
// (메모리 삭제->메모리 할당->원소복사 반복..)
// 그래서 deque는 이처럼 vector의 단점을 해결하기 위해 여러 개의 메모리 블록을 할당하고 사용자에게는 하나의 블록처럼 보이게 한다.
// 즉 메모리 부족할 때마다 일정한 크기의 새로운 메모리 블록을 할당하여 이전 메모리를 제거하거나 이전 원소를 복사하는 등의 연산을 수행하지 않는다.
// (부족시 메모리 할당->메모리 할당..)
// (또한 새로운 원소를 순차열 중간에 삽입제거 하더라도 원소의 개수가 작은쪽으로 밀어내게 된다(
// STL 컨테이너 중 deque와 vector는 배열 기반 컨테이너로서 임의 접근 반복자를 지원한다.
// 노드 기반 컨테이너인 나머지 컨테이너 list, set, multiset, map, mutilmap은 양방향 반복자를 지원한다.
// 그래서 임의 접근 반복자가 제공하는 + , -, += -=, [] 연산을 모두 수행할 수 있다.

// list
// 노드 기반 컨테이너로 원소가 노드 단위로 저장되며 이중 연결리스트(doubly linked list)로 구현
// 원소를 탐색할때, 임의접근 반복자(at(), []) 는 불가능하고 양방향 반복자 (++, --) 를 이용해서 탐색
// vector, deque과는 다르게 멤버 함수 에서 정렬(sort, merge), 이어붙이기(splice) 가 있습니다.
// [head] < -> [node] <-> [tail] : 주소가 완전 제각각
// list는 중간 삽입, 삭제가 빠름!!!!!!!!!!!!!!!!!!!!!!!!!!
// indexing 이 약함


using std::cout;
using std::endl;


bool condition(const int& value)
{
    return value % 2 == 0;
}

int main()
{
    {
        // 양방향 연결 리스트
        std::list<int> list0{ 1, 2, 3 };
        // list0[2]; 안 됨, Indexing 자체가 O(n)이 걸리기 때문에 지원하지 않음 // 성능이 나오지 않아서임
        // stl은 느리면(적합하지 않으면) 연산을 지원하지 않는다.
        // Head <-> Node0 <-> Node1 <-> Tail

        std::list<int>::iterator iter = list0.begin();
        std::advance(iter, 2); // 이렇게 두 번 전진할 수는 있음
        cout << *iter << endl; // 3을 가르킴
        
        list0.sort(); // sort 를 따로 지원
        //std::sort(list0.begin(), list0.end()); std::sort() 는 랜덤 액세스 이터레이터를 지원하는 컨테이너만 가능
        //랜덤 액세스 이터레이터는 list0[2] 접근가능해야한다는 의미


        // list는 중간 삽입, 삭제가 빠름!!!!!!!!!!!!!!!!!!!!!!!!!!
        list0.remove(2);
        list0.remove_if(condition); // 조건에 맞으면 지움 // 여기서는 짝수 지움
        cout << endl;

        for (int num : list0)
        {
            cout << num <<  endl;
        }

        cout << "================" << endl;
        std::list<int> list1{ 1, 1, 2, 3 };
        std::list<int> list2{ 1, 2, 3, 4 };

        // 정렬 되어 있는 두 리스트를 연결하여 정렬
        list1.merge(list2);
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;

        // 중복 제거
        list1.unique();
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;
    }

    {
        // 거의 사용하지 않는다. 제약이 많음
        cout << "forward_list" << endl;
        // 단방향 연결 리스트
        std::forward_list<int> list0{ 1, 2, 3, 4 };
        list0.insert_after(list0.begin(), 10);

        for (int num : list0)
        {
            cout << num << endl;
        }

        // list0.insert_after(); 맨 처음[0]에 넣는게 아니다. 요소번호 [1]에 넣는다
        // tail을 모름
        // push_front 만 있음
        // // [head] -> [node] -> [tail] : 단방향
    }
}

