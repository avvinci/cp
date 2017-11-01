int spanningTree(vector <pair<int,int> > g[], int MAX) {
    priority_queue<ii, vii, greater<ii> > cut;
    cut.push(ii(0, 1));
    vb marked(MAX, false);
    int ans = 0;
    while(!cut.empty()) {
        ii p = cut.top();
        cut.pop();
        int v = p.S;
        ans += p.F;
        if(marked[v]) continue;
        marked[v] = true;
        for(int i = 0; i < g[v].size(); i++) {
            if(marked[g[v][i].S] == false) {
                cut.push(g[v][i]);
            }
        }
    }
    return ans;
}