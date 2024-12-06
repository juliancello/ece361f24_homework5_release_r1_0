/*Copyright (c) 2016 CareerMonk Publications and others.
#E-Mail            : info@careermonk.com
#Creation Date     : Unknown
#Created by        : Narasimha Karumanchi
#Book Title        : Data Structures And Algorithms Made Easy
#Warranty          : This software is provided "as is" without any
#                    warranty; without even the implied warranty of
#                    merchantability or fitness for a particular purpose.*/

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "BinaryTree.h"
#include "BST_ADT.h"

struct BinaryTreeNode *root = NULL;

void insert(struct temp_humid_data data) {
   struct BinaryTreeNode *tempNode = malloc(sizeof(struct BinaryTreeNode));
   struct BinaryTreeNode *current;
   struct BinaryTreeNode *parent;

   tempNode->data = &data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //go to left of the tree
         if(data.timestamp < parent->data->timestamp) { // FIXME?
            current = current->left;
            
            //insert to the left
            if(current == NULL) {
               parent->left = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->right;

            //insert to the right
            if(current == NULL) {
               parent->right = tempNode;
               return;
            }
         }
      }            
   }
}

struct BinaryTreeNode* search(struct temp_humid_data data) { // FIXME Works with direct call but not searchBST
   printf("\n");
   struct BinaryTreeNode *current = root;
   printf("Visiting elements: ");

   while(current->data->timestamp != data.timestamp) {
      if(current != NULL)
         printf("%d ",(int) current->data->timestamp);

	  // data @ current node > data we are looking for
	  // so we need to traverse the path where data < data current node
      //go to left tree
      if(current->data->timestamp > data.timestamp) {
         current = current->left;
      }
      //else go to right tree
      else {                
         current = current->right;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}



int main2() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   // for(i = 0; i < 7; i++)
   //    insert(array[i]);
   //
   // i = 31;
   // struct BinaryTreeNode * temp = search(i);
   //
   // if(temp != NULL) {
   //    printf("[%d] Element found.", temp->data);
   //    printf("\n");
   // }else {
   //    printf("[ x ] Element not found (%d).\n", i);
   // }
   //
   // i = 15;
   // temp = search(i);
   //
   // if(temp != NULL) {
   //    printf("[%d] Element found.", temp->data);
   //    printf("\n");
   // }else {
   //    printf("[ x ] Element not found (%d).\n", i);
   // }
      
   return 0;
}

/*
If we compile and run the above program, it will produce the following result −

Output
Visiting elements: 27 35 [31] Element found.
Visiting elements: 27 14 19 [ x ] Element not found (15).

*/