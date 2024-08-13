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
const int MN = 3e5+5;

int n, a[MN], c[MN];

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i];
        rep(j,0,30) {
            if((a[i]>>j)&1) c[j]++;
        }
    }
    int ans = 0;
    rep(i,0,n) ans += a[i];
    rep(i,0,n) {
        int sum = 0;
        for(int j=0,k=1; j<30; ++j,k<<=1) {
            if((a[i]>>j)&1) sum += (n-c[j]) * k;
            else sum += c[j] * k;
        }
        ans = max(ans, sum);
    }
    cout << ans;
}
