/*
 * Homework # : Trie Dictionary
 * Due: 3/29/19
 * Name: Kirk Vasilas
 * Cite: Justin Trugman, Dave Lehman, joe Puciloski
 * Pledge: I pledge my honor that I have abided by the stevens honor code.
 */

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

class Trie {
private:
	class Node {
	public:
		Node* next[26];
		bool isWord;
		Node(){
			for(int i = 0; i< 26; i++)
				next[i] = nullptr;
		}
		
	};

	Node* root;
public:
	Trie() : root(new Node) {}
	
	void insert(string word){

		Node* p = root;
		for (int i = 0; i < word.length(); i++){

			int index = (int)(word[i]) - 97;
			if(p->next[index] == nullptr)
				p->next[index] = new Node();
			p = p->next[index];

		}
		p->isWord = true;
	}
	
	void contains(string word){

		Node* p = root;
		for (int i = 0; i < word.length(); i++){

			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				cout << "false" << '\n';
				return;
			}
			p = p->next[index];
		}

		if(p->isWord)
			cout << "true" << '\n';
		else
			cout << "false" << '\n';
	}
	
	void containsPrefix(string word){

		Node* p = root;
		for (int i = 0; i < word.length(); i++){
            
			int index = (int)(word[i]) - 97;
			if(p->next[index]==nullptr){
				cout << "false" << '\n';
				return;
			}
			p = p->next[index];
		}

		cout << "true" << '\n';
	}
};


int main() {
	Trie trie;
	ifstream f ("dict.txt");
	string dictionary;
	while(f >> dictionary){
		trie.insert(dictionary);
	}
	ifstream in ("hw5.txt");
	string input;
	while(in >> input){
		trie.contains(input);
	}
}