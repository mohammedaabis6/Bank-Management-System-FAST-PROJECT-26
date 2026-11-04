
void SearchAccount(){

    int i, choice, number;
    char name[100];

if (count == 0){
    printf("There are no accounts in the bank yet.\n");
    return;
}

printf("Search by:\n1. Account Number\n2. Account Holder Name\nChoose an option:\n");
choice = readInt();

if(choice == 1){
    printf("Enter Account Number: \n");
    number = readInt();

    for(i=0; i<count; i++){
        if(Bank[i].accountnumber == number){
            printf("Account Number: %d\n", Bank[i].accountnumber);
            printf("Account Holder: %s\n", Bank[i].Name);
            printf("Account Type: %s\n", Bank[i].accountype);
            printf("Current Balance: %.2f\n", Bank[i].cash);
            return;
        }
    }

    printf("No account found with the account number %d\n", number);
}

else if (choice == 2)
{
    printf("Enter Account Holder Name: \n");
    readLine(name, sizeof(name));

    for(i=0; i<count; i++){
        if(containsIgnoreCase(Bank[i].Name, name)){
            printf("Account Number: %d\n", Bank[i].accountnumber);
            printf("Account Holder: %s\n", Bank[i].Name);
            printf("Account Type: %s\n", Bank[i].accountype);
            printf("Current Balance: %.2f\n", Bank[i].cash);
            return;
        }
    }
    printf("No Account found with the name %s\n", name);
}

else{
    printf("Invalid Option\n");
}



}



