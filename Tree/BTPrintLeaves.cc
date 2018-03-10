void printLeaves(Node* root){
    if (root){
          printLeaves(root->left);
              if ( !root->left && !root->right )
                      std::cout<<root->data<<' ';
                  printLeaves(root->right);
                    }
}
