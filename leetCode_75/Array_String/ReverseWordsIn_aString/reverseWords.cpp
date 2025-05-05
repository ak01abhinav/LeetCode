#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    string reverseWords(string s)
    {
        int size = s.size();
        string rev = "", temp = "";
        for (int i = 0; i < size; i++)
        {
            if (s[i] != ' ')
            {
                temp += s[i];
            }
            else if (temp != "")
            {
                if (rev != "")
                    rev = temp + " " + rev;
                else
                    rev = temp;
                temp = "";
            }
        }
        // to handle the last word
        if (temp != "")
        {
            rev = (rev != "") ? temp + " " + rev : rev = temp;
        }
        return rev;
    }
};

int main()
{
    string s = "the sky is blue";
    string s2 = " the sky   is blue  ";
    Solution sol;
    cout << sol.reverseWords(s) << endl;
    cout << sol.reverseWords(s2) << endl;

    return 0;
}