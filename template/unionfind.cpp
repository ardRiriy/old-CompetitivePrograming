class UnionFind {
   private:
    vector<int> uf;

   public:
    UnionFind(int size) : uf(size) {
        for (int i = 0; i < size; i++) uf[i] = -1;
    }

    int root(int n) {
        if (uf[n] < 0)
            return n;
        else
            return uf[n] = root(uf[n]);
    }

    bool connected(int a, int b) { return root(a) == root(b); }

    void marge(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        if (root_a != root_b) {
            if (uf[root_a] > uf[root_b]) swap(root_a, root_b);
            uf[root_a] += uf[root_b];
            uf[root_b] = root_a;
        }
    }

    int size(int n) { return -uf[root(n)]; }
};

bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}