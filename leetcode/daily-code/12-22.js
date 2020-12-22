/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var zigzagLevelOrder = function(root) {
    if(root == null) return [];
  let isLeft = true;
  let v = [ root ];
  let ans = [];
  while (v.length != 0) {
    let ret = [];
    let count = v.length;
    for(let i = 0; i < count ; i++){
      let node = v.shift();
      if (isLeft) {
        ret.push(node.val);
      } else {
        ret.unshift(node.val);
      }
      if (node.left != null) {
        v.push(node.left);
      }
      if (node.right != null) {
        v.push(node.right);
      }
    }
    ans.push(ret);
    isLeft = !isLeft;
  }
  return ans;
};
