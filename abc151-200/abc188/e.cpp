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
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MN = 2e5+5;

int n, m, a[MN], dp[MN];
vector<int> e[MN];

signed main() {
    hyper;
    cin >> n >> m;
    rep1(i,1,n) cin >> a[i];
    rep(i,0,m) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
    }
    rr(dp, 0x3f);
    rep1(i,1,n) {
        for(int j: e[i]) {
            dp[j] = min(dp[j], min(dp[i], a[i]));
        }
    }
    int ans = -INF;
    rep1(i,1,n) ans = max(ans, a[i]-dp[i]);
    cout << ans;
}