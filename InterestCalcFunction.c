void CalculateInterest(int index){
    size_t len = strlen(Bank[index].accountype);
    if(len > 0 && Bank[index].accountype[len -1] == '\n'){
        Bank[index].accountype[len -1] = '\0';
    }

    if(strcasecmp(Bank[index].accountype, "Saving") == 0 || strcasecmp(Bank[index].accountype, "savings") == 0){

        if(Bank[index].InterestRate == 0){
            printf("Enter Interest Rate (e.g., 5 for 5%%) for %s", Bank[index].Name);
            scanf("%f", &Bank[index].InterestRate);
        }

        if(Bank[index].YearsActive == 0){
            printf("Enter Years Active for %s", Bank[index].Name);
            scanf("%d", &Bank[index].YearsActive);
        }

        float interest = (Bank[index].cash * Bank[index].InterestRate * Bank[index].YearsActive) / 100.0;
        Bank[index].cash = Bank[index].cash + interest;

        printf("\n--- Interest Calculation Report ---\n");
        printf("Account Holder: %s", Bank[index].Name);
        printf("Interest Earned: %.2f\n", interest);
        printf("New Updated Balance: %.2f\n", Bank[index].cash);

    }
    else{
        printf("Interest is only applicable for Saving accounts. Current account type is: %s\n", Bank[index].accountype);
    }


}