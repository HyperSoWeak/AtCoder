#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, k, x;
bool b[10];

bool check(int x) {
    while(x > 0) {
        if(b[x % 10]) return false;
        x /= 10;
    }
    return true;
}

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,k) {
        cin >> x;
        b[x] = 1;
    }
    for(;;n++) {
        if(check(n)) {
            cout << n;
            return 0;
        }
    }
}