#include <algorithm>

void extract_max_from_heap(std::vector<int> &vec,int &heap_size)
{
	if(heap_size !=0)
	std::swap(vec[0],vec[heap_size-1]);

	heap_size--;

}

void max_heapify(std::vector<int> &vec,int index,int size)
{
	


	if(index >= size )
		return ;

	int left_index = 2*index + 1;
	int right_index = 2*index + 2;
	int largest_index = index;

	if(left_index < size )
	{
		if(vec[left_index] > vec[largest_index])
			largest_index = left_index;
	}

	if(right_index < size)
	{
		if(vec[right_index] > vec[largest_index])
			largest_index = right_index;
	}

	std::swap(vec[index],vec[largest_index]);

	//recursive call to largest index as it might now be disturbed . 
	if(index != largest_index)
	max_heapify(vec,largest_index,size);
}

int kth_largest_elements( std::vector<int> &vec,int k)
{
	std::cout<<"Lmao \n";
     int size = vec.size();

     for(int i=size/2 + 1; i>=0; --i)
     {
     	max_heapify(vec,i,vec.size());
     }

     for(int i=0;i<size;++i)
     	std::cout<<vec[i]<<" ";
     std::cout<<std::endl;

     for(int i=0;i<k;++i)
     {
     	extract_max_from_heap(vec,size);
     	max_heapify(vec,0,size);
     }


     for(int i=0;i<vec.size();++i)
     	std::cout<<vec[i]<<" ";
     std::cout<<std::endl;

     return 0;

}



