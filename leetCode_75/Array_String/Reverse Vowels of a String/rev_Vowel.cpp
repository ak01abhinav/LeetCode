#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowel(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isVowel(s[i])) // when any vowel will encountered from start it stop there and check for other end vowel further...;
            {
                i++;
            }
            while (i < j && !isVowel(s[j])) // when any vowel found from the end it will stop and get swapped in 29th line...;
            {
                j--;
            }
            swap(s[i], s[j]); // swap and move further by line 30 and 31;
            i++;
            j--;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    string inp;

    cout << "Enter the string: ";
    getline(cin, inp);

    string res = sol.reverseVowel(inp);
    cout << "output is: " << res << endl;
    return 0;
}