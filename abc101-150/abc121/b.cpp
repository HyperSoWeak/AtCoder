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

int n, m, c, b[20], a, cnt = 0;

signed main() {
    cin >> n >> m >> c;
    rep(i,0,m) cin >> b[i];
    rep(i,0,n) {
        int sum = 0;
        rep(j,0,m) {
            cin >> a;
            sum += a * b[j];
        }
        if(sum + c > 0) cnt++;
    }
    cout << cnt;
}