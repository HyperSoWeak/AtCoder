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
#define MAXN 1005
#define MOD 998244353

int h, w, clr[MAXN][MAXN], cnt = 0, cc = 0;
string s[MAXN];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool check(int x, int y) {
    return (x>=0 && y>=0 && x<h && y<w);
}
void dfs(int x, int y) {
    if(clr[x][y] || !check(x, y) || s[x][y]!='#') return;
    clr[x][y] = cnt;
    rep(i,0,4) dfs(x+dx[i],y+dy[i]);
}

int fastpow(int n, int p) {
    int ans = 1;
    while(p > 0) {
        if(p & 1) ans = (ans*n) % MOD;
        p >>= 1;
        n = (n*n) % MOD;
    }
    return ans;
}
int modInv(int n) { return fastpow(n, MOD-2); }

signed main() {
    hyper;
    cin >> h >> w;
    rep(i,0,h) cin >> s[i];
    rep(i,0,h) rep(j,0,w) {
        if(s[i][j]=='#' && !clr[i][j]) {
            cnt++;
            dfs(i,j);
        }
    }
    int sum = 0;
    rep(x,0,h) rep(y,0,w) {
        if(clr[x][y]) continue;
        cc++;
        unordered_set<int> st;
        rep(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if(check(nx,ny) && clr[nx][ny]) st.insert(clr[nx][ny]);
        }
        sum += 1ll - st.size();
    }
    cout << ((cc*cnt+sum)%MOD*modInv(cc))%MOD;
}