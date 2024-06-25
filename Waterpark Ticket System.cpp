#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include<string.h>
#include <algorithm>
#include <vector>
#include <limits>
#include <ctime>
#define BG 30.00
#define SB 20.00
#define BC 80.00
#define SC 50.00
#define MAX_PRODUCT_NAME_LENGTH 50

using namespace std;

// For catalog
struct Product 
{
    char merchCode;
    string merchName;
    double merchPrice;
} merchProduct;

// For customer with discount points and membership status
struct Customer
{
    double discountPoints = 0.00;
    bool isMember = false;
    bool ansMember;
    int IDMember;
} merchCustomer;

void clearScreen() 
{
    std::cout << "\033[2J\033[1;1H";
}

//function declaration
void signup();
void booking();
void login();
void booking_info();
void update_tix();
void service();
void display_service();
void display();
void vr();
void event();
void membership(Customer &customer);
void merchandiseMenu(Customer &customer);
void display_menu();
void menu_calc();
void upprice();
void displayMemberInfo();
void purchaseMerchandise(const char *productName, float merchandisePrice);
void menu_receipt(float );

//global variable
char name[50];
char product_name[MAX_PRODUCT_NAME_LENGTH];
char code_service, code_item, num[11];
int memberId,memberPoints,cust, code, pw1, pw2, num2, mmbr, mmbr2, mconf, member_id, new_member, exist_member, change_tix, code_c_tix, p_conf, no, product, item, q1 = 0, q2 = 0, q3 = 0, q4 = 0, qn = 0, tq1 = 0, tq2 = 0, tq3 = 0, tq4 = 0, number = 0;
float price, price1,price2,price3,price4,total,productPrice;
float total1 = 0, total2 = 0, total3 = 0, total4 = 0 , totals_service = 0 ,totals_fb = 0;
int x = 0, y = 1, q, num_set, s, h, l, numProduct;
int answer, lengthnum;
int user_admin, i, ans, upSet, upMerch;
int t = 0, ageE[100], sumE = 0, eventChoice, explore;
char namegame[50];
char pnum[10];
char pic[13]; 
const int MAX_TICKETS = 4;
int mn1=0,mn2=0,mn3=0,mn4=0;

//array
char cat_ticket[4][25] = {"  Adult ", "Children", "Older Citizen", "Foreigner"};
char cat_service[4][25] = {"BIG BUOY","SMALL BUOY","BIG CABIN","SMALL CABIN"};
int quantity[] = {15,15,10,5};
char key[4][5] = {"a.","b.","c.","d."};
int cprice[] = {30,20,80,50};
char food[4][25] = {"Nasi Lemak ", "Nasi Goreng", "Mee Goreng ", "ShellOut "};
float fp [] = {15,20,18,99};
float fpoints[] = {30,200,350,45};
char drinks[4][25] = {" Teh Tarik ", " Teh O Ais ", "Bandung Soda", "Orange Juice"};
char var[] = {'A','B','C','D'};
float newSet[4];
float newpoints[4];
int bil[MAX_TICKETS] = {1, 2, 3, 4};
double tprice[MAX_TICKETS] = {60.0, 30.0, 35.0, 90.0};


