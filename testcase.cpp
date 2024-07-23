#include<iostream>
#include <sstream>
#include "bintree.h"
#include<string>
#include<vector>

using namespace std;
const int SIZE = 100;

// Test case for adding integers to the binary search tree
bool AddTest1() { //int
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");

    string expectedOutput[] = {"0", "1", "2", "3"};
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(expectedOutput[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for adding strings to the binary search tree
bool AddTest2() { //string
    BinTree mytree;
    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("d");

    string expectedOutput[] = {"a", "b", "c", "d"};
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(expectedOutput[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for handling duplicate values in the binary search tree
bool AddTest3() { //duplicate value
    BinTree mytree;
    mytree.insert("11");
    mytree.insert("13");
    mytree.insert("8");
    mytree.insert("144");
    mytree.insert("8");

    string expectedOutput[] = {"8", "11", "13", "144"};
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(expectedOutput[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for checking if the tree is empty (initially empty)
bool EmptyTest1(){ //empty tree
    BinTree mytree;
    return (mytree.isEmpty() == true);
}

// Test case for checking if the tree is empty (after insertion)
bool EmptyTest2(){ //empty tree
    BinTree mytree;
    mytree.insert("1");
    
    return (mytree.isEmpty() == false);
}

// Test case for copying binary search tree with integers
bool CopyConstructorTest1(){ //int
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");

    BinTree mytree_copy(mytree);
    string myarr2[SIZE];
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);
    mytree_copy.bstreeToArray(myarr2);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(myarr2[i] != myarr[i]){
            return false;
        }
    }
    
    return true;

}

// Test case for copying binary search tree with strings
bool CopyConstructorTest2(){ //string
    BinTree mytree;
    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("d");

    BinTree mytree_copy(mytree);
    string myarr2[SIZE];
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);
    mytree_copy.bstreeToArray(myarr2);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(myarr2[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for retrieving a value that exists in the tree
bool RetrieveTest1(){
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");
    Node *root;
    
    return mytree.retrieve("2", root) == true;
}

// Test case for retrieving a value that does not exist in the tree
bool RetrieveTest2(){ //value that does not exist
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");
    Node *root;
    
    return mytree.retrieve("4", root) == false;
}

// Test case for retrieving a value that exists in the middle of the tree
bool RetrieveTest3(){ //value in between
    BinTree mytree;
    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("d");
    Node *root;
    
    return mytree.retrieve("c", root) == true;
}

// Test case for converting a binary search tree to an array (strings)
bool bstToArrayTest1(){
    BinTree mytree;
    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("d");

    string expectedOutput[] = {"a", "b", "c", "d"};
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(expectedOutput[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for converting a copied binary search tree to an array
bool bstToArrayTest2(){ //convert 2 tree to bstToarray 
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");

    BinTree mytree_copy(mytree);
    string myarr2[SIZE];
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);
    mytree_copy.bstreeToArray(myarr2);

    for(int i = 0; i < mytree.NumberOfNode(); i++){
        if(myarr2[i] != myarr[i]){
            return false;
        }
    }
    
    return true;
}

// Test case for checking the size of a non-empty tree
bool SizeTreeTest1(){
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("0");
    mytree.insert("3");

    return mytree.NumberOfNode() == 4;
}

// Test case for checking the size of an empty tree
bool SizeTreeTest2(){
    BinTree mytree;

    return mytree.NumberOfNode() == 0;
}

// Test case for converting an array to a binary search tree
bool ArrayToBSTTest() {
    BinTree mytree;
    mytree.insert("18");
    mytree.insert("3");
    mytree.insert("37");
    mytree.insert("11");
    mytree.insert("25");
    mytree.insert("21");
    mytree.insert("40");
    mytree.insert("8");
    mytree.insert("13");
    mytree.insert("1");
    mytree.insert("42");
    mytree.insert("15");

    // Obtain array representation
    string myarr[SIZE];
    mytree.bstreeToArray(myarr);

    // Apply arrayToBSTree
    mytree.arrayToBSTree(myarr);

    BinTree mytree2;
    mytree2.insert("15");
    mytree2.insert("8");
    mytree2.insert("25");
    mytree2.insert("1");
    mytree2.insert("11");
    mytree2.insert("18");
    mytree2.insert("40");
    mytree2.insert("3");
    mytree2.insert("13");
    mytree2.insert("21");
    mytree2.insert("37");
    mytree2.insert("42");
  
    return mytree == mytree2;
}

// Test case for displaying the binary search tree
bool DisplayTreeTest() {
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("3");

    cout << endl;
    mytree.displayTree();
    cout << endl;

    return true;  // Manually inspect the console output
}

// Test case for displaying the binary search tree sideways
bool DisplaySidewaysTest() {
    BinTree mytree;
    mytree.insert("2");
    mytree.insert("1");
    mytree.insert("3");

    cout << endl;
    mytree.displaySideways();
    cout << endl;

    return true;  // Manually inspect the console output
}

// Test case for comparing two identical trees
bool TreeSameTest(){
    BinTree mytree;
    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("d");

    BinTree mytree2(mytree);
    
    return mytree2 == mytree;
}

// Test case for comparing two different trees
bool TreeDifferentTest(){
    BinTree mytree;
    mytree.insert("c");
    mytree.insert("b");
    mytree.insert("a");

    BinTree mytree2;
    mytree.insert("b");
    mytree.insert("c");
    mytree.insert("a");
    
    return mytree2 != mytree;
}

// Test case for getting the height of a specific node in the tree
bool HeightTest(){
    BinTree mytree;
    mytree.insert("c");
    mytree.insert("b");
    mytree.insert("a");

    return mytree.getHeight("b") == 2;
}

// Test case for testing the assignment operator
bool AssignmentOperatorTest(){
    BinTree mytree;
    mytree.insert("c");
    mytree.insert("b");
    mytree.insert("a");

    BinTree mytree2; 
    mytree2 = mytree;

    return mytree2 == mytree;
}

int main(){
    cout << "AddTest1: ";
    cout << ((AddTest1()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "AddTest2: ";
    cout << ((AddTest2()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "AddTest3: ";
    cout << ((AddTest3()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "EmptyTree1: ";
    cout << ((EmptyTest1()) ? "PASSED" : "FAILED");
    cout << endl;
    
    cout << "EmptyTree2: ";
    cout << ((EmptyTest1()) ? "PASSED" : "FAILED");
    cout << endl;

    cout << "CopyConstructorTest1: ";
    cout << ( (CopyConstructorTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "CopyConstructorTest1: ";
    cout << ( (CopyConstructorTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "RetrieveTest1: ";
    cout << ( (RetrieveTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "RetrieveTest2: ";
    cout << ( (RetrieveTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "RetrieveTest3: ";
    cout << ( (RetrieveTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "bstToArrayTest1: ";
    cout << ( (bstToArrayTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "bstToArrayTest2: ";
    cout << ( (bstToArrayTest2()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "SizeTreeTest1: ";
    cout << ( (SizeTreeTest1()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "SizeTreeTest2: ";
    cout << ( (SizeTreeTest1()) ? "PASSED" : "FAILED" );
    cout << endl;
    
    cout << "ArrayToBSTTest: ";
    cout << ( (ArrayToBSTTest()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << endl;
    cout << endl << "DisplayTreeTest: ";
    cout << ( (DisplayTreeTest()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << endl << "DisplaySidewaysTest: ";
    cout << ((DisplaySidewaysTest()) ? "PASSED" : "FAILED" );

    cout << endl << "TreeSameTest: ";
    cout << ((TreeSameTest()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "HeightTest: ";
    cout << ((HeightTest()) ? "PASSED" : "FAILED" );
    cout << endl;

    cout << "AssignmentOperatorTest: ";
    cout << ((AssignmentOperatorTest()) ? "PASSED" : "FAILED" );
    cout << endl;
   
    return 0;
}

