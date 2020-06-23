#include "../include/dijkstra.h"


//first element of pair is the adj vertex and the second element is the cost to that vertex
//N is the number of vertices
//src is the source vertex


min_container sssp(vector<pair<int,int>>graph[],int N,int src)
{
    min_container res;
    bool visited[N]={false};
    //initialize all distances to MAX
    //all prev nodes to -1
    res.min_cost=vector<int>(N,__INT32_MAX__);
    res.prev = vector<int>(N,-1);

    //cost of source node is zero
    res.min_cost[src]=0;
    // now go through all the unvisited noes
    for(int i=0;i<N;++i)
    {
        //find the min cost vertex 
        int minv=-1;
        for(int j=0;j<N;++j)
        {
            if(visited[j]==false && (minv==-1 || res.min_cost[j]<res.min_cost[minv]))
                minv = j;
        }

        visited[minv]=true;
        //visit all the edges and relax them
        for(int j=0; j<graph[minv].size();++j)
        {
            int vert = graph[minv][j].first;
            int cost = graph[minv][j].second;

            if( (res.min_cost[minv]+ cost) < res.min_cost[vert] )
            {
                res.min_cost[vert]= res.min_cost[minv]+cost;
                res.prev[vert]=minv;
            }

        }

         
    }
    return res;
}