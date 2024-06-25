#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

int n, m, k, ans = 0;
int a[MAXN], rk[MAXN], lst[MAXN];

signed main() {
    hyper;
    cin >> n >> m >> k;
    rep(i,0,n) cin >> a[i];
    for(int d=30; d>=0; --d) {
        rep(i,0,n) {
            rk[i] = lst[i];
            if(!((a[i]>>d) & 1)) rk[i] += (1<<d) - (a[i] % (1<<d));
        }
        sort(rk, rk+n);
        int sum = 0;
        rep(i,0,k) sum += rk[i];
        if(sum <= m) {
            ans += (1<<d);
            rep(i,0,n) {
                if(!((a[i]>>d) & 1)) {
                    lst[i] += (1<<d) - (a[i] % (1<<d));
                    a[i] = 0;
                }
            }
        }
    }
    cout << ans;
}