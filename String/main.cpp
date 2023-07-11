#include "algo.h"
int main(int argc, char* argv[])
{
    std::string src = "abababd";
    std::string dst = "aba";
    KMP(src, dst);
    return 0;
}
