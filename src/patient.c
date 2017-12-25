/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*Standard Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//own library
#include "linkList.h"
#include "dummy.h"
#include "queues.h"
#include "patient.h"

Patient* createPatient(char* id, int priority, char* code){
    Patient* patient = malloc(sizeof(Patient));
    strcpy(patient->id, id);
    patient->priority = priority;
    strcpy(patient->code, code);
    patient->time = 0;
    return patient;
}//end patient

char* getClientID(Patient * patient) { 
    return patient->id;
}//end func

int getPriority(Patient * patient) { 
    return patient->priority;
}//end func

char* getCode(Patient * patient) { 
    return patient->code;
}//end func

int getTime(Patient* patient){
    return patient->time;
}//end func

void setTime(Patient* patient, int time){
    patient->time = time;
}//end func

void printPatient(void * patient) {
    printf("%s\t\t %d\t\t %s\t\t %d", getClientID(patient), getPriority(patient), getCode(patient), getTime(patient));
}//end func 

void printPatientNoTime(void * patient) {
    printf("%s\t\t %d\t\t %s\t\t", getClientID(patient), getPriority(patient), getCode(patient));
}//end func 