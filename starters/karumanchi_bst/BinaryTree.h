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

struct BinaryTreeNode* createNewNode(int data);
void inOrder(struct BinaryTreeNode* root);
void preOrder(struct BinaryTreeNode* root);
void postOrder(struct BinaryTreeNode* root);

#endif //BINARYTREE_H
