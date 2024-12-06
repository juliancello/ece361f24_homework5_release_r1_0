/**
* @file BinarySearchTree.h
*
* @version 1.0.0
* @author Julian Kosanovic (jkosa2@pdx.edu)
* @date   2-Dec-2024
*
* @brief
* Binary search tree header file
*
* @details
* Revision History
* ----------------

*	1.0.0	(02-Dec-2024)	Initial version
*
* @note Header file for Karumanchi's BinarySearchTree.c
*/


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryTree.h"

// struct BinaryTreeNode { // TODO deprecate
//     int data;
//     struct BinaryTreeNode *leftChild;
//     struct BinaryTreeNode *rightChild;
// };

/**
* @brief TODO
* @param data int
* @return	void
*
* @details
* TODO
*/
void insert(struct temp_humid_data data);

/**
* @brief TODO
* @param data int
* @return	struct BinaryTreeNode*
*
* @details
* TODO
*/
struct BinaryTreeNode* search(struct temp_humid_data data);

#endif //BINARYSEARCHTREE_H
