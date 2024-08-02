#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
#define MAXN 1000005
#define MAXSQN 1005

bool pp[MAXSQN];
vector<int> p;
int n, a[MAXN];

bool pc() {
    bool check[MAXN] = {0};
    rep(i,0,n) {
        int t = a[i];
        for(auto x: p) {
            if(x * x > t) break;
            if(t % x == 0) {
                if(check[x]) return false;
                check[x] = true;
                while(t % x == 0) t /= x;
            }
        }
        if(t > 1) {
            if(check[t]) return false;
            check[t] = true;
        }
    }
    return true;
}

bool sc() {
    int ans = a[0];
    rep(i,1,n) ans = __gcd(ans, a[i]);
    return (ans == 1);
}

signed main() {
    hyper;
    rep(i,2,MAXSQN) pp[i] = 1;
    for(int i=2; i*i<=MAXSQN; ++i) {
        if(pp[i]) {
            for(int j=i*i; j<=MAXSQN; j+=i) {
                pp[j] = 0;
            }
        }
    }
    rep(i,0,MAXSQN) if(pp[i]) p.pb(i);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    if(pc()) {
        cout << "pairwise coprime\n";
        return 0;
    }
    if(sc()) {
        cout << "setwise coprime\n";
        return 0;
    }
    cout << "not coprime\n";
}