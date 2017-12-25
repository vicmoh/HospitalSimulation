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
    char const* const fileName = argv[1];
    FILE* filePointer = fopen(fileName, "r");
    char patientID[100], patientCode[100], input[100];
    int patientPriority, numOfLine=0, menu=0, numOfScan=0;
    int timer = 1;

    //if there is no file
    if(filePointer == NULL){
        printf("No such file\n");
        return 0;
    }//end if

    //init list for queues
    Queues* preLine = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line1 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line2 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line3 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line4 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* line5 = initializeQueues(dummyPrint, dummyDelete, dummyCompare);
    Queues* postLine = initializeQueues(dummyPrint, dummyDelete, dummyCompare); 

    //scan until end of file
    while(numOfScan != EOF){
        numOfLine = numOfLine + 1;
        numOfScan = fscanf(filePointer, "%s %d %s\n", patientID, &patientPriority, patientCode);
        void* patient = createPatient(patientID, patientPriority, patientCode);
        insert(preLine, patient);
    }//end while
    
    //delete the weird random extra duplicate at the end
    pop(preLine, getFromBack(preLine->list));

    //print the incoming client
    //printf("\nIncoming patients...\n");
    //printSomePatient(preLine);

    //assign the patient to segment line
    //printf("\nAssigning patient...\n");
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

    /*print which patient is being assign
    printf("\n");
    if(line1->list->head != NULL){
        printf("Priority 1 assigned to line 1...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line1);
        printf("\n");
    }
    if(line2->list->head != NULL){
        printf("Priority 2 assigned to line 2...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line2);
        printf("\n");
    }
    if(line3->list->head != NULL){
        printf("Priority 3 assigned to line 3...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line3);
        printf("\n");
    }
    if(line4->list->head != NULL){
        printf("Priority 4 assigned to line 4...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line4);
        printf("\n");
    }
    if(line5->list->head != NULL){
        printf("Priority 5 assigned to line 5...\n");
        printf("PatientID\t Priority\t Stymptom Code\n");
        printSomePatient(line5);
        printf("\n");
    }*/

    //empty postLine after diagnose
    tempNode = postLine->list->head;
    while(tempNode != NULL) {
        tempNode = tempNode->next;
        pop(postLine, getFromFront(postLine->list));
    }//end while

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
    //while loop the menu until exit
    do{
       //ask the user of the menu option
        printf("\n");
        printf("1) Adding a new patient.\n");
        printf("2) Processing the full simulation.\n");
        printf("3) Exit the program.\n");
        printf("Enter the number for the menu:\n");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';
        menu = atoi(input);
        //segment the option based on what you choose
        if(menu == 1){
            //empty postLine after diagnose
            tempNode = postLine->list->head;
            while(tempNode != NULL) {
                tempNode = tempNode->next;
                pop(postLine, getFromFront(postLine->list));
            }//end while

            //enter the id
            do{
                printf("Enter the patient ID:\n");
                fgets(patientID, 100, stdin);
                patientID[strlen(patientID)-1] = '\0';
                //ask again if code is more than 8
                if(strlen(patientID) > 7){
                    printf("Input ID maximum 7 characters.\n");
                    printf("Please re-enter.\n");
                }//end if
            }while(patientID[0] == '\0' || strlen(patientID) > 7);
            //ask for priority
            do{ 
                printf("Enter the patient priority:\n");
                fgets(input, 100, stdin);
                input[strlen(input)-1] = '\0';
                patientPriority = atoi(input);
            }while(patientPriority < 1 || patientPriority > 5);
            //ask for the code
            int symptomCheck = 0;
            do{
                printf("Enter the patient code:\n");
                fgets(patientCode, 100, stdin);
                patientCode[strlen(patientCode)-1] = '\0';
                //asign patient to proper line
                symptomCheck = codeCheck(patientCode);
            }while(symptomCheck != 1);

            //assign the patient to correct line
            if(patientPriority == 1){
                void * patient = createPatient(patientID, patientPriority, patientCode);
                insert(line1, patient);
            }else if(patientPriority == 2){
                void * patient = createPatient(patientID, patientPriority, patientCode);
                insert(line2, patient);
            }else if(patientPriority == 3){
                void * patient = createPatient(patientID, patientPriority, patientCode);
                insert(line3, patient);
            }else if(patientPriority == 4){
                void * patient = createPatient(patientID, patientPriority, patientCode);
                insert(line4, patient);
            }else if(patientPriority == 5){
                void * patient = createPatient(patientID, patientPriority, patientCode);
                insert(line5, patient);
            }//else if

            /*print which patient is being assign
            printf("\n");
            if(line1->list->head != NULL){
                printf("Priority 1 assigned to line 1...\n");
                printf("PatientID\t Priority\t Stymptom Code\n");
                printSomePatient(line1);
                printf("\n");
            }
            if(line2->list->head != NULL){
                printf("Priority 2 assigned to line 2...\n");
                printf("PatientID\t Priority\t Stymptom Code\n");
                printSomePatient(line2);
                printf("\n");
            } 
            if(line3->list->head != NULL){
                printf("Priority 3 assigned to line 3...\n");
                printf("PatientID\t Priority\t Stymptom Code\n");
                printSomePatient(line3);
                printf("\n");
            }
            if(line4->list->head != NULL){
                printf("Priority 4 assigned to line 4...\n");
                printf("PatientID\t Priority\t Stymptom Code\n");
                printSomePatient(line4);
                printf("\n");
            }
            if(line5->list->head != NULL){
                printf("Priority 5 assigned to line 5...\n");
                printf("PatientID\t Priority\t Stymptom Code\n");
                printSomePatient(line5);
                printf("\n");
            }*/

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
        }else if(menu == 2){
            //print the sorted list
            printf("\nPost patient line-up...\n");
            printf("PatientID\t Priority\t Stymptom Code\t Time Finished\n");
            printAllPatient(postLine);
            printf("\n");
            //exit the program
            printf("Program is exiting...\n");
            return 0;
        }else if(menu == 3){
            printf("Program is exiting...\n");
        }else{
            printf("\nInvalid input, please re-enter.\n\n");
        }//end if
    }while(menu != 3);

    //exit the program
    return 0;
}//end main