#include<iostream>
#include<vector>
#include<algorithm>
#include <sstream>
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		while (l1)
		{
			s1.push(l1->val);
			l1 = l1->next;
		}
		while (l2)
		{
			s2.push(l2->val);
			l2 = l2->next;
		}
		int sum = 0;
		ListNode *result = new ListNode(0);
		while (!s1.empty() || !s2.empty())
		{
			if (!s1.empty())
			{
				sum += s1.top();
				s1.pop();
			}
			if (!s2.empty())
			{
				sum += s2.top();
				s2.pop();
			}

			int value = sum % 10;
			result->val = value;
			ListNode *temp = new ListNode(sum / 10);
			temp->next = result;
			result = temp;
			sum = sum / 10;
		}
		return result->val == 0 ? result->next : result;
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
		ListNode* l1 = stringToListNode(line);
		getline(cin, line);
		ListNode* l2 = stringToListNode(line);

		ListNode* ret = Solution().addTwoNumbers(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}