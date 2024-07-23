#include "bintree.h"
#include <iostream>
using namespace std;

void printArray(string a[]) {
    for (int i = 0; i < ARRAYSIZE; i++) {
    if (!a[i].empty())
        cout << a[i] << ' ';
    }
    cout << endl;
}

//18 3 37 11 25 21 40 8 13 1 42 15
int main(){
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

    cout << "Size: " << mytree.NumberOfNode();

    
    // mytree.insert("b");
    // mytree.insert("a");
    // mytree.insert("c");
    // mytree.insert("b");
    // mytree.insert("a");
    // mytree.insert("c");
    cout << mytree;
    cout << endl;

    mytree.displayTree();
    cout << endl;
    mytree.displaySideways();

    string testnode = "18";
    Node *addr;

    bool found = mytree.retrieve(testnode, addr);
    cout << "Retrieve " << testnode << (found ? ": found" : ": not found") << endl;
    if (found){
        cout << "Node address = " << addr << endl;
    }

    cout << "Height of node " << testnode << " is " << mytree.getHeight(testnode) << endl;

    // BinTree copytree(mytree);
    // copytree.insert("31");
    // cout << "Copy Tree: " << copytree << endl;
    

    // BinTree T = mytree;
    // cout << "Assign Tree: " << T << endl;
    // cout << "Are they same? " << ((copytree == T) ? " yes " : " no") << endl;
    // cout << "Are they different? " << ((copytree != T) ? " yes " : " no") << endl;

    // string ndarray[ARRAYSIZE];
    // //Note that bstreeToArray empty the original filetree. Therefore, we need to copy the filetree to a new tree before 
    // //calling this if want to keep the original tree.

    //     BinTree original (mytree);
    //     mytree.bstreeToArray(ndarray);
    //     printArray(ndarray);

    //     cout << "original: " << endl << original << endl;
    //     cout << "mytree: " << endl << mytree << endl; 
    //     cout << "Array to BST: should balance the tree" << endl;
    //     mytree.arrayToBSTree(ndarray);

    //     mytree.displaySideways();

    //     mytree.displayTree();

    //     cout<<"Compare the original tree and recovered tree"<<endl;
    //     cout << "Are they same? " << ((original == mytree) ? " yes " : " no") << endl;
    //     cout << "Are they different? " << ((original != mytree) ? " yes " : " no") << endl;
    //     cout << mytree.getHeight("15");
    return 0;
}

