#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
  return nullptr;  
}

ListNode* buildList(){
  return nullptr;
}

template<typename... Types>
ListNode* buildList(int first, Types... items){
  ListNode* head = new ListNode(first);
  head->next = buildList(items...); 
  return head;
}

void print(ListNode* l){
  std::cout << "List: ";
  while(l != nullptr){
    std::cout << l->val;
    l = l->next;
    if(l != nullptr)
      std::cout << " -> ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv){
  print(buildList(1,2,3,4));
   
}
