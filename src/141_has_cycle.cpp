#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Floyd's cycle finding algorithm
bool hasCycle(ListNode *head) {
	ListNode* slow = head, * fast = head;
	while(slow != nullptr && fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return true;
	}
	return false;
}

int main(int argc, char** argv) {
	auto nocycle = new ListNode(1);
	nocycle->next = new ListNode(2);	
	nocycle->next->next = new ListNode(3);	

	auto cycle = new ListNode(1);
	cycle->next = new ListNode(2);	
	cycle->next->next = new ListNode(3);	
	cycle->next->next->next = cycle;

	std::cout << "Has Cycle: " << hasCycle(nocycle) << std::endl;
	std::cout << "Has Cycle: " << hasCycle(cycle) << std::endl;
}
