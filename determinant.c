/* Matias Moseley     9/23/2022     CS 450     Assignment 1: Matrix Determinant */

#include<stdio.h>

int main() {
        double s = 1, result, determinant = 1;
        int n, m, h, i, k, w, j;

        scanf("%d", &n); // Matrix Size

        double matrix[n][n];
        double temp;

        for(m = 0; m<n; m++){ // Read in the Matrix
                for(h = 0; h<n; h++){
                        scanf("%lf", &matrix[m][h]); // Store input
                }
        }

        for(i = 0; i<n-1; i++){
                if(matrix[i][i] == 0){ // Row swap needed
                        for(m = i+1; m<n; m++){ // Check coloum for viable swap
                                if(matrix[m][i] != 0){
                                        s = -s; // Invert sign
                                        for(h=0; h<n; h++){ // Swap the rows here
                                                temp = matrix[m][h];
                                                matrix[m][h] = matrix[i][h];
                                                matrix[i][h] = temp;
                                        }
                                        break;
                                }
                        }
                }
                for(k = i+1; k<n; k++){ // Row Addition/Subtraction
                        result = matrix[k][i] / matrix[i][i]; // Find constant to multiply row k by
                        for(w = 0; w<n; w++){
                                matrix[k][w] -= (result*matrix[i][w]); // Multiply row k by row i * constant
                        }
                }
        }

        for(j = 0; j<n; j++){ // Calculate determinant by iterating over the diagonal
                determinant *= matrix[j][j];
        }

        printf("%lf", determinant*s); // Output determinant to STDOUT

        return 0;
}