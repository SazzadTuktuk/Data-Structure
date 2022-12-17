//Clinic Management System
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include <fstream>
#include <iostream>
using namespace std;

// Head of Patient,Doctor and Staff


struct Patient
{
    char patient_name[40];
    char gender[6];
    char age[3];
    char admit_date[11];
    char release_date[11];
    char bed_no[4];
    struct Patient *next_p;
}*patient,*p_temp,*p_temp1;

struct Doctor
{
    char doctor_name[50];
    char doctor_gender[6];
    char specialist[50];
    char designation[30];
    struct Doctor *next_d;
}*doctor,*d_temp,*d_temp1;


struct Staff
{
    char staff_name[50];
    char staff_gender[6];
    char staff_rank[20];
    char staff_work[20];
    struct Staff *next_s;
}*staff,*s_temp,*s_temp1;

struct Head
{
    int count_p,count_d,count_s;
    struct Patient *p_p;
    struct Doctor *d_p;
    struct Staff *s_p;
}*p_h,*d_h,*s_h;


void create_head()//Head creation of patient Doctor and Staff
{
    p_h=(struct Head*)malloc(sizeof(struct Head));
    p_h->count_p=0;
    p_h->p_p=NULL;

    d_h=(struct Head*)malloc(sizeof(struct Head));
    d_h->count_d=0;
    d_h->d_p=NULL;

    s_h=(struct Head*)malloc(sizeof(struct Head));
    s_h->count_s=0;
    s_h->s_p=NULL;


}

void create_patient_node()
{
    patient=(struct Patient*)malloc(sizeof(struct Patient));

    //printf("Enter Patient Name : ");
    fgets(patient->patient_name,40,stdin);
    printf("\n");
     printf("Enter Patient Name : ");
    gets(patient->patient_name);
    printf("\n");
    printf("Enter Patient Gender : ");
    fgets(patient->gender,6,stdin);
    printf("\n");
    printf("Enter Patient Age : ");
    gets(patient->age);
    printf("\n");
    printf("Enter Patient Bed no : ");
    gets(patient->bed_no);
    printf("\n");
    printf("Enter Patient Admit Date : ");
    gets(patient->admit_date);
    printf("\n");
getch();

/*
    char patient_name[50];/
    char gender[6];/
    char age[3];/
    char admit_date[11];
    char release_date[11];
    patient data input





    */
}
void create_doctor_node()
{
    doctor=(struct Doctor*)malloc(sizeof(struct Doctor));

    printf("Enter Doctor Name : ");
    gets(doctor->doctor_name);
    gets(doctor->doctor_name);
    printf("\n");
    printf("Enter Patient Gender : ");
    gets(doctor->doctor_gender);
    printf("\n");
    printf("Enter Specialist : ");
    gets(doctor->specialist);
    printf("\n");
    printf("Enter Designation : ");
    gets(doctor->designation);
    printf("\n");
     /*
    char doctor_name[50];
    char doctor_gender[6];
    char specialist[50];
    char designation[30];
    doctor data input
    */

}
void create_staff_node()
{
    staff=(struct Staff*)malloc(sizeof(struct Staff));
    printf("Enter Staff Name : ");
    gets(staff->staff_name);
    gets(staff->staff_name);
    printf("\n");
    printf("Enter Staff Gender : ");
    gets(staff->staff_gender);
    printf("\n");
    printf("Enter Staff Rank : ");
    gets(staff->staff_rank);
    printf("\n");
    printf("Enter Staff Work : ");
    gets(staff->staff_work);
    printf("\n");


    /*
    char staff_name[50];
    char staff_gender[6];
    char staff_rank[20];
    char staff_work[20];
    staff data input
    */
}
//
//
//    Adding Nodes Starts
void add_partient()
{
    printf("Input Patient Info: \n");
    create_patient_node();
    patient->next_p=p_h->p_p;
    p_h->p_p=patient;
    p_h->count_p++;
}

void add_doctor()
{
    printf("Input Doctor Info:\n ");
    create_doctor_node();
    doctor->next_d=d_h->d_p;
    d_h->d_p=doctor;
    d_h->count_d++;

}

void add_staff()
{
    printf("Input Staff Info: \n");
    create_staff_node();
    staff->next_s=s_h->s_p;
    s_h->s_p=staff;
    s_h->count_s++;
}
//
//
//    Adding Nodes Finish

