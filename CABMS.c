#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main_exit;

struct date
{
    int day, month, year;
};

struct
{
    char name[50];
    int acc_no;
    int age;
    char address[50];
    char citizenship[10];
    double phone_no;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transct;

float interest(float t, float amount, int rate)
{
    float SI;
    SI = (t * amount * rate) / 100;
    return (SI);
}

void fordelay(int j)
{
    int i, k;
    for (i = 0; i < j; i++)
        k = i;
}

void close(void)
{
    printf("This project on Banking Management System is made by 'Paras Saxena'\n");
}

void new_account()
{
    int choice;
    FILE *oldf;

    oldf = fopen("OldRecords.txt", "a+");
    printf("\t\t Enter Today's date(dd/mm/yy) \n ");
    scanf("%d %d %d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
account_no:
    printf("\t\t Enter account number: \n");
    scanf("%d", &check.acc_no);

    while (fscanf(oldf, "%s %d %d %s %s %lf %s %f %d %d %d", add.name, &add.acc_no, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account Already Exist!!\n");
            fordelay(1000000);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("Enter your name:\n");
    scanf("%s", add.name);
    printf("Enter date of birth:\n");
    scanf("%d %d %d", &add.dob.day, &add.dob.month, &add.dob.year);
    printf("Enter your address:\n");
    scanf("%s", add.address);
    printf("Enter Citizenship:\n");
    scanf("%s", add.citizenship);
    printf("Enter your phone number:\n");
    scanf("%lf", &add.phone_no);
    printf("Enter the amount you want to deposit:\n");
    scanf("%d", &add.amt);
    printf("Enter the type of account you want:\n\tSaving \t\t Current\t\t Fixed1(for an year)\t\t Fixed2(for 2 years)\t\t Fixed3(for 3 years)\n");
    scanf("%s", add.acc_type);

    fprintf(oldf, "%s %d %d %s %s %lf %s %f %d %d %d\n", add.name, &add.acc_no, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year);
    fclose(oldf);
    printf("Account Created Successfully!!\n");
new_invalid:
    printf("Chose '1' to go to main menu and '0' for exit\n");
    scanf("%d", &main_exit);
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 0)
    {
        close();
    }
    else
    {
        printf("Invalid Input!!\n");
        goto new_invalid;
    }
}

int view_list()
{
    FILE *view;
    view = fopen("OldRecords.txt", "r");
    printf("Name\t\t Account_No\t\tAddress\t\t Phone_no\n");
    int count;

    while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        printf("%s\t\t%d\t\t%s\t\t%lf\n", add.name, add.acc_no, add.address, add.phone_no);
        count++;
    }
    fclose(view);

    if (count == 0)
    {
        printf("Data Not Found!!\n");
    }
view_invalid:
    printf("Chose '1' to go to main menu and '0' for exit\n");
    scanf("%d", &main_exit);
    if (main_exit == 1)
    {
        menu();
    }
    else if (main_exit == 1)
    {
        close();
    }
    else
    {
        printf("Entered Invalid Number!!\n");
        goto view_invalid;
    }
}

void edit(void)
{
    FILE *newf;
    FILE *oldf;
    int c;
    int choice;

    newf = fopen("New_data.txt", "w");
    oldf = fopen("OldRecords.txt", "r");
    printf("Enter the account number of the person whose data you want to update:\n");
    scanf("%d", &upd.acc_no);
    while (fscanf(oldf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {

        if (add.acc_no == upd.acc_no)
        {
            c = 0;
            printf("Which information you want to change \n1.Address\t\t 2.DOB\t\t 3.Phone_Number\t\t ");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter the new address:\n");
                scanf("%s", upd.address);
                fscanf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                system("cls");
                printf("Change Saved!\n");
            }
            else if (choice == 2)
            {
                printf("Enter the new Date of birth:\n");
                scanf("%d %d %d", &upd.dob.day, &upd.dob.month, &upd.dob.year);
                fscanf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &upd.dob.month, &upd.dob.day, &upd.dob.year, &add.age, upd.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                system("cls");
                printf("Change Saved!\n");
            }
            else if (choice == 3)
            {
                printf("Enter the new phone number\n");
                scanf("lf", upd.phone_no);
                fscanf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, upd.address, add.citizenship, &upd.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                system("cls");
                printf("Change Saved!\n");
            }
            else
            {
                printf("Invalid Input!!\nAnd old record is:\n");
                fprintf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &upd.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
            }
        }
    }
            fclose(oldf);
            fclose(newf);
            remove("OldRecords");
            rename("New_data", "OldRecords");

            if (c != 0)
            {
                system("cls");
                printf("Record Not Found !!\n");
            edit_invalid:
                printf("Enter '0' for exit and '1' for main menu and '2' to try again:\n");
                scanf("%d", &main_exit);
                if (main_exit == 1)
                {
                    menu();
                }
                else if (main_exit == 2)
                {
                    edit();
                }
                else if (main_exit == 0)
                {
                    close();
                }
                else
                {
                    printf("Invaid !!\n");
                    goto edit_invalid;
                }
            }
            else
            {
                printf("Enter '0' for exit and '1' for main menu:\n");
                scanf("%d", &main_exit);
                if (main_exit == 1)
                {
                    menu();
                }
                else if (main_exit == 0)
                {
                    close();
                }
            }
        }

        void transact(void)
        {
            int choice, count;
            FILE *newf;
            FILE *oldf;
            newf = fopen("New_record.txt", "r");
            oldf = fopen("OldRecords.txt", "w");

            printf("Enter the account number:\n ");
            scanf("%d", &transct.acc_no);

            while (fscanf(oldf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
            {

                if (add.acc_no == transct.acc_no)
                {
                    count = 1;
                    if (strcmp(add.acc_type, "Fixed(for an year)") == 0 || strcmp(add.acc_type, "Fixed(for 2 years)") == 0 || strcmp(add.acc_type, "Fixed(for 3 years)") == 0)
                    {
                        printf("You Cannot deposit or withdraw any amount in 'Fixed' account\n");
                        system("cls");
                        fordelay(100000000);
                        menu();
                    }
                    else
                    {
                        printf("Do you want to deposit or withdraw?\n1.Deposit\n2.Withdraw\nEnter your choice '1' for deposit and '2' for withdraw:\n");
                        scanf("%d", &choice);

                        if (choice == 1)
                        {
                            printf("Enter the amount you want to deposit:\n");
                            scanf("%d", &transct.amt);
                            add.amt += transct.amt;
                            printf("Your final account balance is %d\n", add.amt);
                            fprintf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone_no, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                            printf("Deposited Sucessfully!!\n");
                        }
                        else if (choice == 2)
                        {
                            printf("Enter the amount you want to Amount:\n");
                            scanf("%d", &transct.amt);
                            add.amt -= transct.amt;
                            printf("Your final account balance is %d\n", add.amt);
                            fprintf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone_no, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                            printf("Withdrawn Sucessfully!!\n");
                        }
                        else
                        {
                            fprintf(newf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone_no, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                        }
                    }
                }
            }
                fclose(oldf);
                fclose(newf);
                remove("OldRecords");
                rename("New_record", "OldRecords");
                if (count != 1)
                {
                    printf("Record Not Found!!\n");
                transct_invalid:
                    printf("Enter '1' for main menu and '0' for exit\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit)
                    {
                        close();
                    }
                    else
                    {
                        goto transct_invalid;
                    }
                }
                else
                {
                trans_invalid:
                    printf("Enter '1' for main menu and '0' for exit\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit)
                    {
                        close();
                    }
                    else
                    {
                        goto trans_invalid;
                    }
                }
            }

            void erase(void)
            {
                int var = 0;
                FILE *oldf;
                FILE *newf;
                oldf = fopen("OldRecords", "r");
                newf = fopen("New_record", "w");

                printf("Enter the account nnumber of the customer you want to Delete!\n");
                scanf("%d", &rem.acc_no);
                while (fscanf(oldf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
                {
                    if (add.acc_no != rem.acc_no)
                    {

                        printf("%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year);
                    }
                    else
                    {
                        var = 1;
                        printf("Account Deleted Successfully!!\n");
                    }
                }
                fclose(oldf);
                fclose(newf);
                remove("OldRecords");
                rename("New_Record", "OldRecords");
                if (var == 0)
                {
                    printf("Account Not Found!!\n");
                    system("cls");
                erase_invalid:
                    printf("Enter '1' for main menu and '0' for exit:\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit == 0)
                    {
                        close();
                    }
                }
                else
                {
                    printf("Enter '1' for main menu and '0' for exit:\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit == 0)
                    {
                        close();
                    }
                }
            }

            void see(void)
            {
                FILE *oldf;
                int rate;
                float intest;
                int time;
                int choice;
                int test;
                oldf = fopen("OldRecords", "r");

                printf("Do you want to check your account:\n 1.Account Number\t\t 2.Holder Name\nEnter your choice:\n");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter your account number:\n");
                    scanf("%d", &check.acc_no);

                    while (fscanf(oldf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
                        if (add.acc_no == check.acc_no)
                        {
                            test = 1;
                            printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone_no,
                                   add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
                            if (strcmp(add.acc_type, "Fixed1") == 0)
                            {
                                time = 1;
                                rate = 5;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                            }
                            if (strcmp(add.acc_type, "Fixed2") == 0)
                            {
                                time = 1;
                                rate = 7;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                            }
                            if (strcmp(add.acc_type, "Fixed3") == 0)
                            {
                                time = 1;
                                rate = 9;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                            }
                            if (strcmp(add.acc_type, "Saving") == 0)
                            {
                                time = 1;
                                rate = 6;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d of every month:\n ", intest, add.deposit.day);
                            }
                            if (strcmp(add.acc_type, "Current") == 0)
                            {

                                printf("You will not get any interest as you account iis current account:\n");
                            }
                        }
                }
                if (choice == 2)
                {
                    printf("Enter holder name :\n");
                    scanf("%s", check.name);

                    while (fscanf(oldf, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone_no, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
                    {
                        if (add.name == check.name)
                        {
                            test = 1;

                            printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone_no,
                                   add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

                            if (strcmp(add.acc_type, "Fixed1") == 0)
                            {
                                time = 1;
                                rate = 5;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                            }
                            if (strcmp(add.acc_type, "Fixed2") == 0)
                            {
                                time = 1;
                                rate = 7;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                            }
                            if (strcmp(add.acc_type, "Fixed3") == 0)
                            {
                                time = 1;
                                rate = 9;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d/%d/%d:\n ", intest, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                            }
                            if (strcmp(add.acc_type, "Saving") == 0)
                            {
                                time = 1;
                                rate = 6;
                                intest = interest(time, add.amt, rate);
                                printf("You will get %0.2f as an interest on %d of every month:\n ", intest, add.deposit.day);
                            }
                            if (strcmp(add.acc_type, "Current") == 0)
                            {

                                printf("You will not get any interest as you account iis current account:\n");
                            }
                        }
                    }
                }

                fclose(oldf);
                if (test != 1)
                {
                    system("cls");
                    printf("Record Not Found!!\n");
                see_invalid:
                    printf("Enter '1' for main menu and '0' for exit and '2' to try again:\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit == 0)
                    {
                        close();
                    }
                    else if (main_exit == 2)
                    {
                        see();
                    }
                    else
                    {
                        printf("You entered invalid number:\n");
                        goto see_invalid;
                    }
                }
                else
                {
                    printf("Enter '1' for main menu and '0' for exit \n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        menu();
                    }
                    else if (main_exit == 0)
                    {
                        close();
                    }
                }
            }

            void menu(void)
            {
                int choice;
                system("cls");
                system("color 9");

                printf("\t\t\tCUMSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
                printf("            Welcome to the Main Menu \n                  ");
                printf("1. Create a new account :\n 2. Update the existing account:\n 3. For Transction\n 4. Check the details of exixting Account:\n 5. Removing existing account:\n 6. View customers list\n 7. Exit\n\n Enter your choice:\n");
                scanf("%d", &choice);

                system("cls");
                switch (choice)
                {
                case 1:new_account();
                    break;
                case 2: edit();
                    break;
                case 3:transact();
                    break;
                case 4:see();
                    break;
                case 5:erase();
                    break;
                case 6:view_list();
                    break;
                case 7:close();
                    break;
                }
            }

            int main()
            {
                char pass_code[13];
                char actual_pass[13] = "Projectfirst";

            login_try:
                printf("Enter the password to login :\n");
                scanf("%s", pass_code);

                if (strcmp(pass_code, actual_pass) == 0)
                {
                    printf("Correct Password loading!!\n\t\t wait for a moment\n");
                    for (int i = 0; i <= 5; i++)
                    {
                        fordelay(100000000);
                        printf("..");
                    }
                    system("cls");
                    menu();
                }
                else
                {
                    printf("Wrong Password!!\n");
                    printf("Enter '1' to try again and '0' for exit:\n");
                    scanf("%d", &main_exit);
                    if (main_exit == 1)
                    {
                        system("cls");
                        goto login_try;
                    }
                    else if (main_exit == 0)
                    {
                        close();
                    }
                    else
                    {
                        printf("Invalid input!!\n");
                        fordelay(100000000);
                        system("cls");
                        goto login_try;
                    }
                }

                return 0;
            }
