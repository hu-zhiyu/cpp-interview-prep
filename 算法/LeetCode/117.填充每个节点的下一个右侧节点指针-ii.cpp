/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS
        if(root == nullptr) return nullptr;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty()){
            Node* temp1;
            int sizeQ = Q.size();
            for(int i = 0; i < sizeQ; i++){
                temp1 = Q.front();
                Q.pop();
                if(i != sizeQ - 1){
                    Node* temp2 = Q.front();
                    temp1->next = temp2;
                }
                if(temp1->left) Q.push(temp1->left);
                if(temp1->right) Q.push(temp1->right);             
            }
        }
        return root;
    }
};
// @lc code=end