//
//
//
// Display Functions Starts
void patient_display()
{
    printf("\nPatient List \n ");
    if(p_h->count_p > 0){
            p_temp=p_h->p_p;
    while(p_temp!=NULL)
    {
        printf("Patient Name : ");
    puts(p_temp->patient_name);
    printf("\n");
    printf("Patient Gender : ");
    puts(p_temp->gender);
    printf("\n");
    printf("Patient Age : ");
    puts(p_temp->age);
    printf("\n");
    printf("Enter Patient Bed no : ");
    puts(p_temp->bed_no);
    printf("Admit Date : ");
    puts(p_temp->admit_date);
    printf("\n");
        p_temp=p_temp->next_p;
    }
    printf("\n\n");
    }
    else printf("No patient is listed Yet)\n\n");

}
void doctor_display()
{
    printf("\nDoctor List ");
    if(d_h->count_d > 0){
            d_temp=d_h->d_p;
    while(d_temp!=NULL)
    {
        printf("Doctor Name : ");
    puts(d_temp->doctor_name);
    printf("\n");
    printf("Patient Gender : ");
    puts(d_temp->doctor_gender);
    printf("\n");
    printf("Specialist : ");
    puts(d_temp->specialist);
    printf("\n");
    printf("Designation : ");
    puts(d_temp->designation);
    printf("\n");
        d_temp=d_temp->next_d;
    }
    printf("\n\n");
    }
    else printf("No Doctor is listed Yet)\n\n");

}

void staff_display()
{
    printf("\n Staff List ");
    if(s_h->count_s > 0){
            s_temp=s_h->s_p;
    while(s_temp!=NULL)
    {

        printf("Staff Name : ");
    puts(s_temp->staff_name);
    printf("\n");
    printf("Staff Gender : ");
    puts(s_temp->staff_gender);
    printf("\n");
    printf("Staff Rank : ");
    puts(s_temp->staff_rank);
    printf("\n");
    printf("Staff Work : ");
    puts(s_temp->staff_work);
    printf("\n");

        s_temp=s_temp->next_s;
    }
    printf("\n\n");
    }
    else printf("No Staff is listed Yet)\n\n");

}

//
//
//
// Display Functions Finish

//
//
// Search option Starts

void patient_search()
{
    int choice,found=0;
    if(p_h->count_p>0)
        {
    int i=0;
    char n[3];
    char name[60];
    printf("\n Search Patient \n");
    printf("1. For Bed \n 2. For Name \n");
    scanf("%d",&choice);

    if(choice==1)
    {


        printf("Enter Bed no : ");
        gets(n);
        p_temp=p_h->p_p;
        for(i=1; i<=p_h->count_p; i++)
        {
            if(strcmp(p_temp->bed_no,n)==0)
            {
                found=1;
                break;
            }
                p_temp=p_temp->next_p;
        }
    if(found==1)
    {
    printf("Patient Name : ");
    puts(p_temp->patient_name);
    printf("\n");
    printf("Patient Gender : ");
    puts(p_temp->gender);
    printf("\n");
    printf("Patient Age : ");
    puts(p_temp->age);
    printf("\n");
    printf("Enter Patient Bed no : ");
    puts(p_temp->bed_no);
    printf("Admit Date : ");
    puts(p_temp->admit_date);
    printf("\n");
    }

    else {printf("Inputted bed number %s is not found in the list\n",n);}
    }


    else if(choice==2)
           {

            printf("Enter Patient Name : ");
            gets(name);
            p_temp=p_h->p_p;
            for(i=1; i<=p_h->count_p; i++)
        {
            if(strcmp(p_temp->patient_name,name)==0)
            {
                found=1;
                break;
            }
                p_temp=p_temp->next_p;
        }
    if(found==1)
    {
    printf("Patient Name : ");
    puts(p_temp->patient_name);
    printf("\n");
    printf("Patient Gender : ");
    puts(p_temp->gender);
    printf("\n");
    printf("Patient Age : ");
    puts(p_temp->age);
    printf("\n");
    printf("Enter Patient Bed no : ");
    puts(p_temp->bed_no);
    printf("Admit Date : ");
    puts(p_temp->admit_date);
    printf("\n");
    }

    else
        {
            printf("Inputted name %s is not found in the list\n",name);
        }
           }

        else
            {printf("Inviolat Input!!!\n\n");
        }
}

}
//
//
// Search option finish

