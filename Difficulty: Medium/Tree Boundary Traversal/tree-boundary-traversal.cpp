


class Solution {
  public:
   bool isleaf(Node* root) {
      return (root->left == NULL && root->right == NULL);
   }
 
    void addleftboundary( Node *root, vector<int>&res){
       Node *curr = root -> left;
      
       while( curr){
           if ( !isleaf(curr))  res.push_back(curr -> data);
           if( curr-> left) curr = curr -> left; //go left left left 
           else  curr = curr ->right; // if not left then go right
          
       }
       
   }
     
      void addrightboundary( Node *root, vector<int>&res){
         vector<int> temp; // ye isliye cz to store in reverse of right boundary
         Node *curr = root -> right;
      
       while( curr){
           if ( !isleaf(curr))  temp.push_back(curr -> data);
           if( curr-> right) curr = curr -> right; //go right right right 
           else  curr = curr ->left; // if no then go left
           
       }
       
        for ( int i= temp.size()-1; i >=0; --i){
            res.push_back(temp[i]); // storing right boundary elements in reverse
        }
   }
   
     void addleafnodes( Node *root, vector<int> &res){
       
        if (isleaf(root)){
            res.push_back( root -> data);
            return;
        } 
        if (root -> left) addleafnodes( root ->left, res);
        if (root -> right) addleafnodes( root -> right, res);
        
    }
   
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if ( ! root ) return res; // root not present
        if ( !isleaf(root)) res.push_back( root->data); // root is not leaf then add
        addleftboundary( root ,res); // recursion layega left boundary
        addleafnodes(root, res );
        addrightboundary( root ,res);
        return res;
    }
};