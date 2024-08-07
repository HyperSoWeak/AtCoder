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
    int n, a[100005], sum = 0, cnt = 0;
    bool f = 0;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i];
        if(a[i] < 0) cnt++, a[i] = -a[i];
        else if(a[i] == 0) f = 1;
        sum += a[i];
    }
    if(f || cnt%2==0) cout << sum;
    else cout << sum - *min_element(a,a+n) * 2;
}
