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
	AccDefault = Acc;
	AttackPointDefault = AttackPoint;
	RangeAttackDefault = RangeAttack;	
	SpecialArray[0] = "1.Heal                  30";
	SpecialArray[1] = "2.Circle Heal           50";
	Death	   = false;
	AttackTurn = false;
	Enable   = false;
	MoveTurn   = false;

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
	AttackPointDefault = k.AttackPointDefault;
	RangeAttackDefault = k.RangeAttackDefault;	
	AccDefault = Acc;
	SpecialArray[0] = k.SpecialArray[0];
	SpecialArray[1] = k.SpecialArray[1];
	AttackTurn = k.AttackTurn;
	Enable   = k.Enable;
	MoveTurn   = k.MoveTurn;
	Death	   = k.Death;
	
}
Sage::~Sage(){

}
void Sage::SpecialArea (const int & SPC){
if (SPC == 2) {
	if (SP>50) {
	}
	else {throw "SP tidak mencukupi.";}
	}
else {throw "Tidak ada Skill yang dimaksud!.";}
}


void Sage::Special (const int & SPC, Job &Target){
if (AttackTurn == false) {
	if (SPC == 1) {
		if (SP>20) {
		Target.ReceiveHP(int (300*SpecialBonus));
		SP	-= 20;
		AttackTurn = true;}
		else {throw "SP tidak mencukupi.";}
		}
	else {throw "Tidak ada Skill yang dimaksud!.";}	
	}
}


