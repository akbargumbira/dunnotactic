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
		MapPlayer[1][1]=12;
		MapPlayer[0][0]=23;
		MapPlayer[4][4]=25;
		MapPlayer[4][5]=28;
		MapPlayer[1][4]=15;
		MapPlayer[7][4]=17;
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
// Display Box Turn
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
	void Display::displayBoxMap(int P, int L) {
		string H1 = "+===+";
		string H2 = "=====+";
		string V1 = "     |";
		string Rumput = "     |";
		string Pohon = " ??? |";
		string Lumpur = " ... |";
		string Air = " ~~~ |";
		string Area = " aaa |";
		string Player1 = " -1- |";
		string Player2 = " P-2 |";
		int i;
		int j;
		int k;
		
		// menampilkan indeks teratas
		// menampilkan garis horizontal teratas
		cout << "     +";
		for(i=0;i<P;++i) {
			cout << H2;
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
		
		// menampilkan box di bawah indeks teratas
		for(j=1;j<=L;++j) {
			// menampilkan garis horizontal
			cout << "+====+";
			for(i=1;i<=P;++i) {
				cout << H2;
			}
			cout << endl;
			
			// menampilkan garis vertikal 1 (atas)
			cout << "|    |";
			for(i=1;i<=P;++i) {
				cout << V1;
			}
			cout << endl;
			
			// menampilkan garis vertikal 2 (tengah)
			if(j<10) {
				cout << "| " << j << "  |";
			}
			else {
				cout << "| " << j << " |";
			}
			for(i=1;i<=P;++i) {
				if(MapPlayer[i-1][j-1]!=0) {
					if(IdPlayer(i-1,j-1)==1) {
						cout << Player1;
					} else {
						cout << Player2;
					}
				}
				// else 
				// if(MapArea[i-1][j-1]!=99) {
					// cout << Area;
				// }
				else {
					switch(DunnoTactic::M.GetTerrain(i,j)) {
						case 1: {
							cout << Rumput;
							break;
						}
						case 2: {
							cout << Pohon;
							break;
						}
						case 3: {
							cout << Lumpur;
							break;
						}
						case 4: {
							cout << Air;
							break;
						}
						default: {
							cout << V1;
							break;
						}
					}
				}
			}
			cout << endl;
			
			// menampilkan garis vertikal 3 (bawah)
			cout << "|    |";
			for(i=1;i<=P;++i) {
				cout << V1;
			}
			cout << endl;
		}

		// menampilkan garis horizontal terbawah (penutup)
		cout << "+====+";
		for(i=1;i<=P;++i) {
			cout << H2;
		}
                cout << endl;
	}

// Display box Info
	void Display::displayBoxInfo() {
		int i;
		int j;
		int lengthBox = 40;
		string Blank = "     ";
		cout << Blank;
		for(i=1;i<=lengthBox;++i) {
			cout << "/";
		}
		for(j=1;j<=9;++j) {
			cout << endl;
			cout << Blank << "/";
			for(i=1;i<=lengthBox-2;++i) {
				cout << " ";
			}
			cout << "/";
		}
		cout << endl;
		cout << Blank;
		for(i=1;i<=lengthBox;++i) {
			cout << "/";
		}
	}

// Set Area
	void Display::setArea(int initX, int initY, int range) {
		
		int factorX;
		int factorY;
		int x;
		int y;
		
		int i;
		int j;
		
		if(IsLumpur(initX-1,initY-1)) {
			MapArea[initX-1][initY-1]=1;
		} else {
			MapArea[initX-1][initY-1]=0;
		}
		// inisialisasi asumsi jarak
		for(i=1;i<=range;++i) {
			// Kuadran 1 dan 3
			factorY=-i;
			for(factorX=0;factorX<i;++factorX) {
				// kuadran 1
				x = initX+factorX-1;
				y = initY+factorY-1;
				if(PassTerrain(x+1,y+1) && PassPlayer(initX-1,initY-1,x,y)) {
					MapArea[x][y]=i;
				}
				// kuadran 3
				x = initX-factorX-1;
				y = initY-factorY-1;
				if(PassTerrain(x+1,y+1) && PassPlayer(initX-1,initY-1,x,y)) {
					MapArea[x][y]=i;
				}
				++factorY;
			}
			// Kuadran 2 dan 4
			factorX=i;
			for(factorY=0;factorY<i;++factorY) {
				// kuadran 4
				x = initX+factorX-1;
				y = initY+factorY-1;
				if(PassTerrain(x,y) && PassPlayer(initX-1,initY-1,x,y)) {
					MapArea[x][y]=i;
				}
				// kuadran 2
				x = initX-factorX-1;
				y = initY-factorY-1;
				if(PassTerrain(x,y) && PassPlayer(initX-1,initY-1,x,y)) {
					MapArea[x][y]=i;
				}
				--factorX;
			}
		}
		
		// penghapusan daerah-daerah yang melebihi dari range move
		for(i=1;i<=range;++i) {
			// Kuadran 1 dan 3
			factorY=-i;
			for(factorX=0;factorX<i;++factorX) {
				// kuadran 1
				x = initX+factorX-1;
				y = initY+factorY-1;
				if(MapArea[x][y]!=99 && MinAround(x,y) < range) {
					if(IsLumpur(x,y)) {
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
				// kuadran 3
				x = initX-factorX-1;
				y = initY-factorY-1;
				if(MapArea[x][y]!=99 && MinAround(x,y) < range) {
					if(IsLumpur(x,y)) {
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
				++factorY;
			}
			// Kuadran 2 dan 4
			factorX=i;
			for(factorY=0;factorY<i;++factorY) {
				// kuadran 4
				x = initX+factorX-1;
				y = initY+factorY-1;
				if(MapArea[x][y]!=99 && MinAround(x,y) < range) {
					if(IsLumpur(x,y)) {
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
				// kuadran 2
				x = initX-factorX-1;
				y = initY-factorY-1;
				if(MapArea[x][y]!=99 && MinAround(x,y) < range) {
					if(IsLumpur(x,y)) {
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
				--factorX;
			}
		}
	}
	void Display::MoveAnimated(int initX, int initY, int targetX, int targetY) {
		int NbStep;
		int x;
		int y;
		setArea(initX,initY,4);
		x = targetX-1;
		y = targetY-1;
		NbStep = MapArea[x][y];
		
		int xSaved[NbStep];
		int ySaved[NbStep];
		int i;
		int Minimum;
		
		for(i=0;i<NbStep;++i) {
			Minimum = MinAround(x,y);
			if(MapArea[x][y-1]==Minimum) {
				xSaved[i]=x;
				ySaved[i]=y-1;
				y=y-1;
			} else
			if(MapArea[x+1][y]==Minimum) {
				xSaved[i]=x+1;
				ySaved[i]=y;
				x=x+1;
			} else
			if(MapArea[x][y+1]==Minimum) {
				xSaved[i]=x;
				ySaved[i]=y+1;
				y=y+1;
			} else {
				xSaved[i]=x-1;
				ySaved[i]=y;
				x=x-1;
			}
		}
		int preX;
		int preY;
		preX=initX-1;
		preY=initY-1;
		displayBoxMap(9,9);
		for(i=NbStep-2;i>=0;--i) {
			x=xSaved[i];
			y=ySaved[i];
			MapPlayer[x][y]=MapPlayer[preX][preY];
			MapPlayer[preX][preY]=0;
			preX=x;
			preY=y;
			sleep(1);
			system("clear");
			displayBoxMap(9,9);
		}
		sleep(1);
		system("clear");
		MapPlayer[targetX-1][targetY-1]=MapPlayer[preX][preY];
		MapPlayer[preX][preY]=0;
		displayBoxMap(9,9);
	}
	
// method-method yang private
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
		} else {
			Minimum = Min2(Min2(MapArea[x][y-1],MapArea[x][y+1]), Min2(MapArea[x-1][y],MapArea[x+1][y]));
		}
		return Minimum;
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
	
	bool Display::IsTree(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==2);
	}
	
	bool Display::IsWater(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==4);
	}
	
	bool Display::IsLumpur(int x, int y) {
		return (DunnoTactic::M.GetTerrain(x,y)==3);
	}
	
	int Display::IdPlayer(int x, int y) {
		int id;
		if(MapPlayer[x][y]<20 && MapPlayer[x][y]!=0) {
			id=1;
		} else if(MapPlayer[x][y]>=20) {
			id=2;
		} else {
			id=0;
		}
		return id;
	}
	
	bool Display::IsFriend(int x1, int y1, int x2, int y2) {
		return (IdPlayer(x1,y1)==IdPlayer(x2,y2));
	}
