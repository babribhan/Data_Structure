/*
1. Create a stack.
2. push the root to stack.
3. Repeat while stak is not empty
4.   Pop from stak and print it .
5.   if right child exists push it to stack.
6.   if left child exists push it to stack.
7.   Go to step 4.
*/

void preorder(Node* root){
        if ( !root) return;
        std::stack<Node*> s;
        s.push(root); 
        while (!s.empty()){
                Node* current = s.top();s.pop();
                std::cout<<current->data<<' ';
                if ( current->right)
                        s.push(current->right);
                if ( current->left)
                        s.push(current->left);
        }
}
