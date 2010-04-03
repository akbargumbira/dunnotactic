#include <iostream>
#include <stdlib.h>
#include "Job.h"

using namespace std;

Job::Job(){}

Job::Job (const string& Race)
{
    // Race Human
    if (Race == "human")
    {
        RaceName = "Human";
        AttackPoint    = 300;
        Defense        = 100;
        Acc            =  30;
        Evade          =  15;
        SpecialBonus   =   1.2;
        RangeMove      =   4;
        RangeAttack    =   1;

        HP             = 1600;
        SP             =  140;
        X              =    0;
        Y              =    0;
    }

//Race Elf
if (Race == "elf") {
RaceName = "Elf";
AttackPoint    = 200;
Defense        =  60;
Acc            =  60;
Evade          =  50;
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
Acc            =  40;
Evade          =  30;
SpecialBonus   =   2.0;
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
Acc            =  20;
Evade          =   5;
SpecialBonus   =   1.3;
RangeMove      =   3;
RangeAttack    =   1;
      
HP             = 2000;
SP             =   80;
X              =    0;
Y              =    0; }
}

Job::Job(const Job& J)
{
    RaceName = J.RaceName;
    AttackPoint = J.AttackPoint;
    Defense = J.Defense;
    Acc = J.Acc;
    Evade = J.Evade;
    SpecialBonus = J.SpecialBonus;
    RangeMove = J.RangeMove;
    RangeAttack = J.RangeAttack;
    HP = J.HP;
    SP = J.SP;
    X = J.X;
    Y = J.Y;
}

Job& Job::operator=(const Job& J)
{
    RaceName = J.RaceName;
    AttackPoint = J.AttackPoint;
    Defense = J.Defense;
    Acc = J.Acc;
    Evade = J.Evade;
    SpecialBonus = J.SpecialBonus;
    RangeMove = J.RangeMove;
    RangeAttack = J.RangeAttack;
    HP = J.HP;
    SP = J.SP;
    X = J.X;
    Y = J.Y;
    return *this;
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
	srand(time(NULL));
	Target.ReceiveAttack(int(float(AttackPoint) * (0.01 * float(rand()%21 + 90))));	  
}

void Job:: ReceiveAttack (const int& Attack) {
     HP = HP - (Attack - Defense);}

void Job:: ReceiveHP (const int& Attack) {
     HP = HP + (Attack); }  

void Job::Special (Job &Target) {
}

