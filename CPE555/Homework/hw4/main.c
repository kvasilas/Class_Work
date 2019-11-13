/*
 * CPE-555 Real-Time and Embedded Systems
 * Stevens Institute of Technology
 * Spring 2017
 *
 * FreeRTOS currlate
 *
 * Name: Kirk Vasilas
 * Collaborate: Brereton Conway
 */

/* Standard includes */
#include <stdio.h>

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "queue.h"
#include "time.h"

/* global variables */
/* (Declare your global variables here) */

QueueHandle_t xTimeQueue;


/* function prototypes */
/* (Add your function prototypes here) */

void TimeTask(void *pvParameters);
void DisplayTask(void *pvParameters);



struct alarm_time{
		int min;
		int sec;
	};

struct alarm_time input_time;

/* main application code */
int main( void )
{


	/* set STDOUT to be non-buffered to that printf() messages display immediately */
	setbuf(stdout, NULL);

	printf("Application started\n");

	printf("Enter Number of Minutes:\n");
	scanf("%d", &input_time.min);
	printf("Enter Number of Seconds:\n");
	scanf("%d", &input_time.sec);

	if( (input_time.sec < 0) || (input_time.min < 0) ){
		printf("Invalid\n");
		for( ;; );
	}

	/* (Add your application code here) */
	xTaskCreate(TimeTask, "Create timetask", 1000, NULL, 1, NULL);
	xTaskCreate(DisplayTask, "Create displaytask", 1000, NULL, 1, NULL);

	vTaskStartScheduler();

	return 0;
}


/* (Add any additional function definitions here) */

void TimeTask(void *pvParameters){
	xTimeQueue = xQueueCreate( 1, sizeof( struct alarm_time *) );
	if( xTimeQueue == NULL ){
		printf("Error: queue not created.\n");
	}
	struct alarm_time curr_time = input_time;
	struct alarm_time *pxTime;
	while( (curr_time.min > 0) || (curr_time.sec > 0)){

		if(curr_time.min == 1){
			if (curr_time.sec == 1){
							printf("Time Remaining: %d:00\n", curr_time.min);
							vTaskDelay( 1000 / portTICK_RATE_MS);
							curr_time.sec = 59;
							for (int i = 59; i>0; i--){
								printf("Time Remaining: 0:%02d\n", i);
								vTaskDelay( 1000 / portTICK_RATE_MS);
							}
							printf("Time is up!");
							break;
			}

			else{
				curr_time.sec--;
			}
		}
		else if (curr_time.min == 0){
			curr_time.min = 1;
			for (int i = 58; i>0; i--){
				printf("Time Remaining: 0:%02d\n", i);
				vTaskDelay( 1000 / portTICK_RATE_MS);
			}
			printf("Time is up!");
			break;
		}
		else {
			if (curr_time.sec == 1){
				printf("Time Remaining: %d:00\n", curr_time.min);
				vTaskDelay( 1000 / portTICK_RATE_MS);
				curr_time.min--;
				curr_time.sec = 59;
				}

			else{
				curr_time.sec--;
			}
		}


		pxTime = &curr_time;

		xQueueSend(xTimeQueue, ( void * ) &pxTime, ( TickType_t ) 10 );
		vTaskDelay( 1000 / portTICK_RATE_MS);
	}

	vTaskDelete( NULL );

}
void DisplayTask(void *pvParameters){
	struct alarm_time *pxRxTime;
	while(1){
		if(xTimeQueue != 0){
			if( xQueueReceive( xTimeQueue, &( pxRxTime ), ( TickType_t ) 10 ) ){
				printf("Time Remaining: %d:%02d\n",pxRxTime->min, pxRxTime->sec );
			}
		}
	}
	vTaskDelete( NULL );
}
