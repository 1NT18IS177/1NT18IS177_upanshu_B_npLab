#include <stdio.h>

struct node {
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;
    int i,j,k;
    printf("Enter the number of nodes\n");
    scanf("%d",&no);

    printf("\nEnter the distance matrix\n");
    printf("\nEnter 0 for route from node to itself\n");
    printf("\nEnter 99 if node is unreachable\n");
    for (i = 0; i < no; i++)
	{
        for (j = 0; j < no; j++)
		{
        	scanf("%d",&dm[i][j]);
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do
	{
        flag = 0;
        for ( i = 0; i < no; i++)
		{
            for (j = 0; j < no; j++)
			{
                for ( k = 0; k < no; k++)
				{
                    if ((route[i].dist[j]) > (route[i].dist[k] + route[k].dist[j]))
					{
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    for (i = 0; i < no; i++)
	{

    	printf("\n\n DVR table for router %c\n",alpha[i],"\n");
    	printf("Dest\tCost\tNext Hop\n");
    	//printf("Dest\tNext Hop\t Dist\n");
        for ( j = 0; j < no; j++)
        {
        	//printf("%d\t%d\t\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
        	printf("%c\t%d\t\t%c\n", alpha[j], route[i].dist[j], alpha[route[i].from[j]]);
		}

    }
    return 0;
}
