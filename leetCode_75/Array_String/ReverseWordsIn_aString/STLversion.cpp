#include <iostream>
#include <string>
#include <algorithm> // for reverse
#include <vector>
#include <sstream> // for "istringstream" -> reads only words from string

using namespace std;

class Solution
{
public:
    string ReverseWords(string s)
    {
        istringstream iss(s);
        vector<string> words; // vector of strings, which will strore all words of string s ignoring extra spaces.
        string word;          // will read each word from s via iss tool.

        while (iss >> word)
        {
            words.push_back(word); // strores all words(only words, no spaces) of s, via iss and variable word.
        }

        reverse(words.begin(), words.end()); // this will reverse all words.

        string reversed; // this will stores the reversed string;

        for (int i = 0; i < words.size(); i++)
        {
            reversed += words[i];
            if (i != words.size() - 1)
            {
                reversed += " "; // this will prevent adding extra space at the end;
            }
        }
        return reversed;
    }
};

int main()
{
    Solution sol;
    string s = "the sky is blue";
    string s2 = "   the   sky is blue "; // extra spaces added;
    cout << sol.ReverseWords(s) << endl;
    cout << sol.ReverseWords(s2) << endl;

    return 0;
}