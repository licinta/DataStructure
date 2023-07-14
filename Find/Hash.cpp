#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Hash {
private:
    vector<list<string>>* hash_table;
    int mod = 1777;
    int hash_code(string s)
    {
        int hash = 0;
        for (char i : s) {
            hash += (int)i;
            hash <<= 1;
            hash %= mod;
        }
        return hash;
    }

public:
    int length;
    Hash()
    {
        length = 0;
        hash_table = new vector<list<string>>(mod);
    }
    void insert(string val) { hash_table->at(hash_code(val)).push_back(val); }
    void remove(string val) { hash_table->at(hash_code(val)).remove(val); }
    bool haskey(string val)
    {
        auto iter = hash_table->at(hash_code(val));
        if (find(iter.begin(), iter.end(), val) != iter.end())
            return true;
        return false;
    }
};
void Tester()
{
    Hash hash;
    string s[] = { "123", "abc", "pandas", "cat", "car" };
    for (int i = 0; i < 5; ++i) {
        hash.insert(s[i]);
        cout << "insert into hash_table with value " << s[i] << endl;
    }
    cout << "haskey for 123: " << hash.haskey("123") << endl;
    cout << "haskey for abc: " << hash.haskey("abc") << endl;
    cout << "haskey for cad: " << hash.haskey("cad") << endl;
    cout << "remove 123 in hash_table" << endl;
    hash.remove("123");
    cout << "haskey for 123: " << hash.haskey("123") << endl;
    cout << "haskey for abc: " << hash.haskey("abc") << endl;
    cout << "haskey for cad: " << hash.haskey("cad") << endl;
    return;
}
int main(int argc, char* argv[])
{
    Tester();
    return 0;
}
