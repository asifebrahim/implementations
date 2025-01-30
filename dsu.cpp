#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
class Dsu{
    vector<int> rank,parent;
    public:
    Dsu(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUltimateParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUltimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ult_u=findUltimateParent(u);
        int ult_v=findUltimateParent(v);
        if(ult_u==ult_v){
            return;
        }
        else if(rank[ult_u]>rank[ult_v]){
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }else{
            parent[ult_u]=ult_v;
            rank[ult_u]++;
        }
    }
};

int main(){
    Dsu dsu(7);
    dsu.unionByRank(1,2);
    dsu.unionByRank(2,3);
    dsu.unionByRank(4,5);
    dsu.unionByRank(6,7);
    dsu.unionByRank(5,6);
    if(dsu.findUltimateParent(3)==dsu.findUltimateParent(7)){
        cout<<"7 and 3 are connected---This is the case Before [3,7]"<<endl;
    }else{
        cout<<"3 and 7 are not connected---This is the case Before [3,7]"<<endl;
    }

    dsu.unionByRank(3,7);
    if(dsu.findUltimateParent(3)==dsu.findUltimateParent(7)){
        cout<<"7 and 3 are connected---This is the case After [3,7]"<<endl;
    }
    else{
        cout<<"3 and 7 are not connected---This is the case After [3,7]"<<endl;
    }
}