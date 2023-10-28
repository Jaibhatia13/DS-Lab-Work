#include<bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int leftmax[n];
    int rightmax[n];

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            leftmax[i] = height[i];
        }
        else
            leftmax[i] = max(leftmax[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            rightmax[i] = height[i];
        }
        else
            rightmax[i] = max(rightmax[i + 1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water = water + min(rightmax[i], leftmax[i]) - height[i];
    }
    return water;
}
int main()
{
    vector<int>height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << endl;
}
