/* 
 * File:   Map.h
 * Author: rezanachmad
 *
 * Created on April 4, 2010, 1:43 PM
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
    Map (int,int); //Constructor dengan ukuran masukan dari user
    Map (const Map&); //Copy Constructor
    virtual ~Map();//Destructor

    void Load(string);
    void Save(string);
    void SetTerrainXY(int,int,int);
    void SetTerrainArea(int,int,int,int,int);
    void SetMapRandom();

private :
    int SizeX;
    int SizeY;
    int Terrain[default_size][default_size];
};

#endif	/* _MAP_H */

