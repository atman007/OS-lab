@@ -0,0 +1,134 @@
#include<stdio.h>

void main()
{
	int i, j, r= 6, c= 4;
	int total_resrcs[4], request[4], available[4];
	int curr_alloc[r][c], max_demand[r][c]; 
	int need[r][c], safe[r];
	int check, temp1, temp2, temp3, temp4 , count=6;

//////////////////////////////////// TOTAL RESOURCES //////////////////////////////////////////////////////////////////

	printf("\nenter the total resources of the system\t");
	for (i=0; i<4; i++)
		scanf("%d",&total_resrcs[i]);
	printf("\t");

///////////////////////////////////  MAXIMUM DEMAND//////////////////////////////////////////////////////////////////

	printf("\nenter the maximum demand of the process");
	for (i=0; i<r; i++)
	{
		printf("\nProcess %d \n",i);
		for (j=0; j<c; j++)
			scanf("%d",&max_demand[i][j]);
		printf("\t");
	}	

////////////////////////////////////   CURRENT ALLOCATION //////////////////////////////////////////////////////////
	
	printf("\nenter the current allocation of the process");
	for (i=0; i<r; i++)
	{
		printf("\nProcess %d \n",i);
		for (j=0; j<c; j++)
			scanf("%d",&curr_alloc[i][j]);
		printf("\t");
	}	

///////////////////////////////////////   AVAILABLE ///////////////////////////////////////////////////////////////////

	temp1= curr_alloc[0][0] + curr_alloc[1][0] + curr_alloc[2][0] + curr_alloc[3][0] + curr_alloc[4][0] + curr_alloc[5][0];
	available[0]= total_resrcs[0]-temp1;

	temp2= curr_alloc[0][1] + curr_alloc[1][1] + curr_alloc[2][1] + curr_alloc[3][1] + curr_alloc[4][1] + curr_alloc[5][1];
	available[1]= total_resrcs[1]-temp2;

	temp3= curr_alloc[0][2] + curr_alloc[1][2] + curr_alloc[2][2] + curr_alloc[3][2] + curr_alloc[4][2] + curr_alloc[5][2];
	available[2]= total_resrcs[2]-temp3;

	temp4= curr_alloc[0][3] + curr_alloc[1][3] + curr_alloc[2][3] + curr_alloc[3][3] + curr_alloc[4][3] + curr_alloc[5][3];
	available[3]= total_resrcs[3]-temp4;

	printf("\navailable matrix\n");
	for(i=0; i<c; i++)
		printf("%d",available[i]); 

////////////////////////////////////////      NEED    /////////////////////////////////////////////////////////////////
	
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
			need[i][j]= max_demand[i][j]-curr_alloc[i][j];
	}

	printf("\n\nneed matrix\n");
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
			printf("%d",need[i][j]);
		printf("\n");
	}

//////////////////////////////////// SAFE STATE  //////////////////////////////////////////////////////////////////////     	

	
	while(count != 0)
	{
		i=0;	
		while (i<r)
		{
			if ( need[i][0] ==0 && need[i][1] ==0 && need[i][2] ==0 && need[i][3] ==0 )  			
				i++;
	
			else
			{
				int cnt=0;
				j=0;
				while (j<c)
				{

					if(need[i][j] > available[j])
					{	
						check=1;
						break;
					}
					
					else
					{
						check=0;
					}
					
					j++;				
				}

				if (check == 1)
					i++;


				else
				{
					safe[i] = i+1;
 				
					j=0;
					while (j<c)
					{
						need[i][j] ==0;
						available[j]= available[j] + curr_alloc[i][j];
						j++;		
					}
			
					count= count-1;	
					i++;
	
				}
			}	
		}	
	}

	printf("\n safe state\n");
	for(i=0; i<6; i++);
	printf("%d", safe[i]);
} 
