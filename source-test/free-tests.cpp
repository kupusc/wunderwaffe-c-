#include <CppUTest/TestHarness.h>

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
TEST(free_test, must)
{
    // A a;
    // a.~A();
    unsigned char a = 255;
    // std::cout << a + 1 << std::endl;
    // FAIL("me");
}
