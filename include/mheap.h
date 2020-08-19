#ifndef MHEAP_H
#define MHEAP_H
// heap class in only meant to provide function building and maintaining the heap property . it is not meant to contain the heap . 



int max_heapify(std::vector<int>&);
int build_heap(std::vector<int>&,int &);
int heap_sort(std::vector<int>&,int);
	


class mpriority_queue
{
	// this will contain the heap as supplied directly by user or inserted
	// graudally

	public : 
		bool insert(int elem);
		bool get_max_elem();
		bool extract_max_elem();
		bool increase_key(int index,int new_key);
	private :
		bool isheap();
		bool flushqueue();
			
};

        
#endif
