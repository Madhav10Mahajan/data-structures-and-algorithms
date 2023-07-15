 void dfs(int start,int parent,unordered_map<int,vector<int>>&ourmap,unordered_map<int,bool>&visited,vector<int>&time,vector<int>&low,int timer,vector<vector<int>>&ans){
        
        visited[start]=true;
        time[start]=timer;
        low[start]=timer;
        timer++;
        vector<int> temp=ourmap[start];
        for(int i=0;i<temp.size();i++){
            
            if(temp[i]==parent){
                continue;
            }
            if(visited[temp[i]]!=true){
                
                dfs(temp[i],start,ourmap,visited,time,low,timer,ans);
                low[start]=min(low[start],low[temp[i]]);
                if(low[temp[i]]>time[start]){
                    ans.push_back({temp[i],start});
                }
            }
            else{
                low[start]=min(low[start],low[temp[i]]);
            }
        }
        
    }
    vector<vector<int>> bridges(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,vector<int>> ourmap;
        for(int i=0;i<connections.size();i++){
            
            int a=connections[i][0];
            int b=connections[i][1];
            ourmap[a].push_back(b);
            ourmap[b].push_back(a);
        }
        unordered_map<int,bool> visited(false);
        vector<int> time(n+1,0);
        vector<int> low(n+1,0);
        int timer=0;
        vector<vector<int>> ans;
        dfs(0,-1,ourmap,visited,time,low,timer,ans);
        return ans;
    }
