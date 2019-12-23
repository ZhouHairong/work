#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define CUSTOMERS_COUNT 2
#define PRODUCERS_COUNT 2
#define buf[5]
struct msg{
    struct msg *next;
    int num;
};
struct msg *head = NULL;

pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t threads[CUSTOMERS_COUNT+PRODUCERS_COUNT];
void * consumer(void * p)
{
    int num = *(int *)p;
    free(p);
    for(;;)
    {
        pthread_mutex_lock(&mutex);
        while(bu[0] == NULL)
        {
            printf("%d begin wait a condition...\n",num);
            pthread_cond_wait(&cond, &mutex);
        }
        printf("%d end wait a condition...\n",num);
        printf("%d begin consume product...\n", num);
        pthread_mutex_unlock(&mutex);
        for(i=0;i<=4;i++)
		{
			buf[i]==NULL;
			printf("Consume %d\n",buf[i]);
		}
		printf("Consume finished!----------\n");
        printf("%d end consume product...\n",num);
        sleep(1);
    }
}
void *producer(void *p)
{
    int num = *(int *)p;
    free(p);
    for(;;)
    {
        printf("%d begin produce product...\n", num);
        for(i=0;i<=4;i++)
		{
	        buf[i] = rand()%1000+1;
	        printf("produce %d\n", buf[i]);
		}
        pthread_mutex_lock(&mutex);
        printf("%d end produce product...\n",num);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
int main()
{
    srand(time(NULL));

    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);

    int i;
    for(i=0; i<CUSTOMERS_COUNT; i++)
    {
        int *p = (int *)malloc(sizeof(int ));
        *p=i;
        pthread_create(&threads[i],NULL, consumer, (void*)p);

    }

    for(i=0; i<PRODUCERS_COUNT;i++)
    {
        int*p = (int*)malloc(sizeof(int));
        *p=i;
        pthread_create(&threads[CUSTOMERS_COUNT+i], NULL, producer, (void *)p);

    }

    for(i=0; i<CUSTOMERS_COUNT+PRODUCERS_COUNT;i++)
    {
        pthread_join(threads[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}
