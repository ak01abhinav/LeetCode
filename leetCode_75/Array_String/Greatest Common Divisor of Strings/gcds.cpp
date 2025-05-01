#include <iostream>
#include <string>
#include <numeric> // for std::gcd
using namespace std;

class Solution
{
public:
    // ✅ Checks if the string 'str' can be formed by repeating 'pattern'
    bool isDivisible(string str, string pattern)
    {
        int count = str.length() / pattern.length(); // How many times 'pattern' should repeat
        string temp = "";
        for (int i = 0; i < count; ++i)
        {
            temp += pattern;
        }
        return temp == str; // Return true if the repeated pattern forms the original string
    }

    // ✅ Finds the largest string that divides both str1 and str2
    string commonDivisor(string str1, string str2)
    {
        // Case when both strings are equal — any of them is the answer
        if (str1 == str2)
            return str1;

        // If str1 + str2 is not equal to str2 + str1,
        // then they don't share a common base string
        if (str1 + str2 != str2 + str1)
            return "";

        // Use the GCD of string lengths to find the possible common pattern length
        int gcdLen = gcd(str1.length(), str2.length());

        // Take the first 'gcdLen' characters from str1 as the pattern
        string pattern = str1.substr(0, gcdLen);

        // Check if this pattern can form both strings by repetition
        if (isDivisible(str1, pattern) && isDivisible(str2, pattern))
        {
            return pattern;
        }

        // If not, return empty string
        return "";
    }
};

int main()
{
    Solution s;
    string str1 = "", str2 = "";

    cout << "Enter two strings: ";
    cin >> str1 >> str2;

    cout << "GCD of strings: " << s.commonDivisor(str1, str2) << endl;

    return 0;
}
