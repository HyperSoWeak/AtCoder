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
const int MN = 5005;

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

bool ok(int a, int b) {
    int x, y;
    int d = exgcd(a, b, x, y);
    if(2 % d) return 0;
    cout << y * 2 / d << ' ' << x * 2 / d << '\n';
    return 1;
}

signed main() {
    hyper;
    int x, y;
    cin >> x >> y;
    if(!ok(-x,y) && !ok(x,-y)) cout << "-1\n";
}
