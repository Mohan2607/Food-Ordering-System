#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;
struct User_details
{
    char name[100];
    char password[50];
    char email[100];
    char phone_no[10];
};
struct Hotels
{
    char hotel[100];
    char food_one[50];
    char food_two[50];
    char food_three[50];
    char temp_hotel[50];
    int price_one,price_two,price_three,add_count[50],add_price[50];
};
struct User_details s[100];
struct Hotels h[4];

int choice,i,a,b,j=0,countt=0,n,total=0;
char temp_name[100],temp_pass[50],temp_confirmpass[50],temp_email[50],temp_mobile[10];
int caps=0,small=0,num=0,special_characters=0;
int p=0,z=0,rate=0,flag;
void login();
void signup();
void swiggy();
int account_check();
int validate();
void cart();
void allocate_hotels();
void search_by_hotel();
void search_by_food();
void hotel_details(int);
void food_order(int);
int food_choice,hotel_choice,confirm,food,hotel_id;

int main()
{
    while(1)
	{
	    cout<<"     WELCOME!!   "<<endl<<endl;
	    cout<<"----------------------------"<<endl;
		cout<<"    FOOD ORDERING SYSTEM"<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"1).LOGIN"<<endl<<"2).SIGNUP"<<endl<<"3).EXIT"<<endl<<"Enter Your Choice--:";
	    cin>>choice;
		switch(choice)
		{
			case 1:
			{
				login();
				break;
			}
			case 2:
			{
				signup();
				break;
			}
			case 3:
            {
                exit(1);
            }
			default:
			{
			cout<<"Please enter the valid choice!!";
			break;
			}
		}
	}
}

int account_check()
{
    for(i=0;i<100;i++)
    {
        if(!strcmp(s[i].email,temp_email))
        {
            if(!strcmp(s[i].password,temp_pass))
            {
                cout<<"Account already existed...Please login!!!"<<endl;
                main();
            }
        }
    }
    if(i==100)
    {
       return 1;
    }
}

int validate()
{
    for(i=0;temp_name[i]!='\0';i++)
    {
        if(!((temp_name[i]>='a' && temp_name[i]<='z')|| (temp_name[i]>='A' && temp_name[i]<='Z')))
        {
            countt=0;
            cout<<"Invalid Name....Please enter the valid name....."<<endl<<endl;
            main();
        }
        else
            countt=1;
    }
    if(countt==1)
    {
        caps=0;small=0;num=0;special_characters=0;
        for(i=0;temp_pass[i]!='\0';i++)
        {
            if(temp_pass[i]>='A' && temp_pass[i]<='Z')
                caps++;
            else if(temp_pass[i]>='a' && temp_pass[i]<='z')
                small++;
            else if(temp_pass[i]=='@' || temp_pass[i]=='#' || temp_pass[i]=='&' || temp_pass[i]=='*' || temp_pass[i]=='.')
                special_characters++;
            else if(temp_pass[i]>='0' && temp_pass[i]<='9')
                num++;
        }
        if(caps>=1 && small>=3 && special_characters>=1 && num>=3)
        {
            countt=1;
        }
        else
        {
            countt=0;
            cout<<"The entered password is too weak..!Please enter the strong password...."<<endl;
            main();
        }
    }
    if(countt==1)
    {
        for(i=0;temp_pass[i]!='\0';i++)
        {
            if(temp_pass[i]!=temp_confirmpass[i])
            {
                countt=0;
               cout<<" Password did not match...Please try again!!"<<endl;
                main();
                break;
            }
            else
                countt=1;
        }
    }
    if(countt==1)
    {
        int at=0,dot=0;
        small=0;num=0;
        for(i=0;temp_email[i]!='\0';i++)
        {
            if(temp_email[i]=='@')
                at++;
            else if(temp_email[i]=='.')
                dot++;
            else if(temp_email[i]>='a' && temp_email[i]<='z')
                small++;
            else if(temp_email[i]>='0' && temp_email[i]<='9')
                num++;
            else
            {
                cout<<"Enter valid mail address..."<<endl;
                main();
                break;
            }
        }
        if(at==1 && dot==1 && small>=5)
            {
                countt=1;
            }
        else
        {
            countt=0;
            cout<<"Please enter the valid mail address..."<<endl;
            main();
        }
    }
    if(countt==1)
    {
        num=0;
        for(i=0;temp_mobile[i]!='\0';i++)
        {
            if(temp_mobile[i]>='0' && temp_mobile[i]<='9')
                num++;
        }
        if(num==10 &&temp_mobile[0]!='0')
        {
            return 1;
        }
        else
        {
            cout<<"Please enter the valid Mobile number..."<<endl;
            main();
        }
    }
}

