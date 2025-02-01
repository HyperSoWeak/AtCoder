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
const int MOD = 998244353;
const int MN = 2e5+5;

int n;
string a[15];

int flip(int n, int idx) {
    if(n == 0) return 1;
    int l = 3*idx, r = 3*(idx+1);
    int cnt = 0;
    vi v;
    rep(i,l,r) if(a[n-1][i] == a[n][idx]) v.push_back(flip(n-1,i));
    sort(v.begin(), v.end());
    if(v.size() == 2) return v[0];
    else return v[0] + v[1];
}

signed main() {
    hyper;
    cin >> n >> a[0];
    rep(i,0,n) {
        string s = a[i];
        string t = "";
        rep(j,0,s.size()/3) {
            int cnt = 0;
            rep(k,0,3) cnt += (s[j*3+k] == '1');
            if(cnt >= 2) t += '1';
            else t += '0';
        }
        a[i+1] = t;
    }
    cout << flip(n, 0) << '\n';
}
