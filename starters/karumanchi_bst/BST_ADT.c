/**
* @file BST_ADT.c
*
* @version 1.0.0
* @author Julian Kosanovic (jkosa2@pdx.edu)
* @date   2-Dec-2024
*
* @brief
* Binary search tree abstract data type
*
* @details
* Revision History
* ----------------

*	1.0.0	(02-Dec-2024)	Initial version
*
* @note TODO
*/
#include "BST_ADT.h"

#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include "BST_ADT.h"

#include <math.h>
#include <stdio.h>
#include "../iom361_r2/iom361_r2.h"

struct BinaryTreeNode *root;

struct BinaryTreeNode* createNewBST(struct temp_humid_data *data) {
    struct BinaryTreeNode* new_bst_tree_node = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    new_bst_tree_node->data=data;
    new_bst_tree_node->left = NULL;
    new_bst_tree_node->right = NULL;
    return new_bst_tree_node;
}
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* root, struct temp_humid_data *data) {
    // insert(*data);
    if (root == NULL) {
        return createNewBST(data);
    }

    if (data->timestamp < root->data->timestamp) {
        root->left = insertNode(root->left, data);
    } else if (data->timestamp > root->data->timestamp) {
        root->right = insertNode(root->right, data);
    }

    return root;
}
struct BinaryTreeNode* searchBST(struct BinaryTreeNode* root, struct temp_humid_data *data) {
    // FIXME
    // struct BinaryTreeNode * temp = search(*data);
    // return temp;
    if (root == NULL || root->data->timestamp == data->timestamp) {
        return root;
    }
    // 86400

    if (data->timestamp < root->data->timestamp) { // FIXME is this the right logic?
        return searchBST(root->left, data);
    } else {
        return searchBST(root->right, data);
    }
}
// TODO perform in order traversal and display values in timestamp order. Use inOrder() from BinaryTree
void displayInOrder(struct BinaryTreeNode* root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%s", ctime(&root->data->timestamp)); // Print epoch time nicely for the humans
        displayInOrder(root->right);
    }
}

struct BinaryTreeNode* populateBST(int num_nodes) {
    int max_num = 1733011199;
    int min_num = 1730419200;
    uint32_t temp_value, humid_value;
    time_t test_time;
    uint32_t* io_base;
    int rtn_code;
    struct temp_humid_data *data = malloc(sizeof(struct temp_humid_data));
    struct temp_humid_data data_table[num_nodes];

    printf("Initializing registers\n");
    io_base = iom361_initialize(16, 16, &rtn_code);
    if (rtn_code != 0) { // Error checking
        printf("FATAL(main): Could not initialize I/O module\n"); // initialization failed
        return 1;
    }

    for (int i = 0; i < num_nodes; i++){ // Populate data
        test_time = generateRandomTimestamp(min_num, max_num); // Between Nov 1 00:00:00 2024 - Nov 30 23:59:59 2024
        printf("%s", ctime(&test_time)); // Print epoch time nicely for the humans
        _iom361_setSensor1_rndm(1.0, 9.0, 70.0,
        90.0);
        // temp_value = rand() % (9 + 1 - 1) + 1;
        temp_value = iom361_readReg(io_base, TEMP_REG, &rtn_code);
        temp_value = (temp_value / powf(2,20)) * 200.0 - 50;
        printf("Temperature %u\n", temp_value);
        if (rtn_code != 0) {
            printf("ERROR(main): Failed reading I/O register \n");
        }
        // humid_value = rand() % (90 + 1 - 70) + 70; //
        humid_value = iom361_readReg(io_base, HUMID_REG, &rtn_code);
        humid_value = (humid_value/ pow(2, 20)) * 100;
        printf("Humidity %u\n", humid_value);
        if (rtn_code != 0) {
            printf("ERROR(main): Failed reading I/O register\n");
        }
        data->humid = humid_value;
        data->temp = temp_value;
        data->timestamp = test_time;

        data_table[i] = *data;
    }
    root = insertNode(root, &data_table[0]);
    for (int i = 1; i < 10; i++) {
        insertNode(root, &data_table[i]);
    }
    return root;
    //free(data);
}

time_t generateRandomTimestamp(int min, int max) {
    // Test values
    // int max_num = 1733011199;
    // int min_num = 1730419200;
    time_t test_time = (time_t) rand() % (max + 1 - min) + min;
    return test_time;
}

int main() {
    // Compare node and BinaryTreeNode

    // Generate random times from Nov 1 00:00:00 2024 - Nov 30 23:59:59 2024
    // int max_num = 1733011199;
    // int min_num = 1730419200;
    // uint32_t temp_value, humid_value;
    // uint32_t temp, humid;
    int day, month, year;
    time_t user_time;
    struct tm user_date;
    time_t tts;
    // uint32_t* io_base;
    // int rtn_code;
    struct temp_humid_data *data = malloc(sizeof(struct temp_humid_data));
    // struct temp_humid_data data_table[10];
    // struct dateTime { // Inspired by datetime.datetime() from Python
    //     int year;
    //     int month;
    //     int day;
    //     int hour;
    //     int minute;
    //     int second;
    // } user_date;

    srand(time(NULL)); // randomize seed

    printf("Enter in a date (mm/dd/yyyy): ");
    // scanf("%d/%d/%d", &month, &day, &year);
    day = 30;
    month = 11;
    year = 2024;
    printf("\n");
    year = year - 1900;
    month = month - 1;
    // time_t user_date = ((time_t) year * 31540000 + (time_t) month * 2628288 + (time_t) day * 86400);
    // printf("%d", (int) user_date);
    user_date.tm_year = year;
    user_date.tm_mon = month;
    user_date.tm_mday = day;
    user_date.tm_hour = 0;
    user_date.tm_min = 0;
    user_date.tm_sec = 0;

    user_time = mktime(&user_date);

    data->humid = NULL;
    data->temp = NULL;
    // data->timestamp = (time_t) 1731715199;
    data->timestamp = user_time;

    // dateTimePtr_t create_date(int y, int mo, int d, int h, int mi, int s) {
    //     dateTimePtr_t x = malloc(sizeof(dateTime_t));
    //     x->year = y;
    //     x->month = mo;
    //     x->day = d;

    // Populate the BST with data
    root = populateBST(10);

    struct BinaryTreeNode * temp = searchBST(root, data);   // FIXME why does this break root??
    if(temp != NULL) {
        tts = temp->data->timestamp;
        printf(" %s Timestamp found.", ctime(&tts));
        printf("\n");
    } else {
        tts = data->timestamp;
        printf(" %s Timestamp not found \n\n", ctime(&tts));
    }
    displayInOrder(root);  // FIXME

    printf("\n");

    // free(test_time);
    // free(tempNode);
    free(temp);
    free(root);
    free(data);
}