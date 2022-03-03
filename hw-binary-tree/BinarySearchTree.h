#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct Employee {
    int id;
    int age;
    string name;

    Employee(int id = -1, int age = -1, string name = "")
        : id{ id }, age{ age }, name{ name } { }
};

class BinarySearchTree
{

public:

    struct BinaryNode
    {
        Employee element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const Employee& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ theElement }, left{ lt }, right{ rt } { }

        BinaryNode(Employee&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element{ std::move(theElement) }, left{ lt }, right{ rt } { }

        BinaryNode() {}
    };

    BinarySearchTree() : root{ nullptr }
    {
    }

    /**
     * Destructor for the tree
     */
    ~BinarySearchTree()
    {
        makeEmpty();
    }

    /**
     * Find the smallest item in the tree.
     * return default employee if empty
     */
    const Employee& findMin() const
    {
        if (isEmpty)
            return Employee(-1);
        return findMin(root);
    }

    /**
     * Find the largest item in the tree.
     * return default employee if empty
     */
    const Employee& findMax() const
    {
        return Employee();
    }

    /**
     * Prints employee info if id found in tree
     */
    bool find(int id)
    {
        find(id, root);
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
        return false;
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert(const Employee& x)
    {
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const int id)
    {
        remove(id);
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void report() const
    {
    }

private:

    BinaryNode* root;


    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(const Employee& x, BinaryNode*& t)
    {
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const int id, BinaryNode*& t)
    {
        // pointer to store the parent of the current node
        BinaryNode* parent = nullptr;

        // start with the root node
        BinaryNode* curr = root;

        // search key in the BST and set its parent pointer
        find(id);

        // return if the key is not found in the tree
        if (curr == nullptr) {
            return;
        }

        // Case 1: node to be deleted has no children, i.e., it is a leaf node
        if (curr->left == nullptr && curr->right == nullptr)
        {
            // if the node to be deleted is not a root node, then set its
            // parent left/right child to null
            if (curr != root)
            {
                if (parent->left == curr) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            }
            // if the tree has only a root node, set it to null
            else {
                root = nullptr;
            }

            // deallocate the memory
            free(curr);        // or delete curr;
        }

        // Case 2: node to be deleted has two children
        else if (curr->left && curr->right)
        {
            // find its inorder successor node
            BinaryNode* successor = findMin(curr->right);

            // store successor value
            int val = successor->element.id;

            // recursively delete the successor. Note that the successor
            // will have at most one child (right child)
            delete(root, successor);

            // copy value of the successor to the current node
            curr->element.id = val;
        }

        // Case 3: node to be deleted has only one child
        else {
            // choose a child node
            BinaryNode* child = (curr->left) ? curr->left : curr->right;

            // if the node to be deleted is not a root node, set its parent
            // to its child
            if (curr != root)
            {
                if (curr == parent->left) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
            }

            // if the node to be deleted is a root node, then set the root to the child
            else {
                root = child;
            }

            // deallocate the memory
            free(curr);
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    BinaryNode* findMin(BinaryNode* t) const
    {
        BinaryNode* current = t;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode* findMax(BinaryNode* t) const
    {
        return new BinaryNode();
    }


    /**
     * id is item to search for.
     * t is the node that roots the subtree.
     */
    bool find(const int id, BinaryNode* t) const
    {
            // Base Cases: root is null or key is present at root
            if (root == NULL || root->element.id == id)
                return root;

            // Key is greater than root's key
            if (root->element.id < id)
                return find(id, root->right);

            // Key is smaller than root's key
            return find(id, root->left);
    }

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(BinaryNode*& t)
    {
    }
};

#endif
