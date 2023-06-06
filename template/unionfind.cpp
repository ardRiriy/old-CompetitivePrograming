class UnionFind {
   private:
    vector<int> uf;

   public:
    UnionFind(int size) : uf(size) {
        for (int i = 0; i < size; i++) uf[i] = i;
    }

    int root(int n) {
        if (uf[n] != n) uf[n] = root(uf[n]);
        return uf[n];
    }

    bool connected(int a, int b) { return root(a) == root(b); }

    void marge(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        if (root_a != root_b) uf[root_a] = root_b;
    }

    int size(int n) {
        int cnt = 0;
        int r = root(n);
        for (int k : uf)
            if (k == r) cnt++;
        return cnt;
    }
};