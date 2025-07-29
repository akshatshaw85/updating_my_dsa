class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root = build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inmap);
        return root;
    }
    TreeNode*  build(vector<int> &inorder,int ins,int inend,vector<int>& postorder,int pres,int preend,map<int,int>& inmap)
{
    if(pres>preend || ins>inend)return NULL;
    TreeNode*root= new TreeNode(postorder[preend]);
  int inroot = inmap[postorder[preend]];
int leftTreeSize = inroot - ins;

root->left = build(inorder, ins, inroot - 1,
                   postorder, pres, pres + leftTreeSize - 1, inmap);

root->right = build(inorder, inroot + 1, inend,
                    postorder, pres + leftTreeSize, preend - 1, inmap);

return root;
}
};
