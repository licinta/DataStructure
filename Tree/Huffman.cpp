
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
typedef struct node {
    char c;
    int count;
    node* left;
    node* right;
} Alpha;
Alpha alpha[256];
string s[] = { "abcdef", "aabb", "abdf", "bc" };
/*        the tree maybe like this:
 *           16
 *       7         9
 *   3     4     a   b
 * e  c  d   f
 *
 * */
int len = 4;

struct cmp {
    bool operator()(const Alpha a, const Alpha b) const { return a.count > b.count; }
};

priority_queue<Alpha, vector<Alpha>, cmp> pq;

void map_huffman(Alpha* node, string prefix)
{
    if (!node)
        return;
    map_huffman(node->left, prefix + "0");
    map_huffman(node->right, prefix + "1");
    if (node->left == nullptr && node->right == nullptr){
        cout << node->c << " " << node->count << " " << prefix << endl;
    }
}

void dfs(Alpha* root)
{
    if (root) {
        dfs(root->left);
        dfs(root->right);
    }
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 256; ++i) {
        alpha[i].c = (char)i;
        alpha[i].count = 0;
        alpha[i].left = nullptr;
        alpha[i].right = nullptr;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            alpha[int(s[i].c_str()[j])].count++;
        }
    }
    cout << "Summary\n";
    for (int i = 97; i < 97 + 26; ++i) {
        if (alpha[i].count) {
            pq.push(alpha[i]);
            cout << (char)i << ' ' << alpha[i].count << endl;
        }
    }

    // test the heap
    while (pq.size() > 1) {
        // Alpha a=pq.top();
        Alpha* a = new Alpha(pq.top());
        pq.pop();
        Alpha* b = new Alpha(pq.top());
        pq.pop();
        Alpha new_node = { 0, a->count + b->count, a, b };
        pq.push(new_node);
        // cout << new_node.c << ' ' << new_node.count << endl;
    }
    Alpha huffman = pq.top();
    pq.pop();
    cout << "All weight: " << huffman.count << endl;
    map_huffman(&huffman, "");
    cout << "the tree maybe like this:\n";
    cout << " *           16\n";
    cout << " *       7         9\n";
    cout << " *   3     4     a   b\n";
    cout << " * e  c  d   f\n";
    return 0;
}
