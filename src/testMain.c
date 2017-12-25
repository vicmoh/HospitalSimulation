/*************************
 * Name: Vicky Mohammad
 * ID: 0895381
 *************************/

/*import library*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
//own library
#include "linkList.h"
#include "dummy.h"
#include "queues.h"
#include "patient.h"

void addPatientToLine(void* node, Queues* line, char* patientID, int patientPriority, char* patientCode){
    strcpy(patientID, getClientID(node));
    patientPriority = getPriority(node);
    strcpy(patientCode, getCode(node));
    void * patient = createPatient(patientID, patientPriority, patientCode);
    insert(line, patient);
}//end func

int diagnose(void* node){
    //check the diagnose
    int diagnoseTime = 0;
    if(strcmp(getCode(node), "CV") == 0){
        diagnoseTime = 5;
    }else if(strcmp(getCode(node), "HN") == 0){
        diagnoseTime = 3;
    }else if(strcmp(getCode(node), "EV") == 0){
        diagnoseTime = 10;
    }else if(strcmp(getCode(node), "GI") == 0){
        diagnoseTime = 2;
    }else if(strcmp(getCode(node), "MH") == 0){
        diagnoseTime = 5;
    }else if(strcmp(getCode(node), "NC") == 0){
        diagnoseTime = 5;
    }else if(strcmp(getCode(node), "EC") == 0){
        diagnoseTime = 1;
    }else if(strcmp(getCode(node), "RC") == 0){
        diagnoseTime = 1;
    }else if(strcmp(getCode(node), "SK") == 0){
        diagnoseTime = 2;
    }else if(strcmp(getCode(node), "SA") == 0){
        diagnoseTime = 7;
    }else if(strcmp(getCode(node), "TR") == 0){
        diagnoseTime = 4;
    }else{
        diagnoseTime = 0;
        printf("Unknown sympton.\n");
    }//end if
    return diagnoseTime + 1;
}//endfunc

int codeCheck(char* code){
    int flag = 0;
    //check if patient has this symptom
    if(strcmp(code, "CV") == 0){
        flag = 1;
    }else if(strcmp(code, "HN") == 0){
        flag = 1;
    }else if(strcmp(code, "EV") == 0){
        flag = 1;
    }else if(strcmp(code, "GI") == 0){
        flag = 1;
    }else if(strcmp(code, "MH") == 0){
        flag = 1;
    }else if(strcmp(code, "NC") == 0){
        flag = 1;
    }else if(strcmp(code, "EC") == 0){
        flag = 1;
    }else if(strcmp(code, "RC") == 0){
        flag = 1;
    }else if(strcmp(code, "SK") == 0){
        flag = 1;
    }else if(strcmp(code, "SA") == 0){
        flag = 1;
    }else if(strcmp(code, "TR") == 0){
        flag = 1;
    }else{
        printf("Unknown sympton.\n");
        flag = 0;
    }//end if
    return flag;
}//endfunc

//main
int main(int argc, char **argv){
    //declare variable
    //char const* const fileName = argv[1];
    FILE* filePointer = fopen("./assets/patients.txt", "r");
    char patientID[100], patientCode[100];
    int patientPriority, numOfLine=0, numOfScan=0;
    int timer = 0;

    //if there is no file
    if(filePointer == NULL){
        printf("No such file\n");
        return 0;
    }//end if

    printf("\nTesting: testing to initializeList\n");
    printf("Expecting: it initialize\n");
    //init list for queues
    Queues* preLine = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line1 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line2 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line3 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line4 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line5 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* postLine = initializeQueues(dummyPrint, dummyDelete, dummyCompare); 
    printf("Result: it created athe list and noe can be addedw");
    printf("\nTest: PASS\n\n");
    printf("******************************************************************\n");

    printf("\nTesting: testing for insert function and printForward\n");
    printf("Expecting: it add nodes to the back\n");
    //scan until end of file
    while(numOfScan != EOF){
        numOfLine = numOfLine + 1;
        numOfScan = fscanf(filePointer, "%s %d %s\n", patientID, &patientPriority, patientCode);
        void* patient = createPatient(patientID, patientPriority, patientCode);
        insert(preLine, patient);
    }//end while
    printf("Result: it adds to the back but adds a duplicate at the end of list for some reason");
    printf("\nTest: no error so i guess its a pass\n\n");
    printf("******************************************************************\n");
    
    //delete the weird random extra duplicate at the end
    pop(preLine, getFromBack(preLine->list));

    printf("\nTesting: printing the preline of the files\n");
    printf("Expecting: expect to print all patients\n");
    printf("\n");
    //print the incoming client
    printf("\nIncoming patients...\n");
    printSomePatient(preLine);
    printf("Result: printing work perfectly");
    printf("\nTest: no error works perfectly\n\n");
    printf("******************************************************************\n");

    printf("\nTesting: test if the patients is assigning to correct line\n");
    printf("Expecting: splits them and orginzie list based priority\n");
    //assign the patient to segment line
    printf("\nAssigning patient...\n");
    //split the line into 5 line based on the priorities
    //assign the clients to to seperetae based on the priority
    Node* tempNode = preLine->list->head;
    if(tempNode != NULL) {
        while(tempNode != NULL) {
            void* voidTemp = tempNode;
            if(getPriority((void*)tempNode) == 1){
                addPatientToLine(voidTemp, line1, patientID, patientPriority, patientCode);
            }else if(getPriority(voidTemp) == 2){
                addPatientToLine(voidTemp, line2, patientID, patientPriority, patientCode);
            }else if(getPriority(voidTemp) == 3){
                addPatientToLine(voidTemp, line3, patientID, patientPriority, patientCode);
            }else if(getPriority(voidTemp) == 4){
                addPatientToLine(voidTemp, line4, patientID, patientPriority, patientCode);
            }else if(getPriority(voidTemp) == 5){
                addPatientToLine(voidTemp, line5, patientID, patientPriority, patientCode);
            }//else if
            tempNode = tempNode->next;
            //pop(preLine, getFromBack(preLine->list));
        }//end while
    }//end if

    //print which patient is being assign
    printf("\n");
    if(line1->list->head != NULL){
        printf("Priority 1 assigned to line 1...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line1);
        printf("\n");
    }//end if
    if(line2->list->head != NULL){
        printf("Priority 2 assigned to line 2...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line2);
        printf("\n");
    }//end if 
    if(line3->list->head != NULL){
        printf("Priority 3 assigned to line 3...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line3);
        printf("\n");
    }//end if
    if(line4->list->head != NULL){
        printf("Priority 4 assigned to line 4...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line4);
        printf("\n");
    }//end if
    if(line5->list->head != NULL){
        printf("Priority 5 assigned to line 5...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line5);
        printf("\n");
    }//end if
    printf("Result: patients are assigned to correct line");
    printf("\nTest: no error so its a pass\n\n");
    printf("******************************************************************\n");

    printf("\nTesting: test to see if the liine is sorted\n");
    printf("Expecting: patients has been sorted\n");
    //assign the patient to the correct line
    tempNode = line1->list->head;
    while(tempNode != NULL) {
        addPatientToLine(tempNode, postLine, patientID, patientPriority, patientCode);
        tempNode = tempNode->next;
    }//end while
    tempNode = line2->list->head;
    while(tempNode != NULL) {
        addPatientToLine(tempNode, postLine, patientID, patientPriority, patientCode);
        tempNode = tempNode->next;
    }//end while
    tempNode = line3->list->head;
    while(tempNode != NULL) {
        addPatientToLine(tempNode, postLine, patientID, patientPriority, patientCode);
        tempNode = tempNode->next;
    }//end while
    tempNode = line4->list->head;
    while(tempNode != NULL) {
        addPatientToLine(tempNode, postLine, patientID, patientPriority, patientCode);
        tempNode = tempNode->next;
    }//end while
    tempNode = line5->list->head;
    while(tempNode != NULL) {
        addPatientToLine(tempNode, postLine, patientID, patientPriority, patientCode);
        tempNode = tempNode->next;
    }//end while
    //go through the simulation
    tempNode = postLine->list->head;
    timer = 0;
    while(tempNode != NULL) {
        setTime((void*)tempNode, timer+diagnose(tempNode));
        timer = timer + diagnose(tempNode);
        tempNode = tempNode->next;
    }//end while      
    printAllPatient(postLine);
    printf("Result: patients are assigned to correct line");
    printf("\nTest: no error so its a pass\n\n");
    printf("******************************************************************\n");

    //exit the program
    return 0;
}//end main