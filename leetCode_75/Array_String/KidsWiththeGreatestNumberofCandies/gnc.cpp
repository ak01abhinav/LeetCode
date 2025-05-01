#include <iostream>
#include <algorithm> // for *max_element;
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxVal = *max_element(candies.begin(), candies.end()); // get the maximum val;
        vector<bool> output;
        for (int candy : candies)
        {
            output.push_back(candy + extraCandies >= maxVal);
        }
        return output;
    }
};

int main()
{
    Solution sol;

    // Example test case
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> result = sol.kidsWithCandies(candies, extraCandies);

    cout << "Output: ";
    for (bool val : result)
    {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;
}
