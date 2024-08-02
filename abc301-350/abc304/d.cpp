#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 200005

int w, h, n, p[MAXN], q[MAXN];
int A, B, a[MAXN], b[MAXN];
unordered_map<int, int> mp;

signed main() {
    hyper;
    cin >> w >> h >> n;
    rep(i,0,n) cin >> p[i] >> q[i];
    cin >> A;
    rep(i,0,A) cin >> a[i];
    cin >> B;
    rep(i,0,B) cin >> b[i];
    sort(a, a+A);
    sort(b, b+B);
    rep(i,0,n) {
        int x = upper_bound(a, a+A, p[i]) - a;
        int y = upper_bound(b, b+B, q[i]) - b;
        mp[x * MAXN + y]++;
    }
    int mx = 0, mn = INF;
    if(mp.size() < (A+1) * (B+1)) mn = 0;
    for(auto& e: mp) {
        mx = max(mx, e.se);
        mn = min(mn, e.se);
    }
    cout << mn << ' ' << mx;
}