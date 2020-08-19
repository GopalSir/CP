#ifndef MSSSP
#define MSSSP

#include <vector>
#include <algorithm>
using namespace std;
struct min_container
{
    vector<int>min_cost;
    vector<int>prev;
};

min_container sssp(vector<pair<int,int>>graph[],int N,int src);



#endif MSSSP
