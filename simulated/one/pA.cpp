#include <iostream>
#include <cmath>
#include <iomanip>
#include <ios>
#include <string>
#include <vector>

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

  split(line, words, ' ');

  return words;
}

int main()
{
  while (true)
  {
    vector<string> words = get_line();

    if (words[0] == "*")
      break;

      bool tau = true;
    char init_char = 0;
    for (auto word : words)
    {
      if (init_char == 0)
        init_char = tolower(word[0]);

      tau &= (init_char == tolower(word[0]));
    }

    if (tau)
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}
