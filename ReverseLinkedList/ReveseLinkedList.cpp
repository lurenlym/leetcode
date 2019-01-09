#include<iostream>
#include<vector>
#include <unordered_map>
#include<math.h>
#include<algorithm>
#include <sstream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *p = NULL, *k = NULL;
		while (head)
		{
			k = head->next;
			head->next = p;
			p = head;
			head = k;
		}
		return p;
	}
};
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		ListNode *p = head, *k = head; ListNode *a = new ListNode(0);
//		a->next = head;
//		while (k->next)
//		{
//			ListNode *n = k->next;
//			k->next = n->next;
//			n->next = a->next;
//			a->next = n;
//		}
//		return a->next;
//	}
//};

/*ตÝน้*/
//class Solution {
//public :
//	ListNode *reverseList(ListNode *head) {
//		if (head == NULL || head->next == NULL) 
//			return head;
//		ListNode *p = reverseList(head->next);
//		head->next->next = head;
//		head->next = NULL;
//		return p;
//	}
//};

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
		ListNode* head = stringToListNode(line);

		ListNode* ret = Solution().reverseList(head);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}