//ari
//main function
int main(){
	
	//customer ticketing process (khadijah)
	cout<<"\t\t*********************************************"<<endl;
	cout<<"\t\t\tWELCOME TO UITM SHAH ALAM WATERPARK! ^_^"<<endl;
	cout<<"\t\t*********************************************"<<endl;
	
	cout<<endl<<"\t\tAre you a user or an admin? [1] for user, [2] for admin: ";
	cin>>user_admin;
	if(user_admin == 2)
	{
		update_tix();
		
		cout << endl << endl << "\t\tDo you want to update SET price? [1]YES [2]NO :";
		cin >> upSet;
		
		if(upSet == 1)
			upprice();

			cout<<"\t\tThank You for Service Update ! ^_^";
	
		return 0;
		
		
	}
	else if(user_admin==1)
	{

	signup();
 	booking_info();
	
	//customer service rent (kai)
	service();

	//F&B purchase (aziem)
	display_menu();
	menu_calc();
	menu_receipt(totals_fb);
	
	event();
	//customer discount (afif)
    merchandiseMenu(merchCustomer);
}
 
 return 0;
 }

	//booking function definiton
	void booking(){
	
	login();

	//display ticket category
	cout<<endl<<endl<<"\t\t*************************************************";
	cout<<endl<<endl<<"\t\tPlease select your tickets:";
	cout<<endl<<endl<<"\t\t------------------------------------------------------";
	cout<<endl<<"\t\t|No\t|\tCategory\t\t|\tPrice|";
	cout<<endl<<"\t\t------------------------------------------------------";
	int i;
	for(i=0; i<4; i++)
	cout<<endl<<"\t\t|"<<bil[i]<<"\t|\t"<<cat_ticket[i]<<" \t\t|\tRM"<<tprice[i]<<" |";
	cout<<endl<<"\t\t------------------------------------------------------";

	//customer purchase tickets
	 do{
    cout<<endl<<endl<<"\t\t*************************************************";
   	cout<<endl<<endl<<"\t\tEnter the number of ticket(s) you want to purchase:";
  	cin>>no;
	}while(no<0);
  
  	//initialize variable
  	int count = 1;
  	int membershipFee = 0;
  	
    cout<<endl<<"\t\tInsert code \n\t\t[1] for adult\n\t\t[2] for children\n\t\t[3] for older citizen\n\t\t[4] for foreigner";
    
  	//while loop
  	while(count <= no)
	{
  		do
  		{
    		cout << endl << "\t\tperson " << count << ": ";
    		cin >> code;
		} while(code != 1 && code != 2 && code != 3 && code != 4); //do-while loop

    	if (code == 1)
    	{
    		price += 60;
    		merchCustomer.discountPoints += 60;
		}
   	
		else if(code == 2)
		{
			price += 30;
			merchCustomer.discountPoints += 30;
		}
		
		else if(code == 3)
		{
			price += 35;
			merchCustomer.discountPoints += 35;
		}	
		
		else
		{
			price += 90;
			merchCustomer.discountPoints += 90;
		}
	
    count++;
  }
  
  membership(merchCustomer);
  	
  	// Check if the customer has a membership
    if (merchCustomer.isMember)
    {
        // If the customer has a membership, charge only RM5
        membershipFee = 5;
        cout << "\n\t\tYou will be charged RM" << membershipFee << " for membership renewal.";
    }
        
    else if (merchCustomer.ansMember)
    {
        // If the customer is applying for a new membership, calculate the total membership fee
        membershipFee = 10 + 5; // RM10 registration fee + RM5 annual renewal fee
        cout << "\n\t\tYou will be charged RM" << membershipFee << " for membership registration and renewal.";
    }

    // Add the membership fee to the total price
    price += membershipFee;
}


void update_tix()
{
	do
	{
	cout<<endl<<endl<<"\t\tDo you want to update ticket price? [1] for YES, [2] for NO: ";
	cin>>change_tix;
	if(change_tix==1)
	{
		cout<<endl<<"\t\tSelect code [1] for adult, [2] for children, [3] for older citizen and [4] for foreigner: ";
		cin>>code_c_tix;
		
		switch(code_c_tix)
		{
		case 1:
				cout<<"\t\tUpdate the price in RM: ";
				cin>>tprice[0];
				break;
			case 2:
			    cout<<"\t\tUpdate the price in RM: ";
				cin>>tprice[1];
				break;
			case 3:
				cout<<"\t\tUpdate the price in RM: ";
				cin>>tprice[2];
				break;
			case 4:
				cout<<"\t\tUpdate the price in RM: ";
				cin>>tprice[3];
				break;
			default:
			    cout<<endl<<"\t\tCode is invalid.";	
	}
}
	cout<<endl<<"\t\tUPDATED LIST OF PRICE";
    cout<<endl<<endl<<"\t\t*************************************************";
	cout<<endl<<endl<<"\t\t------------------------------------------------------";
    cout<<endl<<endl<<"\t\t|No\t|\tCategory\t\t|\tPrice|";
	cout<<endl<<"t\t------------------------------------------------------";
	int i;
	for(i=0; i<4; i++)
	cout<<endl<<"\t\t|"<<bil[i]<<"\t|\t"<<cat_ticket[i]<<" \t\t|\tRM"<<tprice[i]<<" |";
	cout<<endl<<"\t\t------------------------------------------------------";
	cout<<endl<<endl<<"\t\t*************************************************";
	
	cout<<endl<<"\t\tAre you done with the price update? [1] for YES, [2} for NO: ";
	cin>>p_conf;
}while(p_conf==2);

}

