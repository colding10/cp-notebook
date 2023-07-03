#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Flight {
    int dest;
    long long start, end;

    Flight(int d, long long s, long long e) : dest(d), start(s), end(e) {}
};

struct Node {
    int airport;
    long long time;
    bool operator<(const Node& other) const {
        return time > other.time;
    }

    Node(int a, long long t) : airport(a), time(t) {}
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Flight> > flights(N + 1);
    for (int i = 0; i < M; i++) {
        int c, d;
        long long r, s;
        cin >> c >> r >> d >> s;
        flights[c].push_back(Flight(d, r, s));
    }

    vector<long long> layover(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> layover[i];
    }

    vector<long long> earliest(N + 1, INF);
    earliest[1] = 0;

    priority_queue<Node> pq;
    pq.push(Node(1, 0));

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        int currAirport = curr.airport;
        long long currTime = curr.time;
        if (currTime > earliest[currAirport]) {
            continue;
        }
        for (Flight& f : flights[currAirport]) {
            long long newTime = f.start + f.end + layover[f.dest];
            if (newTime < earliest[f.dest]) {
                earliest[f.dest] = newTime;
                pq.push(Node(f.dest, newTime));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (earliest[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << earliest[i] << endl;
        }
    }

    return 0;
}
