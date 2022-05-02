#include <iostream>
#include <vector>
#include <deque>
#include <array>
// std:: array 
// std::array 사용은 내장된 고정 배열(int arr[] = {1,2,3,4,5};)을 대체하는 훌륭한 방법이다. 
// 내장된 고정 배열보다 메모리를 더 사용하지 않으며 함수로 전달시 포인터로 형 변환되지 않는 장점이 있고, 
// 단점은 선언할 때 배열 길이를 명시적으로 지정해야 한다는 것뿐이다.

// std::vector
// 동적으로 원소를 추가할 수 있으며 크기가 자동으로 늘어난다.
// 재할당이 일어날수 있으므로 사용하기 전에 크기를 알수 있다면 reserve()로 capacity를 확보하고 사용하자.

// deque
// deque도 중간에 요소를 집어넣으면 시간복잡도 증가.
// 배열을 여러개 가지고 있을뿐

using std::cout;
using std::endl;


int main()
{

    //{
    //    std::vector<int> vec{ 1, 2, 3 };
    //    for (std::vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
    //    {
    //        cout << *iter << endl;
    //    }
    //    cout << "vector========" << endl;
    //}
    {
        std::vector<int> vec{ 0,1, 2, 3,4,5,6,7,8,9 };
        vec.push_back(10);
        for (int num : vec)
        {
            cout << &vec[num] << endl;
        }
        std::vector<int> vec1;
        memcpy(&vec1, &vec, sizeof(vec));
        cout << "============" << endl;
        for (int num : vec1)
        {
            cout << num << endl;
        }

        cout << "============" << endl;
        std::array<int,10> arr1 = { 0,1, 2, 3,4,5,6,7,8,9 };
        for (int num : arr1)
        {
            cout << &arr1[num] << endl;
        }
        int arr[10] = { 0,1, 2, 3,4,5,6,7,8,9 };
        
        int a = 1;
        a = 2;
    }
    {
        //std::vector<int> vec{ 1, 2, 3 };
        //std::vector<int>::iterator iter = vec.begin();

        //int& num = vec[0];
        //vec[0] = 10;
        //cout << *iter << endl;
        //cout << num << endl;
        //cout << "iterator========" << endl;
        ////// 문제 발생 (위 아래 동일증상) // 재할당
        //vec.reserve(vec.capacity() + 1);
        //vec[0] = 100;
        //cout << *iter << endl;
        //cout << num << endl;
        //cout << "========" << endl;
    }
    {
        cout << "========" << endl;
        // 문제 발생 (위 아래 동일증상)
        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        int* num = &vec[0];

        // vector의 사이즈가 크고 얼만큼 커질 지 알 수 있다면 reserve를 미리 해주자
        vec.reserve(vec.capacity() + 1);

        // 둘의 주소가 다르다.
        cout << num << endl;
        cout << &vec[0] << endl;

        // 대체로 시간 복잡도 O(1), 재할당 될 때가 있으니 주의 (시간 복잡도 : ????) 
        vec.push_back(10);

        // 시간 복잡도 O(빅오)(1)
        vec.pop_back(); // 벡터 제일 뒤에 원소 삭제

        // 가장 앞에 삽입했기 때문에  O(빅오)(n), 뒤로 다 밀림
        vec.insert(vec.begin(), 10);

        for (int num : vec)
        {
            cout << "num : " << num << endl;
        }

        cout << vec.size() << endl;
        cout << sizeof(vec) << endl;

        cout << "========" << endl;
        //
        // capacity는 vector의 요소(element)들을 담을 수 있는 메모리가 할당되어 있는 공간의 용량이다.
        // size는 실제 유효한 요소(element)들의 갯수

        // [1, 2, 3, ?] 
        // size = 3
        // capacity = 4

        // push_back(4)
        // [1, 2, 3, 4]
        // size = 4
        // capacity = 4

        // push_back(5)
        // [1, 2, 3, 4, 5, ?, ?, ?] // 배열의 재할당
        // size = 4
        // capacity = 8
    }
    {
        //리저브 먼저하면 재할당 안일어남
        cout << "reserve()_first" << endl;

        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        vec.reserve(vec.capacity() + 1);
        int* num = &vec[0];

        // 둘의 주소가 같다
        cout << num << endl;
        cout << &vec[0] << endl;
    }
    {
        cout << "deque" << endl;

        std::deque<int> nums;

        // 대체로 O(1)
        nums.push_front(1);

        cout << nums[0] << endl;
        cout << &nums[0] << endl;

        // 대체로 O(1)
        nums.push_back(2);

        cout << nums[1] << endl;
        cout << &nums[1] << endl; // cout << &nums[2] << endl; 주소같다

        nums.push_front(10);
        cout << nums[2] << endl;
        cout << &nums[2] << endl;

        // 배열을 여러개 가지고 있다.
        // push_back
        // [0]

        // push_front
        // [1] [0]
        // push_front 도 빠르게 만들기 위해서 배열을 더 만든다.
        // [?,?, ?,10] [1,2,3,]

    }



    return 0;
}