void signup()
{
    cout<<"--------SIGNUP--------"<<endl<<endl;
    cout<<"Enter your Name(ONLY ALPHABETS):";
    cin>>temp_name;
    cout<<"Enter a strong password(Password must be 8 characters):";
    cin>>temp_pass;
    cout<<"Confirm your password:";
    cin>>temp_confirmpass;
    cout<<"Enter your Email Address:";
    cin>>temp_email;
    cout<<"Enter your Mobile number:";
    cin>>temp_mobile;
    a=account_check();
    b=validate();
    if(a==1 && b==1)
    {
        strcpy(s[j].name,temp_name);
        strcpy(s[j].password,temp_pass);
        strcpy(s[j].email,temp_email);
        strcpy(s[j].phone_no,temp_mobile);
        j++;
        cout<<endl<<"Sign up successfully...Please login!!!"<<endl;
    }
}

void login()
{
  cout<<"-------LOGIN-------"<<endl<<endl;
    cout<<"Enter the E-mail:";
    cin>>temp_email;
    cout<<"Enter the password:";
    cin>>temp_pass;
        for(i=0;i<j;i++)
        {
            if(!strcmp(s[i].email,temp_email))
            {
                if(!strcmp(s[i].password,temp_pass))
                   {
                       cout<<endl<<"Login successful..."<<endl;
                       swiggy();
                       break;
                   }
                   else
                   {
                       cout<<"Invalid password...Please Enter the correct password!!<<endl";
                       main();
                       break;
                   }
			}
		}
        cout<<endl<<endl<<"Account does not exist! Please signup..."<<endl<<endl;
        main();
}

void swiggy()
{
    cout<<".. Welcome "<<s[i].name<<"!!"<<endl;
    cout<<"Here, We provide two ways of search for Food Order:)"<<endl<<endl<<"1)."<<"Search_by_hotel"<<endl<<"2)."<<"Search_by_food"<<endl<<"3)."<<"View_Cart"<<endl<<"4)."<<"Exit"<<endl;
    cout<<"Please Enter your choice:";
    cin>>choice;
    switch(choice)
        {
            case 1:
                {
                    search_by_hotel();
                    break;
                }
            case 2:
                {
                    search_by_food();
                    break;
                }
            case 3:
                {
                    cart();
                    break;
                }
            case 4:
                {
                    exit(1);
                }
            default:
                {
                    printf("Enter the valid choice....");
                    break;
                }
        }
}
void search_by_hotel()
{
    allocate_hotels();
    cout<<endl<<"...HOTELS..."<<endl<<"1)."<<h[1].hotel<<endl<<"2)."<<h[2].hotel<<endl<<"3)."<<h[3].hotel<<endl<<"4)."<<h[4].hotel<<endl<<"5)."<<h[5].hotel <<endl<<"6).Go_Back"<<endl<<"7).Exit"<<endl<<"Choose the hotel--:";
    cin>>hotel_choice;
    if(hotel_choice>7)
    {
       cout<<endl<<"Please Enter the valid choice.."<<endl;
        search_by_hotel();
    }
    else if(hotel_choice==6)
        swiggy();
    else if(hotel_choice==7)
        exit(1);
    else
        hotel_details(hotel_choice);
}

