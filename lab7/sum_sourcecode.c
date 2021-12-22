
#include <pthread.h>
#include <stdio.h>
int sum; // this data is shared by the threads
void *runner(void *param); // threads will call this function
int main(int argc, char*argv[] )
{
pthread_t tid; 									//the thread identifier
pthread_attr_t attr; 							//set of thread attributes
if(argc!=2){ 									//the first argment is always program name
	fprintf(stderr, "usage: a.out <integer value>");
	return -1;  								//=exit from program
}
if(atoi(argv[1])<0){							//atoi=>alphabet into integer
	fprintf(stderr, "%d must be >=0\n",atoi(argv[1]));
	return -1;
}
pthread_attr_init(&attr);						//get the default attributes
pthread_create( &tid, &attr,runner, argv[1] ); 		//create the thread
pthread_join(tid, NULL);							//wait for the thread to exit
printf( "sum=%d\n",sum);
return 0;
}
void* runner( void * param )
{
	int i,upper=atoi(param);
	sum=0;
	for(i=1;i<=upper;i++)
		sum+=i;
	pthread_exit(0);
}