void signup()
{
		//customer verification using do-while loop
int cust;
    int lengthnum;

    do {
        cout << "\n\t\tAre you a first-time customer? \n\t\t[1] for YES, [2] for NO: ";
        cin >> cust;
    } while (cust != 1 && cust != 2);

    if (cust == 1) {
        cout << "\n\t\tPlease sign up before booking! ^_^";
        cout << "\n\t\tEnter your firstname: ";
        cin >> name;

        do {
            cout << "\n\t\tInsert your phone number (without -): ";
            cin >> num;
            lengthnum = strlen(num);

            if (lengthnum != 10)
                cout << "\n\t\tInvalid input, please enter again.\n";

        } while (lengthnum != 10);

        cout << "\n\t\tCreate new pin: ";
        cin >> pw1;

        booking();
    } else if (cust == 2) {
        booking();
    }

    cout << "\n\t\tYou have successfully ordered the ticket! :)";
}


//login function definition
void login(){
 	
 	
 int lengthnum;

    do {
        cout << "\n\t\t*********************************************";
        cout << "\n\n\n\t\t*********************************************";
        cout << "\n\t\t>>>>>Please login to proceed<<<<<";
        cout << "\n\t\tInsert your name (nickname only): ";
        cin >> name;

        do {
            cout << "\n\t\tInsert your phone number (without -): ";
            cin >> num;
            lengthnum = strlen(num);

            if (lengthnum != 10)
                cout << "\n\t\tInvalid input, please try again.\n";

        } while (lengthnum != 10);

        cout << "\n\t\tEnter your pin : ";
        cin >> pw2;

        if (pw1 != pw2) {
            cout << "\n\t\tThe pin you entered is incorrect. Please try again.";
        } else {
            cout << "\n\t\tThe pin you entered is correct. You can proceed with the booking.";
        }

    } while (pw1 != pw2);
	} // Check the condition after inputting the password
 
void membership(Customer &customer)
{
    cout << "\n\t\tDo you have a membership? [1] for YES, [0] for NO: ";
    cin >> customer.isMember;

    if (customer.isMember == true)
    {
        cout << "\n\t\tYou will be granted loyalty points for your purchase for F&B!!";
        cout << "\n\t\tEnter your membership ID: ";
        cin >> customer.IDMember;
    }
    else if (customer.isMember == false)
    {
        cout << "\n\n\t\tWould you like to apply for membership? [1] for YES, [0] for NO: ";
        cin >> customer.ansMember;

        if (customer.ansMember == true)
        {
            cout << "\n\t\tYou will be charged RM10 to register and RM5 per annum to renew your membership. Confirm purchase?\n\t\t[1] for YES, [0] for NO: ";
            cin >> customer.ansMember;

            if (customer.ansMember == true)
            {
                cout << "\n\t\tPlease register a new member ID: ";
            	cin >> customer.IDMember;
            	
            	price+=10;
				customer.isMember = true;
            }
            else if (customer.ansMember == false)
            {
                cout << "\n\t\tYou will not be charged for the membership fee.";
            }
        }
    }
}
 
