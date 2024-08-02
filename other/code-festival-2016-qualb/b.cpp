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
#define Yes cout << "Yes\n"
#define No cout << "No\n"

int n, a, b, ac=0, bc=0;
string s;

signed main() {
    cin >> n >> a >> b >> s;
    rep(i,0,n) {
        if(s[i] == 'a') {
            if(ac+bc < a+b) {
                Yes;
                ac++;
            } else No;
        }
        else if(s[i] == 'b') {
            if(ac+bc < a+b && bc<b) {
                Yes;
                bc++;
            } else No;
        }
        else No;
    }
}