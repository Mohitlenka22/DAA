#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        for (int i = 0; i < nums1.size(); i++)
        {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it != nums2.end())
            {
                nums2.erase(it);
                v.push_back(nums1[i]);
            }
        }
        return v;
    }
};