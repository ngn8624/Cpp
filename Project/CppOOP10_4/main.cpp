#include <iostream>
#include <future>
#include <chrono>
#include <experimental/generator>
#include <experimental/coroutine>


// coroutine : 특수한 함수
// return 을 안만나도 정지한다음에 main으로 돌아갈 수 있다.
// 속성 - c/c++ - 명령줄 - /await
// co_yield
// co_await
// co_return

using namespace std::chrono_literals;

std::experimental::generator<int> gen()
{
    std::cout << "gen0" << std::endl;
    co_yield 0; // 일시정지

    std::cout << "gen1" << std::endl;
    co_yield 1;

    std::cout << "gen2" << std::endl;
    co_yield 2;

    std::cout << "gen3" << std::endl;
    co_yield 3;

    std::cout << "gen4" << std::endl;
    co_yield 4;
}

std::experimental::generator<int> gen(int from, int to)
{
    for (auto i = from; i < to; ++i)
        co_yield i;
}

int longTimeJob()
{
    std::this_thread::sleep_for(2s);
    return 100;
}


std::future<int> coroutine()
{
    std::cout << "coroutine0" << std::endl;
    int result = co_await std::async(longTimeJob); //co_await까지 오고 일시정지

    std::cout << "coroutine1" << std::endl;
    co_return result;
}


int main()
{
    //{
    //    // generator 동작 1
    //    auto g = gen();
    //    std::cout << "main" << std::endl;

    //    auto iter = g.begin();

    //    std::cout << "main0" << std::endl;
    //    std::cout << *iter << std::endl;
    //    ++iter;

    //    std::cout << "main1" << std::endl;
    //    std::cout << *iter << std::endl;
    //    ++iter;

    //    std::cout << "main2" << std::endl;
    //    std::cout << *iter << std::endl;
    //    ++iter;
    //    return 0; 
    //}

    //{
    //    // generator 동작 2
    //    for (auto num : gen(0, 10))
    //    {
    //        std::cout << num << std::endl;
    //    }
    //    return 0;
    //}
    {
        // coroutine
        auto future = coroutine();
        std::cout << "main0" << std::endl;
        std::cout << future.get() << std::endl;
    }
}
// co_await std::experimental::suspend_never(); 일시정지안함
// co_await std::experimental::suspend_always(); 항상멈춤
// coroutine().wait();
// cppcoro