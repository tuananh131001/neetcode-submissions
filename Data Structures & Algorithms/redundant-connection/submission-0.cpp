class Solution {
public:
    vector<int> parent;
    vector<int> rnk;

    int find(int n) {
        if (parent[n] != n) {
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }
    
    bool doUnion(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false; // cycle detect
        }

        if (rnk[rootX] > rnk[rootY]) {
            parent[rootY] = rootX;
        } else if (rnk[rootX] < rnk[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootX] = rootY;
            rnk[rootY]++;
        }
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        parent.resize(n);
        rnk.resize(n,0);
        vector<int> res;
        
        for (int i = 1; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge: edges) {
            if (!doUnion(edge[0], edge[1])) { // yes this is redundant conn
                res = edge;
            }
        }
        return res;
    }
};
