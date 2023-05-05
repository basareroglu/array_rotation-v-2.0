#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxN 30

void file_read(int table[maxN][maxN], int nr[2], int nc[2]);
void printing_matrix(int table[maxN][maxN]);
void calculation(int table[maxN][maxN], int nr[2], int nc[2]);

int main() {
    int table[maxN][maxN], nr[2]={0}, nc[2]={0};
    file_read(table, nr, nc);
    printing_matrix(table);
    calculation(table, nr, nc);

    return 0;
}
void calculation(int table[maxN][maxN], int nr[2], int nc[2]){
    int flag_circut=0, index, location, table1[nr[0]][nc[0]],flag1=0;
    char selector[10], direction[10], end[10]={"end"}, row[4]={"row"}, column[10]= {"column"}, right[6]={"right"}, left[10]={"left"}, up[10]={"up"}, down[10]={"down"};
    printf("Welcome!\nType row or column to pick one of them at the selector part. If you type end, the code will end itself.\nEnter your selected parts index at index part.\nYou can only type 4 general way at direction part.\nAt last, you can specify how many square you are planning to move your matrix at the final part.\n");
    for (int c=0;c<nr[0];c++){
        for (int m=0;m<nc[0];m++){
            table1[c][m]=0;
            table1[c][m]=table[c][m];
        }
    }
    while (flag_circut==0){
        printf("Enter the requested information in order: <selector> <index> <direction> <locations>\n");
        scanf("%s %d %s %d", &selector, &index, &direction, &location);
        index-=1;
        //to show the matrix clearly
        printf("Table1:\n");
        for (int d = 0; d<nr[0]; d++){
            for (int r=0; r<nc[0]; r++){
                printf("%d ", table1[d][r]);

            }
            printf("\n");
        }

        if ((strcasecmp(row, selector))==0){
            if ((strcasecmp(right, direction))==0) {
                for (int b = 0; b < nc[0]; b++) {
                    if ((b+location)<nc[0] && flag1==0) {
                        table1[index][b + location] = table[index][b];
                    }
                    else{
                        if (flag1==0) {
                            location = -b;
                        }
                        flag1=1;
                        table1[index][b+location] = table[index][b];
                    }
                }
                flag1 =0;
            }
            else if ((strcasecmp(left, direction))==0) {

                for (int b = 0; b < nc[0]; b++) {
                    if ((b+nc[0]-location)<nc[0] && flag1==0) {
                        table1[index][nc[0]-location+b] = table[index][b];
                    }
                    else{
                        if (flag1==0) {
                            location = -b;
                        }
                        flag1=1;
                        table1[index][b+location] = table[index][b];
                    }
                }
                flag1=0;
            }
        }
        else if ((strcasecmp(column, selector))==0){
            if ((strcasecmp(up, direction))==0) {
                for (int b = 0; b < nr[0]; b++) {
                    if ((b+nr[0]-location)<nr[0] && flag1==0) {
                        table1[b+nr[0]-location][index] = table[b][index];
                    }
                    else{
                        if (flag1==0){
                            location = -b;
                        }
                        flag1=1;
                        table1[b+location][index] = table[b][index];
                    }
                }
                flag1=0;
            }
            else if ((strcasecmp(down, direction))==0) {
                for (int b = 0; b < nr[0]; b++) {
                    if ((b+location)<nr[0] && flag1==0) {
                        table1[b+location][index] = table[b][index];
                    }
                    else{
                        if (flag1==0) {
                            location = -b;
                        }
                        flag1=1;
                        table1[b+location][index] = table[b][index];
                    }
                }
                flag1=0;
            }

        }
        else if ((strcasecmp(end, selector))==0){
            //flag_circut=1;
            exit(0);
        }
        for (int d = 0; d<nr[0]; d++){
            for (int r=0; r<nc[0]; r++){
                table[d][r] = table1[d][r];
            }
        }
        //printing_matrix(table1); I don't know why, it prints random numbers
        for (int d = 0; d<nr[0]; d++){
            for (int r=0; r<nc[0]; r++){
                printf("%d ", table1[d][r]);

            }
            printf("\n");
        }

    }
}

void file_read(int table[maxN][maxN], int nr[2], int nc[2]){
    char file_name[20];
    printf("Enter the name of the file:\n");
    scanf("%s", &file_name);
    FILE *fp;
    if ((fp= fopen(file_name, "r"))==NULL){
        printf("Invalid file");
        exit(0);
    }
    fscanf(fp, "%d %d", &nr[0], &nc[0]);
    while (!feof(fp)){
        for (int i=0; i<nr[0]; i++){
            for (int j=0; j<nc[0]; j++){
                fscanf(fp, "%d", &table[i][j]);
            }
        }
    }
}

void printing_matrix(int table[maxN][maxN]){
    for (int x=0;x<3;x++){
        for (int z=0;z<3;z++){
            printf("%d ", table[x][z]);
        }
        printf("\n");
    }
}
