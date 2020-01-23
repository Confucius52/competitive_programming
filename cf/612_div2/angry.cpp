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
#define MAXN 1000000

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int cur = 0;
    bool flag = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            flag = true;
        }

        if (flag) {
            if (s[i] == 'A') {
                ans = max(ans, cur);
                cur = 0;
            } else {
                cur++;
            }
        }
    }

    cout << max(ans, cur) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
