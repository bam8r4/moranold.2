#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>


using namespace std;

int main(int argc,char *argv[])
{

  time_t *ptr = NULL;
  int pid =0;
  int shmid = 0;
  key_t key = 0;
  key = 0x173600;


   //Return memory identifier.
  shmid = shmget(key,sizeof(time_t),0678|IPC_CREAT);
  ptr = (time_t *) shmat(shmid,(void*)0,0);

	string potPal = argv[0];
	int length = 0;
	int flag = 0;

	cout<<"Yo I am the new process! Time is: "<< *ptr <<endl;

	length = potPal.length();
	cout<<length<<endl;

	for(int i=0;i < length ;i++)
	{
        	if(potPal[i] != potPal[length-i-1]){
            		flag = 1;
            		break;
		}
  	}

	if(flag == 0)
	{
		cout<<potPal<<" is a palindrome"<<endl;
	}
	else
	{
		cout<<potPal<<" is not a palindrome"<<endl;
	}


  return 0;
}
