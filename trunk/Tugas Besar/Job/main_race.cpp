#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Sage.h"
#include "Warrior.h"
#include "Assassin.h"
#include <conio.h>

using namespace std;
string race;
string job;
string name;
string special;
vector<Job *> Player;
vector<Job *> Enemy;
vector<Job *>::iterator i;
Job * obj_job;
Job * obj_job2;

void Display(int &x, int &y) {
	system ("cls");
	cout<<endl;
	cout<<"Player"<<endl;
	cout<<"------------------------"<<endl;
	if (x ==4) {x=1;}
	i = Player.begin();
	obj_job  = *i;
	
	if (x == 1){	
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; 	
	cout<<"Status Karakter      :"<<endl;
	obj_job->Status();}	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
	i++;
	obj_job  = *i;
	if (x == 2){	
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; 
	cout<<"Status Karakter      :"<<endl;
	obj_job->Status();}	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
	i++;
	obj_job  = *i;
	if (x == 3){	
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; 
	cout<<"Status Karakter      :"<<endl;
	obj_job->Status();}	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	cout<<"------------------------"<<endl;
	
	
	cout<<"------------------------"<<endl;
	cout<<endl;	
	cout<<"                  Enemy"<<endl;
	cout<<"                  ------------------------"<<endl;
	
	i = Enemy.begin();
	if (y == 0) {
	for (i = Enemy.begin(); i != Enemy.end(); ++i)
	{
		obj_job  = *i;				
		cout<<"                  -  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl;
		cout<<"                  -  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
		cout<<"                  -  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;		
	} }
	
	else {
		obj_job  = *i;		
		if (y == 1){	
		cout<<"                  >>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }	
		else {
		cout<<"                  -  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
		cout<<"                  -  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
		cout<<"                  -  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
		i++;
		obj_job  = *i;
		if (y == 2){	
		cout<<"                  >>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }	
		else {
		cout<<"                  -  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
		cout<<"                  -  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
		cout<<"                  -  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
		i++;
		obj_job  = *i;
		if (y == 3){	
		cout<<"                  >>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; 
		y = 0;}
			
		else {
		cout<<"                  -  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
		cout<<"                  -  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
		cout<<"                  -  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	}
		cout<<"                  ------------------------"<<endl;
	cout<<endl;
}


void DisplayCommand(int &x, int &y, int &RS){
Display (x,y);
if (RS == 5) {RS = 1;}
if (RS == 0) {RS = 4;}

cout<<"-----------"<<endl;

if (RS == 1) {
cout<<">> Attack   "<<endl; 
cout<<"- Special   "<<endl; 
cout<<"- Item      "<<endl; 
cout<<"- Defend    "<<endl; }

else if (RS == 2) {
cout<<"- Attack   "<<endl; 
cout<<">> Special   "<<endl; 
cout<<"- Item      "<<endl; 
cout<<"- Defend    "<<endl; }

else if (RS == 3) {
cout<<"- Attack   "<<endl; 
cout<<"- Special   "<<endl; 
cout<<">> Item      "<<endl; 
cout<<"- Defend    "<<endl; }

else if (RS == 4) {
cout<<"- Attack   "<<endl; 
cout<<"- Special   "<<endl; 
cout<<"- Item      "<<endl; 
cout<<">> Defend    "<<endl; }
}


int main (){
Player.push_back(new Knight ("human"));
Player.push_back(new Archer("human"));
Player.push_back(new Sage("human"));

int z = 1;
for (i = Player.begin(); i != Player.end(); ++i)
	{
		name = "Player";
		obj_job  = *i;				
		obj_job->SetName(name);	
		z++;
	}

//untuk Enemy
Enemy.push_back(new Mage ("human"));
Enemy.push_back(new Warrior("human"));
Enemy.push_back(new Assassin("human"));

z = 1;
for (i = Enemy.begin(); i != Enemy.end(); ++i)	{
		
		obj_job  = *i;				
		obj_job->SetName("Enemy");	
		z++;
	}
//system battle
int x = 1;
int y = 0;
int RS = 1;
char c;
while (c!=65) {
	y = 0;
	DisplayCommand(x, y, RS);
	cout<<RS;
	c=getch();
	if(c==115)
	{	
		RS = RS -1;
        DisplayCommand(x, y, RS);
	}
	else if(c==120)
	{	
		RS = RS +1;
        DisplayCommand(x, y, RS);
	}
	else if (c ==46) 
	{
    x = x+1;
	DisplayCommand(x,y,RS); 
	}
	else if (c ==13) {
	if (RS == 1) {
		y = 1;	
		DisplayCommand(x,y,RS);
		while (c!=27) {
		c=getch();
		if (c ==120)  {			
			y = y +1;
			DisplayCommand(x,y,RS);}
		if (c ==13) {
			if ( x == 1 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				
			}
			if ( x == 2 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
			    obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				
			}
			if ( x == 3 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				cout<<"Accuracy = "<<obj_job2->GetAcc()<<endl;
				cout<<"Evade objek lawan = "<<obj_job->GetEvade()<<endl;
				obj_job2->Attack(*obj_job);
				c=27;}
				
			}			
			}	
		}
		}
	if (RS == 2) {
		y = 1;	
		DisplayCommand(x,y,RS);
		if (x==1){
		i = Player.begin();		
		obj_job2  = *i;  }
		if (x==2){
		i = Player.begin();		
		obj_job2  = *i+1; }
		if (x==3){
		i = Player.begin();		
		obj_job2  = *i+2; }
		obj_job2->GetSpecialArray();
		cout<<"-----------"<<endl;
		cout<<"Choose Special = "<<endl;
		cin>>special;
		cout<<endl;
		c=12;
		while (c!=27) {
		c=getch();
		if (c ==120)  {			
			y = y +1;
			DisplayCommand(x,y,RS);
			cout<<"-----------"<<endl;
			cout<<special;}
		if (c ==13) {
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				obj_job2->Special(special, *obj_job);
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				obj_job2->Special(special, *obj_job);
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				obj_job2->Special(special, *obj_job);
				c=27;}
			}	
		}
		}
	}
}
  /*
Player.clear();
*/
return 0;}
    

