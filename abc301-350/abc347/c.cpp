#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pii pair<int,int>
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, a, b, d[200005];

signed main() {
    hyper;
    cin >> n >> a >> b;
    rep(i,0,n) {
        cin >> d[i];
        d[i] %= (a+b);
    }
    sort(d, d+n);
    if(d[n-1] - d[0] < a) {
        cout << "Yes";
        return 0;
    }
    rep(i,1,n) {
        if(d[i] - d[i-1] > b) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}