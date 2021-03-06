// 포인터 - 동적 할당
// 자주 변하지 않는 일정한 값이나 설정 정보같은 공용자원에 대한 접근에 있어서 매번 메모리에 로딩하거나 값을 읽어들이는 것보다 일종의 '전역변수'와 같은 개념을 통해서 접근하는 것이 비용도 줄이고 효율을 높일 수있다. 
// 인스턴스 생성 없이 바로 사용가능 하기 때문에 프로그램 내에서 공통으로 사용되는 데이터들을 관리 할 때 이용한다


#include <iostream>

using namespace std;

int main()
{
    {
        // 지역 변수, { } 지역 안에서만 접근 가능
        int num0 = 0;
        static int num1 = 0;
    }
    {
        for (int i = 0; i < 3; ++i)
        {
            // 자동 지역 변수, 자동 할당, 지역 안에서 할당, 지역을 벗어나면 해제
            int num0 = 0;
            // 정적 지역 변수, 정적 할당, 프로그램이 시작 되고 나서 한 번 할당, 종료 될 떄 한 번 해제
            static int num1 = 0;

            ++num0;
            ++num1;

            cout << "num0 : " << num0 << endl;
            cout << "num1 : " << num1 << endl;
        }
    }
    {
        // 자동 자역 변수(pNum)에 동적 할당된 이름 없는 변수(new int)를 가리키게 함
        int* pNum = new int;

        // 수동으로 해제 필요
        delete pNum;
    }
    {
        // 메모리 누수, Memory Leak
        //while (true)
        //{
        //    int* num = new int;
        //}
    }
    {
        //크기
        //int* pNum0 = new int[1];
        int* pNum0 = new int(123);
        int* pNum1 = pNum0;

        cout << *pNum0 << endl; // 123
        delete pNum0;

        // 이미 해제된 포인터 접근(위험)
        //cout << *pNum0 << endl;
        //cout << *pNum1 << endl;


        // 해제된 포인터 다시 해제
        //delete pNum0;
    }
    {
        int* pNum;
        {
            int n = 10;
            pNum = &n; // n은 자동 지역 변수이기 때문에 지역을 벗어나면 자동으로 해제
        }
        // 이미 해제된 변수를 역참조 하니 위험
        //cout << *pNum << endl; 
    }
    {
        // 동적할당을 통해 가변 배열 사용
        int s;
        cin >> s;
        int* arr = new int[s];
        arr[0] = 1;
        cout << arr[0] << endl;

        delete[] arr;
    }
    {
        struct Person
        {
            float weight;
            float height;
        };

        Person* person = new Person{ 74.1f, 180.2f };
        cout << (*person).weight << endl;
        cout << person->weight << endl;

        Person* persons[3] = {
            new Person{56.1f, 174.f},
            new Person{74.2f, 184.f}
        };

        for (Person* person : persons)
        {
            person->weight = 0.0f;
           //(*person).weight = 0.0f;
        }
        
        for (Person* person : persons)
        {
            cout << person->weight << endl; // 0.0f
        }
    }
}