#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <queue>

using namespace std::chrono_literals;

struct Test
{
    int num;
    Test(int num) : num(num)
    {
        std::cout << "Construct : " << num << std::endl;
    }

    ~Test()
    {
        std::cout << "Destruct : " << num << std::endl;
    }
};
thread_local Test test(10);  // thread 개수 만큼 생성 됨

void loop0()
{
    for (int i = 0; i < 10; ++i)
    {
        thread_local int num = 10;  // thread 마다 한 번 초기화 됨, static은 thread 와 관계 없이 한 번 초기화
        num++;
        std::cout << num << std::endl;
    }
}


int num = 0;
void loop1()
{
    for (int i = 0; i < 1000000; ++i)
    {
        num++;
    }

}

void longTimeJob()
{
    std::this_thread::sleep_for(200ms);
}

void produce(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
    while (true)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lock(m);
            jobQueue.push(1);
            std::cout << "produce : " << jobQueue.size() << std::endl;
        }
        //cv.notify_one(); // cv 조건변수가 만들어진걸 알랴줌 // 기다리는 놈 one에게 일어나라
        cv.notify_all(); // 기다리는 놈 전체에게 일어나라
    }
}

void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue) // queue : 먼저 들어온 사람이 가장 먼저 나간다
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(m);
            if (jobQueue.empty())  // lost wakeup //  wakeup 전에 noti를 보낼 수 있다. // 비어 있으면 1리턴
            {
                cv.wait(lock); //대기
            }

            if (jobQueue.empty())  // spurious wakeup // 실제로 notifyer 하지않았는데 깨어날 수 있다. // 비정상적으로 깨어난 조건 변수 알림
            {
                continue;
            }

            int result = jobQueue.front();
            jobQueue.pop();

            std::cout << "consume : " << jobQueue.size() << std::endl;
        }
        longTimeJob();
    }
}

void exceptTest(int& num)
{
    ++num;
    throw std::runtime_error("err");
}



