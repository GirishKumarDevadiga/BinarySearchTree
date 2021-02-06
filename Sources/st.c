#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "../Headers/bst.h"
#include "../../AdaptiveQueue/Headers/queue.h"

BST bst_new() {
    BST bst = {NULL, 0};
    return bst;
}

uint32_t bst_count(const BST *tree) {
    assert(tree != NULL);
    return tree->mass;
}

static TreeNode* _get_new_node_(int32_t ele){
    TreeNode *newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data = ele;
    newnode->left = NULL;
    newnode->right = NULL;
}

BST* bst_add(BST* tree, int32_t element){
    assert(tree != NULL);
    TreeNode *current, *parent;

    current = parent = tree->root;

    while(current != NULL && element != current ->data){
        parent = current;
        if(element < current->data){
            current = current->left;
        } else if (element > current->data) {
            current = current->right;
        }
    }

    if(current == NULL) {
        TreeNode *newnode = _get_new_node_(element);
        if(parent == NULL){
            tree->root = newnode;
        } else if(element < parent->data){
            parent->left = newnode;
        } else if (element > parent->data) {
            parent->right = newnode;
        }
        ++tree->mass;
    }
    return tree;
}

uint8_t bst_lookup(const BST *tree, int32_t key){
    assert(tree != NULL);
    TreeNode *current = tree->root;

    while(current != NULL & key != current->data){
        if(key < current->data){
            if(current->left != NULL){
              current = current->left;
            } else {
             return 0;    
            }
        } else if (key > current->data){
            if(current->right != NULL){
              current = current->right;
            } else {
              return 0;    
            }
        }
    }

    return (current != NULL);
}

static TreeNode* _findMax_(TreeNode *node){
    if(node->right == NULL){
        return node;
    } else {
        return (_findMax_(node->right));
    }
}

static TreeNode* _findMin_(TreeNode *node){
    if(node->left == NULL){
        return node;
    } else {
        return (_findMin_(node->left));
    }
}

static TreeNode* _delete_(BST *tree, TreeNode *node, int32_t element){
    TreeNode *temp;

    if(node == NULL){
        return node;
    } else if(element < node->data){
        node->left = _delete_(tree, node->left, element);
    } else if(element > node->data){
        node->right = _delete_(tree, node->right, element);
    } else if(node->left && node->right) {
        temp = _findMin_(node->right);
        node->data = temp->data;
        node->right = _delete_(tree, node->right, node->data);
    } else {
        temp = node;
        if(node->right == NULL){
            node = node->left;
        } else {
            node = node->right;
        }
        free(temp);
        --tree->mass;
    }
    return node;
}

BST* bst_delete(BST *tree, int32_t element){
    assert(tree != NULL);
    tree->root = _delete_(tree, tree->root, element);

    return tree;
}

static void _inorder_(TreeNode *node){
    if(node) {
       _inorder_(node->left);
       printf("%d\t", node->data);
       _inorder_(node->right);
    }  
}

void bst_inorder(BST *tree) {
    assert(tree != NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode *node){
    if(node) {
       printf("%d\t", node->data);
       _preorder_(node->left);
       _preorder_(node->right);
    }  
}

void bst_preorder(BST *tree) {
    assert(tree != NULL);
    _preorder_(tree->root);
}

static void _postorder_(TreeNode *node){
    if(node) {
       _postorder_(node->left);
       _postorder_(node->right);
       printf("%d\t", node->data);
    }  
}

void bst_postorder(BST *tree) {
    assert(tree != NULL);
    _postorder_(tree->root);
}

void bst_levelordertraversal(BST *tree){
    assert(tree != NULL);   
    Queue q1 = queue_new(tree->mass);
    Queue *q = &q1;
    QueueResult res;
    TreeNode *node = tree->root;
    queue_add(q, node, &res);
    
    while(!queue_empty(q)) {
         queue_delete(q, &res);
         node = (TreeNode*)res.data;
         if(node->left) {
            queue_add(q, node->left, &res);
        } 
         if(node->right){
            queue_add(q, node->right, &res);
         }   
         printf("%d\t", node->data);

  }
}


uint16_t bst_heightoftree(BST *tree){
    assert(tree != NULL);   
    Queue q1 = queue_new(tree->mass);
    Queue *q = &q1;
    QueueResult res;
    int32_t count1 = 0, count2 = 0;
    TreeNode *node = tree->root;
    queue_add(q, node, &res);
    
    while(!queue_empty(q)) {
         queue_delete(q, &res);
         node = (TreeNode*)res.data;
         if(node->left) {
            queue_add(q, node->left, &res);
            ++count1;
        } 
         if(node->right){
            queue_add(q, node->right, &res);
            ++count2;
         }  
  }
   
  if(count1 >= count2){
      return count1 + 1;
  } else {
      return count2 + 1;
  }
}

static uint32_t _terminalnode_(BST *tree){

    assert(tree != NULL);   
    Queue q1 = queue_new(tree->mass);
    Queue *q = &q1;
    QueueResult res;
    TreeNode *node = tree->root;
    queue_add(q, node, &res);
    
    while(!queue_empty(q)) {
         queue_delete(q, &res);
         node = (TreeNode*)res.data;
        if (node->left || node->right){
         if(node->left) {
            queue_add(q, node->left, &res);
        } 
         if(node->right){
            queue_add(q, node->right, &res);
         } 
        } else {
         ++tree->terminalnode_count;
         }  

  }
  return tree->terminalnode_count;

}

uint16_t bst_noOfTerminalNodes(BST *tree){
    assert(tree != NULL);
    int32_t count = 0;

    count = _terminalnode_(tree);

    return count;
}

Min_Max bst_min_max(BST *tree){
    Min_Max min_max;
    min_max.min = _findMin_(tree->root)->data;
    min_max.max = _findMax_(tree->root)->data;

    return min_max;
}

void bst_display_ascending(BST *tree){
    assert(tree != NULL);
    _inorder_(tree->root);

}

static void _bst_desc_(TreeNode *node){
    if(node) {
       _bst_desc_(node->right);
       printf("%d\t", node->data);
       _bst_desc_(node->left);
    }  
}

void bst_display_descending(BST* tree){
    assert(tree != NULL);
    _bst_desc_(tree->root);

}
