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

int q, k, dp[5005];

signed main() {
    hyper;
    cin >> q >> k;
    dp[0] = 1;
    while(q--) {
        char op;
        int x;
        cin >> op >> x;
        if(op == '+') {
            for(int i=k; i>=x; --i) {
                dp[i] = (dp[i] + dp[i-x]) % MOD;
            }
        }
        else {
            rep1(i,x,k) {
                dp[i] = (dp[i] - dp[i-x] + MOD) % MOD;
            }
        }
        cout << dp[k] << '\n';
    }
}