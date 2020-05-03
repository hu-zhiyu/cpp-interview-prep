// for testing code
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
struct listNode{
    int val;
    listNode* next;
    listNode(int a) : val(a), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr){
            return head; // 递归基
        }
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};

int main(){
    Solution a;
    string input1;
    cin >> input1;
    int len = a.lengthOfLongestSubstring(input1);
    cout << len << endl;
}

