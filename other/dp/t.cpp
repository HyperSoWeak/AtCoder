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
const int MN = 2e5+5;

signed main() {
    hyper;
    int n;
    string s;
    cin >> n >> s;
    mat dp(n+1, vi(n+1, 0));
    dp[1][1] = 1;
    rep1(i,2,n) {
        vi ps(i+1, 0);
        rep1(j,1,i-1) ps[j] = (ps[j-1] + dp[i-1][j]) % MOD;
        rep1(j,1,i) {
            if(s[i-2] == '<') dp[i][j] = ps[j-1];
            else dp[i][j] = (ps[i-1] - ps[j-1] + MOD) % MOD;
        }
    }
    int ans = 0;
    rep1(i,1,n) ans = (ans + dp[n][i]) % MOD;
    cout << ans << '\n';
}
