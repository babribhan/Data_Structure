/* 
1. Create s stack.
2. Repeat untill stack is not empty.
3. if current is not null then push it and go to its left.
4. if current is null and stack is not empty then pop from stack and print it and go to its right child.
5. else get out of loop. adn we are done.
*/

void inorder(Node* root){
        std::stack<Node*> s;
        Node* current = root;
        while(1){
                if ( current) {
                        s.push(current);
                        current = current->left;
                }
                else {
                        if (!s.empty()){
                                current = s.top();s.pop();
                                std::cout<<current->data<<' ';
                                current = current->right;
                        }
                        else {
                                break;
                        }
                }
        }
}
