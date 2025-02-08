#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

struct Node {
    int val, pri, size;
    Node *l, *r;
    Node(int val):
        val(val), pri(rand()), size(1), l(nullptr), r(nullptr) {}
};

int getSize(Node* node) {
    return node ? node->size : 0;
}

void updateSize(Node* node) {
    if(node) node->size = getSize(node->l) + getSize(node->r) + 1;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->l;
    node->l = newRoot->r;
    newRoot->r = node;
    updateSize(node);
    updateSize(newRoot);
    return newRoot;
}

Node* rotateLeft(Node* node) {
    Node* newRoot = node->r;
    node->r = newRoot->l;
    newRoot->l = node;
    updateSize(node);
    updateSize(newRoot);
    return newRoot;
}

Node* insert(Node* root, int pos, int val) {
    if(!root) return new Node(val);

    int lSize = getSize(root->l);
    if(pos <= lSize) {
        root->l = insert(root->l, pos, val);
        if(root->l->pri > root->pri) {
            root = rotateRight(root);
        }
    } else {
        root->r = insert(root->r, pos - lSize - 1, val);
        if(root->r->pri > root->pri) {
            root = rotateLeft(root);
        }
    }

    updateSize(root);
    return root;
}

void printInOrder(Node* root) {
    if(!root) return;
    printInOrder(root->l);
    cout << root->val << ' ';
    printInOrder(root->r);
}

signed main() {
    hyper;
    srand(time(0));
    int n;
    cin >> n;
    Node* root = nullptr;
    rep(i,0,n) {
        int p;
        cin >> p;
        root = insert(root, p-1, i+1);
    }
    printInOrder(root);
    cout << '\n';
}
