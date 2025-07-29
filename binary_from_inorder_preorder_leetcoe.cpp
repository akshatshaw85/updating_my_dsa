class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root = build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode* build(vector<int>& preorder,int pres,int preend,vector<int>& inorder,int ins,int inend,map<int,int>& inmap){
        if(pres>preend || ins>inend)return NULL;
        TreeNode*root = new TreeNode(preorder[pres]);
        int rn = inmap[preorder[pres]];
        int size = inmap[preorder[pres]]-ins;
        root-> left =  build(preorder,pres+1,pres+size,inorder,ins,rn-1,inmap);
        root->right =  build(preorder,pres+size+1,preend,inorder,rn+1,inend,inmap);
        return root;
    }
};
