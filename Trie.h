#include <vector>
#include <functional>
#include <stdexcept>

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
        }

    private:
    	int bucket_size;
};

