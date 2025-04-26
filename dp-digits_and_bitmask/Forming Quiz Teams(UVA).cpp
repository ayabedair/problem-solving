#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ln '\n'
#define MAX 1000001
#define eps 1e-6
#define mod 1000000007
#define int long long

void fastIO(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void fileIO(void) {
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
}

int add(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int sub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int dx[]{0, 0, 1, -1};
int dy[]{-1, 1, 0, 0};
// int n, k, mx = LONG_MAX;
// vector<int> levels, vis;
vector<vector<int>> adj;
vector<pair<double, double>> v;
vector<double>d;
int n, m, sz;

double dp[1 << 17];
double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double rec(int i, int mask) {
    if (mask == (1 << n) - 1) return 0.0;
    if (i == n) return 0.0;

    if (dp[mask] == -1.0) return dp[mask];

    double ans = LLONG_MAX;
    int first = -1;
    for (int j = 0; j < n; j++) {
        if (!((1 << j) & mask)) {
            first = j;
            break;
        }
    }
    if (first == -1) return 0.0;

    for (int j = first + 1; j < n; j++) {
        if (!((1 << j) & mask)) {
            ans = min(ans, rec(i + 1, mask | (1 << j) | 1 << first) + dist(v[first].first, v[first].second, v[j].first, v[j].second));
        }
    }

    return dp[mask] = ans;
}


void solve() {
    int tc = 1;
    while (cin >> n && n != 0) {
        memset(dp, -1.0, sizeof(dp));
        string s;
        double x, y;
        for (int i = 0; i < 2 * n; i++) {
            cin >> s;
            cin >> x >> y;
            v.push_back({x, y});
        }
        n = 2 * n;
        cout << "Case " << tc++ << ": " << fixed << setprecision(2) << rec(0, 0) << endl;
        v.clear();
    }


}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }

    return 0;
}
