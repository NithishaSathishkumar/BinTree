#include <iostream> //input and output
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

const int ARRAYSIZE = 100;
// BST Node contains pointer for left, right, and data
struct Node {
    string data;
    Node *left;
    Node *right;
};

class BinTree {
// Overloaded << : prints BinTree in correct structure
friend ostream &operator<<(ostream &, const BinTree &);

public:
    // Constructors
    BinTree();

    //copy constructors
    BinTree(const BinTree &);

    // Desctructor
    ~BinTree();

    // required public methods
    bool isEmpty() const; // check if tree is empty

    // retrieve the pointer of the node of given data
    bool retrieve(const string &data, Node *&other) const;

    bool CheckForNumber(const string &data);
    bool insert(const string &data); // insert node with the node data

    //display
    // displays the tree in pre-order, provide prefix (Root, L--, R--)
    void displayTree() const;
    void displaySideways() const; // displays the tree sidways

    // get height of a node starting from leaf (= 1)
    int getHeight(const string &) const;

    int NumberOfNode() const;
    
    // Overload operators
    // -- Assignment Operator
    BinTree &operator=(const BinTree &); // this = rhs

    // -- Comparison Operators
    bool operator==(const BinTree &) const; // this == rhs
    bool operator!=(const BinTree &) const; // this != rhs

    // Miscellaneous Functions
    void bstreeToArray(string myarr[]);
    void arrayToBSTree(string myarr[]);

private:
    Node *root; // Points to the root of the BST
    int size;

    // You can add private methods here
    bool insertRecursive(Node *&tree, const string &data);
    bool RetrieveRecursive(const string &data, Node *root, Node *&store) const;
    void ClearRecursive(Node *&root);
    void inOrderRecursive(Node *root) const;
    void DisplayTreeRecursive(const Node *root, int level) const;
    void SidewayTreeRecursive(const Node *root, int level) const;
    void CopyTreeRecursive(Node *&root, const Node *other_tree_root);
    int getHeightRecursive(Node *root, const string &data, int &height) const;
    bool IsTreeSame(const Node *root, const Node *other_root) const;
    void createArray(Node *root, string myarr[], int &i);
    void createTree(Node *&root, string myarr[], int start, int end);
};
