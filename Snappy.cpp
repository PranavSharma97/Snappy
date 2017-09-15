#include<bits/stdc++.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
using namespace std;

fstream database("users.txt",ios::ate|ios::in|ios::out);
	
class games{
	
	friend void handleAccount(char user[]);

//Function to select game	

void chooseGame(char user[])
{
	void handleAccount(char user[]);
	system("cls");
	int choice;
	cout<<endl<<"Which game would you like to play?";
	cout<<endl<<endl<<"TIC-TAC-TOE(press 1)(1 PLAYER)";
	cout<<endl<<endl<<"COWS AND BULLS (press 2)(2 PLAYER)";
	cout<<endl<<"Press 3 to exit";
	cin>>choice;
	if(choice==1)
	ticTacToe(user);
	else if(choice==2)
	cowsAndBulls(user);
	else if(choice==3);
	handleAccount(user);
}


void display(char a[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<" ";
			
		}
		cout<<"\n";
	}
}
int full(char a[3][3]){
int f=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
	
		if(a[i][j]=='_')
		f=1;
	}
}
if(f==1)
return 0;
else 
return 1;
	
}
int checkd(char a[3][3],char p){
int f=0;
for(int i=0;i<3;i++){
	if (a[i][i]==p)
	f++;
}
if(f==3)
return 1;
else 
{
	f=0;
	int i=0;
	for(int j=2;j>=0;j--){
		
	if (a[i][j]==p)
	f++;
	i++;
}
}
if(f==3)
return 1;	
else
return 0;
}		
	
	
int checkcol(char a[3][3], char p){
int f=0;
for(int j=0;j<3;j++){
	for (int i=0;i<3;i++){
		if (a[i][j]==p)
		f++;	
	}
	if(f==3){
		return 1;
		break;
	}
	else
	f=0;
}
if(f==0)
return 0;		
}
int checkrow(char a[3][3],char p){
int f=0;
for(int i=0;i<3;i++){
	for (int j=0;j<3;j++){
		if (a[i][j]==p)
		f++;		
	}
	if(f==3){
		return 1;
		break;
	}
	else
	f=0;
}
if(f==0)
return 0;
}

//Game-1 Tic-tac-toe

