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

string s;
int k, n;
vector<int> a;

bool check(int l) {
    int m = (l-1)/2;
    int cost = 0;
    rep(i,0,l) cost += abs(a[m]-a[i]);
    if(cost <= k) return 1;
    rep1(i,1,n-l) {
        cost = cost+a[i-1]+a[i-1+l]-a[i+m]-a[i+m-(l&1)];
        if(cost <= k) return 1;
    }
    return 0;
}

signed main() {
    hyper;
    cin >> s >> k;
    rep(i,0,s.size()) if(s[i] == 'Y') a.push_back(i-a.size());
    n = a.size();
    int l = 1, r = n;
    while(l < r) {
        int m = (l+r+1) / 2;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout << r;
}