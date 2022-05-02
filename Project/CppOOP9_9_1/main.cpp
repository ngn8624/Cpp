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
thread_local Test test(10);  // thread ���� ��ŭ ���� ��

void loop0()
{
    for (int i = 0; i < 10; ++i)
    {
        thread_local int num = 10;  // thread ���� �� �� �ʱ�ȭ ��, static�� thread �� ���� ���� �� �� �ʱ�ȭ
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
        //cv.notify_one(); // cv ���Ǻ����� ��������� �˷��� // ��ٸ��� �� one���� �Ͼ��
        cv.notify_all(); // ��ٸ��� �� ��ü���� �Ͼ��
    }
}

void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue) // queue : ���� ���� ����� ���� ���� ������
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(m);
            if (jobQueue.empty())  // lost wakeup //  wakeup ���� noti�� ���� �� �ִ�. // ��� ������ 1����
            {
                cv.wait(lock); //���
            }

            if (jobQueue.empty())  // spurious wakeup // ������ notifyer �����ʾҴµ� ��� �� �ִ�. // ������������ ��� ���� ���� �˸�
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
    //    // thread �⺻���� ����
    //    std::cout << "thread mother ID: " << std::this_thread::get_id() << std::endl;

    //    // callable ����
    //    std::thread th([] {
    //        std::cout << "thread child ID: " << std::this_thread::get_id() << std::endl;
    //        std::this_thread::sleep_for(1s); // using namespace std::chrono_literals;
    //        });
    //    // std::thread th0 = std::move(th);
    //    // std::cout << "thread move ID: " << std::this_thread::get_id() << std::endl;
    //    // th0.join();

    //    th.join(); // ������ ���� ��� // ���ϸ� ����

    //    //th.detach(); // ���� 
    //    //bool p_thread = th.joinable(); // ������ �������� ���� ...
    //    //std::cout << std::boolalpha;
    //    //std::cout << p_thread << std::endl;
    //    //th.join(); // �ι� ���� ���� �߻�,

    //    std::cout << "Complete" << std::endl;
    //}

    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local ���
    //    std::thread ([] {}).join();
    //    return 0;
    //}
    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local ���
    //    loop0();
    //    return 0;
    //}
    //{
    //    std::cout << "===========================================" << std::endl;
    //    // thread local ���
    //    std::thread(loop0).join();
    //    loop0();
    //    return 0;
    //}
    //{
    //    std::cout << "==============" << std::endl;
    //    std::thread th(loop1);
    //    loop1();
    //    th.join();

    //    std::cout << num << std::endl; // �׻� 2000000 �� ������ �ʴ´�

    //    // num += 1 ����
    //    // 1. load num to register // Ư���� ������ ���Ǵ� �Ͻ����� ��� ��ġ. �����͸� �а� ���� ����� �ſ� ������, �߾� ó�� ��ġ(CPU) ���ο� ����.
    //    // 2. register += 1
    //    // 3. store register to num

    //    // �Ʒ��� ���� ��Ȳ�� �߻��� �� ����
    //    // thread0     thread1
    //    // 1. load(0)
    //    //             1. load(0)  // 2. Computer�� �Ź� �ϳ��� Task�� ó���� �� �ִٸ�? �ش� Task�� ���������� ���� Task�� ��ٸ� �� �ۿ� ����  
    //    // 2. reg(1)   2. reg(1)   // 2. Context Switching : ���� �����ϰ� �ִ� Task(Process, Thread)�� ���¸� �����ϰ� ���� ������ Task�� ���� ���� �о� �����ϴ� ����
    //    // 3. store(1) 3. store(1) // 1. �Ѵ� storage�� ������ 2�� �ƴ� 1�θ� �������� �ִ�. ��, race condition

    //    return 0; 
    //}
    //{
    //    // lock
    //    // �ϳ��� �����徿 �����ϵ���
    //    std::cout << "===========================================" << std::endl;

    //    std::mutex m; // mutex : Mutual Exclusion ��ȣ ����
    //    int num = 0;
    //    auto func = [&num, &m]
    //    {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            // �Ӱ� ���� ����
    //            //m.lock();
    //            //num++; // �ϳ��� �����ϵ��� ���ʿ��� Ʋ���
    //            //m.unlock(); // �Ӱ� �������� ���� �߻� �� ������� ����, std::lock_guard �� �̿��Ͽ� ������ ����
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
    //    // �ϳ��� �����徿 �����ϵ���
    //    std::cout << "===========================================" << std::endl;

    //    std::mutex m; // mutex : Mutual Exclusion ��ȣ ���� // ���� �����忡�� ���� ������ ��ƾ��� ��� : recursive_mutex �� ����� �� ������, �����Ҷ��� �� ������ŭ ���࿩�Ѵ�.
    //    int num = 0;
    //    auto func = [&num, &m]
    //    {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            // �Ӱ� ���� ����
    //            //m.lock();
    //            //num++; // �ϳ��� �����ϵ��� ���ʿ��� Ʋ���
    //            //m.unlock(); // �Ӱ� �������� ���� �߻� �� ������� ����, std::lock_guard �� �̿��Ͽ� ������ ����
    //           
    //            try
    //            {
    //                std::lock_guard<std::mutex> lock(m);
    //                exceptTest(num);
    //            }
    //            catch (...) // Ư�� ���� Ÿ�� ��ſ� ����ǥ(...)�� ����ϸ�, �ش� catch ���� ��� Ÿ���� ���ܸ� ó��
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
    //    // lock �� ��� ��
    //    // is_lock_free ��� ���� �ִµ� �̰��� 
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
    //    bool a = num.is_lock_free(); // ������ ������ �� �տ� volatile�� ���̸� �����Ϸ��� �ش� ������ ����ȭ���� �����Ͽ� �׻� �޸𸮿� ����
    //    std::cout << "a : " << a << std::endl;
    //    std::cout << num << std::endl;  // 2000000
    //    return 0;
    //}

    {
        // producer, consumer
        std::mutex m;
        std::condition_variable cv;
        std::queue<int> jobQueue;
        std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue)); // ref �ϰ�� ref() ����Ѵ�.
        std::thread consumer0(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer1(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));

        producer.join();
        consumer0.join();
        consumer1.join();

        // consume �� wait() 
        // produce �� ����� consume ���� notify_one
    }
}