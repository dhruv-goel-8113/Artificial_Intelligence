#include<bits/stdc++.h>
using namespace std;
void bfs(unordered_map<int,vector<int>>&mp,int start,vector<int>&visited){
    queue<int>q;
    visited[start]=1;
    q.push(start);
    while(!q.empty()){
        int vert=q.front();
        cout<<vert<<" ";
        vector<int>temp=mp[vert];
        for(int i=0;i<temp.size();i++){
            if(!visited[temp[i]]){
                q.push(temp[i]);
                visited[temp[i]]=1;
            }
        }
        q.pop();
    }
}

void dfs(unordered_map<int,vector<int>>&mp,int start,vector<int>&visited){
    if(!visited[start]){
        cout<<start<<" ";
        visited[start]=1;
    }
   for(auto x:mp[start]){
    if(!visited[x]) dfs(mp,x,visited);
   }
   return;
}
int main(){
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    vector<int>visited(n,0);
    int e;
    cout<<"Enter the number of edges : ";
    cin>>e;
    unordered_map<int,vector<int>>mp;
    int v1,v2;
    for(int i=1;i<=e;i++){
        cout<<"Enter the vertices btw which edge is there : ";
        cin>>v1>>v2;
        mp[v1].push_back(v2);
        mp[v2].push_back(v1);
    }
    for(auto &x:mp){
        sort((x.second).begin(),(x.second).end());
    }
    int start;
    cout<<"Enter the starting node : ";
    cin>>start;
    string str;
    cout<<"Choose between bfs/dfs : ";
    cin>>str;
    if(str=="bfs") bfs(mp,start,visited);
    else dfs(mp,start,visited);

    for(int i=0;i<n;i++){
        if(!visited[i]) cout<<i<<" ";
    }
    return 0;
}