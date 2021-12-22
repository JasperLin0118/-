#include <stdio.h>
#define M 5
#define N 8
char colors[4] = {'R', 'G', 'B', 'X'};   // Red, Green, Blue, Empty

void spread(char*, int, int);

int main(void) {
    char graph[M][N];
    int row, col;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            scanf("%c", &graph[i][j]);
        getchar();      // Ignore '\n'
    }
    scanf("%d %d", &row, &col);    // Starting position
    
    spread(&graph[0][0], row, col);
    // Print out the spreading result
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++)
            printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
void spread(char* graph, int row, int col)
{
    char start=*(graph+row*N+col);
    for(int i=col;i<8;i++) //front
    {
        if(*(graph+row*N+i)=='X' ||*(graph+row*N+i)==start)
            *(graph+row*N+i)=start;
        else
            break;
    }
    for(int j=0;j<=col;j++) // back
    {
        if(*(graph+row*N+col-j)=='X' ||*(graph+row*N+col-j)==start)
            *(graph+row*N+col-j)=start;
        else
            break;
    }
    for(int k=row;k<M;k++)// down
    {
        if(*(graph+col+k*N)=='X' ||*(graph+col+k*N)==start)
            *(graph+col+k*N)=start;
        else
            break;
    }
    for(int l=0;l<=row;l++)//up
    {
        if(*(graph+row*N+col-N*l)=='X' ||*(graph+row*N+col-N*l)==start)
            *(graph+row*N+col-N*l)=start;
        else
            break;
    }
}
