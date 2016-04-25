#include <CppUTest/TestHarness.h>
#include <boost/iterator.hpp>

extern "C"
{
    #include <build.h>
}

TEST_GROUP(free_test)
{
    void setup()
    {
    }
    void teardown()
    {

    }
};

class A
{
public:
    A(){}
    ~A(){};
};

// bool func1() {
//     const char* a{"yoyoyo"};
//     boost::iterator<const char*> it;
//     return true;
// }

TEST(free_test, must)
{
    // CHECK(func1() == true);
}
