#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
# define sleep(x) Sleep(1000 * (x))
#endif

void welcome();
void welcomemessage();
void login();
void mainpage();
void vendor();
void booksearch();
void admin();
void sb_author();
void sb_issueno();
void sb_title();
void issue();
void bookreturn();
void deleteUsers();
void bookstatus();
void displaybooks();

//main structure containing book details
struct Book
{
	int status;
	int alert;
	char author[50], title[50];
	int issue_no;

}binfo;

//structure for user credentials
struct usercreds
    {
        char username[20];
        char password[20];

}*userinfo;

//details for administrator login
char admuname[]="admin";
char admpass[]="adminpass101";


int main()
{
    welcome();
    return 0;
}

// A welcome message
void welcomemessage()
{
        system("clear");
        printf("\n\n\n\n\n");
        printf("\n\t\t\t  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
        printf("\n\t\t\t         -------------------------------------------");
        printf("\n\t\t\t        |                                           |");
        printf("\n\t\t\t        |               WELCOME TO                  |");
        printf("\n\t\t\t        |                  BITS                     |");
        printf("\n\t\t\t        |                 PILANI                    |");
        printf("\n\t\t\t        |                LIBRARY                    |");
        printf("\n\t\t\t        |                                           |");
        printf("\n\t\t\t         -------------------------------------------");
        printf("\n\n\n\t\t\t  ~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n");
}

//The welcome page --- It displays the newly added books

         void welcome()
    {
        welcomemessage();
        printf("\n\n\n\t\t\t\t\t Login or sign up to continue\n\t\t\t\t\t Press any key to proceed...\n\n\t\t\t");
        getchar();
        printf("\n\n\t\t\t\t\t\tNEWLY ADDED BOOKS\n\n");
        FILE *fp1;
        fp1=fopen("newlyadded.txt","r");
        while(fread(&binfo,sizeof(binfo),1,fp1))
        {
            printf("\n\t\t\t Author : %s\n\t\t\t Title : %s \n\t\t\t ",binfo.author,binfo.title);

        }
        fclose(fp1);
        getchar();
        login();

    }
                //welcome page function ends here


//mainpage after logging in
    void mainpage()
    {
        welcomemessage();
        //options for logged in user to choose from
        printf("\n\n\t\t\tSelect one of the options from below....\n");
        printf("\n\t\t\t1.Search for books\n");
        printf("\n\t\t\t2.Contact other vendors and Libraries\n");
        printf("\n\t\t\t3.Issue or Return a Book \n");
        printf("\n\t\t\t4.Exit\n");
        printf("\n\n\t\t\t Enter your choice... ");
        int q;
        scanf("%d",&q);
        //switch statement for execution of the function as selected by the user
        switch (q)
            {
                case 1 :
                    booksearch();
                    break;
                case 2 :
                   vendor();
                   break;
                case 3 :
                   issue();
                   break;
                case 4 :
                    system("cls");
                    printf("\n\n\n\n\t\t\t\t\t\t THANK YOU FOR VISITING US\n\n");
                    sleep(2);
                    exit(1);
                    break;
                default:
                    printf("Invalid Input");
                    break;

            }

    }


            /////////////////////////////////////////////////////////// LOGIN FUNCTION ///////////////////////////////////////////////////////////

                void login()
    {
        system("cls");
        welcomemessage();
        //userfile.dat is the file containing all the user information
        FILE *fptr;
        fptr=fopen("userfile.dat","r+");
        char uname[20], pass[20];
        int k;char c;
        userinfo=(struct usercreds *)malloc(sizeof(struct usercreds));
        //to check admin credentials
        char admucheck[20]; char admpasscheck[20];
        printf("\n\t\t\t1.To Log In with an existing account \n");
        printf("\t\t\t2.To Sign Up \n");
        printf("\t\t\t3.For Admin Login \n");
        printf("\t\t\t4.To Exit \n");
        printf("\n\t\t\t");
        scanf("%d",&k);
        switch(k){
        case 1:  //login for already signed up users
            if ( ( fptr=fopen("userfile.dat", "r+")) == NULL) {
                if ( ( fptr=fopen("userfile.dat", "w+")) == NULL) {
                    printf ("The file could not be opened\n");
                    exit ( 1);
                }
            }
            printf("\t\t\tUsername: ");
            scanf("%19s",uname);
            printf("\t\t\tPassword: ");
            scanf("%19s",pass);
            printf("\n");
            while ( fread (userinfo, sizeof(struct usercreds), 1, fptr) == 1) {
                if( strcmp ( userinfo->username, uname) == 0)
                    {
                        printf ("\t\t\tCorrect Username\n");
                        if( strcmp ( userinfo->password, pass) == 0)
                        {
                                printf ("\t\t\tCorrect Password\n");

                                printf("\n\t\t\tDirecting you to homepage....");
                                sleep(3);
                                mainpage();

                        }
                        else
                            {
                                printf("\t\t\tSorry Password doesn't match\n");
                                char p;
                                scanf("%c",&p);
                                printf("\t\t\tTry Again ? (Y/N)");

                                scanf("%c",&p);
                                if ((p == 'Y' || p == 'y'))
                                    {
                                        login();
                                    }
                                    else
                                    {
                                        exit(1);
                                    }

                            }

                }



            }
            break;

        case 2:         //sign up function for creating a new account
            do
            {
                if ( ( fptr=fopen("userfile.dat", "a+")) == NULL) {
                    if ( ( fptr=fopen("userfile.dat", "w+")) == NULL) {
                        printf ("\t\t\tCould not open file\n");
                        exit ( 1);
                    }
                }
                printf("\t\t\tPlease enter a Username: ");
                scanf("%19s",userinfo->username);
                printf("\t\t\tPlease enter your password: ");
                scanf("%19s",userinfo->password);
                fwrite (userinfo, sizeof(struct usercreds), 1, fptr);
                printf("\t\t\tSigned Up Successfully !!!\n");
                printf("\t\t\tDo you want to add another new account ?(Y/N): ");
                scanf(" %c",&c);
            }while(c=='Y'||c=='y');
            //login();

            free ( userinfo);
            fclose(fptr);
            exit(1);
            break;

        case 3:               //login for the administrator

            printf("\n\t\t\tPlease Enter Username :");
            scanf("%19s",admucheck);
            if (strcmp(admucheck,admuname)==0)
            {
                printf("\n\t\t\tPlease Enter Password :");
                scanf("%19s",admpasscheck);
                if (strcmp(admpasscheck,admpass)==0)
                {
                    admin();

                }
                else
                {
                    printf("\n\t\t\t INCORRECT PASSWORD ");
                    login();
                }

            }
            else
            {
                printf("\n\t\t\t INORRECT USERNAME");
                login();

            }
            break;


        case 4 :
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\t THANK YOU FOR VISITING US\n\n");
            sleep(2);
            exit(1);
            break;
        default :
            printf("Invalid Input");
            break;


        }
        free ( userinfo);
        fclose(fptr);




    }       //login function definition ends

////////////////////////// VENDOR AND OTHER LIBRARIES MANAGEMENT ///////////////////////////////
//function for ordering a book from a vendor or a library


        void vendor()
 {
        system("cls");
        welcomemessage();
        char bookname[30]; char authorname[30];char email[50];char vendno[5];
        printf("\t\t\t Would you like to place a request for the book to \n\t\t\t 1. A Vendor\n\t\t\t 2. Other Libraries\n\t\t\t 3. Back to Homepage\n\t\t\t 4. EXIT\n\t\t\t Enter Your Choice...\n");
        int y;
        FILE *fp3;
        char ch3;
        printf("\t\t\t");scanf("%d",&y);
        switch(y)
        {
            case 1 :             //ordering a book from a vendor
                system("cls");
                //vendorlist.txt is the list containing the details of different vendors
                fp3=fopen("vendorlist.txt","r");

                do
                {
                    ch3 = fgetc(fp3);
                    putchar(ch3);

                }       while(ch3 != EOF);

                fclose(fp3);
                gets(bookname);
                printf("\n\t\tPlease enter the details of the book");
                printf("\n\t\tTitle:");
                gets(bookname);
                printf("\n\t\tAuthor:");
                gets(authorname);
                printf("\n\t\tEnter the serial number of the desired vendor :");
                gets(vendno);
                printf("\n\t\tPlease Enter your Email-ID :");
                gets(email);
                printf("\n\t\tYou have decided to order the book %s by %s from the Vendor number%s",bookname,authorname,vendno);
                printf("\n\t\tDo you wish to CONFIRM this order?   (Y/N)");
                char p=getchar();
                switch (p)
                    {
                        case 'Y' :
                            printf("\n\t\tORDER CONFIRMED.... You will be contacted soon regarding this order.");
                            printf("\n\t\tReturning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'y' :
                            printf("\n\t\tORDER CONFIRMED.... You will be contacted soon regarding this order.");
                            printf("\n\t\tReturning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'N' :
                            printf("\n\t\tSorry... Your order was canceled. Returning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'n':
                            printf("\n\t\tSorry... Your order was canceled. Returning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        default :
                            printf("\n\t\t\tInvalid Input");
                            break;

                    }

                break;
            case 2 :            // To place a request to other libraries
                system("cls");
                //liblist.txt is the file containing details of books
                fp3=fopen("liblist.txt","r");

                do
                {
                    ch3 = fgetc(fp3);
                    putchar(ch3);

                }       while(ch3 != EOF);

                fclose(fp3);
                gets(bookname);
                printf("\n\t\tPlease enter the details of the book");
                printf("\n\t\tTitle:");
                gets(bookname);
                printf("\n\t\tAuthor:");
                gets(authorname);
                printf("\n\t\tEnter the serial number of the desired Library :");
                gets(vendno);
                printf("\n\t\tPlease Enter your Email-ID :");
                gets(email);
                printf("\n\t\tYou have decided to request the book %s by %s from Library Number %s",bookname,authorname,vendno);
                printf("\n\t\tDo you wish to CONFIRM this request?   (Y/N)");
                char j=getchar();
                switch (j)
                    {
                        case 'Y' :
                            printf("\n\t\tREQUEST CONFIRMED.... You will be contacted soon regarding this request.");
                            printf("\n\t\tReturning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'y' :
                            printf("\n\t\tREQUEST CONFIRMED.... You will be contacted soon regarding this request.");
                            printf("\n\t\tReturning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'N' :
                            printf("\n\t\tSorry... Your order was canceled. Returning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        case 'n':
                            printf("\n\t\tSorry... Your order was canceled. Returning to Homepage");
                            getchar();
                            sleep(5);
                            mainpage();
                            break;
                        default :
                            printf("\n\t\tInvalid Input");
                            break;

                    }
                break;



            case 3 :
                mainpage();
                break;
            case 4 :
                system("cls");
                printf("\n\n\n\n\t\t\t\t\t\t THANK YOU FOR VISITING US\n\n");
                sleep(2);
                exit(1);
                break;

            default :
                printf("\n\n\t\t\t\tINVALID INPUT");
                exit(1);
                break;


        }

 }                  //vendor function ends here



/////////////////////////////////////////   ADMINISTRATOR FUNCTION /////////////////////////////////////


 void admin()
 {
    system("cls");
    welcomemessage();
    printf("\n\t\t\t 1. To add a Book  ");
    printf("\n\t\t\t 2. To delete a user  ");
    printf("\n\t\t\t 3. To Check Book Status  ");
    printf("\n\t\t\t 4. To List all Books  ");
    printf("\n\t\t\t 5. To exit  \n\t\t\t ");
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 1 :   // adding a book
            break;
        case 2 :   // deleting a book
            deleteUsers();
            break;
        case 3 :   // To check status of a particular book
            bookstatus();
            break;
        case 4 :   // To display list of all books in library
            displaybooks();
            break;
        case 5 :
            system("cls");
            printf("\n\n\n\n\t\t\t\t\t\t THANK YOU FOR VISITING US\n\n");
            sleep(2);
            exit(1);
            break;
        default :
            printf("Invalid Input");
            break;
    }
        FILE *fp;
        FILE *fp2;

    int recsize;
    char z;
    fp2 = fopen("newlyadded.txt","r+");   // TO STORE IN NEWLY ADDED BOOKS
    fp = fopen("lms.txt" , "r+");         // TO STORE IN BOOKS LIST - LMS.TXT
    if(fp == NULL)
    {
	fp = fopen("lms.txt" , "w+");
	if(fp == NULL)
	{
	    printf("\n\t\t\t Error in opening file : \n");
	}
    }
    recsize = sizeof(binfo);

    fseek(fp , 0 ,SEEK_END);        //FSEEK STATEMENT IS USED TO RELOCATE POINTER AT END OF THE FILE AND PREVENT OVERWRITING
    fseek(fp2 , 0 ,SEEK_END);
    printf("\n\t\t\t Enter author name : ");
    scanf("%c",&z);
    gets(binfo.author);
    printf("\n\t\t\t Enter Title : ");
    gets(binfo.title);
    printf("\n\t\t\t Enter issue number   : ");
    scanf("%d" , &binfo.issue_no);
    binfo.status=1;         //BOTH STATUS AND ALERT FOR EACH BOOK ARE INITIALIZED TO 1 i.e. THE ARE AVAILABLE FOR ISSUING AND RESERVATION
    binfo.alert=1;
    printf("\n\t\t\t Author : %s\n\t\t\t Title : %s \n\t\t\t Issue Number : %d",binfo.author,binfo.title,binfo.issue_no);
    fwrite(&binfo,recsize,1,fp2);
    fwrite(&binfo,recsize,1,fp);
    printf("\n\n\t\t\tBook added successfully!\n");
    fclose(fp);
    fclose(fp2);

}


//////////////////////////////////// BOOK SEARCH FUNCTION ////////////////////////////////


void booksearch()
 {
        welcomemessage();
        int v;
        printf("\n\t\t\t Select Search Criteria :");
        printf("\n\t\t\t 1)By TITLE");
        printf("\n\t\t\t 2)By AUTHOR");
        printf("\n\t\t\t 3)By ISSUE NUMBER");
        printf("\n\t\t\t Please enter your choice ....   ");
        scanf("%d",&v);
        switch(v)
        {
            case 1 :            //SEARCH BY TITLE
                sb_title();
                break;

            case 2 :            //SEARCH BY AUTHOR
                sb_author();
                break;

            case 3 :            //SEARCH BY ISSUE NUMBER
                sb_issueno();
                break;

            default :
                printf("Invalid Input...");
                sleep(3);
                booksearch();
                break;

        }



 }


//////////////////////////// SEARCH BY DIFFERENT PARAMETERS FUNCTIONS LISTED BELOW ///////////////////////////////////

 void sb_author()
{
	char aname[50],z;
	FILE *fp8;
	int i,c=0;
	printf("\n\t\t\tEnter author name\n\t\t\t");
	scanf("%c",&z);
	gets(aname);
	//printf("name to be searched: %s",aname);
	fp8= fopen("lms.txt","rb"); //lms is the main data file
	if(fp8 == NULL)
	{
		fp8 = fopen("lms.txt" , "w+");
		if(fp8 == NULL)
		{
		 printf("error in opening file : \n");
		}
	}
	while(fread(&binfo,sizeof(binfo),1,fp8))
	{
		i=strcmp(aname,binfo.author);
		if(i==0)
		{       c++;
			printf("\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\n",binfo.title,binfo.author,binfo.issue_no)
			;
		}
	}
	if(c>0)
		printf("\n\t\t\t%d books found\n",c);
	else	printf("\n\t\t\tNo books found\n");
	fclose(fp8);
}


void sb_title()
{
	char tit[50],z;
	FILE *fp6;
	int i,c=0;
	printf("\n\t\t\tEnter title\n");
	scanf("%c",&z);
	gets(tit);
	fp6= fopen("lms.txt","rb"); //lms is the main data file
	if(fp6 == NULL)
	{
		fp6 = fopen("lms.txt" , "w+");
		if(fp6 == NULL)
		{
		printf("error in opening file : \n");
		}
	}
	while(fread(&binfo,sizeof(binfo),1,fp6))
	{
		i=strcmp(tit,binfo.title);
		if(i==0)
		{       c++;
			printf("\n\t\t\tBook found!\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\n",binfo.title,binfo.author,binfo.issue_no);
		}
	}
	if(c>0)
		printf("\n\t\t\t %d books found!\n\n",c);
	else	printf("\n\t\t\t No books found!\n");
	fclose(fp6);
}


void sb_issueno()
{
	int ino,c=0;
	FILE *fp7;
	printf("\n\t\t\tEnter issue no.\n");
	scanf("%d",&ino);
	fp7= fopen("lms.txt","rb"); //lms is the main data file
	if(fp7 == NULL)
	{
		fp7 = fopen("lms.txt" , "w+");
		if(fp7 == NULL)
		{
		printf("error in opening file : \n");
		}
	}
	while(fread(&binfo,sizeof(binfo),1,fp7))
	{
		if(ino==binfo.issue_no)
		{       c++;
			printf("\n\t\t\tBook Found!\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n",binfo.title,binfo.author,binfo.issue_no);
		}
	}
	if(c>0)
		printf("\n\t\t\t%d books found\n",c);
	else	printf("\n\t\t\tNo books found\n");
	fclose(fp7);
}



//////////////////////////// SEARCH BY DIFFERENT PARAMETERS FUNCTIONS LISTED ABOVE ///////////////////////////////////



//////////////////////////////////// FUNCTION TO ISSUE / RETURN / RESERVE / CANCEL RESERVATION ///////////////////////////

void issue()
{
        system("cls");
        welcomemessage();

        FILE *fp9;
        fp9=fopen("lms.txt","r+");


        printf("\n\t\t\tYou need the Issue Number of the book to issue a book");
        printf("\n\t\t\t1. If you know the Issue Number of the book you wish to issue ");
        printf("\n\t\t\t2. If you wish to return a book ");
        printf("\n\t\t\t3. If you wish to cancel your Reservation for a book ");
        printf("\n\t\t\t4. If you wish to Check the Issue Number of a book using the Search Option ");
        printf("\n\t\t\t5. To Exit ");
        printf("\n\t\t\tPlease Enter your choice\n\t\t\t");
        int j1;
        char r2;char r3;
        char email2[30];
        int issueno;
        scanf("%d",&j1);

        switch(j1)
        {
            case 1:
                printf("\n\t\t\tPlease enter your email-ID : ");
                scanf("%29s",email2);
                printf("\n\t\t\tPlease enter the Issue Number of the book : ");
                scanf("%d",&issueno);

                while(fread(&binfo,sizeof(binfo),1,fp9))
	{
                    if(issueno==binfo.issue_no)
                        {
                         printf("\n\t\t\tBook Found!\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\n",binfo.title,binfo.author,binfo.issue_no);
                            //printf("%d",binfo.status);

                            if (binfo.status==1)
                            {
                                printf("\n\t\t\t This Book is Available for Issuing. ");
                                printf("\n\t\t\tDo you want to issue this book? (Y/N)");
                                getchar();
                                scanf("%c",&r2);
                                sleep(3);
                                if(r2=='y'||r2=='Y')
                                    {
                                        printf("\n\t\t\t The Book\n\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\t\t has been issued to you. ",binfo.title,binfo.author,binfo.issue_no);
                                        printf("\n\n\t\t\tYou are requested to return the book in 15 days in an orderly condition \n\t\t\totherwise appropriate fines would be charged");
                                        binfo.status=0;
                                        //printf("%d",binfo.status);
                                        fseek(fp9, -sizeof(binfo), SEEK_CUR);
                                        fwrite(&binfo,sizeof(struct Book),1,fp9);

                                        sleep(2);


                                    }   //


                            }

                                else
                           {printf("\n\t\t\tSorry the book you requested is not available.");
                                //printf("%d\n\%d",binfo.status,binfo.alert);
                                if (binfo.alert==1)
                                {
                                    printf("\n\t\t\tYou can Reserve this book for when it returns to the Library");
                                    printf("\n\t\t\tDo you wish to Reserve this book ? (Y/N)");
                                    getchar();
                                    scanf("%c",&r3);
                                    if(r3=='y'||r3=='Y')
                                    {
                                        printf("\n\t\t\t The Book\n\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\t\t has been Reserved for you. ",binfo.title,binfo.author,binfo.issue_no);
                                        printf("\n\n\t\t\tYou will receive an e-mail once the book is available again for issuing");
                                        binfo.alert=0;
                                        fseek(fp9, -sizeof(binfo), SEEK_CUR);
                                        fwrite(&binfo,sizeof(struct Book),1,fp9);

                                        sleep(2);
                                        exit(1);


                                    }   //
                                }

                                else
                                    {
                                        printf("\n\t\t\tSorry But this book is already Reserved !");
                                        printf("\n\t\t\tPlease try again later ");
                                    }
                           }



                    }
	}
                            fclose(fp9);
                            sleep(3);
                            exit(1);



            break;



           case 2 :
            printf("\n\t\t\tPlease enter your email-ID : ");
            scanf("%29s",email2);
            printf("\n\t\t\tPlease enter the Issue Number of the book : ");
            scanf("%d",&issueno);

            while(fread(&binfo,sizeof(binfo),1,fp9))
            {
                if(issueno==binfo.issue_no)
                {
                    printf("\n\t\t\tBook Found!\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\n",binfo.title,binfo.author,binfo.issue_no);
                    if (binfo.status==0)
                    {
                        printf("\n\t\t\tDo you want to return this book? (Y/N)");
                        getchar();
                        scanf("%c",&r2);
                        if(r2=='y'||r2=='Y')
                            {
                                printf("\n\t\t\t The Book\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\t\t\t has been returned. ",binfo.title,binfo.author,binfo.issue_no);
                                printf("\n\t\t\t Thank You for visiting us.");
                                binfo.status=1;
                                fseek(fp9, -sizeof(binfo), SEEK_CUR);
                                fwrite(&binfo,sizeof(struct Book),1,fp9);
                                fclose(fp9);
                                sleep(2);
                                mainpage();

                            }



                    }


                        else
                                {
                                    printf("\n\n\t\t\tThe Book you requested is already issued. Please try again later");
                                }

                }

            }
           break;

           case 3 :
                printf("\n\t\t\tPlease enter your email-ID : ");
            scanf("%29s",email2);
            printf("\n\t\t\tPlease enter the Issue Number of the book : ");
            scanf("%d",&issueno);

            while(fread(&binfo,sizeof(binfo),1,fp9))
            {
                if(issueno==binfo.issue_no)
                {
                    printf("\n\t\t\tBook Found!\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\n",binfo.title,binfo.author,binfo.issue_no);
                    if (binfo.alert==0)
                    {
                        printf("\n\t\t\tDo you want to cancel your reservation for this book? (Y/N)");
                        getchar();
                        scanf("%c",&r2);
                        if(r2=='y'||r2=='Y')
                            {
                                printf("\n\t\t\t The Book\n\t\t\tTitle: %s\n\t\t\tAuthor: %s\n\t\t\tIssue no.: %d\n\t\t\t has been unreserved. ",binfo.title,binfo.author,binfo.issue_no);
                                printf("\n\t\t\t Thank You for visiting us.");

                                binfo.alert=1;
                                fseek(fp9, -sizeof(binfo), SEEK_CUR);

                                fwrite(&binfo,sizeof(struct Book),1,fp9);
                                fclose(fp9);
                                sleep(2);
                                mainpage();

                            }



                    }


                        else
                                {
                                    printf("\n\n\t\t\tThe Book you requested is already available for reservation.");
                                }

                }

            }
               break;







           case 4 :
            booksearch();
            break;

           case 5 :


          default :
                printf("\n\t\t\tINVALID INPUT");
                sleep(2);
                break;



        }
        fclose(fp9);
}


///////////////////////////////////    ISSUE FUNCTION ENDS HERE ////////////////////////////////////


//////////////////////////// FUNCTION TO DELETE USER ///////////////////////////
// THIS FUNCTION MAY NOT WORK ON WINDOWS BUT WAS TESTED TO BE WORKING ON UBUNTU ////////////////////////////
void deleteUsers()
{
    welcomemessage();
    int fnd = 0;
    char userDelete[20] ;
    FILE *fp;
    FILE *tmp;
    fp = fopen("userfile.dat","r");
    if(fp == NULL)
    {
        printf("File not opened\n");
        exit(1);
    }
    tmp = fopen("tmpfile.dat","w");
    if(tmp == NULL)
    {
        fclose(fp);
        printf("File not opened\n");
        exit(1);
    }
    fread (userinfo,sizeof(struct usercreds), 1, fp);
    fwrite(userinfo,sizeof(struct usercreds), 1, tmp);
    printf("\n\t\t\tEnter User ID to delete :");
    scanf("%s",userDelete);
    while (fread(userinfo, sizeof(struct usercreds), 1, fp))
    {
        if(strcmp(userinfo->username,userDelete)!=0)
        {

            fwrite(userinfo, sizeof(struct usercreds), 1, tmp);
        }
        else
        {
            fnd = 1;
        }
    }
    (fnd)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmp);
    remove("userfile.dat");
    rename("tmpfile.dat","userfile.dat");
}


//////////////////////////// FUNCTION TO CHECK STATUS OF A PARTICULAR BOOK ///////////////////////////////

void bookstatus()
{

        FILE *fp9;
        fp9=fopen("lms.txt","r+");
        int issueno;
        printf("\n\t\t\tPlease enter the Issue Number of the book : ");
                scanf("%d",&issueno);

                while(fread(&binfo,sizeof(binfo),1,fp9))
	{
                    if(issueno==binfo.issue_no)
                        {
                         printf("\n\t\t\tBook Found!\n\t\t\tTitle : %s\n\t\t\tAuthor : %s\n\t\t\tIssue no. : %d\nIssue Status : %d\nReservation Status : %d\n",binfo.title,binfo.author,binfo.issue_no,binfo.status,binfo.alert);
                         printf("\n\t\t\t1 = Available 0 = Not Available");

                        }
	}

}


/////////////////////////////////// FUNCTION TO DISPLAY ALL BOOKS IN THE LIBRARY ////////////////////////
void displaybooks()
{

    int i=0;
    FILE *fp3;
    fp3= fopen("lms.txt","r");
    printf("\n\t\t\t1 = Available 0 = Not Available\n\n");
    while(fread(&binfo,sizeof(binfo),1,fp3))
	{
        i=i+1;
        printf("\n\t\t\tBook %d\n\t\t\tTitle : %s\n\t\t\tAuthor : %s\n\t\t\tIssue no. : %d\n\t\t\tIssue Status : %d\n\t\t\tReservation Status : %d\n",i,binfo.title,binfo.author,binfo.issue_no,binfo.status,binfo.alert);



	}
	exit(1);
}
