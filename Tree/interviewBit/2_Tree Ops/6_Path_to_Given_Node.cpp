bool inorder(vector<int>&ans, TreeNode* root, int x){

    if(!root){
        return false;
    }
    ans.push_back(root->val);

    // we will store the val before every recursive call so to have the track record

    if(root->val == x){
        return true;
    }

    if(inorder(ans,root->left,x) || inorder(ans,root->right,x)){
        return true;
    }

    // if none of the above recursive call true the val is not below the current node hence we pop();
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* root, int B) {
    
    vector<int>ans;
    inorder(ans,root,B);
    return ans;
}