#include <iostream>
#include <string>

void KMP(std::string src, std::string dst);
void KMP(std::string src, std::string dst)
{
    //=================next=====================
    int next[dst.length() + 1];
    next[0] = 0;
    int i = 0, j = 0;
    for (i = 1; i <= dst.length(); i++) {
        while (j && dst[j] != dst[i]) {
            j = next[j - 1];
        }
        if (dst[j] == dst[i]) {
            j++;
        }
        next[i] = j;
    }
    //=================match======================
    i = 0, j = 0;
    for (i = 0; i < src.length(); i++) {
        while (j && src[i] != dst[j]) {
            j = next[j - 1];
        }
        if (src[i] == dst[j])
            j++;
        if (j == dst.length()) {
            std::cout << "Find at " << i - j + 1 << std::endl;
            j = next[j - 1];
        }
    }
    return;
}
