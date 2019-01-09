#include<iostream>
#include<vector>
#include<algorithm>
#include <sstream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(int intersectVal, ListNode*headA, ListNode *headB,int skipA,int skipB) {
		ListNode *p1 = NULL, *k1 = NULL,*p2= NULL,*k2= NULL;
		while (headA)
		{
			k1 = headA->next;
			headA->next = p1;
			p1 = headA;
			headA = k1;
		}
		while (headB)
		{
			k2 = headB->next;
			headB->next = p2;
			p2 = headB;
			headB = k2;
		}
		ListNode *result = new ListNode(0);
		ListNode *pp1 = new ListNode(0);
		ListNode *pp2 = new ListNode(0);
		pp1->next= p1;
		pp2->next = p2;
		result = pp1;
		while (pp1->next&&pp2->next)
		{
			if (pp1->next->val == pp2->next->val)
			{
				pp1 = pp1->next;
				pp2 = pp2->next;
				continue;
			}
			else
			{
				pp1->next = NULL;
				break;
			}
		}
		ListNode *p3 = NULL, *k3 = NULL;
		ListNode *re = result->next;
		while (re)
		{
			k3 = re->next;
			re->next = p3;
			p3 = re;
			re = k3;
		}
		return p3;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		int intersectVal = stringToInteger(line);
		getline(cin, line);
		ListNode* listA = stringToListNode(line);
		getline(cin, line);
		ListNode* listB = stringToListNode(line);
		getline(cin, line);
		int skipA = stringToInteger(line);
		getline(cin, line);
		int skipB = stringToInteger(line);

		ListNode* ret = Solution().getIntersectionNode(intersectVal, listA, listB, skipA, skipB);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}