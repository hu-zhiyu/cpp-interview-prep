#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cstdlib>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    string strAns = "[";
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "[null]";
        // 层序遍历
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* temp = Q.front();
            Q.pop();
            if(temp) strAns += to_string((*temp).val);
            else  strAns += "null";
            strAns.push_back(',');
            if(temp){
                Q.push(temp->left);
                Q.push(temp->right);
            }
        }
        strAns.erase(strAns.find_last_of(','));
        strAns.push_back(']');
        return strAns;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        TreeNode* temp = nullptr;
        vector<TreeNode*> int_data;
        int ptr1 = 1, ptr2, ptr3 = 1, ptr4 = 0;
        while(ptr1 < data.size()){  // 将string转换为指针数组
            if(data.find_first_of(',') != -1) ptr2 = data.find_first_of(',');
            else ptr2 = data.size() - 1;
            if(data.substr(ptr1, ptr2 - ptr1) == "null") int_data.push_back(nullptr);
            else int_data.push_back(new TreeNode(stoi(data.substr(ptr1, ptr2 - ptr1))));
            data.replace(ptr2, 1, " ");
            ptr1 = ptr2 + 1;
        }
        root = int_data[0];
        temp = root;
        while(ptr3 < int_data.size()){  // 从层序遍历建树
            if(temp){
                temp->left = int_data[ptr3];
                temp->right = int_data[ptr3 + 1];
                ptr3 += 2;
            }
            temp = int_data[++ptr4];
        }
        return root;
    }
};
int main(){
    Codec a;
	a.deserialize("[1,2,3,null,null,4,5]");
	return 0;
}