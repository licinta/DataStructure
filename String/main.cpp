#include "algo.h"
int main(int argc, char* argv[])
{
    std::string src = "abababd";
    std::string dst = "ababd";
    KMP(src, dst);
    return 0;
}
