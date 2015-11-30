#include <vector>
#include <functional>
#include <stdexcept>
#include "node.h"

using std::vector;
using std::function;
using std::invalid_argument;

#pragma once
template <typename key_type, typename data_type>
class Trie{
    public:
        bool insert(vector<key_type> key, data_type data, function<int(key_type)> get_index){
        	return true;
        }
        data_type retrieve(vector<key_type>){
        	throw invalid_argument("Key not found in trie");
        	data_type ref;
        	return ref;
        }
        Trie(int bucketSize){
        	bucket_size = bucketSize;
        	root =  node<data_type>(bucket_size);
        	// myvec = vector<int>();
        	// myvec();
        	myvec[1000] = bucket_size;
        }

    private:
    	int bucket_size;
    	node<data_type> root;
    	vector<int> myvec;
};

