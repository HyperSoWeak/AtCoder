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

struct Circle {
    int x, y, r;
} a[3005];
int n, sx, sy, tx, ty;
vector<int> g[3005];
int find(int x, int y) {
    rep(i,0,n) {
        if((a[i].x-x)*(a[i].x-x)+(a[i].y-y)*(a[i].y-y) == a[i].r*a[i].r) return i;
    }
    return -1;
}

bool can = 0, vis[3005] = {0};
void dfs(int x, int t) {
    if(vis[x]) return;
    if(x == t) can = 1;
    vis[x] = 1;
    for(int i: g[x]) dfs(i, t);
}

signed main() {
    hyper;
    cin >> n >> sx >> sy >> tx >> ty;
    rep(i,0,n) cin >> a[i].x >> a[i].y >> a[i].r;
    rep(i,0,n) rep(j,i+1,n) {
        int d = (a[i].x-a[j].x)*(a[i].x-a[j].x) + (a[i].y-a[j].y)*(a[i].y-a[j].y); 
        if(d <= (a[i].r+a[j].r)*(a[i].r+a[j].r) && d >= (a[i].r-a[j].r)*(a[i].r-a[j].r)) {
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    int s = find(sx,sy), t = find(tx,ty);
    dfs(s, t);
    if(can) cout << "Yes\n";
    else cout << "No\n";
}