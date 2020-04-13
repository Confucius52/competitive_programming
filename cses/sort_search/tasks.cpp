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

int n;
vector<int> nums;
ll ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        ans += b;
        nums.push_back(a);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        ans -= 1LL * nums[i] * (n - i);
    }

    cout << ans << '\n';

    return 0;
}
