#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 105
#define MAXK 100005
#define MOD 1000000007

int n, k, a[MAXN], dp[MAXN][MAXK], ps[MAXK];

signed main() {
    hyper;
    cin >> n >> k;
    rep1(i,1,n) cin >> a[i];
    rep1(j,0,k) {
        dp[1][j] = (j <= a[1]);
        ps[j+1] = ps[j] + dp[1][j];
    }
    rep1(i,2,n) {
        rep1(j,0,k) dp[i][j] = (ps[j+1] - ps[max(0,j-a[i])]) % MOD;
        rep1(j,0,k) ps[j+1] = ps[j] + dp[i][j];
    }
    cout << dp[n][k];
}
