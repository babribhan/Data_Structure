void printBoundaryRight(Node* root){
  if (root){
    if ( root->right) {
      printBoundaryRight(root->right);
      std::cout<<root->data<<' ';
    }
    else if ( root->left) {
      printBoundaryRight(root->left);
      std::cout<<root->data<<' ';
    }
  }
}
void printBoundaryLeft(Node* root){
  if (root){
    if ( root->left) {
      std::cout<<root->data<<' ';
      printBoundaryLeft(root->left);
    }
    else if ( root->right) {
      std::cout<<root->data<<' ';
      printBoundaryLeft(root->right);
    }
  }
}
void printBoundary(Node* root){
  if ( root){
    std::cout<<root->data<<' ';
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
    // Print all leaves from left to right.
    printLeaves(root->left);
    printLeaves(root->right);
    // Print the right boundary in bottom-up manner.
    printBoundaryRight(root->right);
  }
}

