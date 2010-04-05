#include <iostream>
#include <stdlib.h>
#include "Job.h"

using namespace std;

Job::Job(){}

Job::Job (const string& Race) {
//Race Human
if (Race == "human") {
RaceName = "Human";
AttackPoint    = 300;
Defense        = 100;
Acc            =  30;
Evade          =  25;
SpecialBonus   =   1.2;
RangeMove      =   4;
RangeAttack    =   1;
      
HP             = 1600;
SP             =  140;
X              =    0;
Y              =    0; }

//Race Elf
if (Race == "elf") {
RaceName = "Elf";
AttackPoint    = 200;
Defense        =  60;
Acc            =  40;
Evade          =  35;
SpecialBonus   =   1.5;
RangeMove      =   5;
RangeAttack    =   1;
      
HP             = 1200;
SP             =  120;
X              =    0;
Y              =    0; }

//Race Fairy
if (Race == "fairy") {
RaceName = "Fairy";
AttackPoint    = 140;
Defense        =  40;
Acc            =  35;
Evade          =  30;
SpecialBonus   =   1.7;
RangeMove      =   6;
RangeAttack    =   1;
      
HP             =  800;
SP             =  200;
X              =    0;
Y              =    0; }

//Race Orc
if (Race == "orc") {
RaceName = "Orc";
AttackPoint    = 240;
Defense        = 140;
Acc            =  25;
Evade          =  20;
SpecialBonus   =   1.3;
RangeMove      =   3;
RangeAttack    =   1;
      
HP             = 2000;
SP             =   80;
X              =    0;
Y              =    0; }
for (int w = 0; w<10;w++) {
SpecialArray[w] = "none";  }
}


Job::~Job () {}
//Attribut
int Job::GetAttackPoint (){
      return AttackPoint;}

int Job::GetDefensePoint (){
      return Defense;}     

int Job::GetAcc (){
      return Acc;}      

int Job::GetEvade (){
      return Evade;}  

float Job::GetSpecialBonus (){
      return SpecialBonus;} 

int Job::GetRangeMove (){
      return RangeMove;}        

int Job::GetRangeAttack (){
      return RangeAttack;}

int Job::GetHP (){
    if (HP <= 0)
       {cout<<"HP habis, Karakter mati = ";}
    return HP;}

int Job::GetSP (){
    return SP;}
	
int Job::GetHPDefault() {
	return HPDefault;}
	
int Job::GetSPDefault() {
	return SPDefault; }
	
string Job::GetName() {
	return Name; }
	
string Job::GetJobName(){
	return JobName;}

void Job::SetName(const string& str){
	Name = str;}

string Job::GetSpecialArray(int &j) {
	return SpecialArray[j]; }
	
void Job::SetDeath(bool &D) {
	Death = D; }
	
bool Job::GetDeath() {
	return Death; }

//posisi
int Job::GetX (){
      return X; }

int Job::GetY (){
      return Y; }

//Method Lain


void Job::SetEnemy (Job &enemy) {
	int i = 0;
	while (Enemy[i] != NULL) {
	i++; }
	Enemy[i] = &enemy;}


//Method Karakter
void Job::Move (const int &x, const int &y) {
	X = x; 
	Y = y;}

void Job::Attack (Job &Target) {
	int i = Acc - Target.GetEvade();
	int z ;
	srand(time(NULL));
	if (i==0)
	{
		z = rand()%10 + 1;
	}	
	if ((i>0) && (i<=5))
	{
		z = rand()%8 + 1;
	}
	
	if ((i>5) && (i<=10))
	{
		z = rand()%7 + 1;
	}
	
	if ((i>15) && (i<=20))
	{
		z = rand()%6 + 1;
	}
	if (i>20) 
	{
		z = rand()%5 + 1;
	}
	if ((i>-10) && (i<0))
	{
		z = rand()%12 + 1;
	}
	
	if ((i>-20) && (i<=-10))
	{
		z = rand()%16 + 1;
	}
	
	if ((i>-30) && (i<=-20))
	{
		z = rand()%25 + 1;
	}
	if (i>-30) 
	{
		z = rand()%50 + 1;
	}
	system("pause");
	
	if((z>=1) && (z<=5)) {
	int Damage = int(float(AttackPoint) * (0.01 * float(rand()%21 + 90)));
	Target.ReceiveAttack(Damage);
	}
	else  {
	cout<<"Miss"<<endl;
	system("pause");}
}

void Job:: ReceiveAttack (const int& Attack) {
	int i = (Attack - Defense);
	if (i<0){ i = 1; }
    HP = HP - i;
	if (HP<=0){
	HP = 0;
	Death = true;}
}

void Job:: ReceiveHP (const int& Attack) {
    HP = HP + (Attack); }  

void Job::Special (const string & STR, Job &Target) {
}

