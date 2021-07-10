#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<int> adj[] ,int sauce , int curr , bool visit[], int str[] , bool done[], bool& strong){
        if(sauce == curr) return 1 ; 
        // this means from the particular vertex we can move to the root 
        
        
        if(str[curr] != -1) return str[curr];
        // if its not -1 , it means its value has been already evaluated ! so just return 
        
        visit[curr] = 1 ; 
        str[curr] = 0 ; // now setting it zero because we will perm XOR to see if final result 
        // is 0 or 1 to see if its connected to root or not !

        for(auto v : adj[curr]){
            if(!visit[v])
            str[curr] |= dfs(adj , sauce , v , visit , str , done,strong);
            // seeing different ways to reach root !
        }
        
        if(str[curr]) { // if we have reached root 
            if(done[curr] == 1) strong = true ; // if it was already done 
            // means it was already part one one component so STRONG SET TO TRUE 
            
            
            else done[curr] = 1 ; // else it means it wasn't part of any component , so 
            // new component should be added so we are only updating done[] !
        }
        visit[curr] = 0 ;  // its a kinda back tracking to check different path so at last just reseting 
        // it to be not visited 
        
        return str[curr]; // returing the value if it has meet root or not !
        
    }
    int kosaraju(int V, vector<int> adj[])
    {
    
     bool visit[V] = {0}; // will help to find if already visited 
     int cnt = 0 ; // for counting components 
     
     int str[V]; // str to check 
     fill(str , str + V , -1); // initialized to -1 not 0 .
     // but will be containing 0/1 eventually 
     
     bool done[V] = {0}; // initialized to 0 
     // done means its a already a part of strong component !
     
     
     // concept is like , lets say 'e' is a part of Component 1 and Component 2 ,
     // then Component  1 and 2 must be same ! they are just 1 together !!
     
     // IF YOU STILL DONT GET IT THEN THINK WHY ! GET A PEN AND PAPER !
   
     for(int i = 0 ; i< V ; i++){
         if(not done[i]){ // if its not a part of any component then only we will go for it !
             done[i] = 1 ; // now its a part !!! 
             
             int sauce = i ; // its the root from where traversing will start ! 
             
             bool strong = false ; // lets assume its not a part of component yet !
             for(auto vertex : adj[i]){
                 dfs(adj , sauce , vertex , visit,str,done,strong);
                 // helps to modify strong variable ! !
             }
             
             if(!strong) cnt++; // if not strong it means we assume it associates with some new component 
             // that wasnt being considered untill now !
             
             fill(visit , visit+V , 0 ); // reset 
             fill(str , str+V , -1);  // reset 
         }
     }
     return cnt ; // returing count ! 
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

