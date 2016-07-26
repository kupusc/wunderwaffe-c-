#include <CppUTest/TestHarness.h>
#include <string>
#include <multitask.h>

//////// Fixture //////////

TEST_GROUP(smoke_llvm)
{
    const std::string clang_build_cmd = "clang++ ";
    const std::string file_path = "./llvm-pass-example.cpp";
    const std::string clang_bitcode_cmd = clang_build_cmd + " -emit-llvm -c " + file_path;
    const std::string clang_build = clang_build_cmd + file_path;
    const std::string pass_test = "opt -load ./libllvm-pass.so -mutation < llvm-pass-example.bc > /dev/null";

    void setup()
    {
    }
};


//////// Tests /////////////

TEST(smoke_llvm, compiles_with_clang)
{
    CHECK_EQUAL(execute(clang_build.c_str()), 0);
}

TEST(smoke_llvm, generates_a_bitcode)
{
    CHECK_EQUAL(execute(clang_bitcode_cmd.c_str()), 0);
}

TEST(smoke_llvm, mutation_pass_works)
{
    execute(clang_bitcode_cmd.c_str());
    CHECK_EQUAL(execute(pass_test.c_str()), 0);
}