void search_by_food()
{
    allocate_hotels();
    while(1)
    {
        cout<<endl<<"Please choose the food"<<endl<<"1)."<<h[1].food_one<<h[1].price_one<<endl<<"2)."<<h[1].food_two<<h[1].price_two<<endl<<"3)."<<h[1].food_three<<h[1].price_three<<endl<<"4)."<<h[2].food_one<<h[2].price_one<<endl<<"5)."<<h[2].food_two<<h[2].price_two<<endl<<"6)."<<h[2].food_three<<h[2].price_three<<endl<<"7)."<<h[3].food_one<<h[3].price_one<<endl<<"8)."<<h[3].food_two<<h[3].price_two<<endl<<"9)."<<h[3].food_three<<h[3].price_three<<endl<<"10)."<<h[4].food_one<<h[4].price_one<<endl<<"11)."<<h[4].food_two<<h[4].price_two<<endl<<"12)."<<h[4].food_three<<h[4].price_three<<endl<<"13)."<<h[5].food_one<<h[5].price_one<<endl<<"14)."<<h[5].food_two<<h[5].price_two<<endl<<"15)."<<h[5].food_three<<h[5].price_three<<"16)."<<"Go-Back"<<endl<<"17)."<<"Exit"<<endl;
       cout<<endl<<"Please Enter Your Choice";
        cin>>food;
        if(food>16)
            {
                cout<<"Please Enter the valid choice"<<endl;
                search_by_food();
            }
            else if(food==16)
                swiggy();
            else if(food==17)
                exit(1);
            else
                food_order(food);
    }
}

void food_order(int food)
{
    if(food>=1 && food<=3)
		hotel_id=1;
	else if(food>=4 && food<=6)
		hotel_id=2;
	else if(food>=7 && food<=9)
		hotel_id=3;
    else if(food>=10 && food<=12)
        hotel_id=4;
    else
        hotel_id=5;
    flag=1;
    if((food%3)==1)
	{
		cout<<"Please Enter the Count of "<<h[hotel_id].food_one;
		cin>>n;
		rate=(n*h[hotel_id].price_one);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_one))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_one);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
	else if((food%3)==2)
	{
		cout<<"Please Enter the Count of "<<h[hotel_id].food_two<<endl;
		cin>>n;
		rate=(n*h[hotel_id].price_two);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_two))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_two);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
	else if((food%3)==0)
	{
	cout<<endl<<"Please Enter the Count of "<<h[hotel_id].food_three<<":";
		cin>>n;
		rate=(n*h[hotel_id].price_three);
		total=total+rate;
        for(i=0;i<p;i++)
            {
                if(!strcmp(h[i].temp_hotel,h[hotel_id].food_three))
                {
                    h[i].add_price[i]+=rate;
                    h[i].add_count[i]+=n;
                    flag=0;
                }
            }
            if(flag==1)
            {
                strcpy(h[p].temp_hotel,h[hotel_id].food_three);
                h[p].add_count[z]=n;
                h[p].add_price[z]=rate;
                p++;
                z++;
            }
	}
}

void hotel_details(int hotel_choice)
{
    while(1)
    {
         flag=1;
        cout<<endl<<"List of foods available in :"<<h[hotel_choice].hotel<<endl<<"1)."<<h[hotel_choice].food_one<<"-"<<h[hotel_choice].price_one<<endl<<"2)."<<h[hotel_choice].food_two<<"-"<<h[hotel_choice].price_two<<endl<<"3)."<<h[hotel_choice].food_three<<"-"<<h[hotel_choice].price_three<<endl<<"4)."<<"Exit"<<endl<<"Please Enter Your Choice--:";
			cin>>food_choice;
			if(food_choice==1)
			{
				cout<<"Please Enter the Count of -"<<h[hotel_choice].food_one;
				cin>>n;
				rate=(n*h[hotel_choice].price_one);
				total=total+rate;
				for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_one))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_one);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
			}
			else if(food_choice==2)
			{
				cout<<"Please Enter the Count of "<<h[hotel_choice].food_two<<endl;
				cin>>n;
                rate=(n*h[hotel_choice].price_two);
				total=total+rate;
                for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_two))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_two);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
			}
			else if(food_choice==3)
            {
                cout<<"Please Enter the count of "<<h[hotel_choice].food_three<<endl;
                cin>>n;
                rate=(n*h[hotel_choice].price_three);
                total=total+rate;
                for(i=0;i<p;i++)
                {
                    if(!strcmp(h[i].temp_hotel,h[hotel_choice].food_three))
                    {
                        h[i].add_price[i]+=rate;
                        h[i].add_count[i]+=n;
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    strcpy(h[p].temp_hotel,h[hotel_choice].food_three);
                    h[p].add_count[z]=n;
                    h[p].add_price[z]=rate;
                    p++;
                    z++;
                }
            }
            else if(food_choice==4)
            {
                search_by_hotel();
            }
            else
            {
                cout<<"Please Enter the valid choice..."<<endl;
                hotel_details(hotel_choice);
            }
    }
}

