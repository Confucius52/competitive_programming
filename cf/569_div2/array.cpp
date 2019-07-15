// :pray: :arrayman:
// :pray: :summit:
// :pray: :pusheen:
// :pray: :prodakcin:
// :pray: :spacewalker:
// :pray: :duk:
// :pray: :gustav:
// :pray: :tmw:
// :pray: :eed:
// :pray: :chicubed:
// :pray: :arceus:
// :pray: :gamegame:
// :pray: :sinx:
// :pray: :eyg:
// :pray: :evan:
// :pray: :cj:
// :pray: :steph:
// :pray: :fatant:
// :pray: :mathbot:
// :pray: :dolphin:
// :pray: :stef:
// :pray: :geothermal:
// :pray: :mikey:
// :pray: :horse:
// :pray: :snek:
// :pray: :wayne:
// :pray: :wu:
// :pray: :vmaddur:
// :pray: :dorijanko:
// :pray: :gaming:
// :pray: :kassuno:
// :pray: :hyacinth:
// :pray: :chilli:
// :pray: :dhruv:
// :pray: :philip:
// :pray: :paiman:
// :pray: :camel:
// :pray: :tree:
// :pray: :tux:
// :pray: :jony:
// :pray: :kage:
// :pray: :ghost:
// :pray: :aha:
// :pray: :coolguy:
// :pray: :imax:
// :pray: :howlet:
// :pray: :darren:
// :pray: :arie:
// :pray: :blastman: 
// :pray: :zephyr:
// :pray: :spsk:
// :pray: :bigc:

#include <iostream>
#include <fstream>
#include <vector>
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
#define MAXN 100000

using namespace std;

ll n;
ll nums[MAXN];

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> n;
    ll minpos = 0;
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] < 0) {
            nums[i] = - (nums[i]) - 1;
        }

        if (nums[minpos] == 0 || (nums[i] > nums[minpos] && nums[i] != 0)) {
            minpos = i;
        }
    }

    for (ll i = 0; i < n; i++) {
        nums[i] = - (nums[i]) - 1;
    }

    if (n % 2 == 1) {
        nums[minpos] = - (nums[minpos]) - 1;
    }

    for (ll i = 0; i < n; i++) {
        cout << nums[i] << ' ';
    }

    return 0;
}
