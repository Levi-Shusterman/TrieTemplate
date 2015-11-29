
#include "Trie.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using std::vector;
using std::cout;
using std::invalid_argument;

///Test insert and retrieval of character keys and integer data
void test_char_int( ){

	Trie<char,int> test_trie(26);
	vector<char> my_string {'a', 'l','k','s' } ;
	test_trie.insert(my_string, 13, [&]( char a ){ return 1; });
	
	try{
		if( test_trie.retrieve(my_string) == 13 ){
			cout << "Test 1 : character key, int data : PASS\n" ;
		}else{
			cout << "Test 1 : character key, int data, wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test 1 : character key, int data : FAIL \n" ;
	}
}

int main(){
	test_char_int();

}