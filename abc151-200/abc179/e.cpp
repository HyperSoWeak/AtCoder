#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXM 100005

int n, x, m, f[MAXM], a[MAXM];

signed main() {
    hyper;
    cin >> n >> x >> m;
    int l = 1, r = n;
    rep1(i,1,n) {
        if(f[x]) {
            l = f[x], r = i - 1;
            break;
        }
        f[x] = i;
        a[i] = x;
        x = (x*x) % m;
    }
    int ans = 0, sum = 0;
    rep1(i,1,l-1) ans += a[i];
    rep1(i,l,r) sum += a[i];
    ans += sum * ((n-l+1) / (r-l+1));
    rep(i,l,l+((n-l+1)%(r-l+1))) ans += a[i];
    cout << ans;
}