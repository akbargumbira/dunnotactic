#include "Display.h"
#include "../DunnoTactic.h"

// Display constructor
	Display::Display() {
		int i;
		int j;
		
		// set MapArea
		// nilai 99 menandakan petak tersebut player tertentu tidak dapat move ke petak tersebut
		for(i=0;i<30;++i) {
			for(j=0;j<30;++j) {
				MapArea[i][j]=99;
			}
		}
		
		// set MapPlayer
		// default adalah 0, di mana tidak ada player di Map tersebut
		for(i=0;i<30;++i) {
			for(j=0;j<30;++j) {
				MapPlayer[i][j]=0;
			}
		}

                pointerX = 1;
                pointerY = 1;
	}

// Display copy constructor
	Display::Display(const Display& D) {
	}
	
// Display operator assignment
	Display& Display::operator=(const Display& D) {
	}

// Display destructor
	Display::~Display() {
	}
	
// Deklarasi method
        void Display::displayGame() {
            int turn = DunnoTactic::PlayerTurn;
            displayBoxMap();
            displayBoxInfo();
            displayBoxTurn(turn);
        }
	void Display::displayBoxTurn(int Turn) {
		string Blank = "     ";
		cout << endl;
		cout << Blank << "::::::::::::::::::" << endl;
		cout << Blank << ":    PLAYER " << Turn <<"    :" << endl;
		cout << Blank << ":      TURN      :" << endl;
		cout << Blank << "::::::::::::::::::" << endl << endl;
	}
	
	void Display::displayBoxTurnWithName(string Name) {
		string Blank = "     ";
		cout << endl;
		cout << Blank << "::::::::::::::::::" << endl;
		cout << Blank << ":";
		int sumSpace;
		int i;
		
		if(Name.length()<=12) {
			sumSpace = (16-Name.length())/2;
			for(i=0;i<sumSpace;++i) {
				cout << " ";
			}
			cout << Name;
			if(Name.length()%2 == 1) {
				++sumSpace;
			}
			for(i=0;i<sumSpace;++i) {
				cout << " ";
			}
		} else {
			sumSpace = 2;
			for(i=0;i<sumSpace;++i) {
				cout << " ";
			}
			cout << Name.substr(0,12);
			for(i=0;i<sumSpace;++i) {
				cout << " ";
			}
		}
		cout << ":" << endl;
		cout << Blank << ":      TURN      :" << endl;		
		cout << Blank << "::::::::::::::::::" << endl << endl;
	}
	
