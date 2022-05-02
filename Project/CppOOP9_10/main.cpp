#include <iostream>
#include <future>
#include <chrono>


// ���� thread �� row level �� ����ȭ ������ ������ : ���� �����ϱⰡ ��ƴ�
// �Ʒ� �͵��� ���� ������ �߻�ȭ���ص�
// future : ������ ������
// promise : ������ �۽���
// packaged_task
// async


using namespace std::chrono_literals;

int main()
{
    // �� ���? �����忡 ����� �� �ִ�.
    //{
    //    std::promise<int> pro;
    //    std::future<int> fut = pro.get_future();

    //    pro.set_value(10); // set_value ���ϸ� ���ŷ �ɸ�
    //    //pro.set_value(10); // �ι� set_value() ����
    //    std::cout << fut.get() << std::endl;
    //    //std::cout << fut.get() << std::endl; // �ι� get() ����
    //    return 0;
    //}

    //{
    //    // promise - future - value
    //    std::promise<int> pro;
    //    std::future<int> fut = pro.get_future(); // promise�� ���� ���� ������

    //    std::thread th([](std::promise<int> pro) {
    //        std::this_thread::sleep_for(2s);
    //        pro.set_value(10);
    //        }, std::move(pro)); // promise�� �̵��� ������ ���̶� move() �̿�

    //    std::cout << fut.get() << std::endl; // 10
    //    th.join();
    //    return 0;
    //}

    //{
    //    //���� ����
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
    //    //���� �����ϴϱ� packaged_task �̿�
    //    // packaged_task
    //    // promise�� ����� ������ exception�� ������ ������������� packaged_task�� ����� ��� �ڵ鸵�� �˾Ƽ� ���ش�
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
        // ������ ���ε� ������...
        // �Ʒ�ó�� ����
        // async
        // thread ����� ������ ����
        // thread ���������� ������� �ȸ������ ���� �̰��� async �� �޸�
        // std::launch::deferred�� ������ �ȸ��鵵�� ����
        // std::launch::deferred�� fut.get()�� ���������� ���� �ٵ� ������������
        // std::launch::async �� ������ �ٸ� �����忡�� �����ϵ�����
        // std::launch::deferred | std::launch::async ó�� | ������ �ϰԵ� ��� �����ϳ� �ϴ� ��
        // os ���� �����ڿ��� ������ �ѱ����ν�, ���� ����ȭ ������ ���α׷����� �� �� �ִ�. �ƴҼ���,..
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