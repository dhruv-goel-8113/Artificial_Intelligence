#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>mp,vector<int>&visited,int start,int depth){
    if(depth==0) return;
    cout<<start;
    for(auto x:mp[start]){
        if(!visited[x]){
            visited[x]=1;
            dfs(mp,visited,x,depth-1);
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;
    unordered_map<int,vector<int>>mp;
    int v1,v2;
    for(int i=1;i<=e;i++){
        cout<<"Enter the vertices between which edge is there : ";
        cin>>v1>>v2;
        mp[v1].push_back(v2);
        mp[v2].push_back(v1);
    }
    int start;
    cout<<"Enter the starting node : ";
    cin>>start;
    for(auto &x:mp){
        sort(x.second.begin(),x.second.end());
        }

        for(int depth=1;depth<=3;depth++){
            vector<int>visited(n+1,0);
            visited[start]=1;
            dfs(mp,visited,start,depth);
            cout<<endl;
        }
    return 0;
}