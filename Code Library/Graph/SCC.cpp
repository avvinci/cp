typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

void dfs_visit(int u, vvi &g, vb& visited, vi& finished, int pass) {
    visited[u] = true;
    for(int i = 0; i < g[u].size(); i++) {
        if(visited[g[u][i]] == false) {
            dfs_visit(g[u][i], g, visited, finished, pass);
        }
    }
    if(pass = 1)
        finished.push_back(u);
}

vi dfs1(vvi &g) {
    vector<bool> visited(g.size(), false);
    vector<int> finished;
    for(int i = 1; i < g.size(); i++) {
        if(!visited[i]) {
            dfs_visit(i, g, visited, finished, 1);
        }
    }
    return finished;
}

int dfs2(vvi &g, vi& finish) {
    vector<bool> visited(g.size(), false);
    vector<int> finished;
    int num_cc = 0;
    for(int i = finish.size() - 1; i >= 0; i--) {
        if(!visited[finish[i]]) {
            num_cc++;
            dfs_visit(finish[i], g, visited, finished, 2);
        }
    }
    return num_cc;
}

vvi transpose_graph(vvi &g) {
    int n = g.size();
    vvi gt(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < g[i].size(); j++) {
            gt[g[i][j]].push_back(i);
        }
    }
    return gt;
}

// returns number of SCC in graph g
int kosaraju(vvi &g) {
    vi finish = dfs1(g);
    vvi gt = transpose_graph(g);
    return dfs2(gt, finish);
}