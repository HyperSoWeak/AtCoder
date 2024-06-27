#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define int long long
#define INF 0x3f3f3f3f
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;

int n, q, x;
list<int> a;
unordered_map<int, list<int>::iterator> mp;

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        cin >> x;
        a.push_back(x);
        mp[x] = prev(a.end());
    }
    cin >> q;
    while(q--) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            a.insert(next(mp[x]), y);
            mp[y] = next(mp[x]);
        }
        else {
            cin >> x;
            a.erase(mp[x]);
        }
    }
    for(auto i: a) cout << i << ' ';
}