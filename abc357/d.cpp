#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
using namespace std;

const int MOD = 998244353;

int dgt(int n) {
    int ans = 0;
    while(n>0) {
        ans++;
        n /= 10;
    }
    return ans;
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

signed main() {
    int n;
    cin >> n;
    int d = dgt(n);
    int b = fastpow(10, d);
    int a = fastpow(b, n) - 1;
    int bInv = fastpow(b-1, MOD-2);
    cout << ((((n % MOD) * a) % MOD) * bInv) % MOD;
}