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
#define MAXN 200000

using namespace std;

int n;
int nums[MAXN];
map<int, int> p;
int ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int l = 0;
    for (int i = 0; i < n; i++) {
        if (p.count(nums[i]) && p[nums[i]] != -1) {
            while (l <= p[nums[i]]) {
                p[nums[l]] = -1;
                l++;
            }
        }
        p[nums[i]] = i;
        ans = max(ans, i - l + 1);
    }

    cout << ans << '\n';

    return 0;
}