void cart()
{
    if(total==0)
    {
        cout<<"You didn't order anything....Please order the food"<<endl;
        swiggy();
    }
    cout<<endl<<endl<<"--------------Cart----------------"<<endl<<endl;
    for(i=0;i<p;i++)
    {
           cout<<endl<<h[i].temp_hotel<<h[i].add_count[i]<<h[i].add_price[i];
    }
	cout<<"Your Total Order Amount is "<<" "<<total<<endl;
	cout<<"Do you want to add more items in the cart(y=1/n=0):";
	cin>>choice;
	if(choice==1)
    {
        swiggy();
    }
	cout<<"Do You wish to order (y=1/n=0):";
	cin>>choice;
	if(choice==1)
	{
		cout<<"Thank You for your order!! Your Food is on the way. Welcome again!!"<<endl;
		exit(1);
	}
	else if(choice==0)
	{
		cout<<endl<<"Do You want to exit -1 or Go back -0: ";
		cin>>confirm;
		if(confirm==1)
		{
			cout<<"Oops! Your order is cancelled!! Exiting..Thank You :) visit again !"<<endl;
			exit(1);
		}
		else
		{
		    cout<<"Do you want to delete the cart(y=1/n=0):"<<endl;
		    cin>>choice;
		    if(choice==1)
            {
                p=0;
                z=0;
                total=0;
            }
			cout<<"Thank You :)"<<endl;
			swiggy();
		}
	}
	else
	{
		cout<<"Please Enter the correct choice"<<endl;
		cart();
	}
}

void allocate_hotels()
{
    strcpy(h[1].hotel,"Aarya_bhavan");
    strcpy(h[1].food_one,"Full-Meals");
    strcpy(h[1].food_two,"Plain_roast");
    strcpy(h[1].food_three,"chapathi");
    h[1].price_one=130;
    h[1].price_two=40;
    h[1].price_three=60;
    strcpy(h[2].hotel,"Barbeque_nation");
    strcpy(h[2].food_one,"Chicken_briyani");
    strcpy(h[2].food_two,"Chicken_Shawarma");
    strcpy(h[2].food_three,"Grill_chicken");
    h[2].price_one=250;
    h[2].price_two=150;
    h[2].price_three=400;
    strcpy(h[3].hotel,"Denmark_Restaurent");
    strcpy(h[3].food_one,"Dosa");
    strcpy(h[3].food_two,"Chapathi");
    strcpy(h[3].food_three,"Chicken_briyani");
    h[3].price_one=20;
    h[3].price_two=15;
    h[3].price_three=180;
    strcpy(h[4].hotel,"Hotel_mathu");
    strcpy(h[4].food_one,"Mutton_Chukka");
    strcpy(h[4].food_two,"Parotta");
    strcpy(h[4].food_three,"chocolate_icecream");
    h[4].price_one=100;
    h[4].price_two=15;
    h[4].price_three=50;
    strcpy(h[5].hotel,"Domino's");
    strcpy(h[5].food_one,"Pizza");
    strcpy(h[5].food_two,"Burger");
    strcpy(h[5].food_three,"Sandwich");
    h[5].price_one=180;
    h[5].price_two=100;
    h[5].price_three=90;
}
