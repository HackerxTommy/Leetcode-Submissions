/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
public:
    vector<int> postOrder(Node* node) {

        vector<int> post;

        if (node == NULL)
            return post;

        stack<Node*> st;
        Node* curr = node;

        while (curr != NULL || !st.empty()) {

            // Go as left as possible
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {

                Node* temp = st.top()->right;

                // No right subtree
                if (temp == NULL) {

                    temp = st.top();
                    st.pop();
                    post.push_back(temp->data);

                    // Process ancestors whose right subtree
                    // has already been visited
                    while (!st.empty() &&
                           temp == st.top()->right) {

                        temp = st.top();
                        st.pop();
                        post.push_back(temp->data);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }

        return post;
    }
};