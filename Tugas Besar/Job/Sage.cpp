//File: Sage.cpp
//Implementasi kelas Sage

#include "Sage.h"

Sage::Sage(){}

Sage::Sage(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Sage";
	AttackPoint= int(AttackPoint*0.8);
	Defense    = int(Defense*1);
	Acc	       = int(Acc*1);
	Evade      = int(Evade*0.8);
	RangeMove  -= 0;
	RangeAttack+= 2;
	HP         = int(HP*1);
	SP         = int(SP*1.4);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;	
	SpecialArray[0] = "Heal                  30";
	SpecialArray[1] = "Circle Heal           50";
	Death	   = false;

}
Sage::Sage(const Sage& k){
	
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
Sage::~Sage(){
		
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

void Sage::Special (const string & STR, Job &Target){
if (STR == "Heal") {
	if (SP>20) {
	Target.ReceiveHP(int (300*SpecialBonus));
	SP	-= 20;}
	else {cout<<"SP tidak mencukupi";}
	}
if (STR == "Circle Heal") {
	if (SP>50) {
	Target.ReceiveHP(int (300*SpecialBonus));
	SP	-= 50;}
	else {cout<<"SP tidak mencukupi";}
	}
else {cout<<"Tidak ada Skill yang dimaksud!";}

}


