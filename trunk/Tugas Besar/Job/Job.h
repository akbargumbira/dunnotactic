#ifndef _Job_H
#define _Job_H

#include <iostream>
#include <string>
//Job, merupakan penambahan attribut untuk suatu Job yang dipilih
using namespace std;
class Job {
protected :
 
      int       ID;				//ID untuk objek
      string    Name;			//Nama objek (User yang memberi)
	  string 	JobName;		//Job Name objek
	  string 	RaceName;		//RAce Name  objek
	  bool		Death;			//Status objek untuk mati (jika darah habis (0) ) - true jika mati
	  bool 		AttackTurn;		//Status Objek untuk Attack - true jika telah melakukan serangan
	  bool		WaitTurn;		//Status Objek untuk Wait - true jika telah melakukan wait 
	  bool		MoveTurn;		//Status Objek untuk Move - true jika telah melakukan move
      
      //attribut
      int       AttackPoint;	//Attribut nilai serangan
      int       Defense;		//Attribut nilai pertahanan
      int       Acc;			//Attribut nilai ketepatan dalam menyerang
      int       Evade;			//Attribut nilai dalam menghindar
      float     SpecialBonus;	//Attribut nilai tambahan dalam melakukan serangan special 
      int       RangeMove;		//Attribut nilai daerah yang bisa dilalui move
      int       RangeAttack;	//Attribut nilai daerah yang bisa diserang
      
      int       HP;	  			//Attribut nilai kehidupan (jika HP = 0 maka karakter mati, Death = true)
      int       SP;	 			//Attribut nilai simpanan untuk melakukan serangan special (jika SP <= cost yang diperlukan untuk melakukan serangan suatu special, Special tidak dapat dilakukan)
	  string 	SpecialArray[10]; //Attribut List special yang dimiliki
	  
	  //Attribut Default
      int		HPDefault;		//Attribut HPMax
	  int		SPDefault;		//Attribut SPMax
	  int 		AttackPointDefault;	//Attribut Attack original
	  int		RangeAttackDefault;	//Attribut Ranget Attack Original
      //Kordinat karakter
      int       X;				//Posisi Karakter dalam garis X
      int       Y; 				//Posisi Karakter dalam garis Y
 
 public :
      //METHOD
      //Constructor dan destructor
      Job ();					//Constructor Default
	  //Construstor dengan parameter string
	  //I.S : Karakter belum diinstansi
	  //F.S : Karakter telah diinstansi dengan race string
	  Job (const string&);		
	  //Destructor virtual
      virtual ~Job ();
      
      //Attribute
      int GetAttackPoint ();    //mengembalikan nilai attack_point
      int GetDefensePoint ();   //mengembalikan nilai defense_point
      int GetAcc ();            //mengembalikan nilai acc
      int GetEvade ();          //mengembalikan nilai evade
      float GetSpecialBonus (); //mengembalikan nilai spsial_bonus
      int GetRangeMove ();      //mengembalikan nilai range_move
      int GetRangeAttack();     //mengembalikan nilai range_attack
      int GetHP();              //mengembalikan nilai HP
      int GetSP();              //mengembalikan nilai SP
	  int GetHPDefault();		//mengembalikan nilai HPDefault
	  int GetSPDefault();		//mengembalikan nilai SPDefault
	  string GetName();			//mengembalikan nilai Name Karakter
	  string GetJobName();		//mengembalikan nilai JobName Karakter
	  string GetRaceName();		//mengembalikan nilai RaceName Karakter
	  void GetSpecialArray(); //mengembalikan isi list SpesialArray
	  void SetName(const string&);
	  void SetDeath(bool &);
	  void SetAttackTurn (bool &);
	  void SetWaitTurn (bool &);
	  void SetMoveTurn (bool &);
	  bool GetDeath();
	  bool GetAttackTurn();
	  bool GetWaitTurn();
	  bool GetMoveTurn();
	  
	  //Method Lain
	  void Status();
      
      //Posisi
      int GetX ();               //mengembalikan nilai X
      int GetY ();               //mengembalikan nilai Y
      
      //Method Karakter
	  void Move (const int &, const int &);
	  void Attack (Job &Target);
      void ReceiveAttack (const int& );
      void ReceiveHP (const int& );
	  virtual void SpecialArea (const string & STR);
	  virtual void Special (const string & STR, Job &Target);
};      
      
#endif
