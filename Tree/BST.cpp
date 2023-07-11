
#include"iostream"

#define max(l, r) l>r?l:r
#define MA 105
using namespace std;
typedef struct node {
    node *l, *r;
    int val;
} node;
int preorder[MA];

int midorder[MA];

int postorder[MA];


node *insert(node *root, int val) {
    if (val < root->val) {
        if (root->l)
            return insert(root->l, val);
        root->l = new node{nullptr, nullptr, val};
    } else {
        if (root->r)
            return insert(root->r, val);
        root->r = new node{nullptr, nullptr, val};
    }
    return root;
}

node *build(int arr[], int len, node *&root) {
    int b = 0;
    if (!root) {
        root = new node{nullptr, nullptr, arr[b++]};
    }
    for (int i = b; i < len; ++i) {
        insert(root, arr[i]);
    }
    return root;
}

void preOrder(node *root) {
    if (root) {
        preorder[preorder[0]++ + 1] = root->val;
        preOrder(root->l);
        preOrder(root->r);
    }
}

void midOrder(node *root) {
    if (root) {
        midOrder(root->l);
        midorder[midorder[0]++ + 1] = root->val;
        midOrder(root->r);
    }
}

void postOrder(node *root) {
    if (root) {
        postOrder(root->l);
        postOrder(root->r);
        postorder[postorder[0]++ + 1] = root->val;
    }
}

void print(int arr[]) {
    for (int i = 1; i <= arr[0]; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int layerorder[MA][MA];
int depth;

void layerOrder(node *root, int i, int depth) {
    if (root) {
        if (i == depth) {
            //this layer
            layerorder[depth][layerorder[depth][0]++ + 1] = root->val;
        }
        layerOrder(root->l, i + 1, depth);
        layerOrder(root->r, i + 1, depth);
    }

}

int getDetpth(node *root) {
    if (root) {
        return max(getDetpth(root->l), getDetpth(root->r)) + 1;
    }
    return 0;
}

int main() {
    node *root = nullptr;
    int arr[] = {2, 1, 3, 4, 5};
    build(arr, 5, root);
    preOrder(root);
    midOrder(root);
    postOrder(root);
    for (int i = 0; i <= getDetpth(root); ++i)
        layerOrder(root, 0, i);
    print(preorder);
    print(midorder);
    print(postorder);
    for (int i = 0; i <= getDetpth(root); ++i)
        print(layerorder[i]);
    return 0;
}