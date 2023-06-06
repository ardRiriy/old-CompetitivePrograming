class UnionFind {
   private:
    vector<int> uf;

   public:
    UnionFind(int n) : uf(n) {
        for (int i = 0; i < n; i++) uf[i] = -1;
    }

    int root(int n) {
        if (uf[n] >= 0) uf[n] = root(uf[n]);
        return n;
    }

    bool connected(int a, int b) { return root(a) == root(b); }

    void marge(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        if (root_a != root_b) {
            if (root_a > root_b) swap(root_a, root_b);
            uf[root_a] += root_b;
            uf[root_b] = root_a;
        }
    }

    int size(int n) { return -uf[root(n)]; }
};