/**
* @file BST_ADT.h
*
* @version 1.0.0
* @author Julian Kosanovic (jkosa2@pdx.edu)
* @date   2-Dec-2024
*
* @brief
* Binary search tree abstract data type header file.
*
* @details
* Revision History
* ----------------

*	1.0.0	(02-Dec-2024)	Initial version
*
* @note Header file for Karumanchi's BinaryTree.c
*/

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BST_ADT.h"

struct BinaryTreeNode{
    struct temp_humid_data *data;  // TODO refactor all usages
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

/**
* @brief TODO
* @param data int
* @return	struct BinaryTreeNode*
*
* @details
* TODO
*/
struct BinaryTreeNode* createNewNode(int data);

/**
* @brief TODO
* @param root struct BinaryTreeNode*
* @return	void
*
* @details
* TODO
*/
void inOrder(struct BinaryTreeNode* root);

/**
* @brief TODO
* @param root struct BinaryTreeNode*
* @return	void
*
* @details
* TODO
*/
void preOrder(struct BinaryTreeNode* root);

/**
* @brief TODO
* @param root struct BinaryTreeNode*
* @return	void
*
* @details
* TODO
*/
void postOrder(struct BinaryTreeNode* root);

#endif //BINARYTREE_H
