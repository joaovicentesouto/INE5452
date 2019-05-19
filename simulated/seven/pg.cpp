#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

using namespace std;

size_t split(const string &txt, vector<string> &strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	// Decompose statement
	while (pos != string::npos)
	{
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	// Add the last one
	strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}

vector<string> get_line()
{
	string word;
	vector<string> words;
	string line;
	getline(cin, line);

	split(line, words, ' ');

	return words;
}

int main()
{
	vector<string> words = get_line();

	int count = 0;
	int total = words.size();
	for (auto & w : words)
	{
		int i = 0;
		if (w.size() >= 4)
			if (w[0] == w[2] && w[1] == w[3])
				i = 2;
		for (; i < w.size(); i++)
			cout << w[i];
		
		if (++count < total)
			cout << " ";
	}

	cout << endl;

	return (1);
}