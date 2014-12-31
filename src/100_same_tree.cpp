#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if(p == q){
    return true;
  }
  if(p == nullptr || q == nullptr) {
    return false;
  }
  if(p->val != q->val){
    return false;
  }
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char** argv) {
  TreeNode* t1 = new TreeNode(1);
  t1->left = new TreeNode(2);

  TreeNode* t2 = new TreeNode(1);
  t2->left = new TreeNode(3);
  
  TreeNode* t3 = new TreeNode(1);
  t3->right = new TreeNode(3);

  std::cout << "t1,t1: " << isSameTree(t1,t1) << std::endl;
  std::cout << "t3,t3: " << isSameTree(t3,t3) << std::endl;
  std::cout << "t1,t2: " << isSameTree(t1,t2) << std::endl;
  std::cout << "t2,t3: " << isSameTree(t2,t3) << std::endl;
}
