#include "Trie.h"
// #include "node.h"
#include <iostream>

#include <vector>
#include <stdexcept>
using std::vector;
using std::cout;
using std::invalid_argument;

///Test insert and retrieval of character keys and integer data
void test_char_int( ){

	Trie<char,int> test_trie(26);
	char a;
	vector<char> my_string;

	for(a = 'a'; a <= 'q'; a++){
		//randomizing keys in the trie
		//inserting random strings
		my_string = {a, a + 1, a + 2, a + 3} ;
		test_trie.insert(my_string, a, []( char a ){ return 25 - 'z' + a ; });
		
		my_string = {a, a - 2, a + 1, a + 2, a + 3, a + 4} ;
		test_trie.insert(my_string, a + 3, []( char a ){ return 25 - 'z' + a ; });
	}

	try{
		int x;
		if( (x = test_trie.retrieve(my_string, 
			[]( char a ){ return 25 - 'z' + a ; })) == a + 3 ){
			cout << "Test 1 : character key, int data : PASS\n" ;
		}else{
			cout << "Test 1 : character key, int data, wrong value : FAIL\n" ;
			cout << x << "\n";
		}
	}catch(const invalid_argument& e){
		cout << "Test 1 : character key, int data : FAIL \n" ;
	}
}

///Test insert and retrieval of integer keys and character data
void test_int_char(){
	Trie<int, char> test_trie(30);
	int a;
	vector<int> my_string;

	for(a = 1; a <= 24; a++){
		//randomizing keys in the trie
		//inserting random strings
		my_string = {a, a + 1, a + 2, a + 3} ;
		test_trie.insert(my_string, 'a', []( int a ){ return a; });
		
		my_string = {a, a , a + 1, a + 2, a + 3, a + 4} ;
		test_trie.insert(my_string, 'z', []( int a ){ return a; });
	}

	try{
		if( test_trie.retrieve(my_string, []( int a ){ return a; }) == 'z' ){
			cout << "Test 2 : int key, char data : PASS\n" ;
		}else{
			cout << "Test 2 : int key, char data, wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test 2 : int key, char data : FAIL \n" ;
	}

}

void test_two_inserts(){
	Trie<char,int> test_trie(26);

	vector<char> my_string = {'a', 'b', 'c'};
	test_trie.insert(my_string, 11, []( char a ){ return 25 - 'z' + a  ; });

	my_string = {'a', 'b', 'd'};
	test_trie.insert(my_string,  11, []( char a ){ return  25 - 'z' + a  ; });

	try{
		if( test_trie.retrieve(my_string, []( char a ){ return 25 - 'z' + a; }) == 11 ){
			cout << "Test 3 : char key, int data : PASS\n" ;
		}else{
			cout << "Test 3 : char key, int data, wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test 3 : char key, int data : FAIL \n" ;
	}
}

void test_one_char()
{
	Trie<char,int> test_trie(26);

	vector<char> my_string = {'a'};
	test_trie.insert(my_string, 11, []( char a ){ return 25 - 'z' + a  ; });

	try{
		if( test_trie.retrieve(my_string, []( char a ){ return 25 - 'z' + a; }) == 11 ){
			cout << "Test 4, just one character : PASS\n" ;
		}else{
			cout << "Test 4, just one character, wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test 4, just one character : FAIL \n" ;
	}

}
int main(){
	test_char_int();
	test_int_char();
	test_two_inserts();
	test_one_char();
}


