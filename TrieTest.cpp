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
			[]( char a ){ return 25 - 'z' + a ; })) == 'q' + 3 ){
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

void test_long_key_short_key(){
	Trie<int, char> test_trie(30);
	int a;

	vector<int> long_string = {1, 2, 3, 4, 5};
	test_trie.insert(long_string , 10,[]( int a ){ return a; });

	vector<int>short_string = {1, 2, 3 };
	test_trie.insert(short_string, 9,[]( int a ){ return a; });

	cout << "\n";

	try{
		if( test_trie.retrieve(long_string, []( int a ){ return a; }) == 10 ){
			cout << "Test long key, short key. Long key value : PASS\n" ;
		}else{
			cout << "Test long key, short key. Long key value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test long key, short key. Long key value : FAIL \n" ;
	}

	try{
		if( test_trie.retrieve(short_string, []( int a ){ return a; }) == 9 ){
			cout << "Test long key, short key. Short key value : PASS\n" ;
		}else{
			cout << "Test long key, short key. Short key value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test long key, short key. Short key value : FAIL \n" ;
	}


	vector<int>branch_string = {1, 2, 3, 7, 8 };
	test_trie.insert(branch_string, 14,[]( int a ){ return a; });

	try{
		if( test_trie.retrieve(branch_string, []( int a ){ return a; }) == 14 ){
			cout << "Test long key, short key. branch_string value : PASS\n" ;
		}else{
			cout << "Test long key, short key. branch_string value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test long key, short key. branch_string value : FAIL \n" ;
	}
}


void test_short_key_long_key(){
	Trie<int, char> test_trie(30);
	int a;

	vector<int>short_string = {1, 2, 3 };
	test_trie.insert(short_string, 9,[]( int a ){ return a; });

	vector<int> long_string = {1, 2, 3, 4, 5};
	test_trie.insert(long_string , 10,[]( int a ){ return a; });

	cout << "\n";

	try{
		if( test_trie.retrieve(long_string, []( int a ){ return a; }) == 10 ){
			cout << "Test short key, long key. Long key value : PASS\n" ;
		}else{
			cout << "Test short key, long key. Long key value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test short key, long key. Long key value : FAIL \n" ;
	}

	try{
		if( test_trie.retrieve(short_string, []( int a ){ return a; }) == 9 ){
			cout << "Test short key, long key. Short key value : PASS\n" ;
		}else{
			cout << "Test short key, long key. Short key value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test short key, long key. Short key value : FAIL \n" ;
	}


	vector<int>branch_string = {1, 2, 3, 7, 8 };
	test_trie.insert(branch_string, 14,[]( int a ){ return a; });

	try{
		if( test_trie.retrieve(branch_string, []( int a ){ return a; }) == 14 ){
			cout << "Test short key, long key. branch_string value : PASS\n" ;
		}else{
			cout << "Test short key, long key. branch_string value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << "Test short key, long key. branch_string value : FAIL \n" ;
	}
}

void test_similiar_key_at_end( ){
	Trie<int, char> test_trie(30);
	int a;

	vector<int> first_string = {1, 2, 3, 4, 5 };
	test_trie.insert(first_string, 9,[]( int a ){ return a; });

	vector<int> second_string = {1, 2, 3, 4, 6};
	test_trie.insert(second_string , 10,[]( int a ){ return a; });

	cout << "\n";

	try{
		if( test_trie.retrieve(second_string, []( int a ){ return a; }) == 10 ){
			cout << " test_similiar_key_at_end. Second_string value : PASS\n" ;
		}else{
			cout << " test_similiar_key_at_end. Second_string value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << " test_similiar_key_at_end. Second_string value : FAIL \n" ;
	}

	try{
		if( test_trie.retrieve(first_string, []( int a ){ return a; }) == 9 ){
			cout << " test_similiar_key_at_end. First_string value : PASS\n" ;
		}else{
			cout << " test_similiar_key_at_end. First_string value. Wrong value : FAIL\n" ;
		}
	}catch(const invalid_argument& e){
		cout << " test_similiar_key_at_end. First_string value : FAIL \n" ;
	}


}

int main(){
	test_char_int();
	test_int_char();
	test_two_inserts();
	test_one_char();

	test_similiar_key_at_end();
	test_short_key_long_key();
	test_long_key_short_key();
}


