#include <bits/stdc++.h>
#include <unistd.h>
#include <syscall.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;
/* read the graph as an adjacency list  */
int main()
{
       key_t mykey = 101;
       size_t mysize = 10;
       char *data_pt;

        int shmid = shmget(mykey,mysize,0666);
        if(shmid<0)
        exit(-1);

        data_pt = (char*)shmat(shmid,nullptr,0);
        if(*data_pt == -1)
        exit(0);
        
        while (1)
        {
          char ch;
          cin>>ch;
          *data_pt = ch;
        }
        
            
}