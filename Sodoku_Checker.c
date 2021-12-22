#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}

void check_sudoku(int (*grid_p)[NUM])
{
    int ans[NUM][NUM]={0};
    int count=0;
    while(count<9)
    {
        int check[9]={0};
        for(int i=0;i<9;i++)  //檢查橫的
        {
            for(int j=1;j<10;j++)
            {
                if(*(grid_p[count]+i)==j)
                    check[j-1]+=1;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(check[i]>1)
            {
                for(int j=0;j<9;j++)
                {
                    if(*(grid_p[count]+j)==i+1)
                        ans[count][j]=1;
                }
            }
        }
        int check2[9]={0};
        for(int i=0;i<9;i++)  //檢查直的
        {
            for(int j=1;j<10;j++)
            {
                if(*(grid_p[i]+count)==j)
                    check2[j-1]+=1;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(check2[i]>1)
            {
                for(int j=0;j<9;j++)
                {
                    if(*(grid_p[j]+count)==i+1)
                        ans[j][count]=1;
                }
            }
        }
        count++;
    }
    int setpoint=0;
    while(setpoint<9)//檢查小九宮格
    {
        int setpoint2=0;
        while(setpoint2<9)
        {
            int check3[9]={0};
            for(int x=0;x<3;x++)
            {
                for(int y=0;y<3;y++)
                {
                    for(int f=1;f<10;f++)
                    {
                        if(*(grid_p[x+setpoint]+y+setpoint2)==f)
                            check3[f-1]+=1;
                    }
                }
            }
            for(int i=0;i<9;i++)
            {
                if(check3[i]>1)
                {
                    for(int x1=0;x1<3;x1++)
                    {
                        for(int y1=0;y1<3;y1++)
                        {
                            if(*(grid_p[x1+setpoint]+y1+setpoint2)==i+1)
                                ans[x1+setpoint][y1+setpoint2]=1;
                        }
                    }
                }
            }
            setpoint2+=3;
        }
        setpoint+=3;
    }
    for(int i=0;i<NUM;i++)
    {
        for(int j=0;j<NUM;j++)
        {
            if(ans[i][j]==1)
                printf("(%d,%d)\n", i, j);
        }
    }
}
