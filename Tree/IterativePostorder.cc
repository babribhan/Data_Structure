/*
1. Create a stack.
2. Repeat while stack is not empty.
3. Repeat while current node is not null 
4.   if right child of current is not null then push right child to stack.
5.   push current to stack and go to left of current.
     go to step 4.
6. if current is null then pop from the stack.
7. if right child of current is exists and right child is not processed yet ( present on top of stack)then
8.    pop right child from the stack and push current node to stack and go to its right child.
9. if either right child is not exists or right child is already processed then print the current node and set current to null.
10. Go to step 3.
*/


void postorder(Node* root){
        if (!root) return;
        std::stack<Node*> s;
        Node* current = root;
        do{
                while(current){ // Go to left most node.
                        if ( current->right)
                                s.push(current->right);
                        s.push(current);
                        current = current->left;
                }
                current = s.top();s.pop();
                if ( current->right && (!s.empty() && current->right == s.top()) ){
                        s.pop();
                        s.push(current);
                        current = current->right;
                }
                else {
                        std::cout<<current->data<<' ';
                        current = nullptr;
                }
        }while(!s.empty());
}
