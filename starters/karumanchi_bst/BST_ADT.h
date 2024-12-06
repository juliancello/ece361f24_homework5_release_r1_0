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
* @note TODO
*/

#ifndef BST_ADT_H
#define BST_ADT_H

#include <time.h>
#include <stdint.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

// TODO data types
struct temp_humid_data {
    time_t timestamp;
    uint32_t humid;
    uint32_t temp;
};

// Just use BST data type and translate into BT data type when necessary

// API function prototypes
// TODO create new BST
/**
 * @brief TODO
 * @param TODO
 * @return TODO
 *
 * @details
 * TODO
 */
struct BinaryTreeNode* createNewBST(struct temp_humid_data *data);
// TODO Insert node into BST
/**
 * @brief TODO
 * @param TODO
 * @return TODO
 *
 * @details
 * TODO
 */
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* root, struct temp_humid_data *data);
// TODO search BST, retrieve and return data
/**
 * @brief TODO
 * @param TODO
 * @return TODO
 *
 * @details
 * TODO
 */
struct BinaryTreeNode* searchBST(struct BinaryTreeNode* root, struct temp_humid_data *data);
// TODO perform in order traversal and display values in timestamp order
/**
 * @brief TODO
 * @param data int
 * @return	struct node*
 *
 * @details
 * TODO
 */
void displayInOrder(struct BinaryTreeNode* root);
struct BinaryTreeNode* populateBST(int num_nodes);
time_t generateRandomTimestamp(int min, int max);

#endif //BST_ADT_H
