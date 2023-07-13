#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <random>
#include <time.h>
#define M 10000
const int MIN = 0x80000000;
const int MAX = 0x7fffffff;
using namespace std;
int heap[M << 2]; // begin from 1
int len;
void down(int arr[], int& len, int idx)
{
    if ((idx << 1 | 0) > len && (idx << 1 | 1) > len) {
        return;
    }
    if ((idx << 1 | 1) <= len && (idx << 1 | 0) < len) {
        int l = arr[idx << 1 | 0], r = arr[idx << 1 | 1];
        int m = min(l, r);
        if (m >= arr[idx])
            return;
        if (l < r) {
            swap(arr[idx], arr[idx << 1 | 0]);
            down(arr, len, idx << 1 | 0);
        } else {
            swap(arr[idx], arr[idx << 1 | 1]);
            down(arr, len, idx << 1 | 1);
        }
        return;
    }
    if ((idx << 1 | 0) <= len) {
        swap(arr[idx], arr[idx << 1 | 0]);
        down(arr, len, idx << 1 | 0);
        return;
    }
    swap(arr[idx], arr[idx << 1 | 1]);
    down(arr, len, idx << 1 | 1);
}
void up(int arr[], int& len, int idx)
{
    if (idx > 1) {
        int p = arr[idx >> 1];
        if (p > arr[idx]) {
            swap(arr[idx >> 1], arr[idx]);
            up(arr, len, idx >> 1);
        }
    }
}
void insert(int arr[], int& len, int val)
{
    arr[++len] = val;
    up(arr, len, len);
}
int front(int arr[], int& len) { return arr[1]; }
int getsize(int arr[], int& len) { return len; }
void pop(int arr[], int& len)
{
    if (len == 0)
        return;
    swap(arr[1], arr[len]);
    len--;
    down(arr, len, 1);
}
void heapify(int arr[], int& len)
{
    for (int i = len; i > 1; --i) {
        down(arr, len, i >> 1);
    }
}
int main(int argc, char* argv[])
{
    srand(clock());
    len = 10;
    for (int i = 1; i <= len; ++i) {
        heap[i] = rand() % 50 - 25;
        cout << heap[i] << " ";
    }
    cout << endl;
    heapify(heap, len);
    for (int i = 1; i <= len; ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
    while (len) {
        cout << front(heap, len) << ' ';
        pop(heap, len);
    }
    cout << endl;
    return 0;
}
