#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int T, L, X, Y;
    cin >> T >> L >> X >> Y;

    int Q;
    cin >> Q;
    double si[Q];

    rep(i, Q) {
        int e;
        cin >> e;
        si[i] = (360.0 * e / T) * M_PI / 180.0;
    }

    double height[Q];
    rep(i, Q) {
        if (si[i] < 90)
            height[i] = L * (1 - cos(si[i])) / 2;
        else if (si[i] < 180)
            height[i] = L * (1 + cos(M_PI - si[i])) / 2;
        else if (si[i] < 270)
            height[i] = L * (1 + cos(3 * M_PI / 2 - si[i])) / 2;
        else
            height[i] = L * (1 - cos(2 * M_PI - si[i])) / 2;
    }

    rep(i, Q) {
        double distance = sqrt(X * X + (Y + L / 2.0 * sin(si[i])) *
                                           (Y + L / 2.0 * sin(si[i])));
        cout << atan2(height[i], distance) * 180.0 / M_PI << endl;
    }
    return 0;
}
