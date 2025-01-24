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
const int MN = 2e3+5;

int dir(int a, int b) {
    return (a - b) / abs(a - b);
}

int dst(int x1, int y1, int x2, int y2, int bx, int by) {
    int ans = abs(x1 - x2) + abs(y1 - y2);
    if(x1 == x2 && x1 == bx && dir(y2, by) == dir(by, y1)) ans += 2;
    if(y1 == y2 && y1 == by && dir(x2, bx) == dir(bx, x1)) ans += 2;
    return ans;
}

signed main() {
    hyper;
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int dx, dy;
    if(xb == xc) dx = 0;
    else dx = dir(xc, xb);
    if(yb == yc) dy = 0;
    else dy = dir(yc, yb);
    int r = abs(xb - xc) + abs(yb - yc);
    if(dx == 0 || dy == 0) {
        int x = xb - dx, y = yb - dy;
        int t = dst(xa, ya, x, y, xb, yb);
        cout << t + r << '\n';
    } else {
        int x1 = xb - dx, y1 = yb;
        int x2 = xb, y2 = yb - dy;
        int t1 = dst(xa, ya, x1, y1, xb, yb);
        int t2 = dst(xa, ya, x2, y2, xb, yb);
        cout << min(t1, t2) + r + 2 << '\n';
    }
}
