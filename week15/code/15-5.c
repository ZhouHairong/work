#include "my.h"
void *watch_count(void *idp)
{
	int *my_id = idp;
	printf("Starting watch count():thread %d\n",*my_id);
	pthread_mutex_lock(&count_mutex);
	if(count<COUNT_LIMIT)
	{
		pthread_cond_wait(&count_threshold_cv,&count_mutex);
		printf("watch count (): thread %d Condition signal received.\n",*my_id);
	}
	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}

void *inc_count(void *idp)
{
	int j,i;
	double result = 0.0;
	int *my_id = idp;
	for(i=0;i<TCOUNT;i++)
	{
		pthread_mutex_lock(&count_mutex);
		count++;
	if(count == COUNT_LIMIT)
	{
		pthread_cond_signal(&count_threshold_cy);
		printf("inc count():thread %d,count = %d Threadshold reached.\n",*my_id,count);
	}
	printf("inc count : thread %d, int = %d ,unlocking mutex\n",*my_id,count);
	pthread_mutex_unlock(&count_mutex);
	for(j=0;j<1000;j++)
	result = result + (double)result;
	}
	pthread_exit(ULL);
}

int main(int argc,char *argv[])
{
	int i,re;
	pthread_t threads[3];
	pthread_attr_t attr;
	pthread_mutex_init(&count_mutex,NULL);
	pthread_cond_init(&count_threshold_cv,NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&threads[0],&attr,inc_count,(void *)&thread_ids[0]);
	pthread_create(&threads[1],&attr,inc_count,(void *)&thread_ids[1]);
	pthread_create(&threads[2],&attr,watch_count,(void *)&thread_ids[2]);
	for(i=0;i<NUM_THREADS;i++)
	{
		pthread_join(threads[i],NULL);
	}
	printf("Main(): Waited on %d threads, Done.\n",NUM_THREADS);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);
}




















