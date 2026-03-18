class TreeAncestor {
public:
    vector<vector<int>> v;
    int nodes;

    TreeAncestor(int n, vector<int>& parent) {
        v.resize(n, vector<int>(16, -1)); // 2^16 > 50000
        nodes = n;

        // Immediate parent
        for (int i = 0; i < n; i++) v[i][0] = parent[i];

        // Precompute 2^j-th ancestors
        for (int j = 1; j < 16; j++) {
            for (int i = 0; i < n; i++) {
                if (v[i][j - 1] != -1) {
                    v[i][j] = v[v[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        if (k >= nodes || node < 0) return -1;

        int x = 0;
        while (k > 0 && node != -1) {
            if (k % 2 == 1) node = v[node][x];
            x++;
            k = k/2;
        }
        return node;
    }
};