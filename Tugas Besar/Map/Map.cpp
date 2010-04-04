/* 
 * File:   Map.cpp
 * Author: rezanachmad
 * 
 * Created on April 4, 2010, 1:43 PM
 */

#include "Map.h"
#include <fstream>
#include <vector>
#include <stdlib.h>

Map::Map()
{
    SizeX=default_size;
    SizeY=default_size;

    for(int i=0;i<SizeX;++i)
    {
        for (int j=0;j<SizeY;++j)
        {
            Terrain[i][j]=1;
        }
    }
}

Map::Map(const Map& orig) {
}

Map::~Map() {
}

void Map::CreateMap(const int& X, const int& Y)
{
    SizeX = X;
    SizeY = Y;

    for(int i=0;i<SizeX;++i)
    {
        for (int j=0;j<SizeY;++j)
        {
            Terrain[i][j]=1;
        }
    }
}

void Map::Save(string s)
{
    string NameFile,ExtFile,Folder;
    ExtFile=".map";
    Folder ="Data/";

    NameFile = Folder+s+ExtFile;
    ofstream outputfile(NameFile.c_str());

    outputfile << SizeX << " " << SizeY<< " #"<<endl;
    for(int i=0;i<SizeX;++i)
    {
        for (int j=0;j<SizeY;++j)
        {
            outputfile<<i+1<<" "<<j+1 <<" "<< Terrain[i][j]<<endl;
        }
    }

    outputfile.close();
}

void Map::Load(string sin)
{
    vector<string> vectortemp;
    int j;

    string NameFile,ExtFile,Folder;
    ExtFile=".map";
    Folder="Data/";
    NameFile = Folder+sin+ExtFile;
    //NameFile.append(sin,0,sin.length());
    //NameFile.append(ExtFile,0,ExtFile.length());
    ifstream fin (NameFile.c_str());
    
    string s;
    while (fin >> s)
    {
        vectortemp.push_back(s);
    }

    SizeX=atoi(vectortemp[0].c_str());
    SizeY=atoi(vectortemp[1].c_str());

    //cout <<vectortemp.size();
    int e = 0;
    for (int i=3;i<vectortemp.size();i=i+3)
    {
        Terrain[atoi(vectortemp[i].c_str())-1][atoi(vectortemp[i+1].c_str())-1]=atoi(vectortemp[i+2].c_str());
    }

    fin.close();
}

void Map::SetTerrainXY(int X, int Y, int GridContent)
{
    if (X<=SizeX && Y<=SizeY)
    {
        Terrain[X-1][Y-1]=GridContent;
    }
    else
    {
        throw "Error dalam mengeset isi terrain";
    }
}

void Map::SetTerrainArea(int X1, int Y1,int X2,int Y2, int GridContent)
{
    for (int i=X1;i<=X2;++i)
    {
        for (int j=Y1;j<=Y2;++j)
        {
            Terrain[i-1][j-1]=GridContent;
        }
    }
}

void Map::SetMapRandom()
{
    srand(time(NULL));
    for(int i = 0; i < SizeX; ++i )
    {
        for (int j=0; j< SizeY; ++j)
        {
            int k = rand()%4 + 1;
            Terrain[i][j] = k;
        }
    }
}

void Map::GetTerrain(int X, int Y)
{
    if (X>SizeX || Y>SizeY || Y<1 || X<1)
    {
        throw "X Y nya salah oi, diluar jangkauan tau!";
    }
    else
    {
        return Terrain[X-1][Y-1];
    }
}