#include <vector>
#include "../include/mheap.h"
// the size of heap is not the size of the array 
// in fact it is the size upto which heap is required or heap sort is required
int  max_heapify(std::vector<int>& arr,int index,int &heapsize)
{
	if(index>=arr.size())
		return -1;
	// checks max heap property at index 
	int left_index=index*2 +1;
	int right_index=index*2 + 2;
	int largest_index=index;    // initialization

	if( (arr[index] > arr[left_index]) &&( left_index <heapsize ) )
		largest_index = left_index;

	if( (arr[largest_index] > arr[right_index]) && (right_index <heapsize ) )
		largest_index = right_index;
	if(largest_index!=index)
	{	
		int temp=arr[largest_index];
		arr[largest_index]=arr[index];
		arr[index]=temp;
		max_heapify(arr,largest_index,heapsize);
	}
	return 1;
}

int build_heap(std::vector<int>& barr,int &heapsize)
{
	const int start_index = heapsize/2;
	for(int i=start_index;i>=0;--i)
	{
	  if( max_heapify(barr,i,heapsize)!=1)
		  return 0;            // return when max_heapify fails 
	}
	return 1;      // return one on succesfull builheap
	
}

int heap_sort(std::vector<int>& arr,int heapsize)
{
	if(build_heap(arr,heapsize)!=1)
		return 0;
	for(int i=heapsize-1;i>0;--i)
	{
		// exchange root with end of heap
		int temp = arr[0];
		arr[0]=arr[heapsize-1];
		arr[heapsize-1] =temp;
		heapsize--;
		max_heapify(arr,0,heapsize);
	}
	return 1;
	// we need to define the heap size now every time hmmmm
}