// Display box Map
	void Display::displayBoxMap() {
		int i;
		int j;
		int k;
                int P = DunnoTactic::M.GetSizeX();
                int L = DunnoTactic::M.GetSizeY();
		
		// menampilkan indeks atas (koordinat x)
		// menampilkan garis horizontal
		cout << "     +";
		for(i=0;i<P;++i) {
                    cout << "=====+";
		}
		cout << endl;
		// menampilkan indeks
		cout << "     |";
		for(i=1;i<=P;++i) {
			if(i<10){
				cout << "  " << i <<"  |";
			}
			else {
				cout << " " << i <<"  |";
			}
		}
		cout << endl;
		
		// menampilkan box di bawah indeks atas
		for(j=1;j<=L;++j) {
                    // menampilkan garis horizontal (baris 0)
                    cout << "+====+";
                    for(i=1;i<=P;++i) {
                        if((pointerX==i && pointerY==j) || (pointerX==i && pointerY==j-1)) {
                            for(int n=1;n<=5;++n) {
                                printCursor(0);
                            }
                            cout << "+";
                        } else {
                            cout << "=====+";
                        }
                    }
                    cout << endl;

                    // menampilkan garis vertikal 1 (baris 1/atas kotak terrain)
                    cout << "|    ";
                     if(pointerX==1 && pointerY==j) {
                        printCursor(0);
                     } else {
                         cout << "|";
                     }
                    for(i=1;i<=P;++i) {
                        if(MapPlayer[i-1][j-1]!=0) {
                            if(pointerX==i && pointerY==j) {
                                printPlayer(i,j,1,true);
                            } else {
                                printPlayer(i,j,1,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        } else {
                            if((pointerX==i && pointerY==j) || MapArea[i-1][j-1]!=99) {
                                printTerrain(i,j,true);
                            } else {
                                printTerrain(i,j,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        }
                    }
                    cout << endl;

                    // menampilkan garis vertikal 2 (baris 2/tengah kotak terrain)
                    // menampilkan indeks samping (koordinat y)
                    if(j<10) {
                        cout << "| " << j;
                        if(pointerX==1 && pointerY==j) {
                            cout << "  ";
                            printCursor(0);
                        } else {
                            cout << "  |";
                        }

                    }
                    else {
                        cout << "| " << j;
                        if(pointerX==1 && pointerY==j) {
                            cout << " ";
                            printCursor(0);
                        } else {
                            cout << " |";
                        }
                    }
                    // menampilkan kotak terrain tengah
                    for(i=1;i<=P;++i) {
                        if(MapPlayer[i-1][j-1]!=0) {
                            if(pointerX==i && pointerY==j) {
                                printPlayer(i,j,2,true);
                            } else {
                                printPlayer(i,j,2,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        }
                        else {
                            if((pointerX==i && pointerY==j) || MapArea[i-1][j-1]!=99) {
                                printTerrain(i,j,true);
                            } else {
                                printTerrain(i,j,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        }
                    }
                    cout << endl;

                    // menampilkan garis vertikal 3 (baris 3/bawah kotak terrain)
                    cout << "|    ";
                     if(pointerX==1 && pointerY==j) {
                         printCursor(0);
                     } else {
                         cout << "|";
                     }
                    for(i=1;i<=P;++i) {
                        if(MapPlayer[i-1][j-1]!=0) {
                            if(pointerX==i && pointerY==j) {
                                printPlayer(i,j,3,true);
                            } else {
                                printPlayer(i,j,3,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        } else {
                            if((pointerX==i && pointerY==j) || MapArea[i-1][j-1]!=99) {
                                printTerrain(i,j,true);
                            } else {
                                printTerrain(i,j,false);
                            }
                            if((pointerX==i && pointerY==j) || (pointerX==i+1 && pointerY==j)) {
                                printCursor(0);
                            } else {
                                cout <<  "|";
                            }
                        }
                    }
                    cout << endl;
		}

		// menampilkan garis horizontal terbawah (penutup)
		cout << "+====+";
		for(i=1;i<=P;++i) {
			if((pointerX==i && pointerY==j) || (pointerX==i && pointerY==j-1)) {
                            for(int n=1;n<=5;++n) {
                                printCursor(0);
                            }
                            cout << "+";
                        } else {
                            cout << "=====+";
                        }
		}
                cout << endl << endl;
	}

// Display box Info
	void Display::displayBoxInfo() {
            int i;
            int j;
            int lengthBox = 60;
            int lengthSpace;
            string Blank = "     ";

            cout << Blank;
            for(i=0;i<lengthBox;++i) {
                    cout << "/";
            }
            cout << endl << Blank << "/";
            for(i=0;i<lengthBox-2;++i) {
                    cout << " ";
            }
            cout << "/";

            j=0;
            while(j < 9 && Info[j].length()!=0) {
                    cout << endl;
                    cout << Blank << "/";
                    if(Info[j]!="") {
                        cout << "  " << Info[j];
                        lengthSpace= lengthBox - Info[j].length()-4;
                    } else {
                        lengthSpace=lengthBox-2;
                    }
                    for(i=1;i<=lengthSpace;++i) {
                            cout << " ";
                    }
                    cout << "/";
                    ++j;
            }
            cout << endl << Blank;
            for(i=1;i<=lengthBox;++i) {
                    cout << "/";
            }
            cout << endl;
	}

	void Display::setAreaMove(int initX, int initY, int range) {
		
            int factorX;
            int factorY;
            int x;
            int y;

            int i;
            int j;
            int looping;

            if(IsLumpur(initX,initY)) {
                    MapArea[initX-1][initY-1]=1;
            } else {
                    MapArea[initX-1][initY-1]=0;
            }
            for(looping=1;looping<=2;++looping) {
                for(i=1;i<=range;++i) {
                    // Kuadran 1 dan 3
                    factorY=-i;
                    for(factorX=0;factorX<i;++factorX) {
                        // kuadran 1
                        x = initX+factorX-1;
                        y = initY+factorY-1;
                        if(x>=0 && y>=0 && x<DunnoTactic::M.GetSizeX() && y<DunnoTactic::M.GetSizeY()) {
                            setDistanceMove(initX-1,initY-1,x,y,range);
                        }
                        // kuadran 3
                        x = initX-factorX-1;
                        y = initY-factorY-1;
                        if(x>=0 && y>=0 && x<DunnoTactic::M.GetSizeX() && y<DunnoTactic::M.GetSizeY()) {
                            setDistanceMove(initX-1,initY-1,x,y,range);
                        }
                        ++factorY;
                    }
                    // Kuadran 2 dan 4
                    factorX=i;
                    for(factorY=0;factorY<i;++factorY) {
                        // kuadran 4
                        x = initX+factorX-1;
                        y = initY+factorY-1;
                        if(x>=0 && y>=0 && x<DunnoTactic::M.GetSizeX() && y<DunnoTactic::M.GetSizeY()) {
                            setDistanceMove(initX-1,initY-1,x,y,range);
                        }
                        // kuadran 2
                        x = initX-factorX-1;
                        y = initY-factorY-1;
                        if(x>=0 && y>=0 && x<DunnoTactic::M.GetSizeX() && y<DunnoTactic::M.GetSizeY()) {
                            setDistanceMove(initX-1,initY-1,x,y,range);
                        }
                        --factorX;
                    }
                }
            }
	}

        void Display::setAreaAttack(int x, int y, int range) {
            int i;
            int j;
            int factor;

            for(i=x-range;i<=x+range;++i) {
                factor=range-abs(x-i);
                for(j=y-factor;j<=y+factor;++j) {
                    if(i>0 && j>0 && i<=DunnoTactic::M.GetSizeX() && j<=DunnoTactic::M.GetSizeY()) {
                        MapArea[i-1][j-1]=abs(x-i)+abs(y-j);
                    }
                }
            }
        }

        void Display::MoveAnimated(int initX, int initY, int targetX, int targetY) {
		int x;
		int y;
                Job* Player = DunnoTactic::GetCharacter(initX,initY);
		setAreaMove(initX,initY,Player->GetRangeMove());
                int xSaved[Player->GetRangeMove()];
                int ySaved[Player->GetRangeMove()];
                int i=1;
		int Minimum;
                x = targetX-1;
		y = targetY-1;
                xSaved[0]=targetX-1;
                ySaved[0]=targetY-1;

                while(x!=initX-1 || y!=initY-1) {
			Minimum = MinAround(x,y);
			if(y>0 && MapArea[x][y-1]==Minimum) {
				xSaved[i]=x;
				ySaved[i]=y-1;
				y=y-1;
			} else
			if(x<DunnoTactic::M.GetSizeX()-1 && MapArea[x+1][y]==Minimum) {
				xSaved[i]=x+1;
				ySaved[i]=y;
				x=x+1;
			} else
			if(y<DunnoTactic::M.GetSizeY()-1 && MapArea[x][y+1]==Minimum) {
				xSaved[i]=x;
				ySaved[i]=y+1;
				y=y+1;
			} else {
				xSaved[i]=x-1;
				ySaved[i]=y;
				x=x-1;
			}
                        ++i;
                        cout << "wooooo3" <<endl;
		}
                clearArea();
		int preX = initX-1;
		int preY = initY-1;
                int temp1;
                int temp2=0;
                pointerX=initX;
                pointerY=initY;
		displayGame();
                x = preX;
                y = preY;
                --i;
                --i;
		while(x!=targetX-1 || y!=targetY-1) {
			x=xSaved[i];
			y=ySaved[i];
                        temp1=temp2;
                        temp2=MapPlayer[x][y];
                        MapPlayer[x][y]=MapPlayer[preX][preY];
                        MapPlayer[preX][preY]=temp1;
                        Player->SetXY(x+1,y+1);
			preX=x;
			preY=y;
			sleep(1);
			system("clear");
                        pointerX=x+1;
                        pointerY=y+1;
			displayGame();
                        --i;
		}
	}

        void Display::AttackAnimated(int initX, int initY, int targetX, int targetY) {
            isAttack=true;
            int modeAttack;
            clearArea();
            Job * Player = DunnoTactic::GetCharacter(initX,initY);
            for(modeAttack=1;modeAttack<=5;++modeAttack) {
                if(modeAttack%2==1) {
                    pointerX=initX;
                    pointerY=initY;
                } else {
                    pointerX=targetX;
                    pointerY=targetY;
                }
                shoutAttackRace(Player->GetRaceName(),modeAttack);
                shoutAttackJob(Player->GetJobName(),modeAttack);
                displayGame();
                sleep(1);
            }
            isAttack=false;
        }

        void Display::SelectMove(int x, int y) {
            clearArea();
            Job* Player = DunnoTactic::GetCharacter(x,y);
            setAreaMove(x,y,Player->GetRangeMove());
            pointerX=x;
            pointerY=y;
            system("clear");
            displayGame();
        }

        void Display::SelectAttack(int x, int y) {
            clearArea();
            Job* Player = DunnoTactic::GetCharacter(x,y);
            setAreaAttack(x,y,Player->GetRangeAttack());
            pointerX=x;
            pointerY=y;
            system("clear");
            displayGame();
        }

        void Display::HighlightGrid(int x, int y) {
            pointerX=x;
            pointerY=y;
            switch(DunnoTactic::M.GetTerrain(x,y)) {
                case 1 : {
                    Info[0]="Tipe Terrain : Rumput.";
                    Info[1]="Deskripsi    : Ijooooo..segerrrrr.";
                    break;
                }
                case 2 : {
                    Info[0]="Tipe Terrain : Air.";
                    Info[1]="Deskripsi    : Dinginnnn, brrrrrrr.";
                    break;
                }
                case 3 : {
                    Info[0]="Tipe Terrain : Lumpur.";
                    Info[1]="Deskripsi    : Lengket lengket gitu, ihhhh.";
                    break;
                }
                case 4 : {
                    Info[0]="Tipe Terrain : Pohon.";
                    Info[1]="Deskripsi    : Tinggi menjulang, wooooo.";
                    break;
                }
                default : {
                    Info[0]="Tipe Terrain : Unknown";
                    Info[1]="Deskripsi    : Unknown";
                    break;
                }
            }
            Info[2]=" ";
            cout << MapPlayer[x-1][y-1] << endl;
            if(MapPlayer[x-1][y-1]!=0) {
                if(IdPlayer(x-1,y-1)==1) {
                    Info[3]="Player - 1";
                } else {
                    Info[3]="Player - 2";
                }
                Job* Player = DunnoTactic::GetCharacter(x,y);
                Info[4]= Player->GetRaceName() + "-" + Player->GetJobName();
                Info[5]="HP           : "+DunnoTactic::ToString(Player->GetHP());
                Info[6]="SP           : "+DunnoTactic::ToString(Player->GetSP());
                Info[7]="Attack       : "+DunnoTactic::ToString(Player->GetAttackPoint());
                Info[8]="Defense      : "+DunnoTactic::ToString(Player->GetDefensePoint());
            } else {
                for(int i=3;i<=8;++i) {
                    Info[i]="";
                }
            }
            displayGame();
        }

        void Display::clearArea() {
            for(int i = 0;i<30;++i) {
                for(int j = 0;j<30;++j) {
                    MapArea[i][j]=99;
                }
            }
        }

        void Display::clearPlayer() {
            for(int i = 0;i<30;++i) {
                for(int j=0;j<30;++j) {
                    MapPlayer[i][j]=0;
                }
            }
        }
        
        // method get dan set
        void Display::SetInfo(string Infox, int id) {
            Info[id]=Infox;
        }

        void Display::SetMapPlayer(int x, int y, int id) {
            MapPlayer[x-1][y-1]=id;
        }

        string Display::GetInfo(int id) {
            return Info[id];
        }

        int Display::GetMapPlayer(int x, int y) {
            return MapPlayer[x-1][y-1];
        }

        int Display::GetMapArea(int x, int y) {
            if((x>DunnoTactic::M.GetSizeX() || x<1) || (y>DunnoTactic::M.GetSizeY() || y<1))
            {
                throw "Error GetMapArea. X dan Y diluar jangkuan.";
            }
            else
            {
                return MapArea[x-1][y-1];
            }
        }

// method-method yang private
        
        void Display::color(string text, string bg) {
            if(text=="black") {
                cout << "\033[0;30m";
            } else if(text=="red") {
                cout << "\033[0;31m";
            } else if (text=="green") {
                cout << "\033[0;32m";
            } else if (text=="yellow") {
                cout << "\033[0;33m";
            } else if (text=="blue") {
                cout << "\033[0;34m";
            } else if(text=="purple") {
                cout << "\033[0;35m";
            } else if(text=="cyan") {
                cout << "\033[0;36m";
            } else if(text=="light gray") {
                cout << "\033[0;37m";
            } else if(text=="dark gray") {
                cout << "\033[1;30m";
            } else if(text=="bold red") {
                cout << "\033[1;31m";
            } else if (text=="bold green") {
                cout << "\033[1;32m";
            } else if (text=="bold yellow") {
                cout << "\033[1;33m";
            } else if (text=="bold blue") {
                cout << "\033[1;34m";
            } else if(text=="bold purple") {
                cout << "\033[1;35m";
            } else if(text=="bold cyan") {
                cout << "\033[1;36m";
            } else if(text=="white") {
                cout << "\033[1;37m";
            } else {
                cout << "\033[0m";
            }
            if(bg=="black") {
                cout << "\033[0;40m";
            } else if(bg=="red") {
                cout << "\033[0;41m";
            } else if (bg=="green") {
                cout << "\033[0;42m";
            } else if (bg=="yellow") {
                cout << "\033[0;43m";
            } else if (bg=="blue") {
                cout << "\033[0;44m";
            } else if(bg=="purple") {
                cout << "\033[0;45m";
            } else if(bg=="cyan") {
                cout << "\033[0;46m";
            } else if(bg=="light gray") {
                cout << "\033[0;47m";
            } else if(bg=="dark gray") {
                cout << "\033[1;40m";
            } else if(bg=="bold red") {
                cout << "\033[1;41m";
            } else if (bg=="bold green") {
                cout << "\033[1;42m";
            } else if (bg=="bold yellow") {
                cout << "\033[1;43m";
            } else if (bg=="bold blue") {
                cout << "\033[1;44m";
            } else if(bg=="bold purple") {
                cout << "\033[1;45m";
            } else if(bg=="bold cyan") {
                cout << "\033[1;46m";
            } else if(bg=="white") {
                cout << "\033[1;47m";
            } else {
                cout << "\033[0m";
            }
        }

        void Display::printCursor(int status) {
            switch (status) {
                case 0 : {
                    color("light gray","cyan");
                    cout << "$";
                    color("default","default");
                    break;
                }
                default : {
                    
                }
            }
        }
        
        bool Display::PassTerrain(int x, int y) {
		bool Pass;
		if(IsTree(x,y) || IsWater(x,y)) {
			Pass = false;
		} else {
			Pass = true;
		}
		return Pass;
	}

	bool Display::PassPlayer(int x1, int y1, int x2, int y2) {
		bool Pass;
		if(IdPlayer(x2,y2)==0) {
			Pass = true;
		} else
		if(IsFriend(x1,y1,x2,y2)) {
			Pass = true;
		} else {
			Pass = false;
		}
		return Pass;
	}

        void Display::printTerrain(int x, int y, int status) {
            switch(status) {
                case 0 : {
                    switch(DunnoTactic::M.GetTerrain(x,y)) {
                        case 1: {
                            color("light gray","green");
                            break;
                        }
                        case 2: {
                            color("cyan","blue");
                            break;
                        }
                        case 3: {
                            color("bold yellow","yellow");
                            break;
                        }
                        case 4: {
                            color("bold green","green");
                            break;
                        }
                        default : {
                            color("black","black");
                        }
                    }
                    break;
                }
                case 1 : {
                    color("light gray","cyan");
                    break;
                }
                default : {
                    color("black","black");
                }
            }
            switch(DunnoTactic::M.GetTerrain(x,y)) {
                case 1: {
                    cout << "     ";
                    break;
                }
                case 2: {
                    cout << " ~~~ ";
                        break;
                }
                case 3: {
                    cout << " ... ";
                        break;
                }
                case 4: {
                    cout << " ??? ";
                        break;
                }
                default: {
                        cout << " xxx ";
                        break;
                }
            }
            color("default","default");
        }

        void Display::printPlayer(int x, int y, int line, int status) {
            switch(status) {
                case 0 : {
                    if(IdPlayer(x-1,y-1)==1) {
                        color("yellow","bold red");
                    } else {
                        color("white","dark gray");
                    }
                    break;
                }
                case 1 : {
                    color("light gray","cyan");
                    break;
                }
                default : {
                    
                }
            }
            Job* Player = DunnoTactic::GetCharacter(x,y);
            switch(line) {
                case 1 : {
                    if(IdPlayer(x-1,y-1)==1) {
                        cout << " P-1 ";
                    } else {
                        cout << " P-2 ";
                    }
                    break;
                }
                case 2 : {
                    string race = Player->GetRaceName();
                    string job = Player->GetJobName();
                    if(race=="Human") {
                        cout << " H-";
                    } else if(race=="Elf") {
                        cout << " E-";
                    } else if(race=="Fairy") {
                        cout << " F-";
                    } else if(race=="Orc") {
                        cout << " O-";
                    } else {
                        cout << " U-";
                    }
                    if(job=="Archer") {
                        cout << "A ";
                    } else if(job=="Assassin") {
                        cout << "N ";
                    } else if(job=="Knight") {
                        cout << "K ";
                    } else if(job=="Mage") {
                        cout << "M ";
                    } else if(job=="Sage") {
                        cout << "S ";
                    } else if(job=="Warrior") {
                        cout << "W ";
                    } else {
                        cout << "U";
                    }
                    break;
                }
                case 3 : {
                    cout << "(" << MapPlayer[x-1][y-1] << ")";
                    break;
                }
                default : {
                    
                }
            }
            color("default","default");
        }

        void Display::setDistanceMove(int initx, int inity, int x, int y, int range) {
            if(PassTerrain(x+1,y+1) && PassPlayer(initx,inity,x,y) && MinAround(x,y) < range) {
                if(IsLumpur(x+1,y+1)) {
                    if(MinAround(x,y)==range-1) {
                        MapArea[x][y]=99;
                    } else {
                        MapArea[x][y]=MinAround(x,y) + 2;
                    }
                } else {
                    MapArea[x][y]=MinAround(x,y) + 1;
                }
            } else {
                MapArea[x][y]=99;
            }
        }

        void Display::shoutAttackRace(string raceName, int mode) {
            switch(mode) {
                case 1 : {
                    if(raceName=="Human") {
                        Info[0]="ohh dewa human";
                        Info[1]=" ";
                    } else if(raceName=="Elf") {
                        Info[0]="ohh dewa elf";
                        Info[1]=" ";
                    } else if(raceName=="Fairy") {
                        Info[0]="ohh dewa fairy";
                        Info[1]=" ";
                    } else if(raceName=="Orc") {
                        Info[0]="ohh dewa orc";
                        Info[1]=" ";
                    } else {
                        Info[0]="ohh dewa xxx";
                        Info[1]=" ";
                    }
                    break;
                }
                case 2 : {
                    Info[0]="Berilah hukumanmu kepada mereka";
                    break;
                }
                case 3 : {
                    if(raceName=="Human") {
                        Info[0]="Berilah guardianmu ini kekuatanmu";
                        Info[1]=" ";
                    } else if(raceName=="Elf") {
                        Info[0]="Berilah guardianmu ini kebijaksanaanmu";
                        Info[1]=" ";
                    } else if(raceName=="Fairy") {
                        Info[0]="Berilah guardianmu ini kecerdasanmu";
                        Info[1]=" ";
                    } else if(raceName=="Orc") {
                        Info[0]="Berilah guardianmu ini kesabaranmu";
                        Info[1]=" ";
                    } else {
                        Info[0]="Berilah guardianmu ini xxx";
                        Info[1]=" ";
                    }
                    break;
                }
                case 4 : {
                    Info[0]="Wahai musuhku..";
                    Info[1]=" ";
                    break;
                }
                case 5 : {
                    Info[0]="Rasakanlah kekuatan ini";
                    Info[1]=" ";
                    break;
                }
            }
        }

        void Display::shoutAttackJob(string jobName, int mode) {
            switch(mode) {
                case 1 : {
                    if(jobName=="Archer") {
                        Info[2]="Dengan panahku ini..";
                        Info[3]=" ";
                    } else if(jobName=="Assassin") {
                        Info[2]="Dengan pisau beracunku ini..";
                        Info[3]=" ";
                    } else if(jobName=="Knight") {
                        Info[2]="Dengan tombakku ini..";
                        Info[3]=" ";
                    } else if(jobName=="Mage") {
                        Info[2]="Dengan tongkatku ini..";
                        Info[3]=" ";
                    } else if(jobName=="Sage") {
                        Info[2]="Dengan gadaku ini..";
                        Info[3]=" ";
                    } else if(jobName=="Warrior") {
                        Info[2]="Dengan panahku ini..";
                        Info[3]=" ";
                    } else {
                        Info[2]="Dengan xxxku ini..";
                        Info[3]=" ";
                    }
                    break;
                }
                case 2 : {
                    Info[2]="Yang memberontak dari perintahmu";
                    Info[3]=" ";
                    break;
                }
                case 3 : {
                    Info[2]="untuk melindungi tanah ini";
                    Info[3]=" ";
                    break;
                }
                case 4 : {
                    if(jobName=="Archer") {
                        Info[2]="Rasakan panahku menembus dadamu..";
                        Info[3]=" ";
                    } else if(jobName=="Assassin") {
                        Info[2]="Rasakan perihnya racun kematian ini..";
                        Info[3]=" ";
                    } else if(jobName=="Knight") {
                        Info[2]="Rasakan ujung tombak kematianku..";
                        Info[3]=" ";
                    } else if(jobName=="Mage") {
                        Info[2]="Rasakan tongkatku menghentikan nadimu";
                        Info[3]=" ";
                    } else if(jobName=="Sage") {
                        Info[2]="Rasakan gada suci membelah jiwa kotormu..";
                        Info[3]=" ";
                    } else if(jobName=="Warrior") {
                        Info[2]="Rasakan pedangku menyayat jiwamu..";
                        Info[3]=" ";
                    } else {
                        Info[2]="Rasakan xxx";
                        Info[3]=" ";
                    }
                    break;
                }
                case 5 : {
                    if(jobName=="Archer") {
                        Info[2]="HUJAN SERIBU PANAH!!";
                        Info[3]=" ";
                    } else if(jobName=="Assassin") {
                        Info[2]="SAYATAN RACUN KEMATIAN";
                        Info[3]=" ";
                    } else if(jobName=="Knight") {
                        Info[2]="DENTUMAN TOMBAK SAKTI";
                        Info[3]=" ";
                    } else if(jobName=="Mage") {
                        Info[2]="ROH PEMAKAN JIWA!!";
                        Info[3]=" ";
                    } else if(jobName=="Sage") {
                        Info[2]="SINAR GADA SUCI..";
                        Info[3]=" ";
                    } else if(jobName=="Warrior") {
                        Info[2]="AMARAH PEDANG IBLIS..";
                        Info[3]=" ";
                    } else {
                        Info[2]="CIATTTT";
                        Info[3]=" ";
                    }
                    break;
                }
                default : {
                    break;
                }
            }
            Info[4]="";
        }
        
	int Display::Min2(int a, int b) {
		int min;
		if(a<=b) {
			min = a;
		} else
		{
			min = b;
		}
		return min;
	}

	int Display::MinAround(int x, int y) {
		int Minimum;
		if (x-1<0 && y-1<0) {
			Minimum = Min2(MapArea[x][y+1],MapArea[x+1][y]);
		} else
		if(x-1<0) {
			Minimum = Min2(Min2(MapArea[x][y-1],MapArea[x][y+1]), MapArea[x+1][y]);
		} else
		if(y-1<0) {
			Minimum = Min2(MapArea[x][y+1], Min2(MapArea[x-1][y],MapArea[x+1][y]));
		} else if(x>=DunnoTactic::M.GetSizeX() && y>=DunnoTactic::M.GetSizeY()) {
                    Minimum = Min2(MapArea[x-1][y],MapArea[x][y-1]);
                } else if(x>=DunnoTactic::M.GetSizeX()) {
                    Minimum = Min2(Min2(MapArea[x][y+1],MapArea[x][y-1]),MapArea[x-1][y]);
                } else if(y>=DunnoTactic::M.GetSizeY()) {
                    Minimum = Min2(Min2(MapArea[x-1][y],MapArea[x+1][y]),MapArea[x][y-1]);
                }
                else {
			Minimum = Min2(Min2(MapArea[x][y-1],MapArea[x][y+1]), Min2(MapArea[x-1][y],MapArea[x+1][y]));
		}
		return Minimum;
	}
	
	bool Display::IsTree(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==4);
	}
	
	bool Display::IsWater(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==2);
	}
	
	bool Display::IsLumpur(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==3);
	}
	
	int Display::IdPlayer(int x, int y) {
		int id;
		if(MapPlayer[x][y]>100 && MapPlayer[x][y]<=500) {
			id=1;
		} else if(MapPlayer[x][y]>500) {
			id=2;
		} else {
			id=0;
		}
		return id;
	}
	
	bool Display::IsFriend(int x1, int y1, int x2, int y2) {
		return (IdPlayer(x1,y1)==IdPlayer(x2,y2));
	}

        
