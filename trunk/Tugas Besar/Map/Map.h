/* 
 * File:   Map.h
 * Author: Akbar Gumbira
 *
 * Created on April 1, 2010, 1:43 PM
 */

#ifndef _MAP_H
#define	_MAP_H

#include <iostream>
using namespace std;

class Map
{
public :
    static const int default_size = 30;
    Map(); //constructor default
    Map (const Map&); //Copy Constructor
    virtual ~Map();//Destructor

    void CreateMap(const int& X, const int& Y); //udah pake throw
    void Load(string sin); //udah pake throw
    void Save(string s);
    void SetTerrainXY(int X,int Y, string GridContent); //udah pake throw
    void SetTerrainArea(int X1,int Y1,int X2,int Y2, string GridContent); //udah pake throw
    void SetMapRandom();
    int GetTerrain(int X, int Y);
    int GetSizeX();
    int GetSizeY();

private :
    int SizeX;
    int SizeY;
    int Terrain[default_size][default_size];
};

#endif	/* _MAP_H */