void booking_info()
{
  	cout<<endl<<"\t\t-----------------------------------------";
    cout<<endl<<"\t\t|\t\tBOOKING INFO\t\t|";
    cout<<endl<<"\t\t-----------------------------------------";
    time_t t;   //to display time and date
    time(&t);

    cout<<endl<<"\t\tDate and Time: "<<ctime(&t);//using local time
    cout<<endl<<"\t\tBooking ID: "<<rand() ;//generate random number for booking ID
    cout<<endl<<"\t\tName: "<<name;
    
    if(cust==2) //customer phone number verification
    cout<<endl<<"\t\tPhone No: "<<num2;
    else
    cout<<endl<<"\t\tPhone No: "<<num;
 	cout<<endl<<"\t\tTotal ticket(s) purchased: "<<no;
    cout<<endl<<endl<<"\t\tTotal payment is: \n\t\t>>>>>RM "<<price<<"<<<<<";
 }
 
 void service()
{
	cout << "\n\n\t\t------------------------------------------\n";
	cout << "\t\t|\t\tSERVICE RENT\t\t |";
	cout << "\t\t\n\t\t------------------------------------------\n";
	cout << "\t\t\tITEM\t\tPRICE\tQUANTITY\t";
	
	int i;
	
    for(i = 0; i < 4; i++)
    	cout<<"\n\t\t"<<key[i]<<"\t"<<cat_service[i]<<"\tRM"<<cprice[i]<<"  \t  "<<quantity[i]<<"\t";
    
	cout << "\n\n\t\tEnter the number of item that you want to rent:";
	cin >> product;
	
	if(product <= 0 && item <= 0)
	{ 
	   cout << "\t\tEnter positive value only: ";
	   cin >> product;
	}
	
	int g;
	
	for(g = 1; g <= product; ++g)
	{
		cout << "\n\t\tItem " << g << "\n";
		cout << "\t\tEnter Item code>> ";
		cin >> code_service;
		
		switch(code_service)
		{
			case 'a':
				cout << "\t\tEnter quantity of item (*INTEGER ONLY*)>> ";
				cin >> q1;
				tq1 = tq1 + q1;
				merchCustomer.discountPoints += (tq1 * q);
				break;
			case 'b':
				cout << "\t\tEnter quantity of item (*INTEGER ONLY*)>> ";
				cin >> q2;
				tq2 = tq2 + q2;
				merchCustomer.discountPoints += (tq2 * q);
				break;
			case 'c':
				cout << "\t\tEnter quantity of item (*INTEGER ONLY*)>> ";
				cin >> q3;
				tq3 = tq3 + q3;
				merchCustomer.discountPoints += (tq3 * q);
				break;
			case 'd':
				cout << "\t\tEnter quantity of item (*INTEGER ONLY*)>> ";
				cin >> q4;
				tq4 = tq4 + q4;
				merchCustomer.discountPoints += (tq4 * q);
				break;
			default:
				cout << "\t\tInvalid input! Re-enter again\n";
			    cout << "\t\t***************\n";
		        --g;     
				break;
		}
		
		while((code != 'a' || code != 'b' || code != 'c' || code != 'c') && (q1 < 0 || q2 < 0 || q3 < 0 || q4 < 0))
		{
			number = 0;
			tq1 = 0;
			tq2 = 0;
			tq3 = 0;
			tq4 = 0;
			
			cout << "\t\tInvalid input! Re-enter again\n";
			cout << "\t\t***************\n";
		}
 	}

    cout << "\n\n\t\tItems rented: \n";
    cout << "\t\t----------------------\n";
    cout << "\t\t" << cat_service[0] << "\t" << tq1 << "\tRM" << tq1 * BG << "\t";
    cout << "\n\t\t" << cat_service[1] << "\t" << tq2 << "\tRM" << tq2 * SB << "\t";
    cout << "\n\t\t" << cat_service[2] << "\t" << tq3 << "\tRM" << tq3 * BC << "\t";
    cout << "\n\t\t" << cat_service[3] << "\t" << tq4 << "\tRM" << tq4 * SC << "\t";
    
    display_service();
    
	price1 = tq1 * BG;
	price2 = tq2 * SB;
	price3 = tq3 * BC;
	price4 = tq4 * SC;
	
	totals_service = price1 + price2 + price3 + price4;
	
	cout << "\n\t\tTotal price is RM" << totals_service << "\n";
} 
 
void display_service()
{
	cout << "\n\n\t\tItems Left: \n";
    cout << "\t\t----------------------\n";
    cout << "\t\t" << cat_service[0] << "\t" << quantity[0] - tq1 << "\n";
    cout << "\t\t" << cat_service[1] << "\t" << quantity[1] - tq2 << "\n";
	cout << "\t\t" << cat_service[2] << "\t" << quantity[2] - tq3 << "\n";
    cout << "\t\t" << cat_service[3] << "\t" << quantity[3] - tq4 << "\n";
}

