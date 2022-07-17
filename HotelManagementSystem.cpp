#include<fstream>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
#include"hash.hpp"
using namespace std;
//MARK:- Interface Functions Here =>

void intro() {
	cout<<"\n\n\t            ";
	cout<<"     Project On Hotel Management System";
	cout<<"\n\n\t\t\t\t     MADE BY";
	cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t Archit Bikram   \t\t\t      ||";
	cout<<"||\t\t\t\t\t\t\t\t\t      ||";
	cout<<"||\t\t\t\t\t  \t\t\t\t      ||";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void head() {
	system("CLS"); 
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"\t\t\t\t\t\t\t\t       ";
	cout<<"\t\t\t\t\t\t\t   XYZ Group of Hotels       ";
	cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
}

void time() {
	int i=0;
	long long j;
	cout<<"	\n\n\n	Connecting to Server\n 	Syncing Data";
	while(i<10)	{
		for (j=5;j>4;j++) {
			if (j==99999) {
				cout<<".";
				break;
			}
		}
		++i;
	}
}
string Admin_pswd_hash;
bool match(string S1,string S2){
	if(S1.size() != S2.size()) return false;
	for(int i = 0 ; i < S1.size() ; i++)
		if(S1[i] != S2[i]) return false;
	return true;
}
// void __hash(string &S){
// for(int i = 0 ; i < (S.size()/2) ; i++) 
// 	S[i] = S[S.size()-i-1];
// return;
//}

bool Authentication(string user,string Pswd_hash){
	for(int i = 0; i < 5; i++) if(user[i] != "admin"[i]) return false;
	for(int i = 0 ; i < Pswd_hash.size() ; i++)
		if(Pswd_hash[i] != Admin_pswd_hash[i] ) return false;
	return true;
}



// Hotel Class Here =>

class hotel {
	private:
			int room_no;
			char name[30];
			char address[50];
			char phone[15];
			int days;
			float fare;
	public:
			void main_menu();		//to display the main menu
			void add();				//to book a room
			void display(); 		//to display the customer record
			void rooms();			//to display allotted rooms
			void edit();			//to edit the customer record
			int check(int);	     	//to check room status
			void modify(int);		//to modify the record
			void delete_rec(int);   //to delete the record
			void ChangePswd();		//to change password
};

void hotel::main_menu() {
	int choice = 1;
	while(choice!=6) {
		system("CLS");
		head();
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *";
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Book A Room";
		cout<<"\n\t\t\t2.Customer Record";
		cout<<"\n\t\t\t3.Rooms Allotted";
		cout<<"\n\t\t\t4.Edit Record";
		cout<<"\n\t\t\t5.Change Password";
		cout<<"\n\t\t\t6.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice) {
			case 1:	add();
					break;
			case 2: display();
					break;
			case 3: rooms();
					break;
			case 4:	edit();
					break;
			case 5: ChangePswd();
					break;
			case 6: break;
			default: {
				cout<<"\n\n\t\t\tWrong choice.....!!!";
				cout<<"\n\t\t\tPress any key to continue....!!";
				main_menu();
			}
		}
	}
}

void hotel::ChangePswd(){
	while(true)
	{system("CLS");
	head();
	// Login Starts
	string UserName, Pswd, Y;
	cout<<"\n\n\t\t\t\tDo you want to go back?(Y/N) => "; 
	cin >> Y;
	cout<<"\n\n\t\t\t\tusername => ";
	cin>>UserName;
	cout<<"\n\t\t\t\tpassword => ";
	cin>>Pswd;
	__hash(Pswd);
	cout<<"\n\n\t";
	time();
	cout<<"\t";
	if(Authentication(UserName,Pswd))
		{cout<<"\n\n\t\t\t  !!!Correct Password!!!"; break;}}
	string Npswd,Rpswd;
	do
	{cout<<"\n\t\t\t\tNew password => ";
	cin>>Npswd; __hash(Npswd);
	cout<<"\n\t\t\t\tRepeat New password => ";
	cin>>Rpswd; __hash(Rpswd);
	if(match(Rpswd,Npswd))
	{
		Admin_pswd_hash = Rpswd;
		ofstream outfile;
		outfile.open("pswdhsh.dat", ofstream::out | ofstream::trunc);
		outfile<<Admin_pswd_hash;
		outfile.close();
		return;
	}
	cout<<"\n\t\t\t\t Retry? (Y/N) ";
	cin >> Npswd;
}
while(match(Npswd,"Y"));
	return;
}

