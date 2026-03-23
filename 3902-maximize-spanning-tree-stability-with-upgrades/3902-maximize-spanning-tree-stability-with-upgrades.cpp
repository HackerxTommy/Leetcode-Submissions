class UnionFind {
private:
    vector<int> parent, rank;
    int count;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        count = n;
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        count--;
        return true;
    }
    
    bool connected() { return count == 1; }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> must_edges, optional_edges;
        for (auto& e : edges) {
            if (e[3] == 1) must_edges.push_back(e);
            else optional_edges.push_back(e);
        }
        
        // First, check if must_edges form a forest without cycles
        UnionFind uf_must(n);
        int must_edges_used = 0;
        for (auto& e : must_edges) {
            if (uf_must.unite(e[0], e[1])) must_edges_used++;
            else return -1; // Cycle in must edges
        }
        
        // Binary search on the answer
        int left = 0, right = 1e9, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(n, must_edges, optional_edges, k, mid, must_edges_used)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
    
private:
    bool isPossible(int n, vector<vector<int>>& must_edges, vector<vector<int>>& optional_edges, int k, int min_strength, int must_edges_used) {
        UnionFind uf(n);
        int upgrades_used = 0;
        
        // First add all must edges
        for (auto& e : must_edges) {
            if (e[2] < min_strength) return false; // Must edge doesn't meet requirement
            uf.unite(e[0], e[1]);
        }
        
        // Add optional edges without upgrade if they meet min_strength
        for (auto& e : optional_edges) {
            if (e[2] >= min_strength && uf.unite(e[0], e[1])) {
                must_edges_used++;
            }
        }
        
        // If already connected, we might not need all upgrades
        if (uf.connected()) return true;
        
        // Now try using upgrades on optional edges that are below min_strength
        for (auto& e : optional_edges) {
            if (upgrades_used >= k) break;
            if (e[2] * 2 >= min_strength && e[2] < min_strength) {
                if (uf.unite(e[0], e[1])) {
                    upgrades_used++;
                    must_edges_used++;
                }
            }
        }
        
        // Check if we have a spanning tree with enough edges
        return uf.connected() && must_edges_used == n - 1;
    }
};