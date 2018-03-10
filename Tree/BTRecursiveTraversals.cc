void inOrder(Node *root){
    if ( root ) {
          inOrder(root->left);
              std::cout<<root->data<<' ';
                  inOrder(root->right);
                    }
}
void postOrder(Node *root){
    if ( root ) {
          postOrder(root->left);
              postOrder(root->right);
                  std::cout<<root->data<<' ';
                    }
}
void preOrder(Node *root){
    if ( root ) {
          std::cout<<root->data<<' ';
              preOrder(root->left);
                  preOrder(root->right);
                    }
}