void ticTacToe(char user[])
{	
	void handleAccount(char*);
	int back;
	
system("cls");

char name[100];
char p1,p2;

cout<<"\n*************************TIC TAC TOE********************\n";
cout<<"\nRules of the game:-";
cout<<"\n1. Its a one player game v/s computer";
cout<<"\n2. There is one symbol per player i.e. 'X' or 'O'";
cout<<"\n2. The player selects his symbol first";
cout<<"\n3. The player/computer who manages to complete one entire row/ diagonal /column in 3X3 grid, shall be declared the WINNER";
cout<<"\n\nLets Begin!\n";
system("pause");
system("cls");
cout<<"\nTHE GAME BEGINS\n";
cout<<"\nEnter your name: ";

cin>>name;
cin.ignore();
cout<<name<<": Enter choice: 'X' or 'O' ";

cin>>p1;
if(p1=='X'||p1=='x')
{
p1='X';
p2='O';
}
else if(p1=='O'||p1=='o'){
p2='X';
p1='O';
}
int f=1;
char a[3][3],ch='_';
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		a[i][j]=ch;
	}
}
cout<<endl;
int r,c,col,row,d,true1=0,true2=0,y=0;
while(y==0){
display(a);
cout<<"\n "<<name<<": Enter your position: ";
cout<<"\nEnter row : ";
cin>>r;
cin.ignore();
cout<<"Enter column: ";
cin>>c;
true1=0;
while(true1==0){
	if((a[r-1][c-1]==p1)||(a[r-1][c-1]==p2)){
		cout<<"\nSorry...This position is already occupied..please enter again: ";
		cout<<"\nEnter row : ";
		cin>>r;
		cout<<"Enter column: ";
		cin>>c;
		}
	else {
		true1=1;
		a[r-1][c-1]=p1;
		}
}
		display(a);

d=checkd(a,p1);
row=checkrow(a,p1);
col=checkcol(a,p1);

if((d==1)||(col==1)||(row==1))
{
cout<<"\n\n "<<name<<" has won the game!!\nGame Over!\n";
display(a);
	char temp[100];
	strcpy(temp,user);
	string details(temp);
	details+="gamedetails.txt";
	ofstream detail(details.c_str(),ios::app);
	 time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    detail<<endl<<"GAME : TIC TAC TOE"<<endl;
    detail<<"DATE : "<<now->tm_mday<<'-'<< (now->tm_mon + 1) << '-'<< (now->tm_year + 1900);
    detail<<endl<<"SCORE : 100"<<endl;
break;
}
if(full(a)==1){
	cout<<"\nGAME has been drawn!";
	cout<<"\nTHANKS for playing.";
	break;
}
else{
		cout<<"\nComputer's turn: ";
		cout<<"\nComputer is thinking...";
srand(time(NULL));
r=rand()%3+1;
srand(time(NULL));
c=rand()%3+1;
true2=0;

while(true2==0){
	if((a[r-1][c-1]==p1)||(a[r-1][c-1]==p2)){
		srand(time(NULL));
		r=rand()%3+1;
		srand(time(NULL));
		c=rand()%3+1;
		}
	else{
		true2=1;
		a[r-1][c-1]=p2;
		}
}
		display(a);
d=checkd(a,p2);
row=checkrow(a,p2);
col=checkcol(a,p2);
	
if((d==1)||(col==1)||(row==1))
{
cout<<"\n\nComputer has won the game!!\nGame Over!\n";
display(a);
char temp[100];
	strcpy(temp,user);
	string details(temp);
	details+="gamedetails.txt";
	ofstream detail(details.c_str(),ios::app);
	 time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    detail<<endl<<"GAME : TIC TAC TOE"<<endl;
    detail<<"DATE : "<<now->tm_mday<<'-'<< (now->tm_mon + 1) << '-'<< (now->tm_year + 1900);
    detail<<endl<<"SCORE : 0"<<endl;
break;
}
y=full(a);
if(y==1){
	cout<<"\nGAME has been drawn!";
	cout<<"\nTHANKS for playing.";
	break;
}	
system("cls");
}
}	
cout<<"\n***********************MADE BY: Vidhu and Pranav****************************\n";
cout<<endl<<endl<<"press 1 to go back";
cin>>back;
if(back==1)
handleAccount(user);

}


//Game-2 Cows and Bulls

