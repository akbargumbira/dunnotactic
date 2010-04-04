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
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
	i++;
	obj_job  = *i;
	if (x == 2){	
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
	i++;
	obj_job  = *i;
	if (x == 3){	
	cout<<">>  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }	
	else {
	cout<<"-  "<<obj_job->GetName()<<" / "<<obj_job->GetJobName()<<endl; }
	cout<<"-  "<<obj_job->GetHP()<<" / "<<obj_job->GetHPDefault()<<endl;	
	cout<<"-  "<<obj_job->GetSP()<<" / "<<obj_job->GetSPDefault()<<endl<<endl;	
	
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

int d=getche();
cout<<d;
system ("pause");
system ("cls");
cout << "------------------------------------------------"<<endl;	
cout << "DUNNO Tactics "<<endl;
cout << "------------------------------------------------"<<endl;
cout<<"Pilih dulu race yang anda inginkan"<<endl;
cout<<"=================================="<<endl;
cout<<"=  Human                     ====="<<endl;
cout<<"=  Elf                       ====="<<endl;
cout<<"=  Fairy                     ====="<<endl;
cout<<"=  Orc                       ====="<<endl;
cout<<"=================================="<<endl;
cin >> race;
system ("cls");	
cout << "------------------------------------------------"<<endl;	
cout << "DUNNO Tactics "<<endl;
cout << "------------------------------------------------"<<endl;
cout<<"Pilih ally job  yang anda inginkan"<<endl;
cout<<"=================================="<<endl;
cout<<"=  Knight                    ====="<<endl;
cout<<"=  Archer                    ====="<<endl;
cout<<"=  Sage                      ====="<<endl;
cout<<"=  Mage                      ====="<<endl;
cout<<"=  Assasin                   ====="<<endl;
cout<<"=  Warrior                   ====="<<endl;
cout<<"=================================="<<endl;

for (int z = 1; z<=3; z++) {
cout<<"Ally  "<<z<<" = ";cin>>job;
if (job=="knight") {
Knight *K= new Knight(race);
Player.push_back(K);}
if (job=="archer") {
Archer *K= new Archer(race);
Player.push_back(K);}
if (job=="mage") {
Mage *K= new Mage(race);
Player.push_back(K);}
if (job=="sage") {
Sage *K= new Sage(race);
Player.push_back(K);}
if (job=="warrior") {
Warrior *K= new Warrior(race);
Player.push_back(K);}
if (job=="assassin") {
Assassin *K= new Assassin(race);
Player.push_back(K);}
}
cout<<endl;
cout<<"Set nama untuk ally"<<endl;
int z = 1;
for (i = Player.begin(); i != Player.end(); ++i)
	{
		cout<<"ally "<<z<<" = ";cin>>name;
		obj_job  = *i;				
		obj_job->SetName(name);	
		z++;
	}

//untuk Enemy
srand(time(NULL));
int rn = rand()%4;
if (rn == 0) {race = "human";}
else if (rn == 1) {race = "elf";}
else if (rn == 2) {race = "fairy";}
else if (rn == 3) {race = "orc";}

for (int z = 1; z<=3; z++) {
int rn = rand()%6;
if (rn == 0) {
Knight *K= new Knight(race);
Enemy.push_back(K);}
else if (rn == 1) {
Archer *K= new Archer(race);
Enemy.push_back(K);}
else if (rn == 2) {
Mage *K= new Mage(race);
Enemy.push_back(K);}
else if (rn == 3) {
Sage *K= new Sage(race);
Enemy.push_back(K);}
else if (rn == 4) {
Warrior *K= new Warrior(race);
Enemy.push_back(K);}
else if (rn == 5) {
Assassin *K= new Assassin(race);
Enemy.push_back(K);}
}
cout<<endl;

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
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}
			if ( x == 2 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}
			if ( x == 3 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}			
			}	
		}
		}
	if (RS == 2) {
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
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}
			if ( x == 2 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}
			if ( x == 3 )
			{
				if ( y == 1) {
				i = Enemy.begin();
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 2) {
				i = Enemy.begin()+1;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				else if ( y == 0) {
				i = Enemy.begin()+2;
				obj_job  = *i;
				i = Player.begin();
				obj_job2  = *i;
				obj_job->ReceiveAttack(obj_job2->GetAttackPoint());
				c=27;}
				
			}			
			}	
		}
		}
	}
}
  /*
Player.clear();
*/
return 0;}
    

