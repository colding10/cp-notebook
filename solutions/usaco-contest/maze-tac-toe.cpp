#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using db = long double;

template <class T> using V = vector<T>;
template <class T, class U> using P = pair<T, U>;
template <class T, size_t SZ> using AR = array<T, SZ>;

using pi = P<int, int>;
using pll = P<ll, ll>;

using vi = V<int>;
using vll = V<ll>;
using vb = V<bool>;
using vpi = V<pi>;
using vpll = V<pll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

template <class T> bool ckmin(T &a, T &b) {
    return b < a ? a = b, true : false;
}
template <class T> bool ckmax(T &a, T &b) {
    return b > a ? a = b, true : false;
}

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back

#define lb lower_bound
#define ub upper_bound

#define rep(i, begin, end)                                                     \
  for (__typeof(end) i = (begin) - ((begin) > (end));                          \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

const int dx[4] {1, 0, -1, 0}, dy[4] {0, 1, 0, -1};
const char dir[4] {'D', 'R', 'U', 'L'}, cdir[4] {'S', 'E', 'N', 'W'};

inline namespace FileIO {
void setIn(const str &s) {
    freopen(s.c_str(), "r", stdin);
}
void setOut(const str &s) {
    freopen(s.c_str(), "w", stdout);
}
void setIO(const str &s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s))
        setIn(s + ".in"), setOut(s + ".out");
}
} // namespace FileIO

inline namespace ReadIO {
template <class A, class B> void re(pair<A, B> &p);
template <class A> void re(vector<A> &v);
template <class A, size_t SZ> void re(array<A, SZ> &a);

template <class T> void re(T &x) {
    cin >> x;
}
void re(double &d) {
    string t;
    re(t);
    d = stod(t);
}
void re(long double &d) {
    string t;
    re(t);
    d = stold(t);
}
template <class H, class... T> void re(H &h, T &...t) {
    re(h);
    re(t...);
}
template <class A, class B> void re(pair<A, B> &p) {
    re(p.first, p.second);
}
template <class A> void re(vector<A> &x) {
    for (auto &i : x)
        re(i);
}
template <class A, size_t SZ> void re(array<A, SZ> &x) {
    for (auto &i : x)
        re(i);
}
}; // namespace ReadIO

inline namespace WriteIO {};

int N;
V<V<AR<char, 3>>> board;
bool visited[25][25][19683];
set<int> ans;
int pow3[10] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683};

bool isWin(int state) {
    AR<AR<char, 3>, 3> board;
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            board[i][j] = state % 3;
            state /= 3;
        }
    }

    rep(r, 0, 3) {
        if (board[r][0] == 1 && board[r][1] == 2 && board[r][2] == 2)
            return true;
        if (board[r][0] == 2 && board[r][1] == 2 && board[r][2] == 1)
            return true;
        if (board[0][r] == 1 && board[1][r] == 2 && board[2][r] == 2)
            return true;
        if (board[0][r] == 2 && board[1][r] == 2 && board[2][r] == 1)
            return true;
    }

    if (board[0][0] == 1 && board[1][1] == 2 && board[2][2] == 2)
        return true;
    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 1)
        return true;
    if (board[2][0] == 1 && board[1][1] == 2 && board[0][2] == 2)
        return true;
    if (board[2][0] == 2 && board[1][1] == 2 && board[0][2] == 1)
        return true;
    return false;
}

void dfs(int i, int j, int b) {
    if (visited[i][j][b])
        return;
    visited[i][j][b] = true;

    if (board[i][j][0] == 'M' || board[i][j][0] == 'O') {
        int x = board[i][j][1] - '1';
        int y = board[i][j][2] - '1';
        int idx = x * 3 + y;

        int cur_char = (b / pow3[idx]) % 3;
        if (cur_char == 0) {
            int new_char = board[i][j][0] == 'M' ? 1 : 2;
            b = (b % pow3[idx]) + new_char * pow3[idx] + (b - b % pow3[idx + 1]);

            if (!visited[i][j][b] && isWin(b)) {
                ans.insert(b);
                return;
            }

            visited[i][j][b] = true;
        }
    }

    rep(d, 0, 4) {
        int ni = i + dx[d];
        int nj = j + dy[d];

        if (board[ni][nj][0] != '#') {
            dfs(ni, nj, b);
        }
    }
}

int main() {
    setIO();

    cin >> N;

    pi bess;
    board.rsz(N);
    rep(i, 0, N) {
        board[i].rsz(N);
        rep(j, 0, N) {
            cin >> board[i][j][0] >> board[i][j][1] >> board[i][j][2];
            if (board[i][j][0] == 'B') {
                bess = mp(i, j);
            }
        }
    }

    dfs(bess.f, bess.s, 0);

    cout << sz(ans) << endl;
    // you should actually read the stuff at the bottom
}

// keep calm
// stay organized
// do something instead of wasting time
// the solution is probably simpler than you think
