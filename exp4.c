// Aim: To implement Huffman Coding and analyze its time complexity. 

#include <stdio.h> 
#include <stdlib.h> 
 
typedef struct Node { 
    char ch; 
    int f; 
    struct Node *l, *r; 
} Node; 
 
/* Create a new node */ 
Node* createNode(char c, int x) { 
    Node* node = (Node*)malloc(sizeof(Node)); 
 
    node->ch = c; 
    node->f = x; 
    node->l = NULL; 
    node->r = NULL; 
 
    return node; 
} 
 
/* Swap two Node pointers */ 
void swap(Node** a, Node** b) { 
    Node* temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
 
 
/* Min-heap functions */ 
void heapify(Node* heap[], int n, int i) { 
    int smallest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
 
    if (left < n && heap[left]->f < heap[smallest]->f) 
        smallest = left; 
 
    if (right < n && heap[right]->f < heap[smallest]->f) 
        smallest = right; 
 
    if (smallest != i) { 
        swap(&heap[i], &heap[smallest]); 
        heapify(heap, n, smallest); 
    } 
} 
 
/* Insert node into min-heap */ 
void push(Node* heap[], int* n, Node* node) { 
    int i = *n; 
    heap[i] = node; 
    (*n)++; 
 
    while (i > 0) { 
        int parent = (i - 1) / 2; 
 
        if (heap[parent]->f <= heap[i]->f) 
            break; 
 
        swap(&heap[parent], &heap[i]); 
        i = parent; 
    } 
} 
 
/* Remove minimum-frequency node */ 
Node* pop(Node* heap[], int* n) { 
    Node* result = heap[0]; 
 
    (*n)--; 
    heap[0] = heap[*n]; 
 
    heapify(heap, *n, 0); 
 
    return result; 
} 
 
/* Print Huffman codes */ 
void print(Node* root, char code[], int depth) { 
    if (root == NULL) 
        return; 
 
    /* Leaf node */ 
    if (root->l == NULL && root->r == NULL) { 
        code[depth] = '\0'; 
        printf("%c : %s\n", root->ch, code); 
        return; 
    } 
 
 
    /* Left = 0 */ 
    code[depth] = '0'; 
    print(root->l, code, depth + 1); 
 
    /* Right = 1 */ 
    code[depth] = '1'; 
    print(root->r, code, depth + 1); 
} 
 
int main() { 
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'}; 
    int f[] = {5, 9, 12, 13, 16, 45}; 
 
    Node* heap[100]; 
    int n = 0; 
 
    /* Insert all characters into the min-heap */ 
    for (int i = 0; i < 6; i++) { 
        push(heap, &n, createNode(ch[i], f[i])); 
    } 
 
    /* Build Huffman Tree */ 
    while (n > 1) { 
        Node* a = pop(heap, &n); 
        Node* b = pop(heap, &n); 
 
        Node* p = createNode('$', a->f + b->f); 
 
        p->l = a; 
        p->r = b; 
 
        push(heap, &n, p); 
    } 
 
    /* Generate Huffman codes */ 
    char code[100]; 
 
    printf("Huffman Codes:\n"); 
    print(heap[0], code, 0); 
 
    return 0; 
}
