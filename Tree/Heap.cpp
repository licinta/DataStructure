#include <__node_handle>
#include <iostream>
#define M 10000
const int MIN = 0x80000000;
const int MAX = 0x7fffffff;
using namespace std;
int heap[M << 2];
int len;
void down(int arr[], int len, int idx)
{

    int l = arr[idx << 1 | 0], r = arr[idx << 1 | 1];
    if (idx < len) {
        l = l ^ min(l, r);
        swap(arr[idx], arr[idx << 1 | l]);
        down(arr, len, idx << 1 | l);
        return;
    }
}
void up(int arr[], int len, int idx)
{
    if (idx) {
        int p = arr[idx >> 1];
        if (p > arr[idx]) {
            swap(arr[idx >> 1], arr[idx]);
            up(arr, len, idx >> 1);
        }
    }
}
void insert(int arr[], int& len, int val)
{
    arr[len++] = val;
    up(arr, len, len);
}
void pop(int arr[],int len){
//
}
void heapify(int arr[], int len) { }
int main(int argc, char* argv[])
{
    std::cout << MIN << ' ' << MAX << endl;
    return 0;
}
