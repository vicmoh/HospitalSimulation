/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

#ifndef QUEUES_H
#define QUEUES_H

typedef struct queues{
    List * list;
} Queues;

/*
*initialilze the queues
*/
Queues* initializeQueues();

/*
*inset objects to queues
*param queues for the queue
*param toBeAdded for objects to be added 
*/
void insert(Queues* queues, void *toBeAdded);

/*
*pop function for removing objects
*param queues
*param toBeDeleted for objects to be deleted
*return 0, -1, or 1
*/
int pop(Queues* queues, void *toBeDeleted);

/*
*peek the head of the queues
*param for queues
*/
void* peek(Queues* queues);

/*
*print all patients objects =
*param queues
*/
void printAllPatient(Queues* queues);

/*
*print obeject
*param queues
*/
void printSomePatient(Queues* queues);

/*
*check if the list id empty
*param queues
*/
int isEmpty(Queues* queues);

/*
*delete the list
*param queues
*/
void destroy(Queues* queues);

#endif