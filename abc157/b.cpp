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

int a[3][3], n, b;

signed main() {
    hyper;
    rep(i,0,3) rep(j,0,3) cin >> a[i][j];
    cin >> n;
    rep(i,0,n) {
        cin >> b;
        rep(i,0,3) rep(j,0,3) {
            if(a[i][j] == b) a[i][j] = 0;
        }
    }
    rep(i,0,3) {
        if((!a[0][i] && !a[1][i] && !a[2][i]) ||
           (!a[i][0] && !a[i][1] && !a[i][2])) {
            cout << "Yes\n";
            return 0;
        }
    }
    if((!a[0][0] && !a[1][1] && !a[2][2]) ||
       (!a[0][2] && !a[1][1] && !a[2][0])) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
}