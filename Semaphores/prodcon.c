/*||Name: Jonathan Leack
||||Date: 3/1/2016
||||Description: The objective of this assignment is to use semaphores to protect the critical section between two competing threads.*/

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

void *Producer();
void *Consumer();

int BufferSize = 0;
int BufferIndex = 0;
int Iterations = 0;
int *BUFFER;

pthread_cond_t Buffer_Not_Full=PTHREAD_COND_INITIALIZER;
pthread_cond_t Buffer_Not_Empty=PTHREAD_COND_INITIALIZER;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[])
{    

  //check to ensure correct number of arguments were passed
  if(argc != 3)
    {
      printf("ERROR: Incorrect execution syntax.\n");
      exit(-1);
    }

  //set buffersize to passed value
  BufferSize = atoi(argv[1]);

  //check buffersize value
  if(BufferSize < 1 || BufferSize > 64)
    {
      printf("ERROR: Invalid buffer value. Please enter a value between 1 and 64.\n");
      exit(-1);
    }

  //check iterations
  Iterations = atoi(argv[2]);

  //check iteration value
  if(Iterations < 0)
    {
      printf("ERROR: Invalid iteration value. Please enter a positive value.\n");
      exit(-1);
    }

  //create buffer and set threads
  BUFFER=(int *) malloc(sizeof(int) * BufferSize);
  pthread_t ptid,ctid;            
    
  //create threads before joining them
  pthread_create(&ptid,NULL,Producer,NULL);
  pthread_create(&ctid,NULL,Consumer,NULL);    
  pthread_join(ptid,NULL);
  pthread_join(ctid,NULL);
       
  return 0;
}

void *Producer()
{    
  int output = 0;
  int pit = 0;

  //start at beginning of buffer
  if(BufferIndex < 0)
    {
      BufferIndex = 0;
    }

  //set mutex lock
  pthread_mutex_lock(&mVar);

  //run iterations for user's entered number of times
  for(pit; pit < Iterations; pit++)
    {
      //alter if full buffer
      if(BufferIndex==BufferSize)
        {                        
	  pthread_cond_wait(&Buffer_Not_Full,&mVar);
        }     
       output = rand() % 255;

      //set buffer to output and increment index
      BUFFER[BufferIndex] = output;                  
      BufferIndex++;
      printf("MESSAGE: Producer has written %d to the buffer.\n", output);    
    }

  //unlock and signal consumer
  pthread_mutex_unlock(&mVar);
  pthread_cond_signal(&Buffer_Not_Empty);        
}

void *Consumer()
{
  int input = 0;
  int cit = 0;

  //alter buffer index
  BufferIndex--;

  //set mutex lock
  pthread_mutex_lock(&mVar);

  //run iterations for user's entered number of times
  for(cit; cit < Iterations; cit++)
    {
      //alter if buffer reaches negative value
      if(BufferIndex == -1)
        {            
          BufferIndex = 0;
	  pthread_cond_wait(&Buffer_Not_Empty,&mVar);
        }

      //set input to buffer value and decrement index
      input = BUFFER[BufferIndex];       
      printf("MESSAGE: Consumer has written %d to the buffer.\n",input);
      BufferIndex--;              
    }

  //Unlock and signal producer        
  pthread_mutex_unlock(&mVar);        
  pthread_cond_signal(&Buffer_Not_Full);      
}
