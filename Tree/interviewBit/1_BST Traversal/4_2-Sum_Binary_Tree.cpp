
//we will take 2 stack to store the next and before element like BST iterator question 
/*
  next = root left right (ascending)
  before = right root left (descending)

  TC = O(n)
  SC = 2 * O(h) (2 stacks)
*/

int Solution::t2Sum(TreeNode* root, int data) {

    stack<TreeNode*>lside;
    stack<TreeNode*>rside;


    // stored inital value of next
    TreeNode* curr = root;
    while(curr){
        lside.push(curr);
        curr = curr->left;
    }

    // stored inital values of before
    curr = root;
    while(curr){
        rside.push(curr);
        curr = curr->right;
    }

    while(!lside.empty() && !rside.empty()){

        TreeNode* leftNode = lside.top();
        TreeNode* rightNode = rside.top();
        
        if(leftNode->val + rightNode->val == data && leftNode!= rightNode){
            return 1;
        }

        // if sum  greater then proceed with before stack
        else if(leftNode->val + rightNode->val > data){
            rside.pop();
            rightNode = rightNode->left;
            while(rightNode){
                rside.push(rightNode);
                rightNode = rightNode->right;
            }
        }
        else{
            lside.pop();
            leftNode = leftNode->right;
            while(leftNode){
                lside.push(leftNode);
                leftNode = leftNode->left;
            }
        }
    }
    return 0;
}