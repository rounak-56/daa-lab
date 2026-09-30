// Aim: To implement Strassen's Matrix Multiplication and analyse its time complexity. 

#include <stdio.h> 

void add(int A[4][4], int B[4][4], int C[4][4], int n) { 
    int i, j; 
    for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++) 
    C[i][j] = A[i][j] + B[i][j]; 
} 
 
void sub(int A[4][4], int B[4][4], int C[4][4], int n) { 
    int i, j; 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            C[i][j] = A[i][j] - B[i][j]; 
} 
 
void strassen(int A[4][4], int B[4][4], int C[4][4], int n) { 
    int i, j; 
    int m = n / 2; 
 
    int P[7][4][4] = {0}; 
    int X[4][4] = {0}; 
    int Y[4][4] = {0}; 
 
    int A11[4][4] = {0}, A12[4][4] = {0}; 
    int A21[4][4] = {0}, A22[4][4] = {0}; 
 
    int B11[4][4] = {0}, B12[4][4] = {0}; 
    int B21[4][4] = {0}, B22[4][4] = {0}; 
 
    if (n == 1) { 
        C[0][0] = A[0][0] * B[0][0]; 
        return; 
    } 
 
    /* Divide matrices into submatrices */ 
    for (i = 0; i < m; i++) { 
        for (j = 0; j < m; j++) { 
            A11[i][j] = A[i][j]; 
            A12[i][j] = A[i][j + m]; 
            A21[i][j] = A[i + m][j]; 
            A22[i][j] = A[i + m][j + m]; 
 
            B11[i][j] = B[i][j]; 
            B12[i][j] = B[i][j + m]; 
            B21[i][j] = B[i + m][j]; 
            B22[i][j] = B[i + m][j + m]; 
        } 
    } 
 
    /* P1 = (A11 + A22)(B11 + B22) */ 
    add(A11, A22, X, m); 
    add(B11, B22, Y, m); 
    strassen(X, Y, P[0], m); 
 
    /* P2 = (A21 + A22)B11 */ 
    add(A21, A22, X, m); 
    strassen(X, B11, P[1], m); 
 
    /* P3 = A11(B12 - B22) */ 
    sub(B12, B22, Y, m); 
    strassen(A11, Y, P[2], m); 
 
    /* P4 = A22(B21 - B11) */ 
    sub(B21, B11, Y, m); 
    strassen(A22, Y, P[3], m); 
 
    /* P5 = (A11 + A12)B22 */ 
    add(A11, A12, X, m); 
    strassen(X, B22, P[4], m); 
 
    /* P6 = (A21 - A11)(B11 + B12) */ 
    sub(A21, A11, X, m); 
    add(B11, B12, Y, m); 
    strassen(X, Y, P[5], m); 
 
    /* P7 = (A12 - A22)(B21 + B22) */ 
    sub(A12, A22, X, m); 
    add(B21, B22, Y, m); 
    strassen(X, Y, P[6], m); 
 
    /* Combine the results */ 
    for (i = 0; i < m; i++) { 
        for (j = 0; j < m; j++) { 
            C[i][j] = 
                P[0][i][j] + P[3][i][j] 
                - P[4][i][j] + P[6][i][j]; 
 
            C[i][j + m] = 
                P[2][i][j] + P[4][i][j]; 
 
            C[i + m][j] = 
                P[1][i][j] + P[3][i][j]; 
 
            C[i + m][j + m] = 
                P[0][i][j] - P[1][i][j] 
                + P[2][i][j] + P[5][i][j]; 
        } 
    } 
} 
 
int main() { 
    int A[4][4] = { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
    }; 
 
    int B[4][4] = { 
        {1, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 1} 
    }; 
 
    int C[4][4] = {0}; 
 
    strassen(A, B, C, 4); 
 
    printf("Result Matrix:\n"); 
 
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4; j++) { 
            printf("%d ", C[i][j]); 
        } 
        printf("\n"); 
    } 
 
    return 0; 
}
