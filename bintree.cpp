#include "bintree.h"

// Constructor
BinTree::BinTree(){
    this->root = nullptr;
    size = 0;
}

// Copy constructor
BinTree::BinTree(const BinTree &otherTree){
    this->root = nullptr;
    *this = otherTree;
}

// Destructor
BinTree::~BinTree(){
    // Clear the tree and reset size
    ClearRecursive(root);
    size = 0;
}

// Recursive helper function to clear the tree
void BinTree::ClearRecursive(Node *&root){
    if (root != nullptr) {
        // Recursively clear left and right subtrees
        ClearRecursive(root->left);
        ClearRecursive(root->right);

        // Delete the current node and set the pointer to nullptr
        delete root;
        root = nullptr; 
    }
}

// Function to check if a string represents a number
bool BinTree::CheckForNumber(const string &data){
   stringstream input(data);
   double number;
   return(input >> number) && input.eof();
}

// Insert function to add a new node to the tree
bool BinTree::insert(const string &data){
  return insertRecursive(root, data);
}

// Recursive helper function for insertion
bool BinTree::insertRecursive(Node *&root, const string &data){
    // Create a new node if the current node is null
    if(root == nullptr){
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        size++;
        return true;
    }

    // Check whether the data is a number or a string
    if (CheckForNumber(data)) {
        // Data is a number, compare numerically
        double newData = stod(data);

        if (newData == stod(root->data)) {
            return false;  // Duplicate, already exists
        } else if (newData < stod(root->data)) {
            return insertRecursive(root->left, data);
        } else {
            return insertRecursive(root->right, data);
        }
    } else {
        // Data is a string, compare as strings
        if (data == root->data) {
            return false;  // Duplicate, already exists
        } else if (data < root->data) {
            return insertRecursive(root->left, data);
        } else {
            return insertRecursive(root->right, data);
        }
    }
}

// Function to check if the tree is empty
bool BinTree::isEmpty() const{
    if(root == nullptr){
        return true;
    }

    return false;
}

// Function to get the number of nodes in the tree
int BinTree::NumberOfNode() const {
    return size;
}

// Function to retrieve a node with a specified data value
bool BinTree::retrieve(const string &data, Node *&other) const{
    return RetrieveRecursive(data, root, other);
}

// Recursive helper function for retrieval
bool BinTree::RetrieveRecursive(const string &data, Node *root, Node *&store) const{

    // Data not found
    if(root == nullptr){
        return false;
    }

    if(root->data == data){
        store = root; // Update the reference with the found node
        return true;
    }

    if(root->data > data){
        RetrieveRecursive(data, root->left, store);
    }else{
        RetrieveRecursive(data, root->right, store);
    }
    
    return false;
}

// Function to get the height of the tree from a specified node
int BinTree::getHeight(const string &data) const {
    int height = 0;

    // Call the recursive helper function
    getHeightRecursive(root, data, height);
    return height;
}

