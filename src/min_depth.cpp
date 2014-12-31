#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode *root) {
	if(!root) return 0;
	std::set<TreeNode*> v;
	std::queue<TreeNode*> q;
	std::map<TreeNode*, int> d;
	
	v.insert(root);
	q.push(root);
	d[root] =  1;

	while(!q.empty()){
		TreeNode* t = q.front();
		q.pop();

		if(!t->left && !t->right) {
			return d[t];
		}

		if(t->left && v.count(t->left) == 0) {
			v.insert(t->left);
			q.push(t->left);
			d[t->left] = d[t] + 1;
		}

		if(t->right && v.count(t->right) == 0) {
			v.insert(t->right);
			q.push(t->right);
			d[t->right] = d[t] + 1;
		}
	}
	throw std::runtime_error("no leaf found");
}

int main(int argc, char** argv) {
  std::cout << "Min depth: " << minDepth(nullptr) << std::endl;
  
	TreeNode * t = new TreeNode(1);
  t->left = new TreeNode(2);
  t->left->left = new TreeNode(3); 
  std::cout << "Min depth: " << minDepth(t) << std::endl;
	
	TreeNode * t2 = new TreeNode(1);
  t2->left = new TreeNode(2);
  t2->right = new TreeNode(2);
  t2->right->right = new TreeNode(3); 
  std::cout << "Min depth: " << minDepth(t2) << std::endl;
  
	TreeNode * t3 = new TreeNode(1);
  t3->left = new TreeNode(2);
  t3->left->left = new TreeNode(2);
  t3->left->right = new TreeNode(2);
  t3->left->left->left = new TreeNode(2);
  t3->right = new TreeNode(2);
  t3->right->right = new TreeNode(3); 
  t3->right->left = new TreeNode(3); 
  t3->right->right->right = new TreeNode(3); 
  t3->right->right->right->right = new TreeNode(3); 
  std::cout << "Min depth: " << minDepth(t3) << std::endl;
}
