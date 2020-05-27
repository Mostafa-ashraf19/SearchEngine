#ifndef TRIE_h
#define TRIE_h
#include<string>
#include<list>
#include<fstream>
#include<sstream>
#include <unordered_map> 
using namespace std;
struct node
{

	list<int> v;
	int count = 0;
	unordered_map<char, node*> child;


};

class trie
{
private:
	node* root;
public:
	trie();
	void insert(string word_name, int file_ID);
	bool build_trie(string path);
	int return_the_count_of_word(string requied_word_name);
	list<int> search(string requied_word_name);
};
#endif // !TRIE_h



