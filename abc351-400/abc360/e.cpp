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

int mod(int n) { return (n % MOD + MOD) % MOD; }
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
int modDiv(int n, int m) { return mod(mod(n) * modInv(mod(m))); }

signed main() {
    hyper;
    int n, k;
    cin >> n >> k;
    int p = mod(1-modDiv(2*(n-1), n*n));
    int q = modDiv(2, n*n);
    int f = 1;
    rep(i,0,k) f = mod(f * p + mod(1-f) * q);
    int d = modDiv(n+2, 2);
    cout << mod(f + d * mod(1-f));
}