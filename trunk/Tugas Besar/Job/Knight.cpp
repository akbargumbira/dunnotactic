//File: Knight.cpp
//Implementasi kelas Knight

#include "Knight.h"

Knight::Knight(){}

Knight::Knight(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Knight";
	AttackPoint= int(AttackPoint*1);
	Defense    = int(Defense*1.4);
	Acc	       = int(Acc*0.8);
	Evade      = int(Evade*0.8);
	RangeMove  -= 1;
	RangeAttack+= 0;
	HP         = int(HP*1.6);
	SP         = int(SP*0.8);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	SpecialArray[0] = "Sword of Fury         30";

}
Knight::Knight(const Knight& k){
	
	Name 		= k.Name;
	AttackPoint = k.AttackPoint;
	Defense 	= k.Defense;
	RangeMove 	= k.RangeMove;
	RangeAttack = k.RangeAttack;
	HP 			= k.HP;
	SP 			= k.SP;
	Acc 		= k.Acc;
	Evade	    = k.Evade;
	HPDefault   = k.HP;
	SPDefault   = k.SP;
	
}
Knight::~Knight(){
		
    Name		="";
	AttackPoint = 0;
	Defense 	= 0;
	RangeMove 	= 0;
	RangeAttack = 0;
	HP 			= 0;
	SP 			= 0;
	Acc			= 0;
	Evade		 = 0;
	
}


void Knight::Special (const string & STR, Job &Target) {
if (STR == "Sword of Fury") {
	if (SP<30) {
	AttackPoint = int(AttackPoint*2*SpecialBonus) ; 
	Attack(Target);
	AttackPoint = AttackPointDefault;
	SP	-= 30;}
	else {cout<<"SP tidak mencukupi"<<endl;}
	}
else {cout<<"Tidak ada Skill yang dimaksud!"<<endl;}
}

