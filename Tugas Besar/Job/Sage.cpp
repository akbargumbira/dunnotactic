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

void Sage::Special (Job &Target) {
}
