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
const int MN = 1e5+5;

signed main() {
    hyper;
    int n, a[MN], l[MN], r[MN];
    cin >> n;
    rep1(i,1,n) cin >> a[i];
    l[1] = a[1], r[n] = a[n];
    rep1(i,2,n) l[i] = gcd(l[i-1], a[i]);
    for(int i=n-1; i>=1; --i) r[i] = gcd(r[i+1], a[i]);
    int ans = max(l[n-1], r[2]);
    rep1(i,2,n-1) ans = max(ans, gcd(l[i-1], r[i+1]));
    cout << ans << '\n';
}
