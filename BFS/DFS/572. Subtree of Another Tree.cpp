/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // helper func for isSubtree()
    bool isSame(TreeNode *t, TreeNode* s){
        // if both nodes are null then they are same so return true
        if(!t && !s) return true;
        // if either one of them is not null then they arent same
        if(!t || !s) return false;
        
        // here they both are not null so we check their values
        // if the vals arent same then we return false
        if(t->val != s->val) return false;
        
        // here the vals are same so we call isSame to check for both
        // the subtrees
        else return isSame(t->left,s->left) && isSame(t->right,s->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if subRoot is null it can be subtree of root so we dont check it
        // instead if the main tree is null there cannot be a subtree
        if(!root) return false;
        
        //we check for both the nodes, if same then return true 
        if(isSame(root,subRoot))
            return true;
        //both nodes are not same but there is still a possibilty
        //that a subtree may be present in the left or right subtree of the
        // main tree
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};