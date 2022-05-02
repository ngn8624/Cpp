#line 1 "main.cpp"
import std.core;
import std.memory;
import std.threading;

int main()
{
    
    
    
    
    

    std::cout << "a" << std::endl;

    std::vector<int> nums{ 1, 2, 3 };
    for (auto num : nums)
    {
        std::cout << num << std::endl;
    }

    std::thread th([] {
        std::cout << "async" << std::endl;
        });

    std::unique_ptr<int> i = std::make_unique<int>(10);
    std::cout << *i << std::endl;
    th.join();
}
