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
#include <cstdio>
#include <cstring>

#define ll long long
#define ld long double
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
#define MAXN 1000000

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
