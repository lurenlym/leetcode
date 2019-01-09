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
	int numComponents(ListNode* head, vector<int>& G) {
		unordered_map<int, int> m;
		for (int i = 1; i <= G.size(); ++i) {
			m[G[i-1]] = i;
		}
		bool flag = false;
		int result = 0;
		while (head)
		{
			if (m.count(head->val))
			{
				if (flag)
				{
					head = head->next;
					continue;
				}
				else
				{
					flag = true;
					result++;
				}
			}
			else
			{
				flag = false;
			}
			head = head->next;
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

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		vector<int> G = stringToIntegerVector(line);

		int ret = Solution().numComponents(head, G);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}