void display_menu()
{
 	cout << endl << endl << endl << "\t\t" << "MENU" << endl;
 	cout << "\t\t" << "----" << endl << endl;
 	cout << "\t\t" << "Food" << "\t\t" << "Drinks" << "\t\t" << "Price" << endl;
 	cout << "\t\t" << "----" << "\t\t" << "-----" << "\t\t" << "-----" << endl;
 	
 	for (h = 0; h < 4; ++h)
 	{
 		cout << "\t\t" << "----------------------------------------" << endl;
		cout << "\t\t" << "|" << var[h] << "." << food[h] << "|" << "\t" << drinks[h] << "|" << "\t" << fp[h] << endl;
 	}
 	
 	cout << "\t\t" << "----------------------------------------";
}


void menu_calc()
{
	do
 	{
 		if(x <= 4)
 			cout << endl << endl << "\t\t" << "Number of Set (press 0 to exit)>>";
 			cin >> num_set;
 			cout << endl << endl;	
 			x++;
 	} while((num_set != 0) && (num_set > 0) && (num_set >= 5));

 	for (y = 1; y <= num_set; y++)
 	{
 		cout << "\t\t" << "SET" << y << endl << "\t\t" << "Enter Set Code (A,B,C,D ONLY)>>";
 		cin >> code_item;
 		cout << "\t\t" << "Set Quantity (*INTEGER ONLY*)>>";
 		cin >> q;

 		if((code_item == 'A') ||(code_item=='a')&& (q > 0))
 		{
 			total1 += 15 * q;
 			merchCustomer.discountPoints += (15 * q);
 			mn1=q;
		}		

 		else if((code_item == 'B') ||(code_item=='b')&& (q > 0))
 		{
 			total2 += 20 * q;
 			merchCustomer.discountPoints += (20 * q);
 			mn2=q;
		}	
		
		else if((code_item == 'C') ||(code_item=='c')&& (q > 0))
		{
			total3 += 18 * q;
 			merchCustomer.discountPoints += (18 * q);
 			mn3=q;
		}
			
		else if((code_item == 'D') ||(code_item=='d')&& (q > 0))
		{
			total4 += 99 * q;
 			merchCustomer.discountPoints += (99 * q);
 			mn4=q;
		}	
 			
 		else
 		{
			cout << "\t\t" << "Invalid input! Re-enter" << endl;
			cout << "\t\t" << "***************" << endl;
 			y--;
 		}

 		cout<<endl<<endl;
 	}
}
void menu_receipt(float totalfb)
{
	 cout<<"\t\t"<<"Customer Receipt"<<endl<<"\t\t"<<"---------------"<<endl<<endl;
 cout<<"\t\t"<<"Number of Products >> "<<num_set;
 cout<<"\t\t"<<endl<<endl<<"\t\t"<<"SET\tQUANTITY\tPRICE(RM)"<<endl;
 cout<<"\t\t"<<"--- \t--------\t-----"<<endl<<endl;
 cout<<"\t\t"<<"SET A "<<"\t   "<<mn1<<"\t         "<<total1<<endl;
 cout<<"\t\t"<<"SET B "<<"\t   "<<mn2<<"\t         "<<total2<<endl;
 cout<<"\t\t"<<"SET C "<<"\t   "<<mn3<<"\t         "<<total3<<endl;
 cout<<"\t\t"<<"SET D "<<"\t   "<<mn4<<"\t         "<<total4<<endl;

 totalfb=total1+total2+total3+total4;

 cout<<endl<<"\t\t"<<"TOTAL "<<"\t"<<"RM"<<totalfb;
 cout<<endl<<endl<<"\t\t"<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*";
cout<<endl<<"\t\t"<<"Thank you for ordering F&B! ^_^";
cout<<endl<<"\t\t"<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*";
}

 void upprice()//function definition    
{
	do
	{
	for(i=0;i<4;i++)
	{
	cout<<endl<<"\t\t"<<"Value of Update Set Price"<<i+1<< "(RM): ";
	cin>>newSet[i];
}
cout<<endl<<"\t\t"<<"Are you sure? YES[1]NO[2]>> ";
cin>>ans;
}while(ans!=1);
	cout<<endl<<endl<<endl<<"\t\tMENU"<<endl;
 cout<<"\t\t----"<<endl<<endl;
 cout<<"\t\t Food \t\t Drinks\t\tPrice"<<endl<<endl;
 cout<<"\t\t ---- \t\t----- \t\t-----"<<endl;
 for (h=0;h<4;++h)
 {
 cout<<"\t\t----------------------------------------"<<endl;
 cout<<"\t\t|"<<var[h]<<"."<<food[h]<<"|\t"<<drinks[h]<<"|\t"<<newSet[h]<<"|"<<endl;
 }
 cout<<"\t\t----------------------------------------"<<endl;
}