// Recursive helper function for getting the height
int BinTree::getHeightRecursive(Node *root, const string &data, int &height) const{
    
    // Return 0 for null nodes
    if(root == nullptr){
        return 0;
    }

    // Return 1 if it is a left node
    if(root->left == nullptr && root->right == nullptr){
        return 1;
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = getHeightRecursive(root->left, data, height);
    int rightHeight = getHeightRecursive(root->right, data, height);

    // Determine the current height of the subtree
    int currentHeight = max(leftHeight, rightHeight) + 1;

    // Update the height if the current node's data matches the specified data
    if(root->data == data){
        height = currentHeight;
    }

    return currentHeight;
}

// Assignment operator overloading
BinTree &BinTree::operator=(const BinTree &otherTree){
    
    // Check for self-assignment
    if(this == &otherTree){
        return *this;
    }
    
    // Clear the current tree
    this->ClearRecursive(this->root);

    // If the other tree is empty, return the current tree
    if(otherTree.root == nullptr){
        return *this;
    }

    // Copy the other tree
    this->CopyTreeRecursive(this->root, otherTree.root);
    this->size = 0;
    this->size = otherTree.size;

    return *this;

}

// Recursive helper function to copy a tree
void BinTree::CopyTreeRecursive(Node *&root, const Node *other_tree_root){
    
    // Set root to null for an empty tree
    if(other_tree_root == nullptr){ 
        root = nullptr;
    }else{

        // Create a new node and copy data
        root = new Node;
        root->data = other_tree_root->data;
        root->left = nullptr;
        root->right = nullptr;

        // Recursively copy left and right subtrees
        CopyTreeRecursive(root->left, other_tree_root->left);
        CopyTreeRecursive(root->right, other_tree_root->right);
    }
}

// Equality operator overloading
bool BinTree::operator==(const BinTree &other_tree) const{
    return IsTreeSame(root, other_tree.root);
}

// Function to check if two trees are identical
bool BinTree::IsTreeSame(const Node *root, const Node *other_root) const{

    // Both trees are empty, considered identical
    if(root == nullptr && other_root == nullptr){
        return true;
    }

    // One tree is empty while the other is not, considered different
    if(root == nullptr || other_root == nullptr){
        return false;
    }

    // Compare data of current nodes and recursively check left and right subtrees
    if(root->data != other_root->data){
        return false; // Data at current nodes is different
    }

    return IsTreeSame(root->left, other_root->left) && IsTreeSame(root->right, other_root->right);
    
}


// Inequality operator overloading
bool BinTree::operator!=(const BinTree &otherTree) const{

    // Inequality is the opposite of equality
    if(IsTreeSame(root, otherTree.root) == true){
        return false;
    }

    return true;
}

// Function to convert a binary search tree to an array
void BinTree::bstreeToArray(string myarr[]){
    int i = 0;

    // Check if the tree is empty
    if(this->root == nullptr){
        return;
    }
    // Create an array representation of the tree
    createArray(root, myarr, i);

    // Clear the tree after converting to array
    ClearRecursive(root);
}

// Recursive helper function to create an array from a tree
void BinTree::createArray(Node *root, string myarr[], int &i){
    if(root != nullptr){
        createArray(root->left, myarr, i);
        myarr[i++] = root->data;
        createArray(root->right, myarr, i);
    }
}

// Function to convert an array to a balanced binary search tree
void BinTree::arrayToBSTree(string myarr[]){

    // Create a balanced binary search tree from the array
    createTree(root, myarr, 0, size - 1);
}

// Recursive function to create a balanced binary search tree from an array
void BinTree::createTree(Node *&root, string myarr[], int start, int end){
    
    // Base case for an empty range
    if(start > end){
        root = nullptr;
        return;
    }

    int mid = (start + end) / 2;
    root = new Node;
    root->data = myarr[mid];
    size++;
    
    // Recursively create left and right subtrees with updated ranges
    createTree(root->left, myarr, start, mid-1);
    createTree(root->right, myarr, mid + 1, end);
}

// Function to display the tree with root information
void BinTree::displayTree() const{
    if(root != nullptr){
        cout << "Root: ";
    }

    // Call the recursive helper function
    DisplayTreeRecursive(root, 0);
}

// Recursive function to display a tree with proper formatting
void BinTree::DisplayTreeRecursive(const Node *root, int level) const{
    if(root != nullptr){ //base case

        cout << root->data;

        if(root->left != nullptr || root->right != nullptr){
            cout << endl;
        }

        if(root->left != nullptr){
            cout << setw(8 + 5 * level) << "L--";
            DisplayTreeRecursive(root->left, level + 1);
        }

        if(root->right != nullptr){
            if(root->left != nullptr){
                cout << endl;
            }
            cout << setw(8 + 5 * level) << "R--";
            DisplayTreeRecursive(root->right, level + 1);
        }
    }
}

// Function to display the tree sideways
void BinTree::displaySideways() const{
    SidewayTreeRecursive(root, 0);
}

// Recursive function to display a tree sideways
void BinTree::SidewayTreeRecursive(const Node *root, int level) const{
    if(root != nullptr){ 
        if(root->right != nullptr){
            SidewayTreeRecursive(root->right, level + 1);
        }

        cout << setw(4 + 6 * level) << " ";
        cout << root->data << endl;

        if(root->left != nullptr){
            SidewayTreeRecursive(root->left, level + 1);
        }
    }
}

// Recursive function to perform an in-order traversal of the tree
void BinTree::inOrderRecursive(Node *root) const{
    if(root != nullptr){
        inOrderRecursive(root->left);
        cout << root->data << " ";
        inOrderRecursive(root->right);
    }
}

// Overloaded stream insertion operator to display the tree
ostream &operator<<(ostream &cout, const BinTree &other_tree){
    // Call the in-order traversal function to display the tree elements
    other_tree.inOrderRecursive(other_tree.root);
    return cout;
}
