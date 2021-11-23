
#include<stdio.h>
#include<stdlib.h>

char matrix[10];
int f,u;
char turn;

void display()
{   int point,i,row=3,j;
    point=0;
   
    printf("\n\t\t-------------\n");
    for(i=0;i<row;i++)
    {   printf("\t\t| ");
        for(j=0;j<row;j++)
        {
            printf("%c ",matrix[point++]);
            if(j!=row-1)
             printf("| ");
        }
        printf("|\n\t\t-------------\n");       
    }
}


void userInput(int k)
{   
    user:
    printf("\nYour Turn     - ");
    char index;
    int i,j;
    printf("%c",(k%2==0? 'X':'O'));
    printf(" :");
    scanf("%c",&index);
    i = index-48;
    if(!(index>='1' && index<='9') || (matrix[i-1]=='X' || matrix[i-1]=='O') )
    {   
        display();
        printf("\nAlready occupied. Choose someother value !\n");    
        goto user;
    }
    if(k%2 == 0)
        matrix[i-1]='X';
    else
        matrix[i-1]='O';     
    f++;   
}
char checkWin()
{   
    int i,j;
    for(i=0;i<9;i=i+3)
    { 
        if(matrix[i]==matrix[i+1] && matrix[i]==matrix[i+2])
            return matrix[i];
    }
    for(i=0;i<3;i++)
    {
        if(matrix[i]==matrix[i+3] && matrix[i]==matrix[i+6])
            return matrix[i];
    }

    if( matrix[0]==matrix[4] && matrix[0]==matrix[8])
        return matrix[i];
    if(matrix[2]==matrix[4] && matrix[2]==matrix[6])
        return matrix[i];

    return 'n';  
}

void compInput(int k)
{   
    printf("\nComputer Turn - ");
    printf("%c",(k%2==0? 'X':'O'));
    printf(" :\n");
    int i;
    computer:
    i=(rand() % 9) +1 ;
    if(matrix[i-1]=='X' || matrix[i-1] =='O')
        goto computer;
    if(k%2==0)
        matrix[i-1]='X';
    else
        matrix[i-1]='O';
    f++;
}

int main()
{
    int row,column,p=0,us,f=0;
    char input;
    start:
    row = column = 3;
    int i,j,k;
    
    p=f=0;
    u=1;

    for(i=0;i<row;i++)
    { for(j=0;j<row;j++)
      { matrix[p]=49+p;
        p++;
      }
    }
    display();
    for(i=0;i<9;i++)
     matrix[i]=' ';

     k=0;us=0;
     printf("\nDo you want to start first ? ( Y / N ) : ");
     scanf("%c",&input);
     switch(input)
     {
         case 'y':
         case 'Y':
            userInput(k++);
            us = 1;
            break;
         case 'n':
         case 'N':
            us = 0;
            break;
         default:
          goto start;
     }

    m1:
    display();
    char winner;
    int win = -1;
    do{
        if(u%2)   
            compInput(k++);
        else
            userInput(k++);
        u++;
        winner = checkWin();
        display();
        if( (winner =='X' && us==1) || (winner =='O' && us==0))
        {  printf("\nThe User won !");
            win = 1;
            break;
        }
        if((winner =='X' && us==0) || (winner =='O' && us==1))
        {  printf("\nThe Computer won !");
            win = 1;
            break;
        }
    }
    while(k<9 || f!=9);

    if(win ==-1)
     printf("\nmatrixch is Draw !");

    playAgain:    
    printf("\nDo u want to play again ? ( Y/N ): ");
   
    char playAgainInput;
    scanf("%c",&playAgainInput);
    switch(playAgainInput)
    {
        case 'y':
        case 'Y':
            goto start;
        case 'n':
        case 'N':
             break;
        default:
         goto playAgain; 
    }
    return 0;
}
