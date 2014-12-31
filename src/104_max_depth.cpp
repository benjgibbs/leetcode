#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *root) {
  if(!root) return 0;
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);
  return 1 + ((left > right) ? left : right); 
}

int main(int argc, char** argv) {
  TreeNode * t = new TreeNode(1);
  t->left = new TreeNode(2);
  t->left->left = new TreeNode(3); 
  
  std::cout << "Max depth: " << maxDepth(t) << std::endl;
}
