#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main() {
    hyper;
    int n, a[400005], sum = 0;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i];
        sum ^= a[i];
    }
    if(n % 2) {
        cout << "Win\n";
        return 0;
    }
    rep(i,0,n) {
        if(a[i] == sum) {
            cout << "Win\n";
            return 0;
        }
    }
    cout << "Lose\n";
}