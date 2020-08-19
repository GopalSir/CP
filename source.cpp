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
void dijkstra(vector<list<pair<int,int> > > &graph,int src_vert, vector<int> &short_path)
{
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
                }
         }        
         
     } 


}



int main()
{  
    vector<list<pair<int,int> > >graph;
    graph.resize(7);      //N+1;
       graph[1].push_back(make_pair(2,-1));
       // graph[2].push_back(make_pair(1,-1));
       
       graph[1].push_back(make_pair(3,20));
       graph[3].push_back(make_pair(1,20));  
       
        graph[2].push_back(make_pair(3,10));  
         graph[3].push_back(make_pair(2,10));  
       
         graph[2].push_back(make_pair(4,7));
         graph[4].push_back(make_pair(2,7));

         graph[3].push_back(make_pair(4,2));
         graph[4].push_back(make_pair(4,2));

       vector<int>dis(graph.size());
       dijkstra(graph,1,dis);
       for(auto  &elem : dis)
       cout<<elem<<"\t";
    //    cout<<endl;
    // priority_queue<pair<int,int>, vector<pair<int,int> >,customcompare >vert_queue;
    // vert_queue.push(make_pair(1,10));
    // vert_queue.push(make_pair(2,3));
    // vert_queue.push(make_pair(3,6));
    // while(vert_queue.empty()!=true)
    // {
    //     cout<<vert_queue.top().first<<"\t";
    //     vert_queue.pop();
    // }


}




