//BALNCE INQUIRY FUNCTION


void Inquiry(){

    int i, number;

    if(count == 0){
        printf("There are no Accounts in the bank yet.\n");
        return;
    }

    printf("Enter the Account Number: ");
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

    printf("No Account found with the account number %d\n", number);

}
