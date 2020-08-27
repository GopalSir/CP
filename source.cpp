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
       char *data_pointer = nullptr;
       char *temp_pointer = nullptr;
        int shmid = shmget(mykey,mysize,0666);
        if(shmid < 0)
        {
            cout<<"ID failed";
            exit(1);
        }

        data_pointer = (char*)shmat(shmid,nullptr,0);
        if(*data_pointer == -1)
        {
            cout<<"attach failed";
            exit(1);
        }

        temp_pointer = data_pointer;
        *temp_pointer = 'a';
        while (*temp_pointer != 'e'){}
        cout<<"cp.cpp has changed something in memory\n";
        return 0;


}