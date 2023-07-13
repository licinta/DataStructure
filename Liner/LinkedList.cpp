#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T> struct node {
    T val;
    node<T>* next;
};
template <typename T> class linked {
public:
    node<T>* head;
    int length;
    linked()
    {
        head = nullptr;
        length = 0;
    }
    node<T>* index(int i)
    {
        node<T>* p = head;
        for (int j = 0; j < i; ++j) {
            if (p)
                p = p->next;
            else
                return p;
        }
        return p;
    }
    void insert(int i, T val)
    {
        node<T>* n = new node<T> { val, nullptr };
        length++;
        if (length == 1) {
            head = n;
            return;
        }
        if (i == 0) {
            n->next = head;
            head = n;
            return;
        }
        node<T>* p = index(i - 1);
        n->next = p->next;
        p->next = n;
    }
    int remove(int i)
    {
        if (length == 0 || i >= length) {
            return -1;
        }
        length--;
        node<T>*p = head;
        node<T>*q = nullptr;
        if (i == 0) {
            p = head;
            head = head->next;
            free((void*)p);
            return 0;
        }
        p = index(i - 1);
        if (i == length) {
            q = p->next;
            p->next = nullptr;
            free((void*)q);
        } else {
            q = p->next;
            p->next = p->next->next;
            free((void*)q);
        }
        return 0;
    }
    vector<T> toArray()
    {
        node<T>* p = head;
        vector<T> v;
        for (int i = 0; i < length; ++i) {
            v.push_back(p->val);
            p = p->next;
        }
        return v;
    }
};
int main(int argc, char* argv[])
{
    linked<int> l;
    for (int i = 0; i < 10; ++i) {
        l.insert(l.length, i);
    }
    l.insert(0, -3);
    l.insert(1, -2);
    l.insert(2, -1);
    cout << l.toArray().size() << endl;
    for (auto i : l.toArray()) {
        cout << i << " ";
    }
    cout << endl;
    l.remove(1);
    l.remove(0);
    l.remove(l.length - 1);//0
    l.remove(l.length - 0);//1

    cout << l.toArray().size() << endl;
    for (auto i : l.toArray()) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
