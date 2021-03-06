#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>

#define ll long long
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
#define MAXN 110

using namespace std;

int n;
int r[MAXN];
long double ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int x = 1; x <= r[i]; x++) {
                if (x > r[j]) {
                    ans += 1.0 / r[i];
                } else {
                    ans += (x - 1.0) / r[j] * 1.0 / r[i];
                }
            }
        }
    }

    cout << fixed << setprecision(6) << ans << '\n';

    return 0;
}
