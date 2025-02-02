#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, vector<int>& parent, vector<int>& rank) {
    int rootX = find(x, parent);
    int rootY = find(y, parent);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int> > coordinates(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    
    vector<int> parent(n), rank(n, 1);
    
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    
    unordered_map<int, int> x_map, y_map;
    
    for (int i = 0; i < n; ++i) {
        int x = coordinates[i].first;
        int y = coordinates[i].second;
        
        if (x_map.find(x) != x_map.end()) {
            unite(i, x_map[x], parent, rank);
        }
        x_map[x] = i;
        
        if (y_map.find(y) != y_map.end()) {
            unite(i, y_map[y], parent, rank);
        }
        y_map[y] = i;
    }
    
    unordered_map<int, bool> components;
    for (int i = 0; i < n; ++i) {
        components[find(i, parent)] = true;
    }
    
    cout << components.size() - 1 << endl;
    
    return 0;
}
