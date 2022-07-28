class Solution {
  public:
    vector<int> bottomView(Node *root) {
        map<int,int> mpp;
        vector<int> ans;
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp = q.front().first;
            int y = q.front().second;
            mpp[y] = temp->data;
            if(temp->left)
            q.push({temp->left,y-1});
            if(temp->right)
            q.push({temp->right,y+1});
            q.pop();
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
