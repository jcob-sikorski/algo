#include <bits/stdc++.h>

using namespace std;


struct Node {
    int data;
    Node left, right;
}


// https://github.com/williamfiset/data-structures/blob/master/com/williamfiset/datastructures/binarysearchtree/BinarySearchTree.java#L1
class BinarySearchTree {

private:
    int nodeCount = 0;
    Node root = NULL;

public:
    bool is_empty() {
        return !nodeCount ? true : false;
    }

    Node add(Node node, int elem) {
        if (node == NULL) {
            node.left = NULL; node.right = NULL;
            node.data = elem;
        }
        else {
            if (node.data > elem) {
                node.left = add(node.left, elem);
            }
            else {
                node.right = add(node.right, elem);
            }
        }
        return node;
    }

    void utilAdd(int elem) {
        root = add(root, elem);
        nodeCount++;
    }

    Node remove(Node node, int elem) {
        if (node == NULL) return NULL;

        if (node.data > elem) {
            node.left = remove(node.left, elem);
        }
        else if (node.data < elem) {
            node.right = remove(node.right, elem);
        }
        else {
            if (node.left == NULL) {
                Node rightChild = node.right;

                node.data = NULL;
                node = NULL;

                return rightChild;
            }
            else if (node.right == NULL) {
                Node leftChild = node.left;

                node.data = NULL;
                node = NULL;

                return leftChild;
            }
            else {
                Node tmp = findMin(node.right);
                node.data = tmp.data;
                node.right = remove(node.right, tmp.data);
            }
        }
        return node;
    }


    void utilRemove(int elem) {
        root = remove(root, elem);
        nodeCount--;
    }

    Node findMin(Node node) {
        while (node.left != NULL) {
            node = node.left;
        }
        return node;
    }

    Node findMax(Node node) {
        while (node.right != null) {
            node = node.right;
        }
    return node;
    }
}