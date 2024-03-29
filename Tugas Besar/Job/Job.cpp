#include <iostream>
#include <stdlib.h>
#include "Job.h"
#include "../DunnoTactic.h"

using namespace std;
//METHOD
//Constructor dan destructor
Job::Job(){} //Constructor Default

Job::Job (const string& Race) {
//Construstor dengan parameter string
//I.S : Karakter belum diinstansi
//F.S : Karakter telah diinstansi dengan race string	  
//Race Human
	if (Race == "human") {
		RaceName = "Human";
		AttackPoint    = 300;
		Defense        = 100;
		Acc            =  40;
		Evade          =  20;
		SpecialBonus   =   1.2;
		RangeMove      =   4;
		RangeAttack    =   1;
      
		HP             = 1000;
		SPDefault      =  140;
		X              =    0;
		Y              =    0; 
	}

//Race Elf
	if (Race == "elf") {
		RaceName = "Elf";
		AttackPoint    = 200;
		Defense        =  60;
		Acc            =  50;
		Evade          =  25;
		SpecialBonus   =   1.4;
		RangeMove      =   5;
		RangeAttack    =   1;
      
		HP             =  800;
		SPDefault      =  120;
		X              =    0;
		Y              =    0; 
	}

//Race Fairy
	if (Race == "fairy") {
		RaceName = "Fairy";
		AttackPoint    = 140;
		Defense        =  45;
		Acc            =  35;
		Evade          =  25;
		SpecialBonus   =   1.6;
		RangeMove      =   6;
		RangeAttack    =   1;
      
		HP             =  600;
		SPDefault      =  200;
		X              =    0;
		Y              =    0; 
	}

//Race Orc
	if (Race == "orc") {
		RaceName = "Orc";
		AttackPoint    = 240;
		Defense        = 140;
		Acc            =  15;
		Evade          =   7;
		SpecialBonus   =   1.3;
		RangeMove      =   3;
		RangeAttack    =   1;
      
		HP             = 1400;
		SPDefault      =   80;
		X              =    0;
		Y              =    0; 
	}

	for (int w = 0; w<10;w++) {
		SpecialArray[w] = "none";  
	}
        AttackTurn 			= false;
	Enable   			= true;
	MoveTurn   			= false;
	Death	   			= false;
}

//Destructor virtual  
Job::~Job () {}

//Attribut
//Mengembalikan ID
int Job::GetID() {
	return ID;
}

//mengembalikan nilai Name Karakter	
string Job::GetName() {
	return Name; 
}

//mengembalikan nilai JobName Karakter	
string Job::GetJobName(){
	return JobName;
}

//mengembalikan nilai RaceName Karakter
string Job::GetRaceName() {
	return RaceName; 
}

//mengembalikan nilai attack_point
int Job::GetAttackPoint (){
    return AttackPoint;
}

//mengembalikan nilai defense_point
int Job::GetDefensePoint (){
    return Defense;
}     

//mengembalikan nilai acc
int Job::GetAcc (){
    return Acc;
}      

//mengembalikan nilai evade
int Job::GetEvade (){
    return Evade;
}  

//mengembalikan nilai spsial_bonus
float Job::GetSpecialBonus (){
    return SpecialBonus;
} 

//mengembalikan nilai range_move
int Job::GetRangeMove (){
    return RangeMove;
}
        
//mengembalikan nilai range_attack
int Job::GetRangeAttack (){
    return RangeAttack;
}

//mengembalikan nilai HP
int Job::GetHP (){
    if (HP <= 0)
       {HP = 0;}
    return HP;
}

//mengembalikan nilai SP
int Job::GetSP (){
    return SP;
}

//mengembalikan nilai HPDefault	
int Job::GetHPDefault() {
	return HPDefault;
}

//mengembalikan nilai SPDefault	
int Job::GetSPDefault() {
	return SPDefault; 
}

void Job::SetSP(const int &sp) {
    SP = sp;
    if (SP>SPDefault) {
        SP = SPDefault;
    }
}

