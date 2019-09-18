#include<stdio.h>
#include<stdlib.h>

void input(int **, int ,int);
void display(int **, int ,int);
void sum(int **,int **,int **, int, int);

int main()
{
    int **x,**y,**z,m,n;
    printf("Enter the no of rows and columns ::\n");
    scanf("%d %d",&m,&n);

    printf("Enter the Matrix 1 ::\n");
    input(x,m,n);

    printf("Enter the Matrix 2 ::\n");
    input(x,m,n);

    sum(x,y,z,m,n);

    printf("The Matrix 1 you entered is :: \n");
    display(x,m,n);

    printf("The Matrix 1 you entered is :: \n");
    display(y,m,n);

    printf("The Resultant Matrix you entered is :: \n");
    display(z,m,n);
    return 0;
}
void input(int **x, int m, int n){
    int i,j;
    x = (int **)malloc(sizeof(int *)* m);
    for(i=0; i < m ; i++)
        x[i] = (int *)malloc(sizeof(int)*n);

    for(i = 0; i < m ; i++)
        for(j = 0; j < n; j++)
            scanf("%d",&x[i][j]);
}
void display(int **a,int m ,int n){
    int i,j;

    for(i = 0; i < m ; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d",a[i][j]);
    printf("\n");
    }


}
void sum(int **x, int **y, int **z, int m, int n){
    int i,j;
    z = (int **)malloc(sizeof(int *)*m);
    for(i = 0; i < m; i++)
        z[i] = (int *)malloc(sizeof(int *)*n);
    for(i = 0; i < m ; i++)
        for(j = 0; j < n; j++)
            z[i][j] = x[i][j] + y[i][j];
}
