//File: Mage.cpp
//Implementasi kelas Mage

#include "Mage.h"

Mage::Mage(){}

Mage::Mage(const string& RaceName) : Job(RaceName){

	Name 	   			= "";
	JobName	   			= "Mage";
	AttackPoint			= int(AttackPoint*0.6);
	Defense    			= int(Defense*0.8);
	Acc	       			= int(Acc*1.2);
	Evade      			= int(Evade*1);
	RangeMove  			+= 0;
	RangeAttack			+= 0;
	HP         			= int(HP*0.8);
	SP         			= int(SP*1.6);
	HPDefault  			= HP;
	SPDefault  			= SP;
	AccDefault 			= Acc;
	AttackPointDefault 	= AttackPoint;
	RangeAttackDefault 	= RangeAttack;	
	SpecialArray[0] 	= "1.Hell Fire             30";
	AttackTurn 			= false;
	Enable   			= false;
	MoveTurn   			= false;
	Death	   			= false;

}
Mage::Mage(const Mage& k){
	
	Name 				= k.Name;
	AttackPoint 		= k.AttackPoint;
	Defense 			= k.Defense;
	RangeMove 			= k.RangeMove;
	RangeAttack			= k.RangeAttack;
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
Mage::~Mage(){
	
}
void Mage::SpecialArea (const int & SPC){
}
void Mage::Special (const int & SPC, Job &Target) {
	if (AttackTurn == false) {
		if (SPC == 1) {
			if (SP>30) {
				AttackPoint = int(AttackPoint*2.2*SpecialBonus) ; 
				Acc *= 3;
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


