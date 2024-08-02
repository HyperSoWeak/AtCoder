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

signed main() {
    hyper;
    int k;
    cin >> k;
    int t = (k%7==0 ? 9*k/7 : 9*k);
    if(t%2==0 || t%5==0) return cout << "-1", 0;
    int ans = 1, sum = 1;
    for(;;) {
        sum = (sum * 10) % t;
        if(sum == 1) return cout << ans, 0;
        ans++;
    }
}