int time = 1;
set <int> ans;
void dfs(int i,int p,vector <int> adj[],vector <int> &vis,vector <int> &in,vector <int> &low){
    vis[i] = 1;
    in[i] = low[i] = time++;
    int child = 0;
    for(auto it:adj[i]){
        if(it == p) continue;
        if(!vis[it]){
            dfs(it,i,adj,vis,in,low);
            low[i] = min(low[i],low[it]);
                if(low[it] >= in[i] && p != -1) ans.insert(i);
            child++;
        }
        else low[i] = min(low[i],in[it]);
    }
    if(child > 1 && p == -1) ans.insert(i);
}
vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector <int> vis(n),in(n),low(n);
    dfs(0,-1,adj,vis,in,low);
    if(ans.size() == 0) return {-1};
    return vector<int>(ans.begin(),ans.end());
}
