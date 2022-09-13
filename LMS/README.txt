			README for assignment submitted by 2019B3PS0473P

Practical Section No. : 08 (THU - 1,2 Hour)
Question number attempted : 02 (LIBRARY MANAGEMENT SYSTEM)

		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	TEAM:
1) GARVIT SATIJA                - 2019B3PS0473P
2) GAURANG SHARMA        - 2019B2PS0980P
3) KARISHMA K                    - 2019B1PS1047P
 
		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

			DESCRIPTION FOR RUNNING CODE SUBMITTED

1) The name of the file is 2019B3PS0473P_P8.exe.

2) The input files are:
	a)userfile.dat   - List of Users' usernames and passwords
	b)lms.txt          - List of Books in the Library
	c)newbooks.txt - List of the new books to be displayed on the Welcome Page
	d)liblist.txt        - List of Other Libraries from which the user can request a book
	e)vendorlist.txt - List of Vendors from which the customer can order a book
	f)newlyadded.txt - List of newly added books 
	g)tempfile.dat - Temporary file created used in Delete a user function.

3)Upon executing the code
	a) The window will ask the user to press any key to continue
	b) Once the user presses any key (or enter), the user will be asked to either sign up or login. Also 
	   an option will be available for the administrator of the Library
		i)The username for admin is [admin] and password is [adminpass101]
			Admin access can be used to add books to the Library.
	***The window closes after signing up and the user has to log in again.****
     ***Also once signed in as admin please exit after completing all the admin tasks and log in again as a user to proceed***
	c)Once a user Logs in, the user can
		i)Search for a book ( further can search by author, title, issue number)
		ii)Order a book to a Vendor or Request for a book to another Library
		iii)Issue/Return the book - Contains options to issue/return/reserve/cancel reservation options
ONCE THE USER IS LOGGED IN
 AS PER THE QUESTION
1.BOOK MANAGEMENT : Search of books by various parameters can be done by selecting option 1 on homepage after login.
		         The user can search by Author name, Title Name, Issue Number

2.BOOK TRANSACTION : If the user wishes to Issue a book, the user can choose option 3 on the homepage.
		         A new page opens. There are 4 options.
			The user needs to know the issue number of the book he/she wishes to issue.(Option 1)
		         An option has been provided on this page to go to the search page to get the issue number of the 	 	         		book. (Option 4)
		         Once the Issue number is known the user can issue the book, if the book is already issued but 		         		available for reservation the user can reserve the book, if the book is already reserved the user 			is requested to check again later. 
		         The user can return an issued book by choosing (option 2) , he/she will be needing the issue 		         		number of the book to do so.
		         Further the user can cancel reservation for a book by choosing (option 3)
	
3.VENDOR MANAGEMENT : The user can place an order to an affiliated vendor or a request to another library by selecting 		              option 2 on the home page. A new page opens and there are options to do the same.

4.INVENTORY MANAGEMENT: The number of books of a particular title are shown when searched for with the title.

5.USER MANAGEMENT : There is an option to log in or sign up as stated earlier. The user cannot continue without signing in.
		         The user is asked to return the book issued after 15 days when the user issues the book.
		         Also there is an option for administrator login, credentials for which are given above.
			[user id]=[admin]     [password]=[adminpass101]
		          The admin once logged in can
			1) Add a new book to the library
			2)Delete a member from the library
			3)Check list of all books in the library

6.WELCOME PAGE : A suitable welcome page has been provided which also displays the list of newly added books to the 		library.
 
 ALSO A FEW BOOK HAVE ALREADY BEEN ADDED 
 THEIR DETAILS ARE :

  	        Book 1
                        Title : harry potter 1
                        Author : jk rowling
                        Issue no. : 101

                        Book 2
                        Title : harry potter 2
                        Author : jk rowling
                        Issue no. : 102

                        Book 3
                        Title : harry potter 3
                        Author : jk rowling
                        Issue no. : 103

                        Book 4
                        Title : the test of my life
                        Author : yuvraj singh
                        Issue no. : 104

                        Book 5
                        Title : long walk to freedom
                        Author : nelson mandela
                        Issue no. : 105

                        Book 6
                        Title : the diary of a young girl
                        Author : anne frank
                        Issue no. : 106

                        Book 7
                        Title : to kill a mocking bird
                        Author : harper lee
                        Issue no. : 107

                        Book 8
                        Title : pride and prejudice
                        Author : jane austen
                        Issue no. : 108

                        Book 9
                        Title : the book thief
                        Author : markus zusak
                        Issue no. : 109

                          	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	KNOWN LIMITATIONS :
1)The code has been compiled using CODEBLOCKS on Windows and has been checked and is running with all features  working.
2)The code has also been confirmed to be working on REPL.IT on an ubuntu based online compiler.
3)Please do close the program after signing up and login again.
4)The deletion of users feature was not working on windows BUT was WORKING on REPL.IT(ubuntu).
	Further an image with the name 2019B3PS0473P_P08.png has been attached showing the code was compiled on 	our end with 0 errors and 0 warnings.

		~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CONTRIBUTION OF TEAM MEMBERS :
 Gaurang did modules 1,4 and helped with modules 2 and 3.
 Garvit did modules 2,5 and helped in module 6 and compiled all of the modules.
 Karishma did modules 3,6 .


		

