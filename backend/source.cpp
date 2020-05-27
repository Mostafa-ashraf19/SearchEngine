#include<iostream>
#include <filesystem>
#include<fstream>
#include<sstream>
#include"trie.h"
using namespace std;
namespace FS = std::filesystem;
void main() {
	trie mytrie;
	/*for (int i = 0; i < 100001; i++) {
		string name = "E:/3th computer & systems(drive &channel)/projects/data structure/questions/" + to_string(i) + ".txt";
		ifstream file(name, ifstream::in);
		for (string word; file >> word; )
			mytrie.insert(word, i);
	}*/
	cout << "start" << endl;
	mytrie.build_trie("E:/3th computer & systems(drive &channel)/projects/data structure/questions/");
	cout << "finished" << endl;
	string n;
	while (1)
	{
		cout << "enter the word : "<<endl;
		cin >> n;
		auto result = mytrie.search(n);
		if (!result.empty()) {
			for (auto i : result) {
				cout << i << endl;
			}
		}
		else
			cout << "not found" << endl;
	}

}