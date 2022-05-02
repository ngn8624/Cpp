#include <iostream>
#include <future>
#include <chrono>


// 앞의 thread 는 row level 의 동기화 수준을 보여줌 : 직접 제어하기가 어렵다
// 아래 것들은 높은 수준의 추상화수준들
// future : 일종의 수신자
// promise : 일종의 송신자
// packaged_task
// async


using namespace std::chrono_literals;

int main()
{
    // 왜 사용? 쓰레드에 사용할 수 있다.
    //{
    //    std::promise<int> pro;
    //    std::future<int> fut = pro.get_future();

    //    pro.set_value(10); // set_value 안하면 블락킹 걸림
    //    //pro.set_value(10); // 두번 set_value() 못함
    //    std::cout << fut.get() << std::endl;
    //    //std::cout << fut.get() << std::endl; // 두번 get() 못함
    //    return 0;
    //}

    //{
    //    // promise - future - value
    //    std::promise<int> pro;
    //    std::future<int> fut = pro.get_future(); // promise로 부터 값을 가져옴

    //    std::thread th([](std::promise<int> pro) {
    //        std::this_thread::sleep_for(2s);
    //        pro.set_value(10);
    //        }, std::move(pro)); // promise는 이동만 가능한 것이라 move() 이용

    //    std::cout << fut.get() << std::endl; // 10
    //    th.join();
    //    return 0;
    //}

    //{
    //    //조금 복잡
    //    // promise - future - exception
    //    std::promise<int> pro;
    //    std::future<int> fut = pro.get_future();

    //    std::thread th([](std::promise<int> pro) {
    //        try {
    //            throw std::runtime_error("err");
    //        }
    //        catch (...) {
    //            std::exception_ptr e = std::current_exception();
    //            pro.set_exception(e);
    //        }
    //        }, std::move(pro));
    //    try 
    //    {
    //        std::cout << fut.get() << std::endl;
    //    }
    //    catch (const std::runtime_error& err)
    //    {
    //        std::cout << err.what() << std::endl;
    //    }
    //    th.join();
    //    return 0;
    //}

    //{
    //    //위가 복잡하니까 packaged_task 이용
    //    // packaged_task
    //    // promise를 사용할 때에는 exception도 일일히 다해줘야하지만 packaged_task를 사용할 경우 핸들링을 알아서 해준다
    //    std::packaged_task<int(int)> task([](int value) {
    //        if (value < 0)
    //            throw std::runtime_error("err");
    //        return value;
    //        });

    //    std::future<int> fut = task.get_future();
    //    std::thread th(std::move(task), 10);
    //    try {
    //        std::cout << fut.get() << std::endl;
    //    }
    //    catch (const std::runtime_error& err) {
    //        std::cout << err.what() << std::endl;
    //    }
    //    th.join();
    //    return 0;
    //}
    {
        // 쓰레드 조인도 귀찮다...
        // 아래처럼 쓰자
        // async
        // thread 만드는 것조차 없앰
        // thread 내부적으로 만들수도 안만들수도 있음 이것은 async 에 달림
        // std::launch::deferred는 쓰레드 안만들도록 강제
        // std::launch::deferred는 fut.get()을 만날때까지 람다 바디를 실행하지않음
        // std::launch::async 는 무조건 다른 쓰레드에서 실행하도록함
        // std::launch::deferred | std::launch::async 처럼 | 연산을 하게될 경우 둘중하나 하는 것
        // os 구현 제작자에게 선택을 넘김으로써, 좀더 최적화 가능한 프로그래밍이 될 수 있다. 아닐수도,..
        std::cout << "thread id : " << std::this_thread::get_id() << std::endl;
        std::future<int> fut = std::async(std::launch::deferred, [](int value) {
            std::cout << "thread id : " << std::this_thread::get_id() << std::endl;
            if (value < 0)
                throw std::runtime_error("errrrrrrr");
            return value;
            }, -1);
        try {
            std::cout << fut.get() << std::endl;
        }
        catch (const std::runtime_error& err) {
            std::cout << err.what() << std::endl;
        }
        return 0;
    }
}