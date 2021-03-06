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
#include <cstring>

#define ll long long
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
#define MAXN 1000000

using namespace std;

ll ckmin(ll &a, ll b) {
    return a = min(a, b);
}

struct M {
    const static int n = 100;
    ll m[n][n];
    M() { memset(m, 0x3f, sizeof m); }
    M operator*(const M& m2) {
        M res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < n; a++) {
                    ckmin(res[i][j], m[i][a] + m2.m[a][j]);
                }
            }
        }
        return res;
    }
    ll* operator[](const int &x) { return m[x]; }
    static M pow(M &m, ll e) {
        M res = I();
        while (e) {
            if (e & 1) res = res * m;
            m = m * m;
            e >>= 1;
        }
        return res;
    }
    static M I() {
        M m;
        for (int i = 0; i < n; i++) m.m[i][i] = 1;
        return m;
    }
};

ll n, m, k;
int main() {
    cin.tie(0)->sync_with_stdio(0); 

    M path;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        ckmin(path[a][b], w);
    }

    path = M::pow(path, k);
    if (path[0][n - 1] == INFLL) {
        cout << "-1\n";
    } else {
        cout << path[0][n - 1] - 1 << '\n';
    }

    return 0;
}
