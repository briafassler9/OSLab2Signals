/* hello_timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int signal_alarm = 0;
int signal_time = 0;
time_t start, stop;

void siginHandler(int signum){
  int count;
  stop = time(NULL);
  count = stop - start;
  printf("Number of Alarms: %d", count);
}

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  //exit(1); //exit after printing
  sleep(2);
  signal_alarm = 1;
  signal_time++;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  start = time(NULL);
  while(1) {
    signal_alarm = 0;
    alarm(2);
    while(!signal_alarm);
      printf("Turing was right!\n"); //busy wait for signal to be delivered
  }
  return 0; //never reached
}