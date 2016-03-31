int main(int argc, char** argv) {
    int b = 6;
    if(true) {
        for(int i = 0; i < 100; i++) {
            b = i + b;
        }
    }
    return b;
};
