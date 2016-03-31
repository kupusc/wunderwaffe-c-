#include <CppUTest/TestHarness.h>
#include <stdio.h>
#include <string>
#include <llvm-pass.h>

//////////  Stubs /////////


//////// Fixture //////////

std::string compile_cmd = "clang++ ";

std::string compilation = compile_cmd + "./llvm-pass-example.cpp";

TEST_GROUP(llvm)
{
    void setup()
    {
    }
};


//////// Tests /////////////

TEST(llvm, works)
{
    execute(compilation);
}
