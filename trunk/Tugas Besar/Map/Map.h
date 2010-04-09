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
    static const int default_size = 30; //Ukuran dari map dibuat default yaitu 30x30
    Map(); //constructor default Map
    Map (const Map&); //Copy Constructor Map
    virtual ~Map();//Destructor Map

    void CreateMap(const int& X, const int& Y); // Method yang digunakan untuk merekonstruksi ulang Map
    void Load(string sin); // Method yang digunakan untuk meload file .map
    void Save(string s); // Method yang digunakan untuk menyimpan map
    void SetTerrainXY(int X,int Y, string GridContent); // Method yang digunakan untuk mengeset isi terrain
    void SetTerrainArea(int X1,int Y1,int X2,int Y2, string GridContent); // Method yang digunakan untuk mengeset isi terrain dari suatu area
    void SetMapRandom(); // Method yang digunakan untuk mengeset terrain dari map secara random
    int GetTerrain(int X, int Y); // Method yang digunakan untuk mendapatkan isi suatu terrain dari suatu koordinat map
    int GetSizeX(); // Method yang digunakan untuk mendapatkan SizeX dari Map
    int GetSizeY(); // Method yang digunakan untuk mendapatkan SizeY dari Map

private :
    int SizeX; // Ukuran X dari Map yang efektif terpakai
    int SizeY; // Ukuran Y dari Map yang efektif terpakai
    int Terrain[default_size][default_size]; // Matriks dari terrain yang digunakan untuk menyimpan isi dari terrain
};

#endif	/* _MAP_H */

