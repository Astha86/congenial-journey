class Solution {
public:

    void build(TreeNode* root, unordered_map <TreeNode*,TreeNode*>& mp){
        if(root==NULL) return;
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        build(root->left,mp);
        build(root->right,mp);
    }

    TreeNode* first;

    void find(TreeNode* root, int start){
        if(root==NULL) return;
        if(root->val==start){
            first = root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        find(root,start);

        unordered_map <TreeNode*,TreeNode*> parent;
        build(root,parent);

        unordered_set <TreeNode*> s; // stores those node which are infected
        s.insert(first);

        queue<pair<TreeNode*,int>>q; // node with the current level
        q.push({first,0});

        int maxLevel = -1;
        while(q.size()){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int level = p.second;
            maxLevel = max(level,maxLevel);

            if(node->left){
                if(s.find(node->left) == s.end()){
                    q.push({node->left,level+1});
                    s.insert(node->left);
                }
            }

            if(node->right){
                if(s.find(node->right) == s.end()){
                    q.push({node->right,level+1});
                    s.insert(node->right);
                }
            }

            if(parent.find(node) != parent.end()){
                if(s.find(parent[node]) == s.end()){
                    q.push({parent[node],level+1});
                    s.insert(parent[node]);
                }
            }
        }
        return maxLevel;
    }
};
