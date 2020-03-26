// Header Files
#include "TypeDefines.h"
#include "TimerMgrHeader.h"
#include "TimerAPI.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>

/*****************************************************
 * Global Variables
 *****************************************************
 */
// Timer Pool Global Variables
INT8U FreeTmrCount = 0;
RTOS_TMR *FreeTmrListPtr = NULL;

// Tick Counter
INT32U RTOSTmrTickCtr = 0;

// Hash Table
HASH_OBJ hash_table[HASH_TABLE_SIZE];

// Thread variable for Timer Task
pthread_t thread;

// Semaphore for Signaling the Timer Task
sem_t timer_task_sem;

// Mutex for Protecting Hash Table
pthread_mutex_t hash_table_mutex;

// Mutex for Protecting Timer Pool
pthread_mutex_t timer_pool_mutex;

/*****************************************************
 * Timer API Functions
 *****************************************************
 */

// Function to create a Timer
RTOS_TMR* RTOSTmrCreate(INT32U delay, INT32U period, INT8U option, RTOS_TMR_CALLBACK callback, void *callback_arg, INT8	*name, INT8U *err)
{
	RTOS_TMR *timer_obj = NULL;

	// Check the input Arguments for ERROR
	
	// Allocate a New Timer Obj
	timer_obj = alloc_timer_obj();

	if(timer_obj == NULL) {
		// Timers are not available
		*err = RTOS_ERR_TMR_NON_AVAIL;
		return NULL;
	}

	// Fill up the Timer Object


	*err = RTOS_SUCCESS;

	return timer_obj;
}

// Function to Delete a Timer
INT8U RTOSTmrDel(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking

	// Free Timer Object according to its State


	*perr = RTOS_SUCCESS;
	return RTOS_TRUE;
}

// Function to get the Name of a Timer
INT8* RTOSTmrNameGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking

	// Return the Pointer to the String
}

// To Get the Number of ticks remaining in time out
INT32U RTOSTmrRemainGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking

	// Return the remaining ticks

}

// To Get the state of the Timer
INT8U RTOSTmrStateGet(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking

	// Return State
}

// Function to start a Timer
INT8U RTOSTmrStart(RTOS_TMR *ptmr, INT8U *perr)
{
	// ERROR Checking

	// Based on the Timer State, update the RTOSTmrMatch using RTOSTmrTickCtr, RTOSTmrDelay and RTOSTmrPeriod
	// You may use the Hash Table to Insert the Running Timer Obj

}

// Function to Stop the Timer
INT8U RTOSTmrStop(RTOS_TMR *ptmr, INT8U opt, void *callback_arg, INT8U *perr)
{
	// ERROR Checking


	// Remove the Timer from the Hash Table List


	// Change the State to Stopped

	// Call the Callback function if required

}

// Function called when OS Tick Interrupt Occurs which will signal the RTOSTmrTask() to update the Timers
void RTOSTmrSignal(int signum)
{
	// Received the OS Tick
	// Send the Signal to Timer Task using the Semaphore
}

/*****************************************************
 * Internal Functions
 *****************************************************
 */

// Create Pool of Timers
INT8U Create_Timer_Pool(INT32U timer_count)
{
	// Create the Timer pool using Dynamic Memory Allocation
	// You can imagine of LinkedList Creation for Timer Obj

	return RTOS_SUCCESS;
}

// Initialize the Hash Table
void init_hash_table(void)
{

}

// Insert a Timer Object in the Hash Table
void insert_hash_entry(RTOS_TMR *timer_obj)
{
	// Calculate the index using Hash Function
	
	// Lock the Resources

	// Add the Entry

	// Unlock the Resources
}

// Remove the Timer Object entry from the Hash Table
void remove_hash_entry(RTOS_TMR *timer_obj)
{
	// Calculate the index using Hash Function

	// Lock the Resources

	// Remove the Timer Obj

	// Unlock the Resources
}

// Timer Task to Manage the Running Timers
void *RTOSTmrTask(void *temp)
{

	while(1) {
		// Wait for the signal from RTOSTmrSignal()

		// Once got the signal, Increment the Timer Tick Counter

		// Check the whole List associated with the index of the Hash Table
		
		// Compare each obj of linked list for Timer Completion
		// If the Timer is completed, Call its Callback Function, Remove the entry from Hash table
		// If the Timer is Periodic then again insert it in the hash table
		// Change the State
	}
	return temp;
}

// Timer Initialization Function
void RTOSTmrInit(void)
{
	INT32U timer_count = 0;
	INT8U	retVal;
	pthread_attr_t attr;

	fprintf(stdout,"\n\nPlease Enter the number of Timers required in the Pool for the OS ");
	scanf("%d", &timer_count);

	// Create Timer Pool
	retVal = Create_Timer_Pool(timer_count);

	// Check the return Value

	// Init Hash Table
	init_hash_table();

	fprintf(stdout, "\n\nHash Table Initialized Successfully\n");

	// Initialize Semaphore for Timer Task

	// Initialize Mutex if any

	// Create any Thread if required for Timer Task

	fprintf(stdout,"\nRTOS Initialization Done...\n");
}

// Allocate a timer object from free timer pool
RTOS_TMR* alloc_timer_obj(void)
{

	// Lock the Resources
	
	// Check for Availability of Timers

	// Assign the Timer Object

	// Unlock the Resources
}

// Free the allocated timer object and put it back into free pool
void free_timer_obj(RTOS_TMR *ptmr)
{
	// Lock the Resources

	// Clear the Timer Fields

	// Change the State

	// Return the Timer to Free Timer Pool

	// Unlock the Resources
}

// Function to Setup the Timer of Linux which will provide the Clock Tick Interrupt to the Timer Manager Module
void OSTickInitialize(void) {	
	timer_t timer_id;
	struct itimerspec time_value;

	// Setup the time of the OS Tick as 100 ms after 3 sec of Initial Delay
	time_value.it_interval.tv_sec = 0;
	time_value.it_interval.tv_nsec = RTOS_CFG_TMR_TASK_RATE;

	time_value.it_value.tv_sec = 0;
	time_value.it_value.tv_nsec = RTOS_CFG_TMR_TASK_RATE;

	// Change the Action of SIGALRM to call a function RTOSTmrSignal()
	signal(SIGALRM, &RTOSTmrSignal);

	// Create the Timer Object
	timer_create(CLOCK_REALTIME, NULL, &timer_id);

	// Start the Timer
	timer_settime(timer_id, 0, &time_value, NULL);
}

