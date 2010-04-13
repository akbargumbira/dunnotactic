#include <iostream>
#include "Map.h"
#include "../DunnoTactic.h"

using namespace std;

int main()
{
    string temp;
    try {
	Map CobaMap;
        CobaMap.CreateMap(8,8);
        CobaMap.SetTerrainXY(1,1,"lumpur");
        CobaMap.SetMapRandom();
        temp = "ganteng";
        CobaMap.Save(temp);
	CobaMap.Load(temp);
        CobaMap.SetTerrainArea(3,3,5,5,"rumput");
        temp = "ganteng1";
        CobaMap.Save(temp);
    }
    catch (const char * e)
    {
        cout << e << endl;
    }
}
