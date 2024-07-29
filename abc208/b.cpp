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

int p, f[15];

signed main() {
    hyper;
    cin >> p;
    f[0] = 1;
    rep1(i,1,10) f[i] = f[i-1] * i;
    int ans = 0;
    for(int i=10; i>=1; --i) {
        ans += p / f[i];
        p %= f[i];
    }
    cout << ans;
}