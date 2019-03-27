#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
	size_t pos = txt.find( ch );
	size_t initialPos = 0;
	strs.clear();

    // Decompose statement
	while( pos != std::string::npos ) {
		strs.push_back( txt.substr( initialPos, pos - initialPos ) );
		initialPos = pos + 1;

		pos = txt.find( ch, initialPos );
	}

    // Add the last one
	strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

	return strs.size();
}

vector<string> get_line() {
	std::string word;
	std::vector<string> words;
	std::string line;
	std::getline(cin, line);

	split(line, words, '/');

	return words;
}

int main()
{
	unordered_map<char, double> map{
		{'W', ((double) 1   )},
		{'H', ((double) 1/2 )},
		{'Q', ((double) 1/4 )},
		{'E', ((double) 1/8 )},
		{'S', ((double) 1/16)},
		{'T', ((double) 1/32)},
		{'X', ((double) 1/64)},
	};

	while (true)
	{
		vector<string> notes = get_line();

		if (notes[0] == "*")
			break;

		int count = 0;
		for (string compass : notes)
		{
			// cout << compass << endl;
			double duration = 0;
			for (int i = 0; i < compass.size(); i++)
			{
				char n = compass[i];
				duration += map[n];
			}

			if (duration == 1)
				count++;
		}

		cout << count << endl;
	}

	return 0;
}