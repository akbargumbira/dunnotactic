//File: Archer.cpp
//Implementasi kelas Archer

#include "Archer.h"

Archer::Archer(){}

Archer::Archer(const string& RaceName) : Job(RaceName){

	Name 	   			= "";
	JobName	   			= "Archer";
	AttackPoint			= int(AttackPoint*1);
	Defense    			= int(Defense*0.8);
	Acc	       			= int(Acc*1.4);
	Evade      			= int(Evade*1.4);
	RangeMove  			+= 1;
	RangeAttack			+= 6;
	HP         			= int(HP*1);
	SP         			= int(SP*1.2);
	HPDefault  			= HP;
	SPDefault  			= SP;
	AccDefault 			= Acc;
	AttackPointDefault 	= AttackPoint;
	RangeAttackDefault 	= RangeAttack;	
	SpecialArray[0] 	= "1.Meteor Shower         30";
}
Archer::Archer(const Archer& k){
	
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

Archer::~Archer(){	
}

void Archer::SpecialArea (const int & SPC){
}

void Archer::Special (const int & SPC, Job &Target) {
	if (AttackTurn == false) {
		if (SPC == 1) {
			if (SP>25) {
				AttackPoint = int(AttackPoint*1.4*SpecialBonus) ;
				Acc *2.2;
				RangeAttack	+= -1;
				Attack(Target);
				AttackPoint = AttackPointDefault;
				RangeAttack = RangeAttackDefault;
				Acc = AccDefault;
				SP	-= 25;
				AttackTurn = true;}
			else { throw "SP tidak mencukupi.";
			}
		}
		else {throw "Tidak ada Skill yang dimaksud!.";
		}	
	}
}
















