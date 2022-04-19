/**
   going with inorder because it will give the sorted order, and then i will check if the sorting 
   patterns breaks then i will store the value

   TC = O(n)
 */

public class Solution {

TreeNode prev;
TreeNode first;
TreeNode second;
private void inorder(TreeNode node){
if(node==null) return;

 inorder(node.left);
 
 if(prev!=null && prev.val > node.val)
 {
     if(first==null)
     {
         first = prev;
        // System.out.println("1234");
     } 
     second = node;
 }
 
 prev = node;
 inorder(node.right);
}

public ArrayList recoverTree(TreeNode A) {

  prev = null;
  first = null;
  second = null;
  inorder(A);
 
 ArrayList<Integer> ans = new ArrayList<>();
 ans.add(second.val);
 ans.add(first.val);
 
 return ans;
}
}