#include<bits/stdc++.h>
using namespace std;
/*
	Treap = Tree + Heap
	Binary Search Tree: for values x
	Heap: for values y
*/
struct Node {
	int x, y;
	Node *izq, *der;
}

Node* find(Node *t, int x) {
	while(t && t->x != x) {
		if(t->x > x) { // Left part
			t = t->izq;
		} else {
			t = t->der;
		}
	}
	return t;
}

/* Merge: u and v, u <= v */
Node* merge(Node *A, Node *B) {
	if(!A) return B;
	if(!B) return A;
	if(A->y > B->y) {
		A->der = merge(A->der, B);
		return A;
	} else {
		B->izq = merge(A, B->izq);
		return B;
	}
}

/* Split: Xizq < X, X <= Xder */
