#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> flowerbed, int n)
    {
        int size = flowerbed.size();
        int c = 0;
        for (int i = 0; i < size; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool prev = (i == 0) || flowerbed[i - 1] == 0;
                bool next = (i == size - 1) || flowerbed[i + 1] == 0;
                if (prev && next)
                {
                    flowerbed[i] = 1; // place the flower;
                    c++;
                    if (c >= n)
                        return true;
                    i++; // skip the next place;
                }
            }
        }
        return c >= n;
    }
};

int main()
{
    Solution sol;

    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool placed = sol.canPlaceFlowers(flowerbed, n);
    placed ? cout << "All flowers Placed\n" : cout << "All flowers not placed.\n";
    return 0;
}