#include <iostream> 
#include <fstream> 
#include <vector>
#include <queue>

using namespace std;

typedef struct field field;
struct field {
    int cows;
    int dist;
    vector<int> path;
    vector<pair<int, int>> connect;
};

typedef struct loc loc;
struct loc {
    int dist;
    vector<int> path;
};

bool comp(loc &l1, loc &l2) {
    if (l1.dist != l2.dist) {
        return l1.dist > l2.dist;
    }

    int min_sz = l1.path.size() < l2.path.size() ? l1.path.size() : l2.path.size();

    for (int i = 0; i < min_sz; i++) {
        if (l1.path[l1.path.size() - i] != l2.path[l2.path.size() - i]) {
            return l1.path[i] > l2.path[i];
        }
    }
    
    return l1.path.size() > l2.path.size();
}

int n, m, t;
vector<field> fields;

int main() {
    ifstream fin("shortcut.in");
    ofstream fout("shortcut.out");

    fin >> n >> m >> t;
    vector<field> fields = vector<field>(n + 1);

    for (int i = 0; i < n; i++) {
        int c; fin >> c;
        fields[i + 1].cows = c;
    }

    for (int i = 0; i < m; i++) {
        int x, y, t; fin >> x >> y >> t;
        fields[x].connect.push_back({y, t});
        fields[y].connect.push_back({x, t});
    }


    priority_queue<loc, vector<loc>, decltype(&comp)> pq(comp);
    loc start;
    start.dist = 0;
    start.path = {1};
    pq.push(start);

    vector<bool> visited(n + 1, false);
    int visit_count = 0;

    while (visit_count < n) {
        loc pos = pq.top();
        pq.pop();
        int last = pos.path[pos.path.size() - 1];
        //cout << last << endl;

        if (visited[last]) continue;

        visited[last] = true;
        visit_count++;
        fields[last].path = pos.path;
        fields[last].dist = pos.dist;

        for (pair<int, int> p : fields[last].connect) {
            if (!visited[p.first]) {
                loc new_loc;
                new_loc.dist = pos.dist + p.second;
                new_loc.path = vector<int>(pos.path);
                new_loc.path.push_back(p.first);
                pq.push(new_loc);
            }
        }
    }

    vector<int> total_count(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int f : fields[i].path) {
            //cout << i << " to " << f <<
            total_count[f] += fields[i].cows;
        }
    }
        //cout << "despacito\n";

    int max_remove = 0;
    for (int i = 1; i <= n; i++) {
        //cout << total_count[i] << ' ' << fields[i].dist << endl;
        int diff = fields[i].dist - t;
        int mult_diff = total_count[i] * diff;

        if (mult_diff > max_remove) {
            max_remove = mult_diff;
        }
    }    

    fout << max_remove << '\n';
    return 0;
}