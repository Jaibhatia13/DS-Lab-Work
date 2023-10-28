#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode *buildTreeFromPreorder(vector<int> &preorder, int &index, int maxValue)
{
    if (index >= preorder.size() || preorder[index] >= maxValue)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = buildTreeFromPreorder(preorder, index, root->val);
    root->right = buildTreeFromPreorder(preorder, index, maxValue);
    return root;
}

void postorderTraversal(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main()
{
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    int n = 0;
    int maxValue = INT_MAX;

    TreeNode *root = buildTreeFromPreorder(preorder, n, maxValue);

    postorderTraversal(root);
    cout << endl;

    return 0;
}
