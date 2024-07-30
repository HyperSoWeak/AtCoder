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
#define MAXN 200005

int n, k, a[MAXN];

bool check(int x) {
    int sum = 0;
    rep(i,0,n) sum += (a[i]+x-1) / x - 1;
    return sum <= k;
}

signed main() {
    hyper;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    int l = 1, r = *max_element(a, a+n);
    while(l < r) {
        int m = (l+r) / 2;
        if(check(m)) r = m;
        else l = m+1;
    }
    cout << l;
}