void cowsAndBulls(char player[])
{
void loading();	
void handleAccount(char[]);
string a,b,c;
int choice1;
int flag=0,cow=0,bull=0;
char ans='y';
char word[4],word2[4];
cout<<setw(60)<<"Welcome to the game cows and bulls";
cout<<endl<<endl<<"The rules of the game are : "<<endl<<endl<<"1.One player, the ";
cout<<"Chooser, thinks of a four-letter word and the other player the Guesser, tries to guess it.";
cout<<endl<<endl<<"2.At each turn the Guesser tries a four-letter word, and the Chooser says ";
cout<<"how close it is to the answer by giving:"<<endl<<endl<<"The number of Bulls - letters correct in the right position.";
cout<<endl<<endl<<"The number of Cows - letters correct but in the wrong position.";
cout<<endl<<endl<<"3.The word should be a proper english word.";
cout<<endl<<endl<<"4.The word should not consist of repititive letters";
cout<<endl<<endl<<"5.the guesser will get a total of 15 turns to guess the word";


while(ans=='y'||ans=='Y'){
cout<<endl<<endl<<"Enter your name player 1 (Anyone playing as player 1 will ";
cout<<" be by default playing on behalf of user of this account ie. )"<<player;
cout<<"If you want play as "<<player<<"and guess the word, then enter your name as "<<player<<" in player 2's name";
cin>>a;
	
int success=0;	
	
while(success!=1)
{
cout<<endl<<"enter your word "<<a<<" : ";
cin>>word;
flag=0;
for(int i=0; i<4; i++)
{
for(int j=i+1; j<4; j++)
{
	if(word[i]==word[j])
	flag=1;
}
}
if(flag==1)
{cout<<"the word should not have repetition ";
success=0;
}
else
{
loading();
success=1;
}

}
system("cls"); 
cout<<endl<<"Enter your name player 2 :";
cin>>c;
for(int g=1; g<16; g++)
{cout<<endl<<endl<<c<<" enter guess "<<g<<" : ";
cow=0;
bull=0;
for(int i=0; i<4; i++)
cin>>word2[i];
for(int i=0; i<4; i++)
{
for(int j=0; j<4; j++)
{if(word[i]==word2[j] && (i==j))
bull++;
if(word[i]==word2[j] && (i!=j))
cow++;	
}
}
cout<<"bulls = "<<bull<<" and cows = "<<cow;
if(bull==4)
{cout<<endl<<"Congrats "<<c<<" you have guessed the right word and won the game....!!!!";

	char temp[100];
	strcpy(temp,player);
	string details(temp);
	details+="gamedetails.txt";
	ofstream detail(details.c_str(),ios::app);
	 time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    detail<<endl<<"GAME : COWS AND BULLS"<<endl;
    detail<<"DATE : "<<now->tm_mday<<'-'<< (now->tm_mon + 1) << '-'<< (now->tm_year + 1900);
if(strcmpi(c.c_str(),player)==0)
{
    detail<<endl<<"SCORE : 200"<<endl;
}
else
{
	detail<<endl<<"SCORE : 0"<<endl;
}
break;
}

if(g==15)
{
	cout<<endl<<"You have lost the game. Better luck next time...!! ";
	char temp[100];
	strcpy(temp,player);
	string details(temp);
	details+="gamedetails.txt";
	ofstream detail(details.c_str(),ios::app);
	 time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    detail<<endl<<"GAME : COWS AND BULLS"<<endl;
    detail<<"DATE : "<<now->tm_mday<<'-'<< (now->tm_mon + 1) << '-'<< (now->tm_year + 1900);


	if(strcmpi(c.c_str(),player)==0)
	{
    detail<<endl<<"SCORE : 0"<<endl;
	}
	else
	{
	detail<<endl<<"SCORE : 200"<<endl;
	}
}
}
cout<<endl<<endl<<"Want to play another game? Y/N ";
cin>>ans;

}
cout<<endl<<endl<<"Press 1 to go back ";
cin>>choice1;
handleAccount(player);
}

};


class registeredUsers{
	
	char password[100];
	string username,eMail;
	long long mobileNo,DOB;
	games a;
	
	friend void handleAccount(char user[]);
	
