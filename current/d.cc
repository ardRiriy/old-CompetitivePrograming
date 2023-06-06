#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int& a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int& a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int b_search(vector<int>& v, int k) {
    int left = -1, right = v.size();
    while (abs(right - left) > 1) {
        int mid = (left + right) / 2;
        if (v[mid] >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int W, H, N;
    cin >> W >> H >> N;
    vector<pair<int, int>> vec(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        vec[i] = make_pair(x, y);
    }
    int A;
    cin >> A;
    vector<int> aLine(A + 1);
    rep(i, A) cin >> aLine[i];
    aLine[A] = W;

    int B;
    cin >> B;
    vector<int> bLine(B + 1);
    rep(i, B) cin >> bLine[i];
    bLine[B] = H;

    map<int, int> piece;

    rep(i, N) {
        int x = b_search(aLine, vec[i].first);
        int y = b_search(bLine, vec[i].second);
        /*         cout << x << " " << y << endl; */
        piece[x + y * (A + 1)]++;
    }
    auto min_element_it = std::min_element(
        piece.begin(), piece.end(),
        [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.second < p2.second;
        });

    auto max_element_it = std::max_element(
        piece.begin(), piece.end(),
        [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.second < p2.second;
        });
    int m, M;
    M = max_element_it->second;
    m = min_element_it->second;
    if (piece.size() != (A + 1) * (B + 1)) m = 0;
    cout << m << " " << M << endl;
    return 0;
}
