#include "singleton.h"
#include <iostream>

class basic_test
{
public:
    basic_test() :
        val_(0)
    {
        std::cout << "Constructor\n";
    }

    ~basic_test()
    {
        std::cout << "Destructor\n";
    }

    int get_val()
    {
        return val_;
    }

    void set_val(int x)
    {
        val_ = x;
    }

private:
    int val_;
};

typedef singleton<basic_test> single_test;


void fn()
{
    auto z = single_test::instance();
    std::cout << "inside fn(), val = " << single_test::instance()->get_val() << std::endl;
}


int main()
{
    auto x = single_test::instance();
    auto y = single_test::instance();
    //auto y = single_test(*x);
    //single_test y = x;

    std::cout << "address of x = " << x << std::endl;
    std::cout << "address of y = " << y << std::endl;

    int a = x->get_val();
    std::cout << "a = " << a << std::endl;

    x->set_val(3);

    a = y->get_val();
    std::cout << "a = 3? " << a << std::endl;

    y->set_val(2);

    a = x->get_val();
    std::cout << "a = 2? " << a << std::endl;

    fn();
    return 0; 
}

