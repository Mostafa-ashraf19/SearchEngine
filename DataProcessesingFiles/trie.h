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
    float TimeForCurrentSearch{0.0};
    float BuildingTime{0.0};
    int WordSCount{0};
public:
    trie();
    void insert(string word_name, int file_ID);
    bool build_trie(string path);
    list<int> search(string requied_word_name);
    //bool search_bool(string requied_word_name);
    float TimeBulding() const;
    float SearchingTime() const;
    int WordCounts() const;
};
#endif // !TRIE_h



