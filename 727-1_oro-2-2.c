#include<stdio.h>

int main()
{
	int n, c=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		if(x<0){
			c++;
		}
	}
	printf("%d",c);		
}	
