#include <bits/stdc++.h>
#include <thread>

using namespace std;
using namespace chrono;


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

//marks all prime indexes as 0 in the passed by reference vector<int> vec
void prime_sieve(int n,vector<int> &vec)
{
    vec.resize(n+1,0);     //0 means unvivisted index . initially all indexes are unvisited
    for(int i=2;(i*i)<=n;++i)
    {
        if(vec[i]==0)   // if unvisited then visit all multiples
        for(int j=(i*i);j<=n;j+=i)
        {
            vec[j]=1;      //make this multiple visited
        }
    } 
            
}

long long lcs(string a, string b,int m,int n)
{
    int arr[m+1][n+1];

    //base case for when one of the length is zero
    for(int i=0;i<=m;++i) arr[i][0]=0;  // base cases
    for(int i=0;i<=n;++i) arr[0][i]=0;  // base cases

    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i-1] == b[j-1])
            {
                arr[i][j] = 1 + arr[i-1][j-1];
            }
            else
            {
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }

        }
    }

    return arr[m][n];   

}



 void floyd_warshall(int graph[][5],int Vertex_count,int solution_matrix[][5])
{
    //initializing sol matrix same as given graph
    for(int i=0;i<Vertex_count;++i)
    {
        for(int j=0;j<Vertex_count;++j)
        {
            solution_matrix[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < Vertex_count; ++k)
    {
         //k is the intermediate vertex
         //now relax i j pair using  using intermediate vertex k
        for (int i = 0; i < Vertex_count; ++i)
        {
            for (int j = 0; j < Vertex_count; ++j)
            {
             if(solution_matrix[i][j] > (solution_matrix[i][k] + solution_matrix[k][j]) )
                solution_matrix[i][j] = solution_matrix[i][k] + solution_matrix[k][j];
            }
        }

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////



//edit distance problem using recursion. 
//m and n are size of string measured from left to right
int edit_distance(string &a,string &b,int m,int n)
{
    if(m == 0)
        return n;
    if(n ==0)
        return m;

    if(a[m-1] == b[n-1])
        return edit_distance(a,b,m-1,n-1);
    int ans = INT32_MAX;

    int r1 = 1 + edit_distance(a,b,m,n-1);
    int r2 = 1 + edit_distance(a,b,m-1,n);
    int r3 = 1 + edit_distance(a,b,m-1,n-1);

    ans = min(r1,r2);
    ans = min(ans,r3);

    return ans; 
}


int main()
{   /***************************************/
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("time.txt","w",stderr);
    auto start = high_resolution_clock::now();
    /***************************************/
    
    
    string a = "gaurav";
    string b = "gauravd";

    cout<<edit_distance(a,b,6,7);
    







     

    /***************************************/
    auto end = high_resolution_clock::now();
    auto dur = duration_cast<milliseconds>((end - start));
    cerr<<"Elapsed : "<<dur.count()<<" MS\n";
    /***************************************/
   
    return 0;    
}




