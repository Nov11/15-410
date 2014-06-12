#include <pthread.h>
#include <stdio.h>
int counter = 2;
void foo(){
	counter++;
	printf("%d\n", counter);
}
int main()
{
	pthread_t tid[2];
	int i;
	
	for(i = 0; i < 2; i++){
		// pthread_create(&tid[i], 0, foo, 0); counter increse first so must be 3
		
		// pthread_create(&tid[i], 0, foo, 0); same as above
		// pthread_join(tid[i], 0);
		if(fork() == 0){
			foo();
		}
	}
	counter++;
	printf("%d\n", counter);
	return 0;
}