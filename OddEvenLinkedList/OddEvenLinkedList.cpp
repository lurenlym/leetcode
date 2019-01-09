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
	ListNode* oddEvenList(ListNode* head) {
		if ( head==NULL || head->next == NULL || head->next->next==NULL)
			return head;
		ListNode* odd = head;//��������
		ListNode* even = head->next;
		ListNode* oddres = new ListNode(0);//�������
		ListNode* evenres = new ListNode(0);//ż�����
		oddres->next = odd;
		evenres->next = even;
		ListNode* cur = head;
		ListNode* pre = new ListNode(0);
		int num = 0;
		while (even)
		{
			odd->next = odd->next ? odd->next->next : odd->next;
			even->next = even->next ? even->next->next : even->next;
			odd = odd->next? odd->next: odd;
			even = even->next;
		}
		odd->next = evenres->next;
		return oddres->next;
	}
};

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

		ListNode* ret = Solution().oddEvenList(head);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}