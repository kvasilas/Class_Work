// Header File for Timer APIs
#ifndef TIMER_API_H
#define TIMER_API_H

#include "TimerMgrHeader.h"
#include "TypeDefines.h"

// TIMER MANAGER APIs

extern void RTOSTmrInit(void);

extern RTOS_TMR* RTOSTmrCreate(INT32U delay, INT32U period, INT8U option, RTOS_TMR_CALLBACK callback, void *callback_arg, INT8	*name, INT8U *err);

extern INT8U RTOSTmrDel(RTOS_TMR *ptmr, INT8U *perr);

extern INT8* RTOSTmrNameGet(RTOS_TMR *ptmr, INT8U *perr);

extern INT32U RTOSTmrRemainGet(RTOS_TMR *ptmr, INT8U *perr);

extern INT8U RTOSTmrStateGet(RTOS_TMR *ptmr, INT8U *perr);

extern INT8U RTOSTmrStart(RTOS_TMR *ptmr, INT8U *perr);

extern INT8U RTOSTmrStop(RTOS_TMR *ptmr, INT8U opt, void *callback_arg, INT8U *perr);

extern void RTOSTmrSignal(int signum);

// Internal Functions
INT8U Create_Timer_Pool(INT32U timer_count);

void init_hash_table(void);

void insert_hash_entry(RTOS_TMR *timer_obj);

void remove_hash_entry(RTOS_TMR *timer_obj);

void* RTOSTmrTask(void *temp);

RTOS_TMR* alloc_timer_obj(void);

void free_timer_obj(RTOS_TMR *ptmr);

#endif
