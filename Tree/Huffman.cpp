
#include <functional>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
typedef struct node {
    char c;
    int count;
    node *left;
    node *right;
} Alpha;
Alpha alpha[256];
string s[] = {"abcdef", "aabb", "abdf", " bc"};
int len = 4;

struct cmp {
    bool operator()(const Alpha a, const Alpha b) const { return a.count > b.count; }
};

priority_queue<Alpha, vector<Alpha>, cmp> pq;

void map_huffman(Alpha *node, string prefix) {
    if (!node)
        return;
    if (node->left) {
        map_huffman(node->left, prefix + "0");
    }
    if (node->right) {
        map_huffman(node->right, prefix + "1");
    }
    cout << node->c << " " << node->count << " " << prefix << endl;
}

void dfs(Alpha *root) {
    if (root) {
        dfs(root->left);
        dfs(root->right);
    }
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < 256; ++i) {
        alpha[i].c = (char) i;
        alpha[i].count = 0;
        alpha[i].left = nullptr;
        alpha[i].right = nullptr;
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            alpha[int(s[i].c_str()[j])].count++;
        }
    }
    for (int i = 97; i < 97 + 26; ++i) {
        if (alpha[i].count)
            pq.push(alpha[i]);
    }

    // test the heap
    while (pq.size() > 1) {
        //Alpha a=pq.top();
        Alpha *a = new Alpha(pq.top());
        pq.pop();
        Alpha *b = new Alpha(pq.top());
        pq.pop();
        Alpha new_node = {0, a->count + b->count, a, b};
        pq.push(new_node);
        cout << new_node.c << ' ' << new_node.count << endl;
    }
    Alpha huffman = pq.top();
    pq.pop();
    cout << huffman.c << " " << huffman.count << endl;
    // map_huffman(&huffman, "");
    dfs(&huffman);
    return 0;
}