void hotel::add() {
	system("CLS");
	head();
	int r,flag;
	ofstream fout("Record.dat",ios::app);
	cout<<"\n Enter Customer Details";
	cout<<"\n ----------------------";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);
	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";
	else {
		room_no=r;
		cout<<"\n Name: ";
		cin >> (this->name);
		cout<<"\n Address:";
		gets(address);
		gets(address);
		cout<<"\n Phone No: ";
		cin >> (this->phone);
		cout<<"\n No of Days to Checkout: ";
		int var;
		cin>>var;
		fare=var*900;						//900 is currently set as the
											//default price per day
		this->days = var;
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Room is booked...!!!";
	}

	cout<<"\n Press any key to continue.....!!";
	getch();
	fout.close();
}

void hotel::display() {
	system("CLS");
	head();
	ifstream fin("Record.dat",ios::in);
	if(!fin.good())
		{
			cout<<"No Data";
			getch();
			return;
		}
	int r,flag;
	cout<<"\n Enter room no: ";
	cin>>r;
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r) {
			system("CLS");
			head();
			cout<<"\n Customer Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			cout<<"\n Days: "<<days;
			cout<<"\n Total Fare: "<<fare;
			flag=1;
		}
	}
	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant....!!";
	cout<<"\n\n Press any key to continue....!!";
	getch();
	fin.close();
}

void hotel::rooms() {
	system("CLS");
	head();
	ifstream fin("Record.dat",ios::in);
	if(!fin.good()){
		cout<<"NO Rooms Booked";
		getch();
		return;
	}
	cout<<"\n\t\t\t    List Of Rooms Allotted";
	cout<<"\n\t\t\t    ----------------------";
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(hotel));
		cout<<"\n Room no: "<<room_no<<"\n Name: "<<name;
		cout<<"\n Address: "<<address<<"\n Phone: "<<phone;
		cout<<"\n Days: "<<days<<"\n Total: "<<fare;
		cout<<"\n**********************************";
	}
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();
}

void hotel::edit() {
	int choice,r;
	system("CLS");
	head();
	cout<<"\n Enter room no: " ;
	cin>>r;
	system("CLS");
	head();
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.Modify Customer Record";
	cout<<"\n 2.Delete Customer Record";
	cout<<"\n 3.Exit";
	cout<<"\n Enter your choice: ";
	cin>>choice;

	switch(choice) {
		case 1:	modify(r);
				break;
		case 2:	delete_rec(r);
				break;
		case 3: cout<<"\n Press any key to continue....!!!";
				getch();	return;
		default: cout<<"\n Wrong Choice.....!!";
				edit();
	}
	cout<<"\n Press any key to continue....!!!";
	getch();
}


int hotel::check(int r) {
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r) {
			flag=1;
			break;
		}
	}

	fin.close();
	return(flag);
}

void hotel::modify(int r) {
	system("CLS");
	head();
	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);
	while(!file.eof()) {
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));
		if(room_no==r) {
			cout<<"\n Enter New Details";
			cout<<"\n -----------------";
			cout<<"\n Name: ";
			gets(name); gets(name);
			cout<<"\n Address: ";
			gets(address);
			cout<<"\n Phone no: ";
			gets(phone);
			cout<<"\n Days: ";
			cin>>days;
			fare=days*900;
			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		}
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void hotel::delete_rec(int r) {
	system("CLS");
	head();
	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(!fin.eof()) {
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r) {
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone No: "<<phone;
			cout<<"\n Days: "<<days;
			cout<<"\n Total Fare: "<<fare;
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;
			if(ch=='n')
				fout.write((char*)this,sizeof(hotel));
			flag=1;
			break;
		}
		else
			fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant...!!";
	else {
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}

//MARK:- Main() Function Here =>


int main() {
	system("color 30");
	ifstream fil("pswdhsh.dat");
	if(fil.good())
	fil>>Admin_pswd_hash;
	else {Admin_pswd_hash = "12345678",__hash(Admin_pswd_hash);
		ofstream fil("pswdhsh.dat");
		fil<<Admin_pswd_hash;
	}
	fil.close();
	//Initial password is 12345678
	hotel h;
	system("CLS");
	cout<<"\n\n\n";
	intro();
	time();
	cout<<"\n\n\n\t\t\tPress any key to continue....!!";

	getch();
	system("CLS");
	head();
	// Login Starts
	string UserName, Pswd;
	cout<<"\n\n\t\t\t\tusername => ";
	cin>>UserName;
	cout<<"\n\t\t\t\tpassword => ";
	system("color 33");
	cin>>Pswd;
	system("color 30");	
	__hash(Pswd);
	cout<<"\n\n\t";
	time();
	cout<<"\t";
	if(Authentication(UserName,Pswd))
		cout<<"\n\n\t\t\t  !!!Login Successfull!!!";
	else {
		cout<<"\n\n\t\t\t!!!INVALID CREDENTIALS!!!";
		getch();
		exit(-1);
	}
	// -> Login Ends
	system("CLS");
	h.main_menu();
	getch();
	
	return 0;
} 
