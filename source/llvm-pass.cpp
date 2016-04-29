#include "llvm-pass.h"
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    struct Hello : public FunctionPass {
        static char ID;
        Hello() : FunctionPass(ID) {}
        bool runOnFunction(Function &F) override {
          errs() << "Hello: ";
          errs().write_escaped(F.getName()) << "\n";
          return false;
      }
    };
    char Hello::ID = 0;
    static RegisterPass<Hello> X("hello", "Hello World Pass",
                                 false /* Only looks at CFG */,
                                 false /* Analysis Pass */);
};

namespace wunderwaffe
{
    int execute(std::string const& command)
    {
        FILE * f = popen( command.c_str(), "r" );
        if ( f == 0 ) {
            fprintf( stderr, "Could not execute\n" );
            return -1;
        }
        const int BUFSIZE = 1000;
        char buf[ BUFSIZE ];
        while( fgets( buf, BUFSIZE,  f ) ) {
            fprintf( stdout, "%s", buf  );
        }
        pclose( f );
        return 0;
    }
}
