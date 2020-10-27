//Producer Consumer Problem
#include<stdio.h>
#include<unistd.h>
//#include<semaphore.h>

int wait(int a)
{
  return --a;
}

int signal(int b)
{
  return ++b;;
}

int main()
{
	int mutex, full, empty, n;
	printf("Enter no. of slots in buffer : ");
	scanf("%d", &n);

	mutex=1;
	full=0;
	empty=n;
	while(empty>0)
	{
  	//Solution for Producer
  	printf("\nItem-%d is being produced by producer!\n", full+1);
  	mutex=wait(mutex);
  	printf("Placing an item in buffer!\n");
  	mutex=signal(mutex);
  	sleep(3);
  	//Solution for Consumer
  	mutex=wait(mutex);
  	printf("Removing an item from buffer!\n");
  	mutex=signal(mutex);
  	printf("Item-%d is being consumed by consumer!\n", full+1);
  	full=signal(full);
  	empty=wait(empty);
	}
      return 0;
}