void Job::SetHP(const int &hp) {
    HP = hp;
    if (HP>HPDefault) {
        HP = HPDefault;
    }
}

//mengembalikan isi list SpesialArray
int Job::ShowSpecialArray (){
	int i = 0;
	while (SpecialArray[i] != "none") {
		cout<<SpecialArray[i]<<endl;
		i++; 
	}
        return i;
}

//Mengeset ID
void Job::SetID(const int &i) {
	ID = i;
}

//Mengeset Name
void Job::SetName(const string& str){
	Name = str;
}

//Mengeset status death
void Job::SetDeath(bool &D) {
	Death = D; 
}

//Mengeset status  Attack
void Job::SetAttackTurn(bool D) {
	AttackTurn = D; 
}

//Mengeset status  enable	
void Job::SetEnable(bool D) {
	Enable = D; 
}

//Mengeset status Move
void Job::SetMoveTurn(bool D) {
	MoveTurn = D; 
}

//Mengembalikan status Death	
bool Job::GetDeath() {
	return Death; 
}

//Mengembalikan status Attack	
bool Job::GetAttackTurn() {
	return AttackTurn; 
}

//Mengembalikan status Enable
bool Job::GetEnable() {
	return Enable; 
}

//Mengembalikan status Turn
bool Job::GetMoveTurn() {
	return MoveTurn; 
}

//Method lain
//Mengembalikan status Status Semuanya
void Job::Status() {
	cout<<"MoveTurn   = "<<MoveTurn <<endl;
	cout<<"AttackTurn = "<<AttackTurn<<endl;
	cout<<"Enable     = "<<Enable<<endl;
	cout<<"Death      = "<<Death<<endl; 
}

bool Job::IsFriend(Job& Target) {
    return (GetPlayer()==Target.GetPlayer());
}

