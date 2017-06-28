#ifndef __PROCESS_H__
#define __PROCESS_H__

enum action {LOAD, CHANGE, DRAW, CLEAR};

errs_num processor(argument *arg, action act);

#endif // __PROCESS_H__
