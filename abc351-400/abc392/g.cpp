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
const int MN = 1e6+5;

const double PI = acos(-1);
typedef complex<double> cd;
void fft(vector<cd> &v, bool inv) {
    int n = v.size();
	for(int i = 0, j = 0; i < n; i++) {
		if(i < j) swap(v[i], v[j]);
		for(int k = n>>1; (j^=k) < k; k >>= 1);
	}
	for(int step = 1; step < n; step <<= 1) {
		double theta = (inv ? 1 : -1) * PI / step;
		cd omega(cos(theta), sin(theta));
		for(int i = 0; i < n; i += step*2) {
			cd now(1,0);
			for(int j = 0; j < step; j++) {
				cd a = v[i+j];
				cd b = v[i+j+step] * now;
				v[i+j] = a+b;
				v[i+j+step] = a-b;
				now *= omega;
			}
		}
	}
	if(inv) for(int i = 0; i < n; i++) v[i] /= n;
}

vi convolution(vi &a, vi &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());    
    int n = a.size()+b.size()-1, k = 1;
    for(; k < n; k <<= 1);
    fa.resize(k);
    fb.resize(k);
    fft(fa, 0);
    fft(fb, 0);
    rep(i,0,k) fa[i] *= fb[i];    
    fft(fa, 1);
    vi res(n);
    rep(i,0,n) res[i] = round(fa[i].real());
    return res;
}

signed main() {
    hyper;
    int n, x;
    cin >> n;
    vi a(MN, 0);
    rep(i,0,n) {
        cin >> x;
        ++a[x];
    }
    vi b = convolution(a, a);
    int ans = 0;
    rep(i,1,MN) if(a[i]) ans += (b[i*2]-1) / 2;
    cout << ans << '\n';
}
