#include <iostream>
#include <vector>
#include <functional>

using std::function;
using namespace std;

template<typename key_type, typename data_type>
class Trie{

private:

	// Nodes contain a vector containing node pointers and a pointer to an object 
	class node
	{
		// Hierachically contains all of the strata of the trie using a vector containing pointers to the next
		// nodes in the structure
		vector<node*> next_vec;

		// When we find a match, then we will point to an object of type Y defined by the programmer
		data_type* finalObj;

		// Every time a new node is created, we want to initialize its vector of pointers to null
		node(int bucket_size)
		{
			// Initialize the vector of node pointers
			next_vec = new vector<node*>();

			// Fill the newly allocated vector with null node pointers
			for(int i = 0; i < bucket_size; i++)
				next_vec.push_back(NULL);
		}
	};

	typedef class node* node_ptr;
	node_ptr root;
	int bucket_size;

public:

	// Construct the trie by creating a root node
	Trie(int bucket_size)
	{
		this->bucket_size = bucket_size;
		// Try to initialize the root node and check if successful or not
		try
		{
			root = new node(this->bucket_size);

		}
		catch(std::bad_alloc& ba)
		{
			//cout << "Bad memory allocation caught: ";// ba.what() << "\n";
		}
	}

	// Given a search key in the form of a vector, we go through the trie and search for 
	// the object that the the final segment in the key points to. If nothing is found
	// return NULL
	data_type *retrieve(vector<key_type> key, function<int(key_type)> get_index)
	{
		vector<key_type> temp = root->next_vec; // Starting at the root bucket of the trie
		int index;								// The index of the vector which points to the next item
		node_ptr next_node;						// Points to the next node in the trie

		for(auto x: key)
		{
			// Get index of next element
			index = get_index(x);

			// If the node pointer at the index is null then we will have to return NULL because
			// the object that we are searching for is not in the trie
			if(temp[index] == NULL)
				return NULL;

			// Progress through the trie
			temp[index] = next_node;
			temp = next_node->next_vec;
		}

		// Return the object that the last node points to
		return next_node->finalObj;
	}

	bool insert(vector<key_type> key, data_type new_object, function<int(key_type)> get_index)
	{
		vector<key_type> temp = root->next_vec; // Starting at the root bucket of the trie
		int index;								// The index of the vector which points to the next item
		node_ptr next_node;						// Points to the next node in the trie

		//inserting the key
		for(auto x: key){
			// We need to get the index of the temp array by using the lambda expression
			// get_index.
			index = get_index(x);

			// If the index at which we are inserting into is null, then we will create 
			// a new node, otherwise we will just link the node pointer to the next node
			if(temp[index] == NULL)
				next_node = new node(bucket_size);
			
			// Point the node pointer located at temp[index] to the next node and reset
			// the vector pointer to the next_vec of the next node
			temp[index] = next_node;
			temp = next_node->next_vec;
		}

		next_node->finalObj = new_object;
	}
};



int main()
{
	Trie<int, int> trie_harder = new Trie<int, int>(2);
}