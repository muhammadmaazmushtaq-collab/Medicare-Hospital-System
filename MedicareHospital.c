#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, docID, symptom, timeSlot, paymentChoice;
    int age, patientID;
    long long phone;
    int fee = 0;
    float discount = 0;
    float total = 0;
    char name[50];
    int runSystem = 1;
    FILE *fptr;

    srand(time(0));

    do {
        printf("\n==========================================\n");
        printf("      WELCOME TO MEDICARE HOSPITAL        \n");
        printf("==========================================\n");
        
        printf("\n--- Doctor Directory ---\n");
        printf("1. Dr. Maaz (Neurologist)     [Fee: 2000]\n   Slots: Morning (9am-1pm) | Evening (5pm-9pm)\n");
        printf("2. Dr. Shavez (Orthopedic)    [Fee: 2500]\n   Slots: Morning (10am-2pm) | Evening (6pm-10pm)\n");
        printf("3. Dr. Sanawar (Cardiologist) [Fee: 1500]\n   Slots: Morning (8am-12pm) | Evening (4pm-8pm)\n");
        printf("4. Dr. Atzal (General Phy)    [Fee: 1000]\n   Slots: Morning (11am-3pm) | Evening (7pm-11pm)\n");

        printf("\n--- Patient Registration ---\n");
        printf("Enter Patient Name: ");
        scanf(" %[^\n]", name);
        
        printf("Enter Patient Age: ");
        scanf("%d", &age);
        
        printf("Enter Phone Number: ");
        scanf("%lld", &phone);
        
        patientID = (rand() % 9000 + 1000) + (age * 10) + (phone % 1000);
        printf("[System] Assigned Patient ID (MR): %d\n", patientID);

        printf("\n------------------------------------------\n");
        printf("Do you know which doctor to visit?\n");
        printf("1. Yes, I know.\n");
        printf("2. No, recommend based on symptoms.\n");
        printf("Enter choice (1 or 2): ");
        scanf("%d", &choice);

        docID = 0;

        if (choice == 1) {
            printf("\nSelect Doctor ID (1-4): ");
            scanf("%d", &docID);
        } 
        else if (choice == 2) {
            printf("\n--- Symptom Checker ---\n");
            printf("1. Severe Headache / Dizziness\n");
            printf("2. Joint Pain / Fracture\n");
            printf("3. Chest Pain / High BP\n");
            printf("4. Fever / Cough / Flu\n");
            printf("Select your main symptom (1-4): ");
            scanf("%d", &symptom);

            switch(symptom) {
                case 1: docID = 1; break;
                case 2: docID = 2; break;
                case 3: docID = 3; break;
                case 4: docID = 4; break;
                default: 
                    printf("Invalid Symptom!\n");
                    docID = 0;
            }
        } 
        else {
            printf("Invalid Choice.\n");
            docID = 0;
        }

        if (docID > 0 && docID <= 4) {
            
            switch(docID) {
                case 1: fee = 2000; break;
                case 2: fee = 2500; break;
                case 3: fee = 1500; break;
                case 4: fee = 1000; break;
            }

            printf("\nSelect Timing:\n");
            printf("1. Morning\n");
            printf("2. Evening\n");
            printf("Enter choice (1 or 2): ");
            scanf("%d", &timeSlot);

            if (age >= 60) {
                discount = fee * 0.20; 
            } else {
                discount = 0;
            }
            total = fee - discount;

            printf("\nSelect Payment Method:\n");
            printf("1. Cash\n");
            printf("2. Credit/Debit Card\n");
            printf("Enter choice: ");
            scanf("%d", &paymentChoice);

            printf("\n\n");
            printf("==========================================\n");
            printf("            FINAL INVOICE                 \n");
            printf("==========================================\n");
            printf("Patient ID:    %d\n", patientID);
            printf("Patient Name:  %s\n", name);
            printf("Phone:         %lld\n", phone);
            printf("Doctor:        ");
            
            if (docID == 1) {
                printf("Dr. Maaz (Neurologist)\n");
                printf("Timing:        %s\n", (timeSlot == 1) ? "9:00am - 1:00pm" : "5:00pm - 9:00pm");
            } 
            else if (docID == 2) {
                printf("Dr. Shavez (Orthopedic)\n");
                printf("Timing:        %s\n", (timeSlot == 1) ? "10:00am - 2:00pm" : "6:00pm - 10:00pm");
            }
            else if (docID == 3) {
                printf("Dr. Sanawar (Cardiologist)\n");
                printf("Timing:        %s\n", (timeSlot == 1) ? "8:00am - 12:00pm" : "4:00pm - 8:00pm");
            }
            else if (docID == 4) {
                printf("Dr. Atzal (General Phy)\n");
                printf("Timing:        %s\n", (timeSlot == 1) ? "11:00am - 3:00pm" : "7:00pm - 11:00pm");
            }

            printf("Total Payable: %.2f PKR\n", total);
            printf("Payment:       %s\n", (paymentChoice == 1) ? "Cash" : "Credit Card");
            printf("Appointment confirmed! See you soon.\n");
            printf("==========================================\n");

            fptr = fopen("hospital_data.txt", "a");
            
            if (fptr != NULL) {
                fprintf(fptr, "%d %s %lld %d %.2f %d\n", patientID, name, phone, age, total, paymentChoice);
                fclose(fptr);
                printf("[System]: Record saved to file successfully.\n");
            } else {
                printf("Error opening file!\n");
            }

        } else {
            printf("\nCould not proceed due to invalid selection.\n");
        }

        printf("\nDo you want to register another patient? (1 Yes / 0 Exit): ");
        scanf("%d", &runSystem);

    } while (runSystem == 1);

    printf("\n==========================================\n");
    printf("       System Shutting Down...            \n");
    printf("Group Members:\n");
    printf("Muhammad Maaz Mushtaq (CS251041)\n");
    printf("Shavez (CS251075)\n");
    printf("Sanawar Hyder (CS251034)\n");
    printf("Atzal (CS251269)\n");
    printf("==========================================\n");

    return 0;
}
