#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Headers/bst.h"
#include "../../AdaptiveQueue/Headers/queue.h"

// Command to complie code in Linux: gcc -D QUEUE_CONTENT_TYPE="void*" st.c main.c "../../AdaptiveQueue/Sources/queue.c" -o main


// 1. Design a BST class with methods to add element, search element, number of elements and delete requested element
void test_new_add_delete_count_search() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    assert(bst_count(tree) == 0);

    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    assert(bst_count(tree) == 3);
    assert(bst_lookup(tree, 20) == 1);

    tree = bst_delete(tree, 20);
    assert(bst_count(tree) == 2);
    bst_inorder(tree);
    assert(bst_lookup(tree, 20) == 0);
}

// 2. Add methods to in-order, pre-order, post-order and level-order traversals
void test_inorder() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    
    bst_inorder(tree);
}

void test_preorder() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    
    bst_preorder(tree);
}

void test_postorder() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    
    bst_postorder(tree);
}

void test_levelordertraversal() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    
    bst_levelordertraversal(tree);
}

// 3. Add method to find the height of binary search tree
void test_heightoftree() {
    BST tree1 = bst_new();
    BST *tree = &tree1;
    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);
    
    assert(bst_heightoftree(tree) == 5);
}

// 4. Add method to count the number of terminal nodes in BST
void test_numberOfTerminalnodes() {
    BST tree1 = bst_new();
    BST *tree = &tree1;

    tree = bst_add(tree, 10);
    tree = bst_add(tree, 5);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 3);
    tree = bst_add(tree, 6);

    assert(bst_noOfTerminalNodes(tree) == 3);

}

// 5. Add methods to find max and min element in BST
void test_min_max(){
    BST tree1 = bst_new();
    BST *tree = &tree1;

    
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 70);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 85);
    tree = bst_add(tree, 35);
    tree = bst_add(tree, 10);

    assert(bst_min_max(tree).min == 10 && bst_min_max(tree).max == 90);
}

// 6. Add method to display elements in ascending order
void test_bst_display_ascending(){
    BST tree1 = bst_new();
    BST *tree = &tree1;

    tree = bst_add(tree, 55);
    tree = bst_add(tree, 15);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 30);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 12);

    bst_display_ascending(tree);
}

// 7. Add method to display elements in descending order 
void test_bst_display_descending(){
    BST tree1 = bst_new();
    BST *tree = &tree1;

    tree = bst_add(tree, 55);
    tree = bst_add(tree, 15);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 30);
    tree = bst_add(tree, 25);
    tree = bst_add(tree, 12);

    bst_display_descending(tree);
}

int main(){

    test_new_add_delete_count_search();
    test_inorder(); 
    test_preorder();
    test_postorder();
    test_levelordertraversal();
    test_heightoftree();
    test_numberOfTerminalnodes();
    test_min_max();
    test_bst_display_ascending();
    test_bst_display_descending();

    return 0;
}
