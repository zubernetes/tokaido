// node.h
//
// A basic Node implementation. 
// 2016 (c) zubernetes
#ifndef NODE_H
#define NODE_H

struct Node {
	int key;
	Node *left;
	Node *right;
	Node *parent;
};

#endif 
