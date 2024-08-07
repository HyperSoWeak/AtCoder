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
const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    hyper;
    int n, x, a[100];
    cin >> n >> x;
    rep(i,0,n) cin >> a[i];
    sort(a, a+n);
    int sum = 0;
    rep(i,0,n) {
        sum += a[i];
        if(sum > x) return cout << i, 0;
    }
    cout << (sum == x ? n : n-1);
}
