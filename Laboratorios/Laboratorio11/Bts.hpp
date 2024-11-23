#ifndef BTS_HPP
#define BTS_HPP

#include <iostream>
#include <stdexcept>
using namespace std;


struct TreeNode {
    int value; 
    TreeNode* left; 
    TreeNode* right; 

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

}; 


class BinarySearchTree {
    private: 
        TreeNode* root; 

        TreeNode* insert(TreeNode* node, int value); 

        TreeNode* findLCA(TreeNode* node, int v1, int v2);

        void inOrderTransversal(TreeNode* node); 

        bool search (TreeNode* node, int value); 
    public: 

        BinarySearchTree();

        void insert(int value); 

        int findLowestCommonAncestor(int v1, int v2);

        void printInOrder();

};

#endif //BTS_HPP