int Job::GetPlayer() {
    if (ID>=101 && ID<=500)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
//posisi
//Mengeset nilai x, y
void Job::SetXY (const int &x, const int &y) {
	X = x;
	Y = y; 
}

//mengembalikan nilai X
int Job::GetX (){
    return X; 
}

//mengembalikan nilai Y
int Job::GetY (){
    return Y; 
}


//Method Karakter
//I.S : Posisi suatu karakter original
//F.S : Posisi suatu karakter berubah menjadi x, y
void Job::Move (const int &x, const int &y) {
    DunnoTactic::D.setAreaMove(X,Y,RangeMove);
    int temp = DunnoTactic::D.GetMapArea(x,y);
    int temp2 = DunnoTactic::D.GetMapPlayer(x,y);
    if (temp==99 || temp2>100)
    {
        string err = "Karakter tidak bisa menempati petak ("+DunnoTactic::ToString(x)+","+DunnoTactic::ToString(y)+").";
        throw err.c_str();
    }
    else
    {
        DunnoTactic::D.MoveAnimated(X,Y,x,y);
        MoveTurn = true;
    }
}
	
//Fungsi Wait
//I.S : Fungsi masih dalam keadaan Enable = true
//F.S : Enable = false	
void Job::Wait () {
	Enable = false;
}
	
//Fungsi menyerang karakter lain
//I.S : Target.HP masih yang lama
//F.S : Target.HP telah dikurangi Attack this
void Job::Attack (Job& Target) {
        int i = Acc - Target.GetEvade();
	int z ;
	//Mencari perbandingan accuracy dengan Evade Target
	if (i==0) {
		z = rand()%7 ;
	}	
	else if ((i>0) && (i<=8)) {
		z = rand()%6 ;
	}
	else if ((i>8) && (i<=16)) {
		z = rand()%5 ;
	}
	else if (i>16) {
		z = rand()%4;
	}
	else if ((i>(-5)) && (i<0)) {
		z = rand()%8 ;
	}
	else if ((i>(-10)) && (i<=(-5))) {
		z = rand()%9 ;
	}
	else if ((i>(-15)) && (i<=(-10))) {
		z = rand()%10 ;
	}
	else if (i<(-15)) {
		z = rand()%11 ;
	}
        DunnoTactic::D.SetInfo("PLAYER ATTACK",0);
        DunnoTactic::D.SetInfo("",1);
	DunnoTactic::D.AttackAnimated(X,Y,Target.GetX(),Target.GetY());
	if (z<=4) {
		int Damage = int(float(AttackPoint) * (0.01 * float(rand()%21 + 90)));
		Target.ReceiveAttack(Damage);
                if (Target.GetDeath()) {
                    DunnoTactic::D.SetInfo("Karakter dengan ID "+DunnoTactic::ToString(Target.GetID())+" mati.",0);
                    DunnoTactic::D.SetInfo("",1);
                } else {
                    int D = Damage-Target.GetDefensePoint();
                    if (D<=0) {
                        D = 1;
                    }
                    DunnoTactic::D.SetInfo("Karakter "+DunnoTactic::ToString(Target.GetID())+" menerima damage sebesar "+DunnoTactic::ToString(D),0);
                    DunnoTactic::D.SetInfo("HP karakter sekarang : "+DunnoTactic::ToString(Target.GetHP()),1);
                    DunnoTactic::D.SetInfo("",2);
                }
	}
	else  {
            DunnoTactic::D.SetInfo("Attack Miss !!!!!",0);
            DunnoTactic::D.SetInfo("",1);
	}
        DunnoTactic::D.displayGame();
	
	AttackTurn = true;
        MoveTurn =true;
}

//Fungsi menyerang karakter lain
void Job::Attack(const int& x, const int& y) {
    int range = abs(x-X) + abs(y-Y);
    if (range<=RangeAttack) {
        if (DunnoTactic::M.GetTerrain(x,y)==4) {
            DunnoTactic::D.AttackAnimated(X,Y,x,y);
            DunnoTactic::M.SetTerrainXY(x, y, "rumput");
            AttackTurn = true;
            MoveTurn = true;
        } else {
            if(DunnoTactic::D.GetMapPlayer(x,y)>0) {
                Job* J = DunnoTactic::GetCharacter(x,y);
                if(!IsFriend(*J)) {
                    Attack(*J);
                } else {
                    throw "Tidak bisa menyerang teman.";
                }

            } else {
                throw "Tidak ada target.";
            }
        }
    }
    else {
        throw "Serangan diluar jangkuan.";
    }
}

//Fungsi menerima serangan
//I.S : HP masih yang lama
//F.S : HP telah berkurang sesuai Attack
void Job:: ReceiveAttack (const int& Attack) {
	int i = (Attack - Defense);
	if (i<0){ 
		i = 1; 
	}
	
    HP = HP - i;
	
	if (HP<=0){
		HP = 0;
		Death = true;
                Enable = false;
                DunnoTactic::D.SetMapPlayer(X,Y,0);
                X=0;Y=0;
	}
}

//Fungsi menerima HP
//I.S : HP masih yang lama
//F.S : HP telah Bertambah sesuai dengan spesial
void Job:: ReceiveHP (const int& Attack) {
    HP = HP + (Attack);
    if (HP > HPDefault)
        HP = HPDefault;
}  
	
//Fungsi serangan tambahan
//I.S : ~~
//F.S : Target.HP dalam suatu area berkurang (jika spesial heal, maka Target.HP bertambah)
void Job::SpecialArea (const int & SPC){
}

//Fungsi serangan tambahan
//I.S : ~~
//F.S : Target.HP berkurang
void Job::Special (const int & SPC, Job &Target) {
}

void Job::Special (const int & x, const int & y, const int & SPC) {
    int range = abs(x-X) + abs(y-Y);
    if (range<=RangeAttack) {
        if(DunnoTactic::D.GetMapPlayer(x,y)>0) {
            Job* J = DunnoTactic::GetCharacter(x,y);
            if(!IsFriend(*J) || JobName=="Sage") {
                Special(SPC, *J);
            } else {
                throw "Tidak bisa menyerang teman.";
            }
        } else {
            throw "Tidak ada target.";
        }
    }
    else {
        throw "Serangan diluar jangkuan.";
    }
}

