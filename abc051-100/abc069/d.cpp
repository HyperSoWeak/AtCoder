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

int h, w, n, a[10005], m[105][105];

signed main() {
    hyper;
    cin >> h >> w >> n;
    rep(i,0,n) cin >> a[i];
    int p = 0;
    rep(i,0,h*w) {
        int x = i / w;
        int y = (x&1 ? w-(i%w)-1 : i%w);
        m[x][y] = p+1;
        if(!--a[p]) p++;
    }
    rep(i,0,h) rep(j,0,w) cout << m[i][j] << " \n"[j==w-1];
}