void event() {
    int explore;
    cout << "\n\n\t                                    |\n";
    cout << "\t                                    |\n";
    cout << "\t                                  .-'-.\n";
    cout << "\t                                 ' ___ '\n";
    cout << "\t                       ---------'  .-.  '---------\n";
    cout << "\t      ______________________ ___'  '-'  '_________________________\n";
    cout << "\t       ''''''-|---|--/    \\==][^',___,'^][==/    \\--|---|-''''''\n";
    cout << "\t                     \\    //  //         \\  \\    /\n";
    cout << "\t                      '--'   OO         OO   '--'\n\n";
    cout << "\t\t>>PRESENTING THE FIRST WATERPARK INDOOR ARCADE<<" << endl;
    cout<<"\t\tDo you wish to enter the arcade ? "<<endl;
    cout << "\t\tPress [1] yes or [2] no : ";
    cin >> explore;
    if (explore == 1) {
        vr();
    } else {
        cout << "\t\tWe hope you have a fantastic day. Goodbye!" << endl;
    }
}

void vr() {
    int t = 0, ageE[100], sumE = 0, eventChoice;
    char namegame[50];
    char pic[13]; 
    size_t lengthnum, lengthic;
    // Get the current time and date
    time_t currentTime;
    time(&currentTime);

    // Display the date and time
    cout << "\n\t\tDate and Time: " << ctime(&currentTime);

    cout << "\n\t\t*****************WELCOME TO OUR MYSTERIOUS JOURNEY**************" << endl;
    cout << "\t\tOur side has an event where only strong people can win" << endl;
    cout << "\t\t******************************************************************" << endl;
    cout << "\n\t\t-----------------------------------------------------" << endl;
    cout << "\t\t|Events Today                         |Tickets Price|" << endl;
    cout << "\t\t|1. Virtual Reality (vr) Aeroplane Sim| Rm 25 each  |" << endl;
    cout << "\t\t|2. Jet Racing Sim Multiplayer        | Rm 10 each  |" << endl;
    cout << "\t\t-----------------------------------------------------" << endl;
    cout << "\t\t-----------------------------------------------------" << endl;
    cout << "\t\t{*disclaimers age below 12 and above 55 cannot enter for a safety purpose*}" << endl;
  
    
    cout << "\n\t\tUsername: ";
    cin >> namegame;


    do {
        cout << "\t\tEnter a 12-digit identity card number (MY): ";
        cin >> pic;
        lengthic = strlen(pic);
        if (lengthic != 12) {
            cout << "\t\tInvalid input, please try again." << endl;
        }
    } while (lengthic != 12);

    cout << "\n\t\tChoose an event (Enter the event number): ";
    cin >> eventChoice;

    switch (eventChoice) {
        case 1:
            cout << "\n\t\tVirtual Reality (vr) Aeroplane Sim" << endl;
            cout << "\t\tHow many tickets do you want to buy? :";
            cin >> t;
            for (int i = 0; i < t; i++) {
                cout << "\t\tEnter age for customer" << i + 1 << ": ";
                cin >> ageE[i];
                if (ageE[i] <= 12 || ageE[i] >= 55) {
                    cout << "\t\tSorry, you are not eligible to play due to age restrictions." << endl;
                    i--;
                } else {
                    sumE += 25;
                    cout << "\t\tYou are eligible to play in the Virtual Reality Aeroplane Sim event." << endl;
                }
            }
            break;
        case 2:
            cout << "\n\t\tJet Racing Sim Multiplayer selected" << endl;
            cout << "\t\tHow many tickets do you want to buy? :";
            cin >> t;
            for (int i = 0; i < t; i++) {
                cout << "\t\tEnter age for customer " << i + 1 << ": ";
                cin >> ageE[i];
                if (ageE[i] <= 12 || ageE[i] >= 55) {
                    cout << "\t\tSorry, you are not eligible to play due to age restrictions." << endl;
                    i--;
                } else {
                    sumE += 10;
                    cout << "\t\tYou are eligible to play in the Jet Racing Sim Multiplayer event." << endl;
                }
            }
            break;
        default:
            cout << "\t\tInvalid event choice. Exiting..." << endl;
            return;
    }

    cout << "\n\t\t**************RECEIPT**************" << endl;
    cout << "\t\tName: " << namegame << endl;
    cout << "\t\tIdentification: " << pic << endl;
    cout << "\t\tNumber of Tickets: " << t << endl;
    cout << "\t\tTotal Amount: " << sumE << " RM" << endl;
    cout << "\t\t***********************************" << endl;
    cout<<"\t\tThank you for the purchased , we do hope you enjoy. "<<endl;
}

