#include<iostream>
#include<vector>
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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector <ListNode*> result;
		ListNode *res = root;
		int len = 0;
		while (root)
		{
			root = root->next;
			len++;
		}
		int part = len / k;
		int addpart = len%k;
		if (!part)
		{
			int tt = (len);
			while (tt--)
			{
				ListNode *temp = new ListNode(res->val);
				res = res->next;
				result.push_back(temp);
			}
			tt = (k - len);
			while (tt--)
			{
				ListNode *temp = nullptr;
				result.push_back(temp);
			}
			return result;
		}
		while (k--)
		{
			int tempk = 0;
			if (addpart)
			{
				tempk = part+1;
			}
			else
			{
				tempk = part;
			}
			ListNode *resptemp = new ListNode(0);
			resptemp->next = res;
			ListNode *resp = res;
			while (tempk--)
			{
				res = res->next;
				resptemp = resptemp->next;
			}
			resptemp->next = NULL;
			result.push_back(resp);
			if (addpart)
			{
				addpart--;
			}
		}
		return result;
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

int stringToInteger(string input) {
	return stoi(input);
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int pos = stringToInteger(line);

		vector<ListNode*> ret = Solution().splitListToParts(head, pos);

		//string out = boolToString(ret);
		//cout << out << endl;
	}
	return 0;
}
