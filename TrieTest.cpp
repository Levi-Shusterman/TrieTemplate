
#include "Trie.h"
#include <iostream>

#include <vector>
using std::vector;
using std::cout;

///Test insert and retrieval of character keys and integer data
void test_char_int( ){

	Trie<char,int> test_trie(26);
	test_trie.insert("alksdfjafds");
	
	if( test_trie.retrieve("alksdfjafds") ){
		cout << "Test 1 : character key, int data : PASS" ;
	}else{
		cout << "Test 1 : character key, int data : FAIL" ;
	}
}

int main(){
	test_char_int();

}