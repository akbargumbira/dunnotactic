//File: Mage.cpp
//Implementasi kelas Mage

#include "Mage.h"

Mage::Mage(){}

Mage::Mage(const string& RaceName) : Job(RaceName){

	Name 	   = "";
	JobName	   = "Mage";
	AttackPoint= int(AttackPoint*0.8);
	Defense    = int(Defense*0.8);
	Acc	       = int(Acc*1.2);
	Evade      = int(Evade*0);
	RangeMove  += 0;
	RangeAttack+= 0;
	HP         = int(HP*0.8);
	SP         = int(SP*1.6);
	HPDefault  = HP;
	SPDefault  = SP;

}
Mage::Mage(const Mage& k){
	
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
Mage::~Mage(){
		
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

void Mage::Special (Job &Target) {
}
