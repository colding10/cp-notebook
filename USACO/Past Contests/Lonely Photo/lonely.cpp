#include <string>
#include <iostream>

using namespace std;

int main() {
	int n;
	char c;

	cin >> n;

	char cows[n];

	for (int i = 0; i < n; i++) {
		cin >> c;
		cows[i] = c;
	}

	int lonely_photos = 0;
	int h_count;
	int g_count;

	for (int i = 0; i < n - 2; i++) {
		h_count = 0;
		g_count = 0;

		if (cows[i] == 'G') {
			g_count++;
		} else {
			h_count++;
		}

		for (int j = i + 1; j < n; j++) {
			if (cows[j] == 'G') {
				g_count++;
			} else {
				h_count++;
			}

			if (h_count + g_count < 3) {
				continue;
			}

			if (h_count >= 2 and g_count >= 2) {
				break;
			}

			if (h_count == 1 or g_count == 1) {
				lonely_photos++;
			}
		}
	}

	cout << lonely_photos << endl;
}