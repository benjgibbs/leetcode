#include <iostream>
#include <stack>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

long long sum(ListNode * l){
	long long sum = 0;
	long long factor = 1;
	while(l){
		sum += factor * l->val;
		factor *= 10;
		l = l->next;
	}
	return sum;
}


ListNode* fromNum(long long num){
	ListNode* head = nullptr;
	ListNode* n1 = nullptr;
	do{
		ListNode* n2 = new ListNode(num%10);
		num = num / 10;
		if(head == nullptr) {
			head = n2;
			n1 = n2;
		} else {
			n1->next = n2;
			n1 = n2; 
		}
	} while(num > 0); 
	return head;
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	long long s1 = sum(l1);
	long long s2 = sum(l2);	
	
  return fromNum(s1+s2);  
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
/*	
	print(buildList(1,2,3,4));
  print(fromNum(1));
  print(fromNum(1234));
  print(fromNum(10203));
*/
}
