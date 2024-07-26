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
#define MOD 998244353

int k, n, a[1024][1024];
bool ok[1024][1024];
string s, ss = "AB";

bool check(int l, int t) {
    int tt = t;
    rep(i,0,k) {
        if(s[l-1-i] != '?' && s[l-1-i] != ss[tt&1]) return false;
        tt >>= 1;
    }
    rep(i,0,k/2) {
        if(((t>>i)&1) != ((t>>(k-1-i))&1)) return true;
    }
    return false;
}

int dp(int l, int t) {
    if(ok[l][t]) return a[l][t];
    if(!check(l,t)) {
        ok[l][t] = 1, a[l][t] = 0;
        return 0;
    }
    a[l][t] = (dp(l-1, (t>>1)) + dp(l-1, (t>>1)|(1<<(k-1)))) % MOD;
    ok[l][t] = 1;
    return a[l][t];
}

signed main() {
    hyper;
    cin >> n >> k >> s;
    rep(i,0,1<<k) {
        ok[k][i] = 1;
        if(check(k,i)) a[k][i] = 1;
    }
    int ans = 0;
    rep(i,0,1<<k) ans = (ans + dp(n,i)) % MOD;
    cout << ans;
}