	public:	
	
//Function to create a new Account	

void signUp()
{
	void loading();
	void handleAccount(char[]);
	char temp[100];
	int pos2,pos1;
	int i=0,flag=0;
	char ch;
	char str[100];
	system("cls");			
	database.seekg(0,ios::end);
	pos2 = database.tellg();
	database.seekg(0);
	pos1 = database.tellg();
	cout<<endl<<setw(50)<<"SIGN UP FOR SNAPPY HERE !"<<endl<<endl;
	int success=0,success1=0;
	while(success!=1)
	{
	success1=0;
	cout<<"Enter USERNAME : ";
	cin>>username;
	database.seekg(0);
	while(!database.eof())
	{
		database.getline(str,100);
		if(strcmpi(str,username.c_str())==0)
		{
			cout<<"Username already in USE."<<endl<<"Please choose another one."<<endl;
			database.seekg(0);
			success1=1;
			break;
		}
		flag++;
		if(database.tellg()==pos2-pos1 || pos2-pos1==0)
		break;
	}
	if(success1==0)
		success=1;
	}
	int done=0;
	while(done!=1)
	{
	cout<<endl<<"Enter PASSWORD : ";
	i=0;
	ch='\0';
	while(ch!=13)
	{
		ch = getch();
		if(ch==8)
		{done=0;
		break;
		}
		password[i] = ch;
		i++;
		if(ch==13)
		{
			i--;
			password[i]='\0';
			done=1;
			break;
		}
		cout<<"*";
	}
}
	cout<<endl<<"Enter E-mail ID :";
	cin>>eMail;
	cout<<"Enter Year of Birth : ";
	cin>>DOB;
	cout<<"Enter Mobile Number : ";
	cin>>mobileNo;
	database.close();
	database.open("users.txt",ios::app|ios::out);
	database<<username<<endl<<password<<endl;
	strcpy(temp,username.c_str());
	string details(temp);
	username+=".txt";
	details+="details.txt";
	ofstream detail(details.c_str());
	ofstream user(username.c_str());
	detail<<temp<<endl<<password<<endl<<eMail<<endl<<DOB<<endl<<mobileNo<<endl;
	database.close();
	database.open("users.txt",ios::ate|ios::out|ios::in);
	loading();
	handleAccount(temp);
}

	

//Function to check the messages received 

void inbox(string user1)
{
	char temp[100];
	void handleAccount(char[]);
	int choice;
	system("cls");
	char message[100];
	strcpy(temp,user1.c_str());
	cout<<endl<<endl<<setw(40)<<"INBOX"<<endl<<endl;
	user1+=".txt";
	ifstream fin(user1.c_str());
	while(!fin.eof())
	{
		fin.getline(message,100);
		cout<<message<<endl;
	}
	cout<<endl<<endl<<"Enter 1 to go back";
	cin>>choice;
    if(choice==1)
	handleAccount(temp);
}

//Function to send a message

void sendMessage(char sender[])
{	
	void handleAccount(char []);
	char available[100];
	int pos2,pos1;
	static int skip=0;
	bool foundReceiver=false;
	string receiver;
	char receiver2[100],match[200],message[100];
	system("cls");
	database.seekg(0);
	cout<<endl<<endl<<"HI "<<sender<<" , Welcome to the Messaging Centre !!"<<endl<<endl;
	database.seekg(0,ios::end);
	pos2 = database.tellg();
	database.seekg(0);
	pos1 = database.tellg();
	cout<<endl<<"Users available to message : ";
	while(!database.eof())
	{		
		database.getline(available,100);
		if(skip%2==0)
		cout<<available<<endl;	
		skip++;
		if(database.tellg()==pos2-pos1)
		break;
	}
	int success=0;
	int sendChoice;
	cout<<"Do you want to send a message? ";
	cout<<endl<<"Press 1 to send message ";
	cout<<endl<<"Press 2 to exit ";
	cin>>sendChoice;
	if(sendChoice==2)
	handleAccount(sender);
	else if(sendChoice==1)
	{
	while(success!=1)
	{
	cout<<endl<<"To Whom do you want to send a message ? : ";
	cin>>receiver;
	database.seekg(0);
	while(!database.eof())
	{
		database.getline(match,200);
		strcpy(receiver2,receiver.c_str());
		if(strcmpi(receiver2,match)==0)
		{
		foundReceiver = true;
		break;
		}
		if(database.tellg()==pos2-pos1)
		break;
	}
	if(foundReceiver==true)
	{
	success=1;
	cout<<"Enter your Message : ";
	cin.ignore();
	cin.getline(message,100);
	receiver+=".txt";
	ofstream send (receiver.c_str(),ios::app);
	send<<"From : "<<sender<<endl<<message<<endl<<endl;
	handleAccount(sender);
	}
	else
	{
	cout<<endl<<receiver<<" does not have an account !";
	success=0;
	}

}

}


}


//Function for accessing your account

void login()
{	
	void loading();
	void handleAccount(char user[]);
	char ch;
	int i=0,pos2,pos1;
	void handleAccount(char*);
	database.seekg(0);
	void sendMessage(char* a);
	system("cls");
	bool found=false;
	char username[100],password[100],ustr[100],pstr[100];
	database.seekg(0,ios::end);
	pos2 = database.tellg();
	database.seekg(0);
	pos1 = database.tellg();
	cout<<setw(50)<<"LOGIN PAGE"<<endl<<endl;
	
	int success=0,success2=0;
	
	while(success!=1)
	{
	cout<<"Enter USERNAME :";
	cin>>username;
	success2=0;
	while(success2!=1)
	{
	cout<<endl<<"Enter password : ";
	i=0;
	ch='\0';
	while(ch!=13)
	{
		if(ch==8)
		break;
		ch = getch();
		password[i] = ch;
		i++;
		if(ch==13)
		{
			i--;
			password[i]='\0';
			success2=1;
			break;
		}
		cout<<"*";
	}
	}
	
	database.seekg(0);
	while(!database.eof())
	{
		database.getline(ustr,100);
	if(strcmpi(username,ustr)==0)
	{
		database.getline(pstr,100);
		if(strcmpi(password,pstr)==0)
		{found=true;	
		break;
		}
	}
	if(database.tellg()==pos2-pos1)
	break;
	}
	
	loading();
	if(found==true)
	{
		cout<<endl<<"Login Successful";
		handleAccount(username);
	}
	else
	{
		cout<<endl<<"Invalid ID or Password"<<endl;
		cout<<"Try Again : "<<endl;
		success=0;
	}

}


}



};


