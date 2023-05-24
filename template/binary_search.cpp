int b_search(vector<int> &v, int k) {
    int left = -1, right = v.size();
    if (v.back() < k) return -1;
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
