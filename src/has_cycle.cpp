#include <iostream>
#include <unordered_set>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	std::unordered_set<ListNode*> s;
	bool result = false;
	while(head && !result) {
		if(s.count(head)) result = true;
		s.insert(head);
		head = head->next;
	}
	return result;
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
