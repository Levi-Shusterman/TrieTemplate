#include <vector>
#include <functional>
#include <stdexcept>
#include "node.h"
#include <iostream>

using std::vector;
using std::function;
using std::invalid_argument;
using std::out_of_range;
using std::cout;

#pragma once
template <typename key_type, typename data_type>
class Trie{
    public:
        bool insert(vector<key_type> key, data_type data, function<int(key_type)> get_index){
        	int index;
        	node<data_type> *temp = root; //reference variable

        	for( auto x: key){
        		index = get_index(x	);

        		if( index > bucket_size - 1){
        			throw out_of_range("Index greater than bucket_size from lambda, in");  
        		}

        		if( temp->check_index(index)){
        		//Element already in the trie at this point
        			// temp = temp->move_to_index(index);
        		}else{
        		//Element not in the trie
        			temp->create_index(index);
        		}
				temp = temp->move_to_index(index);
        	}
        	temp->assign_data( data);

        	return true;
        }

        data_type retrieve( vector<key_type> key, function<int(key_type)> get_index ){
        	int index;
        	node<data_type> *temp = root; //reference variable
        	int y = 0;

        	for( auto x: key){
        		y++;
        		index = get_index(x);

        		if( temp->check_index(index)){
        			temp = temp->move_to_index(index);
        		}else{
        			 cout << y << " times in retrieve for loop\n" ;

        			throw invalid_argument("Key not found in trie");
        		}
        	}
        	data_type r = temp->get_data();
        	return r;
        }

        Trie(int bucketSize){
        	bucket_size = bucketSize;
        	root = new node<data_type>(bucket_size);
        	// myvec = vector<int>();
        	// myvec();
        }

    private:
    	int bucket_size;
    	node<data_type> *root;
};

