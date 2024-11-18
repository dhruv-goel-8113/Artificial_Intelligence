#include<bits/stdc++.h>
using namespace std;
void astar(vector<vector<int>>&adj,int start,int dest,int n,vector<int>&hscore){
    vector<int>dist(n,INT_MAX);
    dist[start]=0;
    for(int i=0;i<n;i++){
        if(adj[start][i]!=0) dist[i]=adj[start][i]+hscore[i];
    }

    vector<int>visited(n,0);
    vector<int>parent(n,start);
    visited[start]=1;
    int min_nod=start;
    int mind=hscore[start];
    while(min_nod!=dest){
        int curr_node=min_nod;
        min_nod=INT_MAX;
        mind=INT_MAX;
        for(int i=0;i<n;i++){
            if(visited[i]!=1 && dist[i]<mind){
                mind=dist[i];
                min_nod=i;
            }
        }
        visited[min_nod]=1;
        for(int i=0;i<n;i++){
            if(visited[i]!=1 && adj[min_nod][i]!=0 && (dist[i] > (dist[min_nod] - hscore[min_nod] + adj[min_nod][i] + hscore[i]))){
                parent[i]=min_nod;
                dist[i]=dist[min_nod] - hscore[min_nod] + adj[min_nod][i] + hscore[i];
            }
        }
    }
    cout<<"Minimum distance is : "<<dist[dest]<<endl;
    int j=dest;
    string st="";
    char ch=(char)(48+dest);
    st+=ch;
    while(j!=start){
        j=parent[j];
        ch=(char)(48+j);
        st+=ch;
    }
    
    for(int i=st.length()-1;i>=1;i--){
        cout<<st[i]<<"->";
    }
    cout<<st[0];
}
int main(){
    vector<vector<int>>adj={{0,6,3,1,0,0,0,0,0,0},{6,0,2,6,3,4,0,0,0,0},{3,2,0,0,4,5,0,0,0,0},{1,6,0,0,7,8,9,0,0,0},{0,3,4,7,0,6,9,9,0,0},{0,4,5,8,6,0,8,9,0,0},{0,0,0,9,9,8,0,11,12,14},{0,0,0,0,9,9,11,0,14,15},{0,0,0,0,0,0,12,14,0,0},{0,0,0,0,0,0,14,15,0,0}};
    vector<int>hscore={15,13,13,12,10,9,7,6,5,0};
    astar(adj,0,9,10,hscore);
    return 0;
}