pair<double, double> merchandiseCalc(const vector<Product> &catalog, const vector<char> &cart, Customer &customer)
{
    double total = 0.00;
    double redeemPoints = 0.00;

    for (char code : cart)
    {
        auto it = find_if(catalog.begin(), catalog.end(), [code](const Product &p) 
		{
            return p.merchCode == code;
        });

        if (it != catalog.end())
        {
            total += it->merchPrice;
        }
    }

    if (customer.isMember)
    {
        char redeemChoice;
        cout << "\n\t\tDo you want to redeem your discount points? (Y/N): ";
        cin >> redeemChoice;

        if (redeemChoice == 'Y' || redeemChoice == 'y')
        {
    		cout << "\n\t\tEnter the number of discount points to redeem: ";
    		cin >> redeemPoints;
    		
    		if (redeemPoints <= customer.discountPoints && redeemPoints <= total)
    		{
        		customer.discountPoints -= redeemPoints;
        		cout << "\n\t\t" << redeemPoints << " discount points redeemed!\n";
        		cout << "\n\t\t";
        		sleep(2);
    		}
    		else if (redeemPoints >= total)
    		{
        		cout << "\n\t\tRedeemed discount points exceeded total price.\n";
        		redeemPoints = 0.00;
        		cout << "\n\t\t";
        		sleep(2);
    		}
   			else if (redeemPoints > customer.discountPoints)
    		{
        		cout << "\n\t\tNot enough discount points to redeem.\n";
        		redeemPoints = 0.00;
        		cout << "\n\t\t";
        		sleep(2);
    		}
        }
    }
    else
    {
    	cout << "\n\t\t";
    	sleep (2);
        cout << "\n\t\tYou doesn't have membership, only members can redeem discount points.\n";
		cout << "\n\t\t";
    	sleep (2);
    }

    return make_pair(total, redeemPoints);
}

void merchandisePurchase(const vector<Product> &catalog, Customer &customer)
{
    int merchSize;

    cout << "\n\t\tEnter how many merchandise you want to buy!: ";

    while (!(cin >> merchSize))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n\t\tPlease enter a valid integer value: ";
    }

    vector<char> cart(merchSize);
    char codeChoice;

    cout << "\n\t\tChoose your desired merchandise!\n\t\tPlease enter the merchandise code: ";

    for (int i = 0; i < merchSize; i++)
    {
        cout << "\n\t\tMerchandise [" << i + 1 << "]: ";
        cin >> codeChoice;

        // Validate the merchandise code
        while (find_if(catalog.begin(), catalog.end(), [codeChoice](const Product &p) {
                   return p.merchCode == codeChoice;
               }) == catalog.end())
        {
            cout << "\n\t\tPlease enter a valid merchandise code...";
            cout << "\n\t\tMerchandise [" << i + 1 << "]: ";
            cin >> codeChoice;
        }

        cart[i] = codeChoice;
    }

    pair<double, double> calcResult = merchandiseCalc(catalog, cart, customer);
    double totalBeforeDiscount = calcResult.first;
    double redeemPoints = calcResult.second;

    double discountedPrice = totalBeforeDiscount - redeemPoints;

    // Display the receipt
    cout << fixed << setprecision(2);
    cout << "\n\n";
    cout << "\t\t============ Merchandise Receipts ============\n\n";
    cout << "\t\t" << string(46, '-') << endl;
    cout << "\t\t| " << setw(30) << "Product Name" << " | " << setw(9) << "Price(RM)" << " |" << endl;
    cout << "\t\t" << string(46, '-') << endl;

    for (char code : cart)
    {
        auto it = find_if(catalog.begin(), catalog.end(), [code](const Product &p) {return p.merchCode == code;});

        if (it != catalog.end())
        {
            cout << "\t\t| " << setw(30) << it->merchName << " | " << setw(9) << it->merchPrice << " |" << endl;
        }
    }

    cout << "\t\t" << string(46, '-') << endl;
    cout << "\t\t| " << setw(30) << "Total Price" << " | " << setw(9) << totalBeforeDiscount << " |" << endl;
    
    // Display redeemed points and discounted price only if the customer is a member
    if (customer.isMember)
    {
        cout << "\t\t| " << setw(30) << "Redeemed Point" << " | " << setw(9) << redeemPoints << " |" << endl;
        cout << "\t\t| " << setw(30) << "Discounted Price" << " | " << setw(9) << discountedPrice << " |" << endl;
    }

    cout << "\t\t" << string(46, '-') << endl;
}

