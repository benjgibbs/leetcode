#include <iostream>
#include <stack>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode* head = nullptr;
  ListNode* cur = nullptr;
  int carry = 0;
  while(l1 || l2 || carry > 0) {
    int l1val = 0;
    int l2val = 0;
    if(l1) { 
      l1val = l1->val;
      l1 = l1->next;
    }
    if(l2) {
      l2val = l2->val;
      l2 = l2->next;
    }
    int val = l1val + l2val + carry;
    carry = val / 10;
    ListNode* tmp = new ListNode(val % 10);
     
    if(head) {
      cur->next = tmp;
      cur = tmp;
    } else {
      head = tmp;
      cur = tmp;
    }
    
  }
	
  return head;  
}

ListNode* buildList(){
  return nullptr;
}


template<typename... Types>
ListNode* buildList(long long first, Types... items){
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
	print(addTwoNumbers(buildList(2,4,3),buildList(5,6,4)));
	print(addTwoNumbers(buildList(0),buildList(0)));
	print(addTwoNumbers(buildList(9),buildList(1,9,9,9,9,9,9,9,9,9)));
	print(addTwoNumbers(buildList(9),buildList(1,9,9,9,9,9,9,9,9,9)));
/*	
	print(buildList(1,2,3,4));
  print(fromNum(1));
  print(fromNum(1234));
  print(fromNum(10203));
*/
}
