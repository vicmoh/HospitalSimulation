/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

#ifndef PATIENT_H
#define PATIENT_H

/*
*struct for patients class
*/
typedef struct patient{
    char id[100];
    int priority;
    char code[100];
    int time;
} Patient;

/*
*constructor for creating patients
*param id 
*param pririty
*param code
*/
Patient* createPatient(char* id, int priority, char* code);

/*
*get the client id
*param the patient
*return the object
*/
char* getClientID(Patient* patient); 

/*
*get the priority
*param the patient
*return the priority
*/
int getPriority(Patient* patient);

/*
get the code pf patient
*param patients
*reutnr the code
*/
char* getCode(Patient* patient); 

/*
print the patients
*/
void printPatient(void* patient);

/*
print the patient without the time
*/
void printPatientNoTime(void * patient);

/*
*get the time of the patients
*param parients
*return the patient time
*/
int getTime(Patient* patient);

/*
set the time
*param the patien and the time 
*/
void setTime(Patient* patient, int time);

#endif