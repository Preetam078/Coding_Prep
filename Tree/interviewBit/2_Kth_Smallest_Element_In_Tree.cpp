//https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

// TC = O(n)

void inorder(TreeNode*&root, int &k ,int &ans){
            
            if(root == NULL)
                    return ;
            inorder(root->left,k, ans);

            //go till k exist and update the ans variable.
            if(!--k)
                    ans = root->val;
            inorder(root->right, k ,ans);
    }

int Solution::kthsmallest(TreeNode* root, int k) {

    int ans; 
    inorder(root, k, ans);
    return ans;
}