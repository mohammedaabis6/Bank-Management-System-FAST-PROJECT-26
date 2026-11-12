void UpdateandClosure()
{
    if(count==0)
    {
        printf("\nThere are no accounts in the bank yet.\n");
        return;
    }
    printf("\n------ Account Update and Closure Menu\n");
    printf("Enter the Account Number: ");
    int accNum= readInt();

    int index=-1;
    for(int i=0; i<count; i++)
    {
        if(Bank[i].accountnumber==accNum)
        {
            index =i;
            break;
        }
    }
    if(index==-1)
    {
        printf("\nNo account found with account number %d", accNum);
        return;
    }
    if(!Bank[index].Active)
    {
        printf("\nThis account is already closed/deactivated");
        return;
    }
    printf("Enter the 4-digit PIN for account %d", accNum);
    int enteredPIN=readInt();
    if(Bank[index].PIN != enteredPIN)
    {
        printf("\nIncorrect PIN! Operation canceled.\n");
        return;
    }
    printf("\nAccount Found: %s (Type: %s)\n", Bank[index].Name,Bank[index].accountype);
    printf("1. Update Account Details\n");
    printf("2. Close / Deactivate Account\n");
    printf("Choose an option: ");
    int choice = readInt();
    if(choice==1)
    {
        printf("\nWhat would you like to update?\n1. Name\n2. Phone Number\n3.Email Address\n4. PIN\nChoose an option: ");
        int updateChoice= readInt();
        switch(updateChoice)
        {
            case 1:
            {
                promptName(Bank[index].Name, sizeof(Bank[index].Name));
                printf("\nAccount name updated successfully\n");
                break;
            }
            case 2:
            {
                promptPhone(Bank[index].Phone, sizeof(Bank[index].Phone));
                printf("\nPhone Number updated successfully!\n");
                break;
            }
            case 3:
            {
                promptEmail(Bank[index].Email, sizeof(Bank[index].Email));
                printf("\nEmail address updated successfully!\n");
                break;
            }
            case 4:
            {
                printf("Set a new 4-digit PIN: \n");
                int newPIN =readInt();
                while(newPIN<1000 || newPIN>9999)
                {
                    printf("PIN must be exactly 4 digits. Enter again: \n");
                    newPIN= readInt();
                }
                Bank[index].PIN = newPIN;
                printf("\nPIN updated successfully!\n");
                break;
            }
            default:
            {
                printf("\nInvalid option selected.\n");
                return;
            }

        }
        saveData();

    }
    else if (choice==2)
    {
        if(Bank[index].cash>0)
        {
            printf("\nWarning: Your account still has a remaining balance of %.2f.\n", Bank[index].cash);
            printf("Please withdrw your remaining balance before closing the account.\n");
            return;
        }
        if(confirm("Are you sure you want to close/deactivate this account?"))
        {
            Bank[index].Active=0;
            printf("\nAccount %d has been successfully closed/deactivated.\n", accNum);
            saveData();
        }
        else{
            printf("\nAccount closure cancelled.\n");

        }
        
    }
    else
    {
        printf("\nInvalid option selected.\n");

    }
    
}