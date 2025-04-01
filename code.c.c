#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user
{
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main(){

struct user usr,usr1;
int opt,choice;
FILE *fp;
char filename[50],phone[50],pword[50];
char cont ='y';
float amount;

printf("Welcome Valued Customer!!!\n");

printf("\nWhat do you want to do?\n");
printf("\n1. Register an account\n");
printf("\n2. Login to account");

printf("\n\nYour Choice: ");
scanf("%d",&opt);

if(opt ==1){
    
    printf("Enter your Account Number: \t");
    scanf("%s",usr.ac);

    printf("\nEnter your phone number: \t");
    scanf("%s",usr.phone);

    printf("\nEnter your new password: \t");
    scanf("%s",usr.password);

    usr.balance =0;
    strcpy(filename,usr.phone);
    strcat(filename, ".dat");

    fp =fopen(filename,"w");
    fwrite(&usr,sizeof(struct user),1,fp);

    if(fwrite != 0){
        printf("\n\nAccount Successfully registered");

    }
    else{

        printf("\n\nSomething went wrong try again");
    }

fclose(fp);

}

if(opt ==2){


    printf("\nKindly Login to your Account\n");
    printf("\nPhone NUmber: \t");
    scanf("%s",phone);
    printf("\nPassword: \t");
    scanf("%s",pword);
    
    strcpy(filename,phone);
    strcat(filename,".dat");
    
    fp = fopen(filename,"r");

    if(fp == NULL){
        printf("\n Account Number not registered");
        printf("\nThank you for visiting");
        return 1;
    }

    else{

        fread(&usr,sizeof(struct user),1,fp);

        fclose(fp);

        if(!strcmp(pword,usr.password)){
            while(cont == 'y'){
                printf("\nPress 1 for balance enquiry");
                printf("\nPress 2 to deposit an amount");
                printf("\nPress 3 for cash withdrawl");
                printf("\nPress 4 for online transfer");
                printf("\nPress 5 for password change\n");
                printf("\nYour Choice:");
                scanf(" %d",&choice);

                switch(choice){

                case 1:
                    printf("\nYour current balance is %.2f\n",usr.balance);
                    system("pause");
                    break;
                case 2:
                    printf("\nEnter the amount to deposit:\t");
                    scanf("%f",&amount);
        
                    usr.balance +=amount;
        
                    fp =fopen(filename,"w");
                    fwrite(&usr,sizeof(struct user),1,fp);
        
                    if(fwrite != NULL)
                        printf("\nSuccessfully  Deposited");
                    
                    fclose(fp);
                    break;

                case 3:
                    printf("\nEnter the amount for withdrawal:\t");
                    scanf("%f",&amount);
                    if(amount<= usr.balance){
                        usr.balance-=amount;
                        fp =fopen(filename,"w");
                        if(fwrite(&usr, sizeof(struct user), 1, fp)){
                            printf("\nSuccessfully Withdrawn Rs %.2f", amount);
                        }
                        fclose(fp);
                    }
                    else{
                        printf("\nInsufficient balance.");
                    }
                    break;


                case 4:
                    printf("\nPlease enter the phone number to transfer the balance: ");
                    scanf("%s",phone);
                    printf("Enter amount to transfer: \t");
                    scanf("%f",&amount);

                    strcpy(filename,phone);
                    strcat(filename,".dat");
                    
                    fp =fopen(filename,"r");

                    if(fp == NULL){
                        printf("\nAccount Number not registered");
                    }

                    else{
                        fread(&usr1,sizeof(struct user),1,fp);
                        fclose(fp);
                        if(amount>usr.balance){
                            printf("\nInsufficient Balance");
                        }

                        else{
                            fp =fopen(filename,"w");
                            usr1.balance += amount;
                            fwrite(&usr1,sizeof(struct user),1,fp);
                            fclose(fp);

                            if(fwrite != NULL){
                                printf("\nYou have successfully transferred Rs %0.2f to %s",amount,phone);
                            }
                            fclose(fp);
                            strcpy(filename,usr.phone);
                            fp =fopen(strcat(filename,".dat"),"w");
                            usr.balance -= amount;
                            fwrite(&usr,sizeof(struct user),1,fp);
                            if (fwrite(&usr, sizeof(struct user), 1, fp)) {
                                printf("\nTransfer successful.");
                            }
                            fclose(fp);
                           
                            }
                        }
                        break;


                case 5:
                printf("\nPlease enter your new password: ");
                scanf("%s",pword);
                fp =fopen(filename,"w");
                strcpy(usr.password,pword);
                fwrite(&usr,sizeof(struct user),1,fp);
                if(fwrite != NULL){
                printf("\nPassword Successfully Chnaged");
                printf("\n");

                    }
                    fclose(fp);
                    break;


                }

                printf("\nDo you want to continue the transaction [y/n]");
                scanf("%s",&cont);

            }


        }
        else{
            printf("\nInvalid Password");        }
    }


    }


    
return 0;
}