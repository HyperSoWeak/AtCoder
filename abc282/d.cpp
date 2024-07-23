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

int n, m;
vector<int> g[MAXN];
int clr[MAXN], cnt = 1;
bool ok = 1;

int Cn2(int n) { return n * (n-1) / 2; }

void dfs(int u, bool c) {
    if(clr[u]) {
        if(clr[u] != (cnt+c)) ok = 0;
        return;
    }
    clr[u] = cnt + c;
    for(int v: g[u]) dfs(v,!c);
}

signed main() {
    hyper;
    cin >> n >> m;
    rep(i,0,m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep1(i,1,n) {
        if(!clr[i]) {
            dfs(i,0);
            cnt += 2;
        }
    }
    if(!ok) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = Cn2(n) - m, cc[cnt+5] = {0};
    rep1(i,1,n) cc[clr[i]]++;
    rep(i,1,cnt) ans -= Cn2(cc[i]);
    cout << ans;
}