#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=long double;
using str=string;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using pd=pair<db,db>;
using vpi=vector<pi>;
using vi=vector<int>;
using vll=vector<ll>;
using vdb=vector<db>;
#define mp make_pair
#define f first
#define s second

template <class T>bool ckmin(T &a,T &b) {bool B=a > b;a=min(a,b);return B;}
template <class T>bool ckmax(T &a,T &b) {bool B=a < b;a=max(a,b);return B;}

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x),end(x)
#define rall(x) x.rbegin(),x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound

#define FOR(i,a,b) for (int i=(a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i=(b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)

const int INF_32=int(2147483647);
const ll INF_64=ll(9223372036854775807);

const int MOD=1000000007;
const ll BIG=1e18;  // not too close to LLONG_MAX
const int dx[4]{1,0,-1,0},dy[4]{0,1,0,-1};
const char dir[4]{'D','R','U','L'},cdir[4]{'S','E','N','W'};

inline namespace FileIO {
void setIn(const str &s) { freopen(s.c_str(),"r",stdin); }
void setOut(const str &s) { freopen(s.c_str(),"w",stdout); }
void setIO(const str &s="") { cin.tie(0)->sync_with_stdio(0); if (sz(s)) setIn(s + ".in"),setOut(s + ".out");}
}  // namespace FileIO

int main() {
    setIO();

    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
