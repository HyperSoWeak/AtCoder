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
const int MN = 2e5+5;

int n, dpt[MN];
vector<int> e[MN];

void dfs(int u) {
    if(e[u].size() == 0) {
        dpt[u] = 0;
        return;
    }
    vector<int> q;
    for(int v: e[u]) {
        dfs(v);
        q.push_back(dpt[v]);
    }
    sort(q.begin(), q.end(), greater<int>());
    dpt[u] = 0;
    rep(i,0,q.size()) {
        dpt[u] = max(dpt[u], q[i]+i+1);
    }
}

signed main() {
    hyper;
    cin >> n;
    rep1(u,2,n) {
        int v;
        cin >> v;
        e[v].push_back(u);
    }
    dfs(1);
    cout << dpt[1];
}
