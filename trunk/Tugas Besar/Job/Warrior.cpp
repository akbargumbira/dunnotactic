//File: Warrior.cpp
//Implementasi kelas Warrior

#include "Warrior.h"

Warrior::Warrior(){}

Warrior::Warrior(const string& RaceName) : Job(RaceName){

	Name 	   			= "";
	JobName	   			= "Warrior";
	AttackPoint			= int(AttackPoint*1.4);
	Defense    			= int(Defense*1);
	Acc	       			= int(Acc*0.8);
	Evade      			= int(Evade*0.8);
	RangeMove  			-= 0;
	RangeAttack			+= 0;
	HP         			= int(HP*1);
	SPDefault     			= int(SPDefault*1.2);
	HPDefault  			= HP;
	SP                              = 0;
	AccDefault 			= Acc;
	AttackPointDefault 	= AttackPoint;
	RangeAttackDefault 	= RangeAttack;	
	SpecialArray[0] 	= "1.Slash                 30";

}
Warrior::Warrior(const Warrior& k){
	
	Name 				= k.Name;
	AttackPoint 		= k.AttackPoint;
	Defense 			= k.Defense;
	RangeMove 			= k.RangeMove;
	RangeAttack 		= k.RangeAttack;
	HP 					= k.HP;
	SP 					= k.SP;
	Acc 				= k.Acc;
	Evade	    		= k.Evade;
	HPDefault   		= k.HP;
	SPDefault   		= k.SP;
	AttackPointDefault 	= k.AttackPointDefault;
	RangeAttackDefault 	= k.RangeAttackDefault;	
	AccDefault 			= Acc;
	SpecialArray[0] 	= k.SpecialArray[0];
	AttackTurn 			= k.AttackTurn;
	Enable   			= k.Enable;
	MoveTurn   			= k.MoveTurn;
	Death	   			= k.Death;
}

Warrior::~Warrior(){	
}

void Warrior::SpecialArea (const int & SPC) {
}

void Warrior::Special (const int & SPC, Job &Target) {
	if (AttackTurn == false) {
		if (SPC == 1) {
			if (SP>25) {
				AttackPoint = int(AttackPoint*1.8*SpecialBonus) ; 
				Acc *2.1;
				Attack(Target);
				AttackPoint = AttackPointDefault;
				Acc = AccDefault;
				SP	-= 25;
				AttackTurn = true;
			}
			else {throw "SP tidak mencukupi.";
			}
		}
		else {throw "Tidak ada Skill yang dimaksud!.";
		}
	}
}