//
//
// Delete option Starts

void delete_patient()
{
    if(p_h->count_p>0){
    char patientBed[3],j;
    printf("which Bed's Patient u want to Delete : ");
    gets(patientBed);
    gets(patientBed);
    p_temp = p_h->p_p;

    while((p_temp->next_p != NULL) && (strcmp(p_temp->bed_no,patientBed)==0))

    {
        p_temp1 = p_temp;
        p_temp=p_temp->next_p;

    }


        if(strcmp(p_temp->bed_no,patientBed)==0)
        {
            p_temp1->next_p=p_temp->next_p;
            free(p_temp);
        }

p_h->count_p--;}

else{printf("\n Sorry no patient is included \n");}}


void delete_doctor()
{
    if(p_h->count_p>0){
    char doctorName[50],j;
    printf("which Doctor u want to Delete : ");
    gets(doctorName);
    d_temp = d_h->d_p;

    while((d_temp->next_d != NULL) && (strcmp(d_temp->doctor_name,doctorName)==1))

    {
        d_temp1 = d_temp;
        d_temp = d_temp->next_d;

    }


        if(strcmp(d_temp->doctor_name,doctorName)==0)
        {
            d_temp1->next_d=d_temp->next_d;
            free(d_temp);
        }

d_h->count_d--;}
else{printf("\n Sorry no Doctor is included \n");}
}

void delete_staff()
{
    if(p_h->count_p>0)
    {
    char staffName[50],j;
    printf("which Staff u want to Delete : ");
    gets(staffName);
    s_temp = s_h->s_p;

    while((s_temp->next_s != NULL) && (strcmp(s_temp->staff_name,staffName)==1))

    {
        s_temp1 = s_temp;
        s_temp = s_temp->next_s;

    }


        if(strcmp(s_temp->staff_name,staffName)==0)
        {
            s_temp1->next_s=s_temp->next_s;
            free(s_temp);
        }

s_h->count_s--;}
else{printf("\n Sorry no staff is included \n");}}

//
//
// Search option Finish

int main()
{
 printf("\n  Welcome to Hospital Management System\n");
    create_head();

    int ch;
    do
    {
        printf("\n  1.Patient\n");
        printf("  2.Doctor \n");
        printf("  3.Staff\n");
        printf("  4.Exit\n");
        printf(" \n\nEnter Your Choice:\n");
        int n;
        scanf("%d", &n);
        switch(n)
        {
        case 1:
        	printf(" 1.Add patient\n");
            printf(" 2.Delete patient\n");
            printf(" 3.Show all patient \n");
            printf(" 4.Search patient\n");
            printf(" \n\nEnter Your Choice:\n");
            int s;
            scanf("%d",&s);
        switch(s)
        {
        case 1:

            add_partient();
            break;
        case 2:
        	delete_patient();
            break;
        case 3:
            patient_display();
            break;
        case 4:
            patient_search();
			break;
		default:
		 	printf("\n invalid");
	    }
	    break;

        case 2:
        	printf("\n 1.Add Doctor\n 2. Remove Doctor \n 3.Show all doctor \n");
        	printf("Enter choice: \n");
        	int m;
        	scanf("%d",&m);
        	switch(m)
        	{
        		case 1:
        			add_doctor();
        			break;
        		case 2:
        			delete_doctor();
        			break;
        		case 3:
        		    doctor_display();
        		    break;
        		case 4:
        			exit(1);
        			break;
        		default:
        			printf("invalid input\n");
        			break;
			}
			break;
        case 3:
            printf("\n 1.Add Staff\n 2. Remove Staff \n 3.Show Staff \n");
        	printf("Enter choice: \n");
        	int k;
        	scanf("%d",&k);
        	switch(k)
        	{
        		case 1:
        			add_staff();
        			break;
        		case 2:
        			delete_staff();
        			break;
        		case 3:
        		    staff_display();
        		    break;
        		case 4:
        			exit(1);
        			break;
        		default:
        			printf("invalid input\n");
        			break;
			}
            break;

        case 4:

            exit(1);
            break;
        default:
        {
            printf("\n\n Invalid input! \n ");
            break;
        }
        }

    }
    while(ch!=4);



    return 0;

}

