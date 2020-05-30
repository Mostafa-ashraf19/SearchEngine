#include "trie.h"
#include<ctime>

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

        //if (temp->child.find(x) == temp->child.end())
        if(temp != nullptr && temp->child.count(x) == 0)
            temp->child[x] = getNewTrieNode();
        temp->child[x]->count++;

        temp->child[x]->v.push_back(file_ID);
        temp = temp->child[x];
    }
    temp = nullptr;
}

bool trie::build_trie(string path)
{
    clock_t starting_build_time = clock();
    for (int i = 0; i < 100001; i++) {
        string name = path+ to_string(i) + ".txt";
        ifstream file(name, ifstream::in);
        for (string word; file >> word;)
            insert(word, i);
    }
    clock_t end_build_time = clock();
    BuildingTime = static_cast<float>(static_cast<float>(end_build_time) - starting_build_time) / CLOCKS_PER_SEC;
    return true;
}

/*


what is your name? (why)
w w
h h
a X y
t

*/
list<int> trie::search(string requied_word_name)
{
        WordSCount=0;
        clock_t startingSearchtime = clock();
        node* temp = root;
        list<int>empty_list{};
        for (int i = 0; i < requied_word_name.length(); i++) {

            temp = temp->child[requied_word_name[i]];
            if (temp == NULL) return empty_list;

        }
        temp->v.unique();
        clock_t EndSearchtime = clock();
        TimeForCurrentSearch = static_cast<float>((static_cast<float>(EndSearchtime) - startingSearchtime))/ CLOCKS_PER_SEC;
        WordSCount = temp->count;
        return temp->v;
}

float trie::TimeBulding() const
{
    return  BuildingTime;
}

float trie::SearchingTime() const
{
    return  TimeForCurrentSearch;
}

int trie::WordCounts() const
{
    return WordSCount;
}

