#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

int n, m, in[MAXN], x, y, ans[MAXN];
vector<int> g[MAXN], a;
queue<int> q;

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        cin >> x >> y;
        g[x].push_back(y);
        in[y]++;
    }
    rep1(i,1,n) if(!in[i]) q.push(i);
    while(!q.empty()) {
        if(q.size() > 1) {
            cout << "No\n";
            return 0;
        }
        int t = q.front(); q.pop();
        a.push_back(t);
        for(int e: g[t]) if(!--in[e]) q.push(e);
    }
    rep(i,0,n) ans[a[i]] = i+1;
    cout << "Yes\n";
    rep1(i,1,n) cout << ans[i] << ' ';
}