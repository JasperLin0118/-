#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int check(char poker[]){
	char ranks[13]={'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
	int rc[13]={0};
	char suits[4]={'c', 'd', 'h', 's'};
	int sc[4]={0};
	bool flush = false;
	int rmax=0, smax=0, straight_first_rank, rmax_rank, rank_first_suit_amount;
	char straight_first, rank_first_suit;
	for(int i=0;i<15;i+=3)
	{
		for(int j=0;j<13;j++)
		{
			if (poker[i] == ranks[j])
				rc[j]+=1;
		}
	}
	for(int k=1;k<15;k+=3)
	{
		for(int l=0;l<4;l++)
		{
			if(poker[k]==suits[l])
			{
				sc[l]+=1;
				if(sc[l]==5)
				{
					flush=true;
					break;
				}	
			}
		}
	}
	bool straight=false;
	for(int m=0;m<9;m++)
	{
		int flag=0;
		for(int n=m;n<m+6;n++)
		{
			if(rc[n]==1)
				flag+=1;
			else
				break;
		}
		if(flag==5)
		{
			straight_first_rank=m-4;
			straight=true;
			break;
		}
	}
	if(flush==true)
	{
		if(straight==true) //同花順
		{
			char straight_first_suit;
			for(int q=0;q<15;q+=3)
			{
				if(poker[q]==ranks[straight_first_rank+4])
				{
					straight_first_suit=poker[q+1];
					break;
				}
			}
			int straight_first_suit_amount;
			for(int w=0;w<4;w++)
			{
				if(straight_first_suit==suits[w])
				{
					straight_first_suit_amount=w+1;
					break;
				}
			}
			return 9000+100*straight_first_rank+5*(straight_first_rank+4)+straight_first_suit_amount;
		}
		else //同花 
		{
			int card_max, card_max_suit_amount; char card_max_rank, card_max_suit;
			for(int e=12;e>=0;e--)
			{
				if(rc[e]==1)
				{
					card_max=e;
					break;
				}	
			}
			for(int r=0;r<15;r+=3)
			{
				if(poker[r]==ranks[card_max])
				{
					card_max_suit=poker[r+1];
					break;
				}
			}
			for(int t=0;t<4;t++)
			{
				if(suits[t]==card_max_suit)
				{
					card_max_suit_amount=t+1;
					break;
				}
			}
			return 6000+(card_max+2)*50+card_max_suit_amount;
		}
	}
	for(int y=0;y<13;y++)
	{
		if(rc[y]>rmax)
		{
			rmax=rc[y];
			rmax_rank=y;
		}
	}
	if(rmax==4) //鐵支 
		return 8000+50*rmax_rank;
	else if(rmax==3)
	{
		bool flag=false;
		for(int u=0;u<13;u++)
		{
			if(rc[u]==2)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)//葫蘆 
			return 7000+50*rmax_rank;
		else //三條 
			return 4000+50*rmax_rank;
	}
	else if(rmax==2)
	{
		int count=0, rank_max=0; char rank_first_suit2;
		for(int a=0;a<13;a++)
		{
			if(rc[a]==2)
				count+=1;
		}
		if(count==1) //一對 
		{
			for(int ba=12;ba>=0;ba--)
			{
				if(rc[ba]==2)
				{
					rank_max=ba;
					break;
				}
			}
			for(int az=0;az<15;az++)
			{
				if(ranks[rank_max]==poker[az])
					rank_first_suit=poker[az+1];
			}
			for(int ax=0;ax<4;ax++)
			{
				if(rank_first_suit==suits[ax])
					rank_first_suit_amount=ax+1;
			}
			return 2000+rank_max*50+rank_first_suit_amount;
		}
		if(count==2) //兩對
		{
			for(int bb=12;bb>=0;bb--)
			{
				if(rc[bb]==2)
				{
					rank_max=bb;
					break;
				}
			}
			for(int z=0;z<15;z+=3)
			{
				if(ranks[rank_max]==poker[z])
					rank_first_suit=poker[z+1];
			}
			for(int v=12;v>=0;v-=3)
			{
				if(ranks[rank_max]==poker[v])
					rank_first_suit2=poker[v+1];
			}
			if(rank_first_suit2>rank_first_suit)
				rank_first_suit=rank_first_suit2;
			for(int x=0;x<4;x++)
			{
				if(rank_first_suit==suits[x])
					rank_first_suit_amount=x+1;
			}
			return 3000+rank_max*50+rank_first_suit_amount;
		}
	}
	int high, high_suit_amount; char high_suit;
	for(int ad=12;ad>=0;ad--)  //烏龍&順子 
	{
		if(rc[ad]!=0)
		{
			high=ad;
			break;
		}
	}
	for(int ae=0;ae<15;ae+=3)
	{
		if(ranks[high]==poker[ae])
			high_suit=poker[ae+1];
	}
	for(int af=0;af<4;af++)
	{
		if(suits[af]==high_suit)
			high_suit_amount=af+1;
	}
	return 1000+(high+2)*50+high_suit_amount;
}

int check(char before[]);
int main()
{
	char poker[4][15], people[4]={'A', 'B', 'C', 'D'}; int sorting[4][2], flag1, flag2;
	for(int i=0;i<4;i++)
    {
		for(int ai=0;ai<15;ai++)
			scanf("%c", &poker[i][ai]);
    }       
	for(int n1=0;n1<4;n1++)
	{
			sorting[n1][0]=n1;
			sorting[n1][1]=check(poker[n1]);
	}
	for(int ind=0;ind<3;ind++)
	{
		for(int aj=0;aj<4-ind-1;aj++)
		{
			if(sorting[aj][1]>sorting[aj+1][1])
			{
				flag1=sorting[aj][1];
				sorting[aj][1]=sorting[aj+1][1];
				sorting[aj+1][1]=flag1;
				flag2=sorting[aj][0];
				sorting[aj][0]=sorting[aj+1][0];
				sorting[aj+1][0]=flag2;
			}
		}
	}
	for(int ah=3;ah>=0;ah--)
		printf("%c ", people[sorting[ah][0]]);
}
