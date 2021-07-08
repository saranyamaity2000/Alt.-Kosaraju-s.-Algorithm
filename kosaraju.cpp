#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int dfs(vector<int> adj[] ,int sauce , int curr , bool visit[], int str[] , bool done[], bool& strong){
        if(sauce == curr) return 1 ;
        if(str[curr] != -1) return str[curr];
        
        visit[curr] = 1 ; 
        str[curr] = 0 ; 
        int cnt = 0 ; 
        for(auto v : adj[curr]){
            if(!visit[v])
            str[curr] |= dfs(adj , sauce , v , visit , str , done,strong);
        }
        if(str[curr]) {
            if(done[curr] == 1) strong = true ;
            else done[curr] = 1 ;
        }
        visit[curr] = 0 ; 
        return str[curr]; 
    }
    int kosaraju(int V, vector<int> adj[])
    {
     int nums[V] = {0};
     for(int i = 0 ; i<V  ; i++){
         for(auto v : adj[i]){
             nums[i] = 1;
             nums[v] = 1;
         }
     }
     bool visit[V] = {0};
     int cnt = 0 ; 
     int str[V]; 
     bool done[V] = {0};
   
     fill(str , str + V , -1);
     for(int i = 0 ; i< V ; i++){
         if(not done[i]){
         done[i] = 1 ; 
         int sauce = i ;
         bool strong = false ; 
         for(auto vertex : adj[i]){
             dfs(adj , sauce , vertex , visit,str,done,strong);
         }
         if(!strong) cnt++;
         fill(visit , visit+V , 0 );
         fill(str , str+V , -1);
         }
     }
     return cnt ; 
    }
};
int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

