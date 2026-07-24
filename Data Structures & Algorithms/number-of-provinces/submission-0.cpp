class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionFind(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }

        // rank x less than y, then parent x is y
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            rank[rootY]++;
        }
        return true;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        this->parent.resize(n);
        this->rank.resize(n, 0);
        int provinces = n;

        // each islands is its own parent
        for (int i = 0; i < n ; i++) {
            parent[i] = i;
        }

        for (int x = 0; x < n; x++) {
            for (int y = x + 1; y < n; y++) { // ???
                if (isConnected[x][y] == 1) {
                    if (unionFind(x, y)){
                        provinces--;
                    }
                }
            }
        }
        return provinces;
    }
};