#include <vector>
#include <functional>

using std::vector;
using std::function;

#pragma once
template <typename key_type, typename data_type>
class Trie{
    public:
        bool insert(vector<key_type> key, function<int(key_type)> get_index){
        	return true;
        }
        data_type retrieve(vector<key_type>){
        	return null;
        }
        Trie(int bucketSize){
        	bucket_size = bucketSize;
        }

    private:
    	int bucket_size;
};

