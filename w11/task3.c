#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// with the helper tables, we can see the length of the respective parts of a potential plus
// after we filled all helper tables, which takes 2*x*y times, we simply need to find the largest entry with indetical indices of all tables which 
// takes x*y time
// filling the tables can be done analogous to the exericse where we needed to find the longest path
// we dont want unnecessary copy of parameters, since they are read only
// computes the correct entry according to the direction
void entry(int** table,int i,int j,int rows, int cols, int direction){
    if(table[i][j] != 0){
        // top 
        if(direction == 0 && i-1 < 0){
            table[i][j] += table[i-1][j];
        }
        else if (direction == 1 && j-1 < 0){
            table[i][j] += table[i][j-1];
        }
        else if (direction == 2 && i+1 < rows){
            table[i][j] += table[i+1][j];
        }
        else if (direction == 3 && j+1 < cols){
            table[i][j] += table[i][j+1];
        }
        else {
            table[i][j] = 1;
        }
        // else the entry i,j is the the edge so its simply 1
    }
}

// counts the height of each col including the cell i,j for i is row and j is col
// because of the order of iteration, direction must be 0 or 1
int*** helper_tables(int** table, int rows, int cols){
    int** top = malloc(sizeof(int*)*rows);
    int** left = malloc(sizeof(int*)*rows);
    int** right = malloc(sizeof(int*)*rows);
    int** bottom = malloc(sizeof(int*)*rows);

    int*** res = malloc(sizeof(int**)*4);
    res[0] = top;
    res[1] = left;
    res[2] = right;
    res[3] = bottom;

    // initializing with 0
    for(int i = 0; i < rows; i++){
        int* col = malloc(sizeof(int)*cols);
        for(int j = 0; j < cols; j++){
            top[i] = col;
            left[i] = col;
            right[i] = col;
            bottom[i] = col;
        }
    }
    //now computing the length for the top and left table, these can be done in the same go 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            entry(top,i,j,rows,cols,0);
            entry(left,i,j,rows,cols,1);
        }
    }


    // now right and bottom
    for(int i = rows-1; i>=0 ; --i){
        for(int j = cols-1; j >=0; --j){
            entry(right,i,j,rows,cols,3);
            entry(bottom,i,j,rows,cols,2);
        }
    }

    return res;
}

//where tables are the 4 helper tables
int* findPlus(int*** tables, int rows, int cols){

    int* indices = malloc(sizeof(int)*2);
    indices[0] = 0;
    indices[0] = 0;
    int max = 0;
    bool same = true;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            for(int k = 1; k < 4; k++){
                if(tables[k-1][i][j] != tables[k][i][j]){
                    same = false;
                    break;
                }
                

            }
            // since all k are equal we simply check with k=0
            if(same && tables[0][i][j] >= max){
                indices[0] = i;
                indices[1] = j;
                max = tables[0][i][j];
            }

        }
    }
}

int main(){


    return 0;
}