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

int n, x, y, t, a[505], b[505], la=0, lb=0;
bool dpx[505][20025], dpy[505][20025];

signed main() {
    hyper;
    cin >> n >> x >> y;
    rep(i,0,n) {
        cin >> t;
        if(i%2==0) a[++la] = t;
        else b[++lb] = t;
    }
    dpx[1][10010+a[1]] = dpy[0][10010] = 1;
    rep1(i,2,la) rep1(j,10,20010) dpx[i][j] = dpx[i-1][j-a[i]] || dpx[i-1][j+a[i]];
    rep1(i,1,lb) rep1(j,10,20010) dpy[i][j] = dpy[i-1][j-b[i]] || dpy[i-1][j+b[i]];
    if(dpx[la][10010+x] && dpy[lb][10010+y]) cout << "Yes\n";
    else cout << "No\n";
}