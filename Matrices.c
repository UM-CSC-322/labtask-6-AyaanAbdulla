#include <stdio.h>
#include <stdlib.h>

double * input_matrix(int *rows, int *columns, char *name){
    printf("Enter rows and columns for %s\n", name);
    scanf("%d%d", rows, columns);
    double *m = (double *)malloc((*rows) * (*columns) * sizeof(double));
    printf("Enter elements for the matrix \n");
    for (int current_row=0; current_row< *rows; current_row++){
        for(int current_column = 0; current_column < *columns; current_column++){
            printf("Row %d, Column %d value: ", current_row, current_column);
            scanf("%lf", &m[current_row * (*columns) + current_column]);
        }
    }
    return m;
    
}

int matrix_multiply(double *m1, int m1_r, int m1_c, double *m2, int m2_r, int m2_c, double *m_out){
    
    if(m1_r != m2_r){
        return 0;
    }
    for(int i=0; i<m1_r; i++){ // indexing through m1 rows
        for(int j=0; j<m2_c; j++){ // indexing through m2 columns
            double sum =0;
            for(int x = 0; x<m2_r; x++){
                sum = sum + (m1[i* m1_c + x] * m2[x * m2_c + j]);
            }
            m_out[i * m2_c+j] = sum;
        }
    }
    
}

void output_matrix(double *matrix, int rows, int columns){
    for(int current_row = 0; current_row<rows;current_row++){
        for(int current_column = 0; current_column < columns; current_column++){
            printf("%lf ", matrix[current_row * columns+current_column]);
        }
        printf("\n");
    }
}

int main(void) {

    double *m1,*m2,*m3;
    int m1_rows,m1_columns,m2_rows,m2_columns;

    if (((m1 = input_matrix(&m1_rows,&m1_columns,"Matrix 1")) != NULL) &&
((m2 = input_matrix(&m2_rows,&m2_columns,"Matrix 2")) != NULL) &&
((m3 = malloc(m1_rows*m2_columns*sizeof(double))) != NULL)) {
        printf("Matrix 1\n");
        output_matrix(m1,m1_rows,m1_columns);
        printf("Matrix 2\n");
        output_matrix(m2,m2_rows,m2_columns);
        if (matrix_multiply(m1,m1_rows,m1_columns,m2,m2_rows,m2_columns,m3)) {
            printf("Product\n");
            output_matrix(m3,m1_rows,m2_columns);
            free(m1);
            free(m2);
            free(m3);
            return(0);
        } else {
            printf("Error in dimensions\n");
            free(m1);
            free(m2);
            free(m3);
            return(-1);
        }
    } else {
        free(m1);
        free(m2);
        free(m3);
        printf("Error allocating memory\n");
        return(-2);
    }
}
