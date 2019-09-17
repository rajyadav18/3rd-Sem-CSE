#include <stdio.h>
#define compare(x,y) (x>y) ? 1 : (x<y) ? -1 : 0

typedef struct 
{
	int coef, expo;
} poly;

int avail = 0;
poly terms[100];

void attach(int, int);
void add(int,int,int,int,int*,int*);

void main()
{
	int sa,sb,sd,fa,fb,fd,m,n,i;

	printf("Enter no of terms in 1st and 2nd equations: \n");
		scanf("%d%d",&m,&n);

	sa = 0;
	fa = m - 1;
	sb = m;
	fb=  m + n - 1;
	avail = fb + 1;

	printf("Enter coef, expo of all terms in 1st equation:\n");

	for(i=sa; i<=fa; i++)
		scanf("%d%d", &terms[i].coef, &terms[i].expo);

	printf("Enter coef, expo of all terms of 2nd equations:\n");

	for(i=sb; i<=fb; i++)
		scanf("%d%d", &terms[i].coef, &terms[i].expo);

	add(sa, fa, sb, fb, &sd, &fd);

	printf("The resultant polynomial is:\n");

	for(i=sd; i<fd; i++)
		printf("%dx^%d + ", terms[i].coef, terms[i].expo);	

	printf("%dx^%d\n", terms[i].coef, terms[i].expo);
}

void add(int sa, int fa, int sb, int fb, int *sd, int *fd)
{
	int c;
	*sd = fb + 1;

	while(sa<=fa && sb<=fb)
	{
		switch(compare(terms[sa].expo, terms[sb].expo))
		{
			case 1:
				attach(terms[sa].coef, terms[sa].expo);
				sa++;
				break;

			case 0:
				c = terms[sa].coef + terms[sb].coef;
				if(c)
				{
					attach(c,terms[sa].expo);
					sa++;
					sb++;
				}
				break;

			case -1:
				attach(terms[sb].coef, terms[sb].expo);
				sb++;
				break;
		}
	}
		for(; sa <= fa; sa++)
			attach(terms[sa].coef, terms[sa].expo);
		for(; sb <=fb; sb++)
			attach(terms[sb].coef, terms[sb].expo);

		*fd = avail - 1;
}

void attach(int coef, int expo){
	terms[avail].coef = coef;
	terms[avail++].expo = expo;
}