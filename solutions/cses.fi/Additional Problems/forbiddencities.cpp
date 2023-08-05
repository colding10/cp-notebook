#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> visited;

bool checkCitiesConnected(int city_a, int city_b, vector<int> illegal,
                          unordered_map<int, vector<int>> graph) {
    if (find(illegal.begin(), illegal.end(), city_a) != illegal.end()) {
        return false;
    }
    if (city_a == city_b) {
        return true;
    }
    if (visited.find(city_a) != visited.end()) {
        return false;
    }

    visited.insert(city_a);

    for (auto neighbor : graph[city_a]) {
        bool can_reach_b =
            checkCitiesConnected(neighbor, city_b, illegal, graph);
        if (can_reach_b) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int CITIES, ROADS, QUERIES;
    cin >> CITIES >> ROADS >> QUERIES;

    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < ROADS; i++) {
        int city_a, city_b;
        cin >> city_a >> city_b;

        if (graph.find(city_a) == graph.end()) {
            graph[city_a] = {};
        }
        if (graph.find(city_b) == graph.end()) {
            graph[city_b] = {};
        }

        graph[city_a].push_back(city_b);
        graph[city_b].push_back(city_a);
    }

    for (int i = 0; i < QUERIES; i++) {
        visited.clear();

        int city_a, city_b, forbidden_city;
        cin >> city_a >> city_b >> forbidden_city;
        if (checkCitiesConnected(city_a, city_b, {forbidden_city}, graph)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
