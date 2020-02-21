// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#include <math.h>
#include <iostream>

class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        return intToListNode(listNodeToInt(l1) + listNodeToInt(l2));
    }
    
    long long listNodeToInt(ListNode* listNode)
    {
        long long sum = 0;
        int index = 0;
        ListNode * currentPointer = listNode;
        
        while (currentPointer)
        {
            sum += (long long)pow(10, index) * currentPointer->val;
            index++;
            currentPointer = currentPointer->next;
        }
        
        return sum;
    }
    
    ListNode* intToListNode(long long integer)
    {
        int index = 0;
        ListNode* head = new ListNode(0);
        ListNode* listNode = head;

        // get the length of ListNode
        while (integer / pow(10, index) >= 1)
            index++;

        for (int i = 0; i < index; i++)
        {
            long long val = integer % (long long)pow(10, i+1) / (long long)pow(10, i);
            // std::cout << "Integer: " << integer << " i: " << i << " val:" << val << endl;
            listNode->next = new ListNode(val);
            listNode = listNode->next;
        }
        
        if (head->next == NULL)
            return head;
        return head->next;
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
    for(int item : list) {
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