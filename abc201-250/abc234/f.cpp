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
const int MOD = 998244353;
const int MN = 5005;

string s;
int f[26], n;
int dp[26][MN];
int rec[MN][MN];

int nCr(int n, int r) {
    if(rec[n][r]) return rec[n][r];
    if(r == 0 || r == n) return rec[n][r] = 1;
    return rec[n][r] = (nCr(n-1,r-1) + nCr(n-1,r)) % MOD;
}

signed main() {
    hyper;
    cin >> s;
    n = s.size();
    for(char c: s) f[c-'a']++;
    rep1(i,0,f[0]) dp[0][i] = 1;
    rep1(i,1,25) {
        rep1(j,0,n) {
            int sum = 0;
            rep1(k,0,min(f[i],j)) {
                sum += dp[i-1][j-k] * nCr(j,k);
                sum %= MOD;
            }
            dp[i][j] = sum;
        }
    }
    int ans = 0;
    rep1(i,1,n) ans = (ans + dp[25][i]) % MOD;
    cout << ans << '\n';
}
