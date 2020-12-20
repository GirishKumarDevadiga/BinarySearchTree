#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <stdint.h>

typedef struct _tree_node_ TreeNode;
struct _tree_node_ {
    int32_t data;
    TreeNode *left;
    TreeNode *right;
};

typedef struct  _bst_ BST;
struct _bst_{
    TreeNode *root;
    uint32_t mass;
    uint32_t terminalnode_count;
};

typedef struct _min_max Min_Max;
struct _min_max {
  int32_t min;
  int32_t max;
};

BST bst_new();
uint32_t bst_count(const BST *tree);
uint8_t bst_lookup(const BST *tree, int32_t key);
BST* bst_add(BST* tree, int32_t element);
BST* bst_delete(BST* tree, int32_t element);
void bst_inorder(BST *tree); //LPR
void bst_preorder(BST *tree);
void bst_postorder(BST *tree);
void bst_levelordertraversal(BST *tree);
uint16_t bst_heightoftree(BST *tree);
uint16_t bst_noOfTerminalNodes(BST *tree);
Min_Max bst_min_max(BST *tree);
void bst_display_ascending(BST *tree);
void bst_display_descending(BST *tree);

#endif // BST_H_INCLUDED
