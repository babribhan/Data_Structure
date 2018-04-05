#include <iostream>
#include <queue>
enum Color {RED , BLACK,DOUBLE_BLACK};
struct Node{
	int val;
	short  color;
	Node *left;
	Node *right;
	Node *parent;
	Node(int val):val(val),left(nullptr),right(nullptr),parent(nullptr){
	} 
};
typedef Node* pNode;
class RedBT{
pNode root;
protected:
void rotateLeft(pNode&, pNode&);
void rotateRight(pNode&, pNode&);
void fixInsertion(pNode&, pNode&);
void fixDeletion(pNode);
public: 
RedBT() { root = nullptr;}
void insert(const int &n ) ;
void inorder();	
void levelOrder();	
void deleteRBT(int key);
};
pNode minValueNode(pNode root){
while (root->left) {
root = root->left;
}
return root;
}
void inorderUtil(pNode root) {
	if ( root){
		inorderUtil(root->left);
		std::cout<<root->val<<" ";
		inorderUtil(root->right);
	}
}
pNode BstInsert(pNode root , pNode newNode ) {
	if ( !root ) return newNode;
	if ( newNode->val > root->val ) {
		root->right  = BstInsert(root->right,newNode);
		root->right->parent = root;
	}
	else if ( newNode->val < root->val ) {
		root->left = BstInsert(root->left,newNode);
		root->left->parent = root;
	}
	return root;
}
void levelOrderUtil(pNode root ){
	if ( !root ) return;
	std::queue<pNode> q;
	q.push(root);
	while ( !q.empty()){
      short count = q.size();
      while ( count-- ) {
		pNode temp = q.front();q.pop();
		std::cout<<temp->val<<"<"<<temp->color<<">";
		if ( temp->left) 
			q.push(temp->left);
		if ( temp->right) 
			q.push(temp->right);
	}
    std::cout<<std::endl;
}
}
void RedBT::inorder(){
inorderUtil(root);
}
void RedBT::levelOrder(){
	levelOrderUtil(root);
}
void RedBT::insert(const int &val){
	pNode temp = new Node(val);
	root = BstInsert(root,temp);
	fixInsertion(root,temp);
}
void RedBT::rotateRight(pNode &root, pNode &current){
	pNode newRoot = current->left;
	current->left = newRoot->right;
	if ( current->left ){
		current->left->parent = current;
	}
	newRoot->parent = current->parent;
	if ( !current->parent ){
		root = newRoot;
	} 
	else if (  current->parent->left ==  current ) {
		current->parent->left = newRoot;
	}
	else {
		current->parent->right = newRoot;
	}
	newRoot->right = current;
	current->parent = newRoot; 
}
void RedBT::rotateLeft(pNode &root, pNode &current){
	pNode newRoot = current->right;
	current->right = newRoot->left;
	if ( current->right ){
		current->right->parent = current;
	}
	newRoot->parent = current->parent;
	if ( !current->parent ){
		root = newRoot;
	} 
	else if (  current->parent->left ==  current ) {
		current->parent->left = newRoot;
	}
	else {
		current->parent->right = newRoot;
	}
	newRoot->left = current;
	current->parent = newRoot; 
}
void RedBT::fixInsertion(pNode &root, pNode &newNode ) {
/*
  During insertion only below property can be violated of REB BLACK Tree .
  Property 1 (  Root is Black) can be violated if the new inserted node is root  node.
  and property 2 ( No two adjacent RED colored node exists ) can be violated. 
*/
	pNode parent=nullptr , grandParent=nullptr;
	while ( root != newNode && newNode->color != BLACK 
			&& ( newNode->parent->color == RED ) ) {  // While the parent color is RED.
		parent = newNode->parent;
		grandParent = parent->parent;
		if ( parent == grandParent->left ) { // CASE A : When newNode's parent is left child.
			pNode uncle = grandParent->right;
			if ( uncle && uncle->color == RED ) { // CASE 1 : When uncle is red so only recoloring enough.
				uncle->color = parent->color = BLACK;
				grandParent->color = RED;
				newNode = grandParent;
			}   
			else {  // Uncle is BLACK. 
				if ( newNode == parent->right ) { // CASE 2 : LEFT RIGHT CASE
					rotateLeft(root,parent);
					newNode = parent;
					parent  = newNode->parent;
				} 
				// CASE 3 : LEFT LEFT CASE.
				rotateRight(root,grandParent);
				parent->color = !parent->color;
				grandParent->color = !grandParent->color;
				newNode = parent;
			}
		}
		else {  // CASE B : When newznode's parent is right child.
			pNode uncle = grandParent->left;
			if ( uncle && uncle->color == RED ) { // CASE 1 : When uncle is red so only recoloring is enough.
				uncle->color = parent->color = BLACK;
				grandParent->color = RED;
				newNode = grandParent;

			}
			else {  // Uncle is BLACK.
				if ( newNode == parent->left )  {  // CASE 2 : RIGHT LEFT CASE.
					rotateRight(root,parent);
					newNode = parent;
					parent  = newNode->parent;
				}
				// CASE 3 : RIGHT RIGHT CASE.
				rotateLeft(root,grandParent);
				parent->color = !parent->color;
				grandParent->color = !grandParent->color;
				newNode = parent;
			}

		}
	} 
	root->color = BLACK;
}
pNode deleteBST(pNode &root, int val) {
    if (root == nullptr)
        return root;

    if (val < root->val)
        return deleteBST(root->left, val);

    if (val > root->val)
        return deleteBST(root->right, val);

    if (root->left == nullptr || root->right == nullptr)
        return root;

    pNode temp = minValueNode(root->right);
    root->val = temp->val;
    return deleteBST(root->right, temp->val);
}
void RedBT::fixDeletion(pNode nodeToDel){
	/*
		During deletion only below property can be violated of REB BLACK Tree .
		Property 4 (Black height of RB Tree is equal of every root to leaf paths) can be violated if the deleted node is a BLACK node.
		and property 1 ( Root is BLACK ) can also be violated. if deleted node is root itself.
	 */
	// BASE CASE
	if (!nodeToDel) 
		return;
	if ( nodeToDel == root ) {
		root = nullptr;
		delete nodeToDel;
		return;
	}
	// If NodeTeDel or NodeToDel's left or right child is RED then we only need to change the color of replaced child to BLACK.
	if ( nodeToDel->color == RED || (nodeToDel->left && nodeToDel->left->color == RED) 
			|| (nodeToDel->right && nodeToDel->right->color == RED )){
		pNode child = nodeToDel->left ? nodeToDel->left : nodeToDel->right;
		if ( nodeToDel->parent && ( nodeToDel == nodeToDel->parent->left )) 
			nodeToDel->parent->left = child;
		else 
			nodeToDel->parent->right = child;
		if(child){
			child->parent = nodeToDel->parent;    
		child->color = BLACK;
}
		delete nodeToDel;
	}
	else { 
		pNode sibling = nullptr,parent=nullptr,currentNode = nodeToDel;
		// SET THE COLOR OF NODE TO BE DELETED TO DOUBLE BLACK.
		currentNode->color = DOUBLE_BLACK;
		// Now our task is to make this double black node to single black node.
		while( currentNode != root && currentNode->color == DOUBLE_BLACK ){
			parent = currentNode->parent;
			if ( currentNode == parent->left ) { // Deletion is done from Left side and balancing will be done on right side.
				sibling = parent->right;
				if ( sibling && sibling->color == RED ) { 
					// Sibling is RED then change swap color of parent and sibling and perform left rotation on parent.
					sibling->color = BLACK;
					parent->color = RED;
					rotateLeft(root,parent);  
				}
				else { 
					// Sibling is BLACK  colored.
					if( (sibling->left && sibling->left->color == BLACK) && (sibling->right && sibling->right->color == BLACK)) {
						// Sibling and its both left and right child are BLACK.
						// Performing Recoloring sibling color set to RED and parent color is set to BLACK if it was RED else it will be set to DOUBLE_BLACK
						// And recurr for parent.
						sibling->color = RED;
						parent->color = (( parent->color == RED ) ? BLACK : DOUBLE_BLACK );
						currentNode = parent;           
					}
					else {
						// sibling left child is RED means it will be RIGHT LEFT case else it is RIGHT RIGHT case.
						if ( sibling->right && sibling->right->color == BLACK ){
							// if sibling right child is black then is is RIGHT LEFT case.
							if ( sibling->left ) 
								sibling->left->color = BLACK;
							sibling->color = RED;
							rotateRight(root,sibling);
							sibling = parent->right;
						} 
						// RIGHT RIGHT case left rotate.
						sibling->color = parent->color;
						parent->color = BLACK;
						if ( sibling->right ) 
							sibling->right->color = BLACK;
						rotateLeft(root,parent);
						break;
					}
				}
			}  
			else {
				// Deletion is done form right side so balancing will be done on left side.
				sibling = parent->left;
				if ( sibling->color == RED ) {
					// sibling is red then swap color of parent and sibling and perform right rotation on parent.
					sibling->color = BLACK;
					parent->color = RED;
					rotateRight(root,parent);
				} 
				else {
					// Sibling is BLACK.
					if( (sibling->left && sibling->left->color == BLACK) && (sibling->right && sibling->right->color == BLACK)) {
						// Sibling and its both left and right child are BLACK.
						// Performing Recoloring ,sibling color set to RED and parent color is set to BLACK if it was RED else it will be set to DOUBLE_BLACK
						// And recurr for parent.
						sibling->color = RED;
						parent->color = (( parent->color == RED ) ? BLACK : DOUBLE_BLACK );
						currentNode = parent;           
					}           
					else {
						// sibling left child RED  means it will be LEFT RIGHT case else it will be LEFT LEFT case.
						if ( sibling->left && sibling->left->color == BLACK ){ // For LEFT RIGHT case.
							if (sibling->right)
								sibling->right->color = BLACK;
							sibling->color = RED;
							rotateLeft(root,sibling);
							sibling = parent->left;       
						}
						// ONly for LEFT LEFT case
						sibling->color = parent->color;
						parent->color = BLACK;
						if (sibling->left)
							sibling->left->color  = BLACK;
						rotateRight(root,parent);
						break; 
					}
				}
			}
		}
		if ( nodeToDel == nodeToDel->parent->left ) 
			nodeToDel->parent->left = nullptr;
		else 
			nodeToDel->parent->right = nullptr;
		delete nodeToDel;
		root->color = BLACK; 
	}
}
void RedBT::deleteRBT(int key){
	fixDeletion(deleteBST(root,key));
}
int main()
{
    RedBT tree;
 
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
 
    std::cout << "Inoder Traversal of Created Tree\n";
    tree.inorder();
 
    std::cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder();
    tree.deleteRBT(1); 
    std::cout << "--------------"<<std::endl;
    tree.levelOrder();
    tree.deleteRBT(2); 
    std::cout << "--------------"<<std::endl;
    tree.levelOrder();
    tree.deleteRBT(5); 
    std::cout << "--------------"<<std::endl;
    tree.levelOrder();
    return 0;
}
