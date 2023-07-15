	void toposort(int start,vector<vector<int>>&adj,unordered_map<int,bool>&visited,stack<int>&s){
	    
	    visited[start]=true;
	    vector<int> temp=adj[start];
	    for(int i=0;i<temp.size();i++){
	        if(visited[temp[i]]!=true){
	            toposort(temp[i],adj,visited,s);
	        }
	    }
	    s.push(start);
	}
	void dfs(int start,vector<vector<int>>&adj,unordered_map<int,bool>&visited){
	  	
	  	visited[start]=true;
	    vector<int> temp=adj[start];
	    for(int i=0;i<temp.size();i++){
	        if(visited[temp[i]]!=true){
	            dfs(temp[i],adj,visited);
	        }
	    }  
	}
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        stack<int> s;
        unordered_map<int,bool> visited(false);
        for(int i=0;i<n;i++){
            if(visited[i]!=true){
                toposort(i,adj,visited,s);
            }
        }
        vector<vector<int>> reverse(n);
        for(int i=0;i<adj.size();i++){
            vector<int> temp=adj[i];
            for(int j=0;j<temp.size();j++){
                reverse[temp[j]].push_back(i);
            }
        }
        int count=0;
        visited.clear();
        while(s.size()!=0){
            
            int node=s.top();
            s.pop();
            if(visited[node]==true){
                continue;
            }
            count++;
            dfs(node,reverse,visited);
        }
        return count;
    }
