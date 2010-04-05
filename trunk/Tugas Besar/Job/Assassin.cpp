//File: Assassin.cpp
//Implementasi kelas Assassin

#include "Assassin.h"

Assassin::Assassin(){}

Assassin::Assassin(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Assassin";
	AttackPoint= int(AttackPoint*0.6);
	Defense    = int(Defense*1.4);
	Acc	       = int(Acc*1.6);
	Evade      = int(Evade*1.6);
	RangeMove  += 3;
	RangeAttack+= 4;
	HP         = int(HP*1);
	SP         = int(SP*1);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;	
	SpecialArray[0] = "Hell Chain            30";
	Death	   = false;

}
Assassin::Assassin(const Assassin& k){
	
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
Assassin::~Assassin(){
		
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

void Assassin::Special (const string & STR, Job &Target) {
if (STR == "Hell Chain") {
	if (SP>40) {
	AttackPoint = int(AttackPoint*0.8*SpecialBonus) ; 
	RangeAttack += 2;
	Attack(Target);
	AttackPoint = AttackPointDefault;
	RangeAttack = RangeAttackDefault;
	SP	-= 40;}
	else {cout<<"SP tidak mencukupi";}
	}
else {cout<<"Tidak ada Skill yang dimaksud!";}
}


