#include <bits/stdc++.h>
using namespace std;

int t, c;
#define MAXN 100001

bool target[MAXN*2+5];
char command[MAXN];

#define int long long
int32_t main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> t >> c;

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        target[x+c] = true;
    }
    for (int i = 0; i < c; i++) {
        cin >> command[i];
    }

    int orig_score = 0;
    int location = c;
    vector<int> fired;
    vector<int> loc_at_fire;
    int one_left = -1;
    int one_right = -1;
    int two_left = 0;
    int two_right = 0;

    bool seen_l = false;
    bool seen_r = false;
    bool seen_f = false;

    int earliest_l = -1;
    int earliest_r = -1;
    int earliest_f = -1;

    int need_one_right_loc = -1;
    int need_one_left_loc = -1;
    int need_two_right_loc = -1;
    int need_two_left_loc = -1;

    set<int> hit_targets;
    for (int i = 0; i < c; i++) {
        if (command[i] == 'L') {
            location -= 1;
            seen_l = true;
            if (need_two_right_loc == -1) {
                earliest_l = i;
            }
        } else if (command[i] == 'R') {
            location += 1;
            seen_r = true;
            if (need_two_left_loc == -1) {
                earliest_r = i;
            }
        } else {
            fired.push_back(i);
            loc_at_fire.push_back(location);
            seen_f = true;
            if (target[location] && !hit_targets.count(location)) {
                orig_score++;
                hit_targets.insert(location);
                // cout << "hit target orig at : " << location<<endl;
            }
            if (need_one_left_loc == -1 || need_one_right_loc == -1) {
                earliest_f = i;
            }
        }
        if (location-2!=0) {
                if (target[location-2] && seen_r && !target[location]) {
                    two_left++;
                    if (need_two_left_loc == -1) {
                        need_two_left_loc = i;
                    }
                }
            }
            if (location - 1!=0) {
                if (target[location-1] && seen_f&& !target[location]) {
                    one_left++;
                    if (need_one_left_loc == -1) {
                        need_one_left_loc = i;
                    }
                }
            }
            if (location+2 <c*2) {
                if (target[location+2] && seen_l&& !target[location]) {
                    two_right++;
                    if (need_two_right_loc == -1) {
                        need_two_right_loc = i;
                    }
                }
            }
            if (location+1 < c*2) {
                if (target[location+1] && seen_f&& !target[location]) {
                    one_right++;
                    if (need_one_right_loc == -1) {
                        need_one_right_loc = i;
                    }
                }
            }
    }

    int bonus = 0;

    int one_left_missed = 0;
    int one_right_missed = 0;
    int two_left_missed = 0;
    int two_right_missed = 0;
    for (int i = 0; i < fired.size();i++) {
        int f = fired[i];
        int l = loc_at_fire[i];
        if (f >= earliest_f) {
            if (!target[l+1] && target[l] && !hit_targets.count(l)) {
                one_right_missed++;
            }
            if (!target[l-1] && target[l] && !hit_targets.count(l)) {
                one_left_missed++;
            }
        }
        if (f >= earliest_l) {
            if (!target[l+2] && target[l] && !hit_targets.count(l)) {
                two_right_missed++;
            }
        }
        if (f >= earliest_r) {
            if (!target[l-2] && target[l] && !hit_targets.count(l)) {
                two_left_missed++;
            }
        }
    }
    // cout << one_left_missed << " " << one_right_missed << " "
     // << two_left_missed << " " << two_right_missed << endl;
    // cout << one_left << " " << one_right << " " << two_left << " " << two_right << endl;
    bonus = max(bonus, one_left-one_left_missed);
    bonus = max(bonus, one_right-one_right_missed);
    bonus = max(bonus, two_left-two_left_missed);
    bonus = max(bonus, two_right-two_right_missed);
    // cout << "BONUs: " <<bonus<<endl;
    cout << orig_score+bonus<<endl;
}