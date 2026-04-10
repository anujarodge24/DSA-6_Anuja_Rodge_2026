//Accept  4*4 matrix and display the following patern

/*

  1 1 1 *   
  1 1 * 0     
  1 * 0 0
  * 0 0 0     
  
*/

#include<stdio.h>

int main(void)
{

	for(int i=0 ;i < 4 ; i++ )
	{
		int sum =0;
		for(int j=0 ; j < 4 ;j++)
		{
			sum = i+j;
			
			if(sum == 3)
			    printf(" * ");
			
			else if(sum < 3)
			    printf(" 1 ");
			
			else 
				printf(" 0 ");
			
		}
		printf("\n");
	}
	
	return 0;
}
		   