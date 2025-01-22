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
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

bool check(string s, int n) {
    rep(i,0,n/2) if(s[i] != s[n/2+i]) return 0;
    return 1;
}

signed main() {
    hyper;
    string s;
    cin >> s;
    int n = s.size() - 2;
    while(1) {
        if(check(s, n)) {
            cout << n << '\n';
            return 0;
        }
        n -= 2;
    }
}
