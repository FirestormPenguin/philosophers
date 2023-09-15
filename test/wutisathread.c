#include <pthread.h>
#include <stdio.h>


pthread_mutex_t lock;
int counter;

void  *count_routine(int counter_var)
{
	int index;

	index = -1;
	while (++index < 1000000)
	{
	pthread_mutex_lock(&lock);
		counter++;
	pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main()
{
	pthread_t tid1, tid2;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid1, NULL, &count_routine, NULL);
	pthread_create(&tid2, NULL, &count_routine, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);
	printf("counter: %d\n", counter);
}
