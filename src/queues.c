/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

//Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//own library
#include "linkList.h"
#include "dummy.h"
#include "queues.h"
#include "patient.h"

//init queues
Queues *initializeQueues(void (*printFunction)(void *toBePrinted), 
                     void (*deleteFunction)(void *toBeDeleted),
                     int (*compareFunction)(const void *first,const void *second)){
    Queues* queues = malloc(sizeof(Queues));
    queues->list = initializeList(printFunction, deleteFunction, compareFunction);
    return queues;
}/*end if*/

//add back
void insert(Queues* queues, void *toBeAdded){
    insertBack(queues->list, toBeAdded);
}//end func

//delete the head of the list
int pop(Queues* queues, void *toBeDeleted){
    int returnInt = 0;
    returnInt = deleteNodeFromList(queues->list, toBeDeleted);
    return returnInt;
}//end func

//get the head pointer
void* peek(Queues* queues){
    void* ptr;
    ptr = getFromFront(queues->list);
    return ptr;
}//end func

//print all the patient
void printAllPatient(Queues* queues){
    Node* temp = queues->list->head;
    if(temp != NULL) {
        /*move forwawrd using next pointer*/
        while(temp != NULL) {
            void* voidTemp = temp;
            printPatient(voidTemp);
            printf("\n");
            temp = temp->next;
        }/*end while*/
    }/*end if*/
}//end func

//print all the patient
void printSomePatient(Queues* queues){
    Node* temp = queues->list->head;
    if(temp != NULL) {
        /*move forwawrd using next pointer*/
        while(temp != NULL) {
            void* voidTemp = temp;
            printPatientNoTime(voidTemp);
            printf("\n");
            temp = temp->next;
        }/*end while*/
    }/*end if*/
}//end func

void destroy(Queues* queues){
    deleteList(queues->list);
}//end func

int isEmpty(Queues* queues){
    if(queues->list->head == NULL){
        return 0;
    }else{
        return 1;
    }//end if
}//end func