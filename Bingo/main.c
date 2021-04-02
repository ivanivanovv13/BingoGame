#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <unistd.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void clrscr()
{
    system("@cls||clear");
}
void inputRandomNumbers(int a[10][10])
{
	int i,j,flag,num,p,f;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
         	do
	           {
		          num=rand()%100+1; flag=1;

		             for(p=0; p<10 ; p++)
		                {
                          for(f=0;f<10 ;f++)
		                   {
                            if(a[p][f]==num){
                            	 flag=0;
							}

		                   }
                        }
                	} while (flag != 1);
			a[i][j]=num;
		}
	}

}

void inputNumber(int a[10][10],int n,char b[10][10])
{
	int i,j;
	for(i=0; i<10; i++) {
      for(j=0;j<10;j++) {
         if(n==a[i][j]) {b[i][j]=a[i][j];}
         }
      }
      printMatrix(b);
}

void printMatrix(char a[10][10])
{
	clrscr();
	int i,j;
	for(i=0; i<10; i++) {
      for(j=0;j<10;j++) {
      	if(a[i][j]=='*'){ printf("%c   ",a[i][j]); }
        else if (a[i][j]<10) printf("%d   ",(int)a[i][j]);
        else if (a[i][j]>10 && a[i][j]<99) printf("%d  ",(int)a[i][j]);
        else printf("%d ",(int)a[i][j]);
         }
         printf("\n");
      }
}

int checkDiagonals(char a[10][10])
{
	int i,j,num;
	num=0;
	for(i=0; i<10; i++) {
      for(j=0;j<10;j++) {
         if(i==j && a[i][j] != '*') {num++;}
         }
      }
      if(num>=10){return 1; }

}

int checkSecondaryDiagonal(char a[10][10])
{
	int i,j,num;
	num=0;
	for(i=0; i<10; i++) {
      for(j=0;j<10;j++) {
         if((i+j)==9 && a[i][j] != '*') {num++;}
         }
      }
      if(num>=10){return 1; }

}

int checkRows(char a[10][10])
{
	int rows,columns,br=0;
	for(rows = 0; rows < 10; rows++)
    {
        for(columns = 0; columns < 10; columns++)
        {
            if(a[rows][columns] != '*' ) {br++;}
        }
       if(br==10) return 1;
       else br=0;
    }
    return 0;
}

int checkCol(char a[10][10])
{
	int rows,columns,br=0;
	 for(columns = 0; columns < 10; columns++)
    {
        for( rows = 0; rows < 10; rows++)
        {
            if(a[rows][columns] != '*' ) {br++;}
        }
        if(br==10) return 1;
       else br=0;
    }
}

int main(int argc, char *argv[]) {
	int a[10][10]; int i,j,p,f;
	char b[10][10];
	printf("Play the Game of Bingo.\n");
	printf("Find numbers in one diagonal ,column or row and win. (Press Enter to play )  \n");
	getchar();
	for( p=0;p<10;p++)
	{
		for( f=0;f<10;f++)
		{
			b[p][f]='*';
		}
	}
	inputRandomNumbers(a);

	 while(1)
	 {
	 	printf("Insert number from 1 to 100:");
	 	scanf("%d",&j);
	 	inputNumber(a,j,b);
	 	if(checkDiagonals(b)==1) {  printf("You Win"); break; }
	 	if(checkSecondaryDiagonal(b)==1) {  printf("You Win"); break; }
		if(checkRows(b)==1) {  printf("You Win"); break; }
		if(checkCol(b)==1) {  printf("You Win"); break; }
	 }

	return 0;
}

/*for(i=0; i<10; i++) {
         for(j=0;j<10;j++) {
         printf("%d ",(int)a[i][j]);
         }
         printf("\n");
      }
      */

