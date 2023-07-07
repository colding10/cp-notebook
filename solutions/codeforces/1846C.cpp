#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using ll = long long;
using vll = vector<ll, ll>;
using pll = pair<ll, ll>;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)

struct Participant {
    ll index = 0;
    ll points = 0;
    ll penalty = 0;
};

bool compareParticipants(const Participant &p1, const Participant &p2) {
    if (p1.points == p2.points) {
        if (p1.penalty == p2.penalty) {
            return p1.index < p2.index;
        }
        return p1.penalty < p2.penalty;
    }
    return p1.points > p2.points;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<Participant> participants(n);
    F0R(i, n) {
        participants[i].index = i;

        vector<int> times(m);
        for (int &x : times) {
            cin >> x;
        }
        sort(times.begin(), times.end());

        int cur_time = 0;
        for (int prob : times) {
            if ((cur_time + prob) <= h) {
                participants[i].points += 1;
                participants[i].penalty += cur_time + prob;
                cur_time += prob;
            } else {
                break;
            }
        }
    }

    sort(participants.begin(), participants.end(), compareParticipants);

    int rank = 1;
    for (Participant &p : participants) {
        if (p.index == 0) {
            break;
        }
        rank++;
    }

    cout << rank << endl;
}

int main() {
    int t;
    cin >> t;
    rep(t) {
        solve();
    }
}
