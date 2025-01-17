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
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

struct Fenwick {
    vector<int> v;
    int sz;
    Fenwick(int n) {
        v.resize(n+1, 0);
        sz = n;
    }
    int lowbit(int x) { return x&-x; }
    void modify(int p, int x) {
        for(int i=p; i<=sz; i+=lowbit(i)) v[i] += x;
    }
    int query(int p) {
        int sum = 0;
        for(int i=p; i>0; i-=lowbit(i)) sum += v[i];
        return sum;
    }
};

signed main() {
    hyper;
    
}
