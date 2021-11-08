#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include</wait.h> // dung cho wait ko loi

int main()
{
	printf("Moi nhap 1 so: ");
	int n;
	scanf("%d", &n); //input
	pid_t pid;
	pid = fork();
	if (pid < 0) // Foxfail
	{
		fprintf(stderr, "fork false");
		return 2;
	}else if (pid == 0) //Child process
	{
		while(n!=1)
		{
			printf("%d \t",n);
			if(n%2==0)
			{			
				n/=2;	
			}	
			else 
			{
				n=3*n+1;
			}
		}
		printf("%d \t",n); //output
		printf("\n");
		//execlp("/bin/ls", "ls", NULL);
	}
	else //parent process
	{	
		wait(NULL);
		printf("Child complete.\n");
	}
	return 1;
}

