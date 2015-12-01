#include <vector>
using std::vector;

// Nodes contain a vector containing node pointers and a pointer to an object 
#pragma once
template <typename data_type>
class node
{
private:
	// Hierachically contains all of the strata of the trie using a vector containing pointers to the next
	// nodes in the structure
	vector<node<data_type>> next_vec;

	// When we find a match, then we will point to an object of type Y defined by the programmer
	data_type finalObj;

	int bucket_size;
public:

	// Every time a new node is created, we want to initialize its vector of pointers to null
	node(int bucketSize)
	{
		bucket_size = bucketSize;
		// Initialize the vector of node pointers
		// bucket sized all initialized to zero
	}
	node(){
	}
	bool check_index(int index){

		if( next_vec.capacity() == 0 ){
		//vector not yet initialized
			return false;
		}
		else{
		//vector initialized, is the index present?
			node<data_type>& temp = next_vec[index];
			
			if( temp.next_vec.capacity() == 0 ) 
			{	
				return false;
			}
		}

		return true;
	}

	node<data_type>* move_to_index( int index){
		node<data_type> *temp = &(next_vec[index]);
		return temp;
	}

	void create_index(int index){
		next_vec.reserve(bucket_size);
		next_vec[index] = node<data_type>(bucket_size);
	}
	
	void assign_data( data_type data){
		finalObj = data;
	}
	
	data_type get_data( ){
		return finalObj;
	}
};
