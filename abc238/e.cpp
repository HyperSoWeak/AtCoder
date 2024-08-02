#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

int n, q, l, r;
vector<int> g[MAXN];
bool vis[MAXN];

signed main() {
    hyper;
    cin >> n >> q;
    rep(i,0,q) {
        cin >> l >> r;
        g[l-1].push_back(r);
        g[r].push_back(l-1);
    }
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        if(u == 0) return cout << "Yes\n", 0;
        for(int v: g[u]) if(!vis[v]) q.push(v);
    }
    cout << "No\n";
}