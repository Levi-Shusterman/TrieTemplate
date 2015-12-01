# TrieTemplate

Project: Templated Trie data structure, where user can specify a key type and data type associated with each key in the tire.
Purpose: Simple Trie data structure that a user can link into their project.

System: Ubuntu flavor of Linux. Source code can easily be modified to run on a different system.
Compiler: g++, C++ 2011

API: constructor(), insert(), retrieve()
  todo: Add an update() method to modify an existing key's data in the trie

Instructions: Upload node.h and trie.h into a directory. Compile with g++ -std=c++11 *.cpp.
  TrieTest.cpp contains a suite of tests. Add more tests with different data types( can be a class or struct too) to suit your needs.

Perspective: In the future, I hope to have enough time to create a large namespace of templated data structures that users can easily 
  link into a project with different data types and classes. Computer Science university faculties do a terrible job introducing
  generic programming, teaching reusabality, and don't emphasize unit testing. 
