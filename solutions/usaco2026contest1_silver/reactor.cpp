#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

// graph
// a_x + a_y = z (edge with weight z between x and y)
// connected components represent rods that constrain each other
// we can express all rods in a CC in terms of one chosen value
//
//
// model all rods energy as a_i = p_i * t + c_i
// then setting one rod forces another rod with a constraint

// if we revisit a node thru another edge (constraint) then we must get the same
// energy or else its impossible

// MAIN FORM a_i = p_i * t + c_i (p_i is a sign)
// when we run thru edges it resolves values; something will eventually fix t

struct Edge {
    int v;
    ll z;
};

void solve() {
    int N, M;
    cin >> N >> M;

    vector<ll> l(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }

    vector<vector<Edge>> adj(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        ll z;
        cin >> x >> y >> z;

        x--;
        y--; // 0-index fix

        adj[x].push_back({y, z});
        if (x != y) {
            adj[y].push_back({x, z});
        }
    }

    // MAIN FORM a_i = p_i * t + c_i (p_i is a sign)
    vector<ll> p(N, 0);
    vector<ll> c(N, 0);
    vector<bool> visited(N, 0);

    bool impossible = false;
    ll total = 0;

    deque<ll> q;
    vector<ll> comp;

    // process things one cc at a time
    for (int start = 0; start < N && !impossible; start++) {
        if (visited[start]) {
            continue;
        }

        // BFS
        q.clear();
        comp.clear();

        visited[start] = true;

        // set the root to be a = t
        p[start] = 1;
        c[start] = 0;

        q.push_back(start);
        comp.push_back(start);

        bool has_fixed = false;
        ll t_fixed = 0;

        while (!q.empty() && !impossible) {
            ll u = q.front();
            q.pop_front();

            for (auto [v, z] : adj[u]) {
                if (v == u) { // self-loop, 2*a_u = z
                    if (z % 2 != 0) {
                        // impossible cuz has to be integers
                        impossible = true;
                        break;
                    }

                    ll a_req = z / 2;
                    // a_u = p[u] * t + c[u] so t = (a_req - c[u]) / p[u]
                    ll t_req = (a_req - c[u]) * p[u];
                    if (has_fixed && t_req != t_fixed) { // contradiction on t
                        impossible = true;
                        break;
                    }

                    // now we fixed value of t
                    has_fixed = true;
                    t_fixed = t_req;
                } else {
                    /*
                     * a_u = p[u] * t + c[u]
                     * so a_v = z - a_u and plug in defn of a_u
                     * a_v = (-p[u])t + (z - c[u])
                     */
                    ll new_p = -p[u];
                    ll new_c = z - c[u];

                    if (visited[v]) {
                        if (p[v] == new_p) {
                            if (c[v] != new_c) { // contradiction eq
                                impossible = true;
                                break;
                            }
                        } else {
                            /*
                             * we have p[v]t + c[v] = -p[v]t + new_c
                             * 2p[v]t = new_c - c[v]
                             * so t is fixed
                             * also, new_c - c[v] has to be even
                             */
                            ll diff = new_c - c[v];
                            if (diff % 2 != 0) {
                                impossible = true;
                                break;
                            }

                            ll t_req = diff / (2LL * p[v]);
                            if (has_fixed && t_req != t_fixed) {
                                // contradiction in t
                                impossible = true;
                                break;
                            }

                            has_fixed = true;
                            t_fixed = t_req;
                        }
                    } else {
                        visited[v] = true;
                        p[v] = new_p;
                        c[v] = new_c;
                        q.push_back(v);
                        comp.push_back(v);
                    }
                }
            }
        }

        if (impossible) {
            break;
        }

        if (has_fixed) {
            // we can evaluate all of the stuff in the component now
            for (ll u : comp) {
                ll a = p[u] * t_fixed + c[u];
                if (l[u] <= a && a <= r[u]) {
                    total++;
                }
            }
        } else { // need to find a maximum overlap of intervals for t
            // we have equations in t for each rod
            // find intervals that make them active
            // then maximize overlap of intervals
            vector<pair<ll, int>> events;
            // one event for starting an interval and another for stopping an
            // interval event is {pos, delta} delta +1 for add and - remove

            for (ll u : comp) {
                ll lo, hi;
                // l[u] <= p[u]*t + c[u] <= r[u]
                if (p[u] == 1) {
                    lo = l[u] - c[u];
                    hi = r[u] - c[u];
                } else {
                    lo = c[u] - r[u];
                    hi = c[u] - l[u];
                }

                events.push_back({lo, 1});
                events.push_back({hi, -1});
            }

            sort(events.begin(), events.end(),
                 [](const auto &a, const auto &b) {
                     if (a.first != b.first) return a.first < b.first;
                     return a.second > b.second;
                 });

            ll cur = 0;
            ll best = 0;

            for (int i = 0; i < events.size();) {
                ll pos = events[i].first;
                while (i < events.size() && events[i].first == pos &&
                       events[i].second == 1) {
                    cur++;
                    i++;
                }

                best = max(best, cur);
                while (i < events.size() && events[i].first == pos &&
                       events[i].second == -1) {
                    cur--;
                    i++;
                }
            }

            total += best;
        }
    }

    if (impossible) {
        cout << -1 << "\n";
    } else {
        cout << total << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
// STOP LOOKING HERE AND LOOK AT THE PAPER