//Progress bar

void loading()
{
	system("cls"); 
  int a1=100,b1=0,c1=0;
    int j;
for(int i=0; i<101; i++)
{
	cout<<b1<<" % LOADING [";
	if(i%3==0)
	{
for(j=0; j<=(c1+1); j++)
{
	cout<<"|";
	Sleep(5);
}
	if(i==99)
	cout<<"]";
c1++;
}
Sleep(a1);
cout<<'\r';
b1++;
a1-=1;
}
system("cls");
}

//For managing the account

void handleAccount(char user[])
{
	games a;
	registeredUsers b;
	char name[100][100];
	strcpy(name[0],"Username : ");
	strcpy(name[1],"Password : ");
	strcpy(name[2],"Email ID :");
	strcpy(name[3],"Year of Birth : ");
	strcpy(name[4],"Mobile Number : ");
	void welcome();
	char info[200];
	int choice,choice2;
	system("cls");
	cout<<endl<<endl<<"HI "<<user<<" , Welcome to your Account !!"<<endl<<endl;
	cout<<"What would you like to do ?"<<endl<<endl;
	cout<<"1. Check My inbox";
	cout<<endl<<endl<<"2. Compose E-mail ";
	cout<<endl<<endl<<"3. Play Games ";
	cout<<endl<<endl<<"4. View Game Scores";
	cout<<endl<<endl<<"5. View Account Details ";
	cout<<endl<<endl<<"6. Logout "<<endl;
	cout<<endl<<"Enter choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 : {b.inbox(user);
				break;
				}
				
		case 2 : {b.sendMessage(user);
			break;
		
		case 3 : {games a;
		a.chooseGame(user);
			break;
		}
		case 4 : {
			int pos1,pos2;
		system("cls");
		cout<<endl<<setw(50)<<"GAME SCORES"<<endl<<endl;
		string a(user);
		a+="gamedetails.txt";
		ifstream details(a.c_str());
		details.seekg(0,ios::end);
		pos2 = details.tellg();
		details.seekg(0);
		pos1 = details.tellg();
		if(pos2-pos1==0)
		{
			cout<<"No scores available";
			Sleep(2000);
			handleAccount(user);
		}
		int j=0;
		while(!details.eof())
		{
			details.getline(info,200);
			cout<<info<<endl;
		}
		cout<<endl<<endl<<"Press 1 to go back:";
		cin>>choice2;
		if(choice2==1)
		handleAccount(user);
			break;
		}
		case 5 : {system("cls");
		cout<<endl<<setw(50)<<"ACCOUNT DETAILS"<<endl<<endl;
		string a(user);
		a+="details.txt";
		ifstream details(a.c_str());
		int j=0;
		while(!details.eof())
		{
			details.getline(info,200);
			cout<<name[j]<<info<<endl;
			j++;
		}
		cout<<endl<<endl<<"Press 1 to go back:";
		cin>>choice2;
		if(choice2==1)
		handleAccount(user);
			break;
		}
		case 6 : {welcome();
			break;
		}
		}
	}			
}		

//Welcome Page

void welcome()
{
	system("cls");
	int choice;
	cout<<setw(50)<<"WELCOME TO SNAPPY !!"<<endl<<endl<<endl<<endl;
	cout<<"New To SNAPPY?"<<endl<<"Sign Up by Pressing 1";
	cout<<endl<<endl<<"Already a User?"<<endl<<"Login by pressing 2 : "<<endl;
	cin>>choice;
	registeredUsers a;
	if(choice==1)
		a.signUp();
	else if(choice==2)
	{
		a.login();
	}
}


int main()
{	
	welcome();
}
