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
        	int index;
        	node<data_type> &temp = root; //reference variable

        	for( auto x: key){
        		index = get_index(x	);

        		if( temp.check_index(index)){
        		//Element already in the trie at this point
        			temp = temp.move_to_index(index);
        		}else{
        		//Element not in the trie
        			temp.create_index(index);
        			temp = temp.move_to_index(index);
        		}
        	}
        	temp.assign_data( data);

        	return true;
        }

        data_type retrieve( vector<key_type> key, function<int(key_type)> get_index ){
        	int index;
        	node<data_type> &temp = root; //reference variable

        	for( auto x: key){
        		index = get_index(x);

        		if( temp.check_index(index)){
        			temp = temp.move_to_index(index);
        		}else{
        			throw invalid_argument("Key not found in trie");
        		}
        	}
        	return temp.get_data();
        }

        Trie(int bucketSize){
        	bucket_size = bucketSize;
        	root =  node<data_type>(bucket_size);
        	// myvec = vector<int>();
        	// myvec();
        }

    private:
    	int bucket_size;
    	node<data_type> root;
};

