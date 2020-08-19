#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <queue>
using namespace std;

/* used for graph vertex,distance pair comparison */
struct customcompare{
    bool operator()(const pair<int,int> &v1,const pair<int,int> &v2)
    {
        return v1.second > v2.second ;
    }
};


//function to find shortest path to 1 to N vertices from a soucrce vertex
//graph size should already be (N+1) 
/** short_path is the vector which will get result of dijkstra algorithm **/
void dijkstra(vector<list<pair<int,int> > > &graph,int src_vert, vector<int> &short_path){
    priority_queue<pair<int,int>, vector<pair<int,int> >,customcompare >vert_queue;
    vector<bool>visited(graph.size(),false);      //visited vector
    short_path.resize(graph.size());        //making sure to correct any size related issue
    for(auto &elem: short_path)
     elem = INT32_MAX;          // all distance infinite initially
     short_path[src_vert] = 0;  //distance of source vertex from itself is zero duh       
     vert_queue.push(make_pair(src_vert,short_path[src_vert]));      
     while(vert_queue.empty()!=true)
     {
         int cur_vertex = vert_queue.top().first;        
                     //the vertex popped is the now visited and done for

         vert_queue.pop();                    //pop the visited vertex out of queue
         if(visited[cur_vertex]==true) continue ;
         visited[cur_vertex]=true;
         for(auto adj_vert : graph[cur_vertex])
                  {
               if(short_path[adj_vert.first]>(short_path[cur_vertex] + adj_vert.second )) 
                short_path[adj_vert.first] = short_path[cur_vertex] + adj_vert.second;                
                if(visited[adj_vert.first]==false)
                {
                    vert_queue.push(make_pair(adj_vert.first,short_path[adj_vert.first]));                  
                }         }           
     } 


}

/**
 * saves the bfs traversal of graph in bfs_path vector
 * src_vert = starting vertex  **/
void breadth_first_search(vector<list<pair<int,int> > > &graph,int src_vert, vector<int> &bfs_path)
{
    

        vector<bool>visited(graph.size(),false);
        queue<int>vert_queue;       //vertex number
        

        visited[src_vert] = true;
        vert_queue.push(src_vert);         //pushig source vertex

    while (!vert_queue.empty())
    {
        int cur_vertex = vert_queue.front();

       

        vert_queue.pop();
        visited[cur_vertex] = true;
        bfs_path.push_back(cur_vertex);
        for(auto &adj_vertex : graph[cur_vertex])
        {
            if(visited[adj_vertex.first] == false)         //only process unvisited vertices
            {
                vert_queue.push(adj_vertex.first);
                visited[adj_vertex.first] = true;
            }            
        }

        

    }          
}



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    vector<list<pair<int,int> > >graph;
    int n;    
    cin>>n;
    graph.resize((4*n)+1);              //graph size will be N+1
    
   // graph[0].push_back({0,0});

    for(int i=1;i<=(2*n);++i)
    {
        graph[i].push_back({2*i,0});    //reachable vertex and it's weight (weight is irrelevant here)
        graph[i].push_back({i-1,0});
    }
    vector<int>ans;
    breadth_first_search(graph,1,ans);
    for(auto x:ans)
    cout<<x<<"\t";


     
 
}




