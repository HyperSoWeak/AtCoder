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
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 55;

mat operator*(const mat &a, const mat &b) {
    int n = a.size();
    mat c(n, vi(n, 0));
    rep(i,0,n) rep(j,0,n) rep(k,0,n)
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
    return c;
}

mat operator^(mat a, int k) {
    int n = a.size();
    mat b(n, vi(n, 0));
    rep(i,0,n) b[i][i] = 1;
    while(k) {
        if(k & 1) b = b * a;
        a = a * a;
        k >>= 1;
    }
    return b;
}

signed main() {
    hyper;
    int n, k;
    cin >> n >> k;
    mat a(n, vi(n));
    rep(i,0,n) rep(j,0,n) cin >> a[i][j];
    mat b = a ^ k;
    int sum = 0;
    rep(i,0,n) rep(j,0,n) sum = (sum + b[i][j]) % MOD;
    cout << sum << '\n';
}
