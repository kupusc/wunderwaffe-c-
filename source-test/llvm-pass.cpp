#include <CppUTest/TestHarness.h>
#include <stdio.h>
#include <string>
#include <llvm-pass.h>

//////////  Stubs /////////


//////// Fixture //////////

std::string compile_cmd = "clang++ ";

std::string file_path = "./llvm-pass-example.cpp";
std::string compilation = compile_cmd + file_path;

TEST_GROUP(llvm)
{
    void setup()
    {
    }
};


//////// Tests /////////////

TEST(llvm, compiles)
{
    CHECK_EQUAL(wunderwaffe::execute(compilation), 0);
}

// TEST(llvm, freetest)
// {
//     CHECK_EQUAL(wunderwaffe::execute("ls -l"), 0);
// }
