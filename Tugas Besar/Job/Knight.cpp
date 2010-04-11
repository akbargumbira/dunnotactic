//File: Knight.cpp
//Implementasi kelas Knight

#include "Knight.h"

Knight::Knight(){}

Knight::Knight(const string& RaceName) : Job(RaceName){

	Name 	  			= "";
	JobName	   			= "Knight";
	AttackPoint			= int(AttackPoint*1);
	Defense    			= int(Defense*1.4);
	Acc	       			= int(Acc*0.8);
	Evade      			= int(Evade*0.8);
	RangeMove  			-= 1;
	RangeAttack			+= 0;
	HP         			= int(HP*1.6);
	SP         			= int(SP*0.8);
	HPDefault  			= HP;
	SPDefault  			= SP;
	AccDefault 			= Acc;
	AttackPointDefault 	= AttackPoint;
	RangeAttackDefault 	= RangeAttack;		
	SpecialArray[0]		= "1.Sword of Fury         30";

}
Knight::Knight(const Knight& k){
	
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

Knight::~Knight(){	
}

void Knight::SpecialArea (const int & SPC ){
}

void Knight::Special (const int & SPC, Job &Target) {
	if (AttackTurn == false) {
		if (SPC == 1) {
			if (SP>30) {
				AttackPoint = int(AttackPoint*2*SpecialBonus) ; 
				Acc *2.6;
				Attack(Target);
				AttackPoint = AttackPointDefault;
				Acc = AccDefault;
				SP	-= 30;
				AttackTurn = true;
			}
			else {throw "SP tidak mencukupi.";}
			}
		else {throw "Tidak ada Skill yang dimaksud!.";
		}
	}
}

