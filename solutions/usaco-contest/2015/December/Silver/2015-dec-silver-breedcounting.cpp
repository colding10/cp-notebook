#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXQ 100000

int id_1_prefix[MAXN + 1] = {};
int id_2_prefix[MAXN + 1] = {};
int id_3_prefix[MAXN + 1] = {};

int main() {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);

        if (x == 1) {
            id_1_prefix[i]++;
        } else if (x == 2) {
            id_2_prefix[i]++;
        } else if (x == 3) {
            id_3_prefix[i]++;
        }

        id_1_prefix[i] += id_1_prefix[i - 1];
        id_2_prefix[i] += id_2_prefix[i - 1];
        id_3_prefix[i] += id_3_prefix[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        printf("%d %d %d\n", id_1_prefix[y] - id_1_prefix[x - 1],
               id_2_prefix[y] - id_2_prefix[x - 1],
               id_3_prefix[y] - id_3_prefix[x - 1]);
    }

    return 0;
}
