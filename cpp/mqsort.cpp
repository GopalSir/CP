#include "../include/mqsort.h"

int mpartition(std::vector<int>&arr,int mstart,int mend)
{
	
	

	int pivelem = arr[mend];
	int mi=mstart-1;
	
	for(int j=mstart;j<mend;++j)
	{
	   if(arr[j]<=pivelem)
	   {
		   int temp=arr[j];
		   arr[j]=arr[++mi];
		   arr[mi]=temp;
	   }

	}
	int temp=arr[++mi];
	arr[mi]=arr[mend];
	arr[mend]=temp;

	return mi;

}

int mqsort(std::vector<int> &arr,int mstart,int mend)
{
	 if(mstart>=mend)
	 return 1;
		
	int pivot = mpartition(arr,mstart,mend);
	
	if(pivot == -1)
	return -1;

	if(mqsort(arr,mstart,pivot-1) && mqsort(arr,pivot+1,mend) )
		return 1;
	else 
		return -1;
}
