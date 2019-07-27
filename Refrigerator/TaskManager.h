#ifndef TaskManager_H
#define TaskManager_H
#include "src/TaskScheduler/TaskScheduler.h"
Scheduler ts;

/*
  Scheduling defines:
  TASK_MILLISECOND
  TASK_SECOND
  TASK_MINUTE
  TASK_HOUR
  TASK_IMMEDIATE
  TASK_FOREVER
  TASK_ONCE
  TASK_NOTIMEOUT
*/

Task rpm_task (1000 * TASK_MILLISECOND, TASK_FOREVER, &readRPM, &ts, true);
Task ntc_task (500 * TASK_MILLISECOND, TASK_FOREVER, &tempMediaNTC, &ts, true);
//Task pwm_task (100 * TASK_MILLISECOND, TASK_FOREVER, &cycle_hot, &ts, true);

#endif
