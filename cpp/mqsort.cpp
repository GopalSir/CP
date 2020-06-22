#include "../include/mqsort.h"

int mpartition(std::vector<int>&arr,int mstart,int mend)
{
	
	if(mstart>=mend)
		return -1;

	int pivelem = arr[mend];
	int mi=-1;
	
	for(int j=mstart;j<mend;++j)
	{
	   if(arr[j]<=pivelem)
	   {
		   int temp=arr[j];
		   arr[j]=arr[++i];
		   arr[i]=temp;
	   }

	}
	temp=arr[++i];
	arr[i]=arr[mend];
	arr[mend]=temp;

}

int mqsort(std::vector<int> &arr,int mtsart,int mend)
{
	if(arr.size()==1)
		return 1;
		
	int pivot = mqsort(arr,mstart,mend);
	
	if(pivot == -1)
	return -1;

	if(mqsort(arr,mstart,pivot) && mqsort(arr,pivot+1,end) )
		return 1;
	else 
		return -1;
}
