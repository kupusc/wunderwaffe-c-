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

TEST(llvm, works)
{
    wunderwaffe::execute(compilation);
}
