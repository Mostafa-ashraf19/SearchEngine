#include "trie.h"
node* getNewTrieNode()
{
	node* new_node = new node;
	return new_node;
}
trie::trie()
{
	root = nullptr;
}

void trie::insert(string word_name, int file_ID)
{
	if (root == nullptr)
		root = getNewTrieNode();
	node* temp = root;
	for (int i = 0; i < word_name.length(); i++) {
		char x = word_name[i];

		if (temp->child.find(x) == temp->child.end())
			temp->child[x] = getNewTrieNode();
		temp->child[x]->count++;
		temp->child[x]->v.push_back(file_ID);
		temp = temp->child[x];
	}
}

bool trie::build_trie(string path)
{
	for (int i = 0; i < 100001; i++) {
		string name = path+ to_string(i) + ".txt";
		ifstream file(name, ifstream::in);
		for (string word; file >> word;)
			insert(word, i);
	}
	return true;
}

int trie::return_the_count_of_word(string requied_word_name)
{
	node* temp = root;
	for (int i = 0; i < requied_word_name.length(); i++) {
		temp = temp->child[requied_word_name[i]];
	}
	return temp->count;
}

list<int> trie::search(string requied_word_name)
{
	node* temp = root;
	for (int i = 0; i < requied_word_name.length(); i++) {
		temp = temp->child[requied_word_name[i]];
	}
	temp->v.unique();
	return temp->v;
}
