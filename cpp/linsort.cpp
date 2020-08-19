#include "../include/linsort.h"
//function to find maximum value in an array
int maxofarr(std::vector<int>arr)
{
	int result = 0;
	for(auto &x:arr)
	{
		if(x>result)
			result = x;
	}
	return result;
}

int mcountingsort(std::vector<int>&arr)
{
    int cmax = maxofarr(arr);

    //frequency array
    std::vector<int>freq(cmax,0);
    for(auto x:arr)
    {
	    if(x<0)
		    return -1;
	freq[x]++;
    }
	//now we have frequency array , start writing into the original aray the elements 
    int pos=0;
	for(int i=0;i<=cmax;++i)
	{
	    while(freq[i]>0)
	    {
		    freq[i]--;
		    arr[pos++]=i;
	    }
	}	
    return 1;

}
