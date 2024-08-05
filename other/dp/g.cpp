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
#define MAXN 100005

int n, m, in[MAXN], dp[MAXN];
vector<int> g[MAXN];

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
    queue<int> q;
    rep1(i,1,n) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: g[u]) {
            dp[v] = max(dp[v], dp[u]+1);
            if(!--in[v]) q.push(v);
        }
    }
    cout << *max_element(dp+1, dp+1+n);
}