void displayCatalog(const vector<Product>& catalog) 
{
	cout << fixed << setprecision(2);
    cout << "\t\t" << string(38, '-') << endl;
    cout << "\t\t|" << setw(4) << "Code|" << setw(21) << "Product Name|" << setw(11) << "Price(RM)|" << endl;
    cout << "\t\t" << string(38, '-') << endl;

    for (const auto& product : catalog) 
	{
        cout << "\t\t|" << setw(4) << product.merchCode << "|" << setw(20) << product.merchName << "|" << setw(10) << product.merchPrice << "|" << endl;
    }

    cout << "\t\t" << string(38, '-') << endl;
}

void merchandiseMenu(Customer &customer) 
{
    vector<Product> catalog = 
	{
        {'A', "Keychain", 30.00},
        {'B', "T-shirt", 200.00},
        {'C', "Snorkel", 350.00},
        {'D', "Cap", 45.00},
        {'E', "Bottle", 30.00},
        {'F', "Tote Bag", 25.00},
        // can add merch
    };

    int choice;

    do 
	{
        cout << "\n\n";
        cout << "\t\t----------------------------------------------\n";
        cout << "\t\tWELCOME TO SHAH ALAM WATERPARK MERCHANDISE SHOP!\n";
        cout << "\t\t     -HERE'S OUR FINEST MERCHANDISE SOLD-     \n";
        cout << "\t\t----------------------------------------------\n";
        cout << "\n\n";

        cout << "\t\t================ Catalog Menu ================\n";
        cout << "\t\t1. Display Catalog\n";
        cout << "\t\t2. Discount Point\n";
        cout << "\t\t3. Purchase Window\n";
        cout << "\t\t4. Exit\n";
        cout << "\t\t==============================================\n";
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
            	clearScreen();
                cout << "\n\t\tEntering Catalog Window...\n";
                sleep(2);
                displayCatalog(catalog);
                cout << "\n\t\t";
                system("PAUSE");
                break;;
            case 2:
            	clearScreen();
            	cout << "\n\t\tEntering Discount Points Window...\n";                
                sleep(2);
                if (customer.isMember) 
				{
					cout << "\n\t\tID member: " << customer.IDMember << endl;
                    cout << "\n\t\tTotal Discount Points: " << customer.discountPoints << " points\n";
                } 
				
				else 
				{
                    cout << "\n\t\tSorry, only members can view their total points.\n";
                }
                cout << "\n\t\t";
                system("PAUSE");
                break;
            case 3:
            	clearScreen();
                cout << "\n\t\tEntering purchase Window...\n";     
                sleep(2);
                merchandisePurchase(catalog, customer);
                break;
            case 4:
            	clearScreen();
            	cout << "\n\t\t" << "Exiting program. Goodbye!\n";     
                sleep(2);
                break;
            default:
            	clearScreen();
                cout << "\n\t\t"
                     << "Invalid choice. Please enter a valid option.\n";
                cout << "\n\t\t";
                system("PAUSE");
        }

    } while (choice != 3 && choice != 4);
    
}

void allreceipt(){
	booking_info();
	
}
