#include <iostream>
#include <cstring>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream ifs;
    ifs.open("morse_code_table", ios::in);
    if (!ifs.is_open()) {
    	cout << "fail to open file" << endl;
    	return 0;
    }
    string str; char ch;
    map<string, char> m;
    while (ifs >> ch >> str) {
    	m.insert({str, ch});
    }
    ifs.close();
    vector<string> paragraph;
    string input;
    while (cin >> input) {
    	paragraph.push_back(input);
    }
    for (int i = 0; i < (int) paragraph.size(); i++) {
		if (paragraph[i] == "/") {
			cout << " ";
		} else if (m.find(paragraph[i]) != m.end()) {
			cout << m[paragraph[i]];
		}
	}	
	return 0;
}	