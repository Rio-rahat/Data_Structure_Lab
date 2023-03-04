#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

//Structure
typedef struct mdeicine{
    char medicine_name[30];
    char customer_name[30];
    int Medicine_ID;
    int quantity;
	float sale;
	int squantity;
	float total;
	float unit;
	float cost;
	float profit;
}medicine;

// Function Prototype
void purchaseMedicine();
// void saleMedicine();
void searchMedicine();
void stockMedicine();


int main(){
    int num;
    do{
        system("cls");
        printf("\n\n\n");
        printf("\t================================= Welcome to Medical Store Management System =================================\n\n");
        printf("\t\t\t\t\t\t[1]=> PURCHASE NEW MEDICINE\n\n");
        printf("\t\t\t\t\t\t[2]=> SALE MEDICINE\n\n");
        printf("\t\t\t\t\t\t[3]=> SEARCH MEDICINE\n\n");
        printf("\t\t\t\t\t\t[4]=> STOCK OF MEDICINE\n\n");
        printf("\t\t\t\t\t\t[6]=> Exit\n\n");
        printf("\t================================= ******************************************* =================================\n\n");
        printf("\t\t\t\t\t\t Enter Your Choice: ");
        scanf("%d",&num);

        switch(num){
        case 1:
            purchaseMedicine();
            break;
        case 2:
            saleMedicine();
            break;
        case 3:
            searchMedicine();
            break;
        case 4:
            stockMedicine();
            break;
        }
        getch();
    }while(num!=6);

    return 0;
}

//Function Definition
void purchaseMedicine(){
    system("cls");
    medicine *s;
    int n, i;

    printf("Enter Medicine Type Amount: ");
    scanf("%d",&n);

    FILE *fp;

    s = (medicine*)calloc(n,sizeof(medicine));

    if(!fp){
        fp = fopen("MedicineDB.txt","w");
    }
    else{
        fp = fopen("MedicineDB.txt","a");
    }
    for(i=0; i<n; i++){

        printf("Enter Medicine ID: ");
        scanf("%d",&s[i].Medicine_ID);
        fflush(stdin);
        printf("Enter Medicine Name: ");
        gets(s[i].medicine_name);
        printf("Unit Cost Tk.: ");
        scanf("%f",&s[i].unit);
        printf("Sale Cost Tk.: ");
        scanf("%f",&s[i].cost);

        printf("Quantity: ");
        scanf("%d",&s[i].quantity);
        printf("\n");
        printf("***********************************************\n");
        printf("Total Cost: %.2f \t\t Total Sale: %.2f\n",s[i].unit * s[i].quantity,s[i].cost*s[i].quantity);
        fwrite(&s[i],sizeof(medicine),1,fp);
    }
    fclose(fp);
}


void saleMedicine(){
    system("cls");
     medicine s1;
     int mno, found=0, num;
     FILE *fp, *fp1;

     fp = fopen("MedicineDB.txt","r");
     fp1 = fopen("temp.txt","w");

     printf("Enter Medicine Id: ");
     scanf("%d",&mno);
     printf("Enter Quantity: ");
     scanf("%d",&s1.squantity);
     printf("\nID             NAME                  QUANTITY             PRICE        ");
     printf("\n_____________________________________________________________________\n");
     while(fread(&s1,sizeof(medicine),1,fp)){
        if(mno == s1.Medicine_ID && s1.quantity > s1.squantity){
            found =1;
            printf("\n%-15d%-30s%-7.d %-11.2f\n",s1.Medicine_ID,s1.medicine_name,s1.squantity,s1.cost);
            s1.quantity = s1.quantity - s1.squantity;

        }
        fwrite(&s1,sizeof(medicine),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt","r");
        fp = fopen("MedicineDB.txt","w");

        while(fread(&s1,sizeof(medicine),1,fp1)){
            fwrite(&s1,sizeof(medicine),1,fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else{
        printf("\nDetails Not Found");
    }
}


void searchMedicine(){
    system("cls");
     medicine s1;
     int mno, found=0;
     FILE *fp;

     fp = fopen("MedicineDB.txt","r");

     printf("Enter Medicine Id: ");
     scanf("%d",&mno);
     printf("\nID             NAME                  QUANTITY           PRICE        ");
     printf("\n_____________________________________________________________________");
     while(fread(&s1,sizeof(medicine),1,fp)){

        if(mno == s1.Medicine_ID){
            found =1;
            printf("\n%-15d%-30s%-7.d %-11.2f\n",s1.Medicine_ID,s1.medicine_name,s1.quantity,s1.cost);
        }
    }
    if(!found){
        printf("\nDetails Not Found");
    }

     fclose(fp);
}


void stockMedicine(){
    system("cls");
     medicine s1;
     FILE *fp;

     printf("\nID             NAME                  QUANTITY           PRICE        ");
     printf("\n_____________________________________________________________________");

     fp = fopen("MedicineDB.txt","r");
     while(fread(&s1,sizeof(medicine),1,fp)){
        printf("\n%-15d%-30s%-7.d %-11.2f\n",s1.Medicine_ID,s1.medicine_name,s1.quantity,s1.cost);
     }

     fclose(fp);
}



// Binary Search
/*int binarySearch(int key, int arr[]){
    int left=0, right=6, middle;
    while(left<=right){
        middle = (left + right)/2;
        if(a[middle]==key){
            //printf();
            return 0;
        }
        else if(a[middle]< key){
            left = middle+1;
        }
        else{
            right = middle -1;
        }
    }
    printf("Itm not found\n");

}


// Bubble Sort
int bubbleSort(){
    int i, j, swap, temp, size, counter=0;

    for(i=0; i<size-1; i++){
        swap = 0;
        for(j=0; j<size-1-i; j++){
            counter++;
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap = 1;
            }
        }
    }

}*/



