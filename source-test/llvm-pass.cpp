#include <CppUTest/TestHarness.h>
#include <string>
#include <multitask.h>

//////////  Stubs /////////
const std::string clang_build_cmd = "clang++ ";
const std::string file_path = "./llvm-pass-example.cpp";
const std::string clang_build = clang_build_cmd + file_path;

//////// Fixture //////////

TEST_GROUP(llvm)
{
    void setup()
    {
    }
};


//////// Tests /////////////

TEST(llvm, compiles_with_clang)
{
    CHECK_EQUAL(execute(clang_build.c_str()), 0);
}

TEST(llvm, generates_a_bitcode)
{
    const std::string clang_bitcode_cmd = clang_build_cmd + " -emit-llvm -c " + file_path;
    CHECK_EQUAL(execute(clang_bitcode_cmd.c_str()), 0);
}

TEST(llvm, mutation_pass_works)
{
    const std::string pass_test = "opt -load ./libllvm-pass.so -mutation < llvm-pass-example.bc > /dev/null";
    CHECK_EQUAL(execute(pass_test.c_str()), 0);
}
