#include <stdio.h>
#include <stdbool.h>

struct element {
    int num;        // 1~9: valid, 0: don't have value yet
    bool can_modify; // true: white area in the figure, false: gray area in the figure
};
void solve(struct element (*grid_p)[9]);
void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", grid_p[i][j].num);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, num assign 0
                grid[i][j].num = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].num = ch - '0';
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    print_grid(grid);
    return 0;
}
void solve(struct element (*grid_p)[9]) {
    int count=0;
    //printf("%d\n", (grid_p[3][2]).num);
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid_p[i][j].num!=0)
                break;
            else if(grid_p[i][j].num==0)
            {
                int setpoint=0;
                while(setpoint<9)//檢查小九宮格
                {
                    int setpoint2=0;
                    while(setpoint2<9)
                    {
                        for(int x=0;x<3;x++)
                        {
                            for(int y=0;y<3;y++)
                            {
                                if(grid_p[x+setpoint][y+setpoint2].num==num)
                                {
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        setpoint2+=3;
                    }
                    setpoint+=3;
                }//小九宮格的while
                for(int num=1;num<10;num++)
                {
                    int flag=1;
                    while(count<9)
                    {
                        for(int i=0;i<9;i++)  //檢查橫的
                        {
                            if(grid_p[count][i].num==num)
                            {
                                flag=0;
                                break;
                            }
                        }
                        for(int i=0;i<9;i++)  //檢查直的
                        {
                            if(grid_p[i][count].num==num)
                            {
                                flag=0;
                                break;
                            }
                        }
                        count++;
                    } //橫直的while
                    if(flag==1)
                        grid_p[i][j].num=num;
                }
            }
        }
    }
}