int main()
{
    //{
    //    std::cout << "==========================================="<< std::endl;
    //    // thread 기본적인 사용법
    //    std::cout << "thread mother ID: " << std::this_thread::get_id() << std::endl;

    //    // callable 인자
    //    std::thread th([] {
    //        std::cout << "thread child ID: " << std::this_thread::get_id() << std::endl;
    //        std::this_thread::sleep_for(1s); // using namespace std::chrono_literals;
    //        });
    //    // std::thread th0 = std::move(th);
    //    // std::cout << "thread move ID: " << std::this_thread::get_id() << std::endl;
    //    // th0.join();

    //    th.join(); // 끝날떄 까지 대기 // 안하면 문제

    //    //th.detach(); // 끊기 
    //    //bool p_thread = th.joinable(); // 조인이 가능한지 보고 ...
    //    //std::cout << std::boolalpha;
    //    //std::cout << p_thread << std::endl;
    //    //th.join(); // 두번 조인 문제 발생,

    //    std::cout << "Complete" << std::endl;
    //}

    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local 사용
    //    std::thread ([] {}).join();
    //    return 0;
    //}
    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local 사용
    //    loop0();
    //    return 0;
    //}
    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local 사용
    //    std::thread(loop0).join();
    //    loop0();
    //    return 0;
    //}
    //{
    //    std::cout << "==============" << std::endl;
    //    std::thread th(loop1);
    //    loop1();
    //    th.join();

    //    std::cout << num << std::endl; // 항상 2000000 이 나오지 않는다

    //    // num += 1 연산
    //    // 1. load num to register // 특정한 목적에 사용되는 일시적인 기억 장치. 데이터를 읽고 쓰는 기능이 매우 빠르며, 중앙 처리 장치(CPU) 내부에 사용됨.
    //    // 2. register += 1
    //    // 3. store register to num

    //    // 아래와 같은 상황이 발생할 수 있음
    //    // thread0     thread1
    //    // 1. load(0)
    //    //             1. load(0)  // 2. Computer가 매번 하나의 Task만 처리할 수 있다면? 해당 Task가 끝날때까지 다음 Task는 기다릴 수 밖에 없다  
    //    // 2. reg(1)   2. reg(1)   // 2. Context Switching : 현재 진행하고 있는 Task(Process, Thread)의 상태를 저장하고 다음 진행할 Task의 상태 값을 읽어 적용하는 과정
    //    // 3. store(1) 3. store(1) // 1. 둘다 storage에 썼지만 2가 아닌 1로만 써질수가 있다. 즉, race condition

    //    return 0; 
    //}
    //{
    //    // lock
    //    // 하나의 쓰레드씩 접근하도록
    //    std::cout << "===========================================" << std::endl;

    //    std::mutex m; // mutex : Mutual Exclusion 상호 배제
    //    int num = 0;
    //    auto func = [&num, &m]
    //    {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            // 임계 영역 설정
    //            //m.lock();
    //            //num++; // 하나씩 접근하도록 양쪽에서 틀어막음
    //            //m.unlock(); // 임계 영역에서 예외 발생 시 실행되지 않음, std::lock_guard 를 이용하여 해제를 보장
    //            {
    //                std::lock_guard<std::mutex> lock(m); // try_lock(), unique_lock, try_to_lock, own_lock, try_lock_for
    //                num++;
    //            }
    //        }
    //    };

    //    std::thread th0(func);
    //    std::thread th1(func);

    //    th0.join();
    //    th1.join();
    //    std::cout << num << std::endl;  // 2000000
    //    return 0;
    //}
    //{
    //    // exception
    //    // 하나의 쓰레드씩 접근하도록
    //    std::cout << "===========================================" << std::endl;

    //    std::mutex m; // mutex : Mutual Exclusion 상호 배제 // 같은 쓰레드에서 락을 여러개 잡아야할 경우 : recursive_mutex 를 사용할 수 있으며, 해제할때는 그 갯수만큼 해줘여한다.
    //    int num = 0;
    //    auto func = [&num, &m]
    //    {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            // 임계 영역 설정
    //            //m.lock();
    //            //num++; // 하나씩 접근하도록 양쪽에서 틀어막음
    //            //m.unlock(); // 임계 영역에서 예외 발생 시 실행되지 않음, std::lock_guard 를 이용하여 해제를 보장
    //           
    //            try
    //            {
    //                std::lock_guard<std::mutex> lock(m);
    //                exceptTest(num);
    //            }
    //            catch (...) // 특정 예외 타입 대신에 줄임표(...)를 사용하면, 해당 catch 절은 모든 타입의 예외를 처리
    //            {

    //            }
    //        }
    //    };

    //    std::thread th0(func);
    //    std::thread th1(func);

    //    th0.join();
    //    th1.join();
    //    std::cout << num << std::endl;  // 2000000
    //    return 0;
    //}

    

    //{
    //    std::cout << "===========================================" << std::endl;
    //    // atomic
    //    // lock 이 없어도 됨
    //    // is_lock_free 라는 것이 있는데 이것이 
    //    std::atomic_int num = 0;
    //    auto func = [&num]
    //    {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            num++;
    //        }
    //    };

    //    std::thread th0(func);
    //    std::thread th1(func);

    //    th0.join();
    //    th1.join();
    //    bool a = num.is_lock_free(); // 변수를 선언할 때 앞에 volatile을 붙이면 컴파일러는 해당 변수를 최적화에서 제외하여 항상 메모리에 접근
    //    std::cout << "a : " << a << std::endl;
    //    std::cout << num << std::endl;  // 2000000
    //    return 0;
    //}

    {
        // producer, consumer
        std::mutex m;
        std::condition_variable cv;
        std::queue<int> jobQueue;
        std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue)); // ref 일경우 ref() 써야한다.
        std::thread consumer0(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer1(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));

        producer.join();
        consumer0.join();
        consumer1.join();

        // consume 가 wait() 
        // produce 가 만들면 consume 에게 notify_one
    }
}