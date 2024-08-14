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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 1e5+5;

int n, dp[MN], sz[MN];
vector<int> e[MN];

struct Sub {
    int v, type;
    Sub(int a, int b): v(a), type(b) {}
};
bool cmp(const Sub& a, const Sub& b) {
    if(a.type != b.type) return a.type > b.type;
    return a.v > b.v;
}

void dfs(int u) {
    sz[u] = 1;
    dp[u] = 0;
    if(!e[u].size()) return;
    vector<Sub> q;
    for(int v: e[u]) {
        dfs(v);
        sz[u] += sz[v];
        int t;
        if(sz[v]%2==0) {
            if(dp[v]-1 > 0) t = 2;
            else t = 0;
        } else t = 1;
        q.emplace_back(dp[v]-1, t);
    }
    sort(q.begin(), q.end(), cmp);
    bool turn = 1;
    for(auto [v,t]: q) {
        if(t == 2) dp[u] += v;
        else if(t == 1) {
            if(turn) dp[u] += v;
            else dp[u] -= v;
            turn = !turn;
        }
        else {
            if(turn) dp[u] += v;
            else dp[u] -= v;
        }
    }
}

signed main() {
    hyper;
    cin >> n;
    rep1(x,2,n) {
        int y;
        cin >> y;
        e[y].push_back(x);
    }
    dfs(1);
    cout << (n-1-dp[1])/2+1;
}
