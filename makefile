#Julian Kosanovic
#5-Dec-2024
#makefile for BST_ADT

HDRS = BST_ADT.h BinarySearchTree.h BinaryTree.h
OBJS = BST_ADT.o BinarySearchTree.o BinaryTree.o

BST_ADT: BinarySearchTree.o BinaryTree.o BST_ADT.o
	gcc -Wall -std=c99 -o BST_ADT.exe *.o
BST_ADT.o: BinaryTree.h BinarySearchTree.h BST_ADT.h
	gcc -Wall -std=c99 -c rpn_calculator.c
BinarySearchTree.o: BinaryTree.o BinarySearchTree.c BinarySearchTree.h
	gcc -Wall -std=c99 -c BinarySearchTree.c
BinaryTree.o: BinaryTree.c BinaryTree.h
	gcc -Wall -std=c99 -c SLinkedList.c
BST_ADT.o: BST_ADT.c BST_ADT.h
	gcc -Wall -std=c99 -c BST_ADT.c
clean:
	rm *.o *.exe

$(OBJS): $(HDRS)