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
    int n, p[10], sum = 0;
    cin >> n;
    rep(i,0,n) {
        cin >> p[i];
        sum += p[i];
    }
    sum -= *max_element(p,p+n) / 2;
    cout << sum;
}