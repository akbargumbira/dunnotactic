//File: Warrior.cpp
//Implementasi kelas Warrior

#include "Warrior.h"

Warrior::Warrior(){}

Warrior::Warrior(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Warrior";
	AttackPoint= int(AttackPoint*1.4);
	Defense    = int(Defense*1);
	Acc	       = int(Acc*0.8);
	Evade      = int(Evade*0.8);
	RangeMove  -= 0;
	RangeAttack+= 0;
	HP         = int(HP*1);
	SP         = int(SP*1.2);
	HPDefault  = HP;
	SPDefault  = SP;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;
	SpecialArray[0] = "Slash                 30";
	Death	   = false;

}
Warrior::Warrior(const Warrior& k){
	
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
Warrior::~Warrior(){
		
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
void Warrior::Special (const string & STR, Job &Target) {
if (STR == "Slash") {
	if (SP>25) {
	AttackPoint = int(AttackPoint*1.8*SpecialBonus) ; 
	Attack(Target);
	AttackPoint = AttackPointDefault;
	SP	-= 25;}
	else {cout<<"SP tidak mencukupi";system("pause");}
	}
else {cout<<"Tidak ada Skill yang dimaksud!";system("pause");}
}


