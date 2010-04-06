/* 
 * File:   Map.cpp
 * Author: Akbar Gumbira
 * 
 * Created on April 1, 2010, 1:43 PM
 */

#include "Map.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "../DunnoTactic.h"
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

Map::Map(const Map& orig)
{

}

Map::~Map()
{
    SizeX=0;
    SizeY=0;
}

void Map::CreateMap(const int& X, const int& Y)
{
    if (X<=30 && Y<=30 && X>=5 && Y>=5)
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
    else
    {
        throw "Error : Ukuran Map minimal adalah 5x5, ukuran Map maksimal adalah 30 x 30.";
    }
}

void Map::Save(string s)
{
    string NameFile,ExtFile,Folder;
    ExtFile=".map";
    Folder ="Data/";

    NameFile = Folder+s+ExtFile;
    ofstream outputfile(NameFile.c_str());

    outputfile << SizeX << " " << SizeY<< " " << SizeX*SizeY<<endl;
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
    ifstream fin (NameFile.c_str());

    if (fin==false)
    {
      throw "Error : Nama File tidak ditemukan.";

    }

    string s;
    while (fin >> s)
    {
        if (DunnoTactic::IsInteger(s))
        {
            vectortemp.push_back(s);
        }
        else
        {
            throw "Error : File yang Anda load sudah rusak.";
        }
        
    }

    int TotalGrid;
    SizeX=atoi(vectortemp[0].c_str());
    SizeY=atoi(vectortemp[1].c_str());
    TotalGrid = atoi(vectortemp[2].c_str());

    if ((vectortemp.size()!=3*(TotalGrid+1)) || (SizeX*SizeY!= TotalGrid))
    {
        SizeX=default_size;
        SizeY=default_size;
        throw "Error : File yang Anda load sudah rusak.";
    }
    else
    {
        for (int i=3;i<vectortemp.size();i=i+3)
        {
            Terrain[atoi(vectortemp[i].c_str())-1][atoi(vectortemp[i+1].c_str())-1]=atoi(vectortemp[i+2].c_str());
        }
    }
    fin.close();
}

void Map::SetTerrainXY(int X, int Y, string GridContent)
{
    int GridContentConvert;
    
    if (GridContent=="rumput")
    {
        GridContentConvert = 1;
    }
    else if (GridContent == "air")
    {
        GridContentConvert = 2;
    }
    else if (GridContent == "lumpur")
    {
        GridContentConvert = 3;
    }
    else if (GridContent == "pohon")
    {
        GridContentConvert = 4;
    }
    else
    {
        throw "Error : Daerah Terrain yang tersedia adalah rumput, air, lumpur, dan pohon.";
    }


    if (X<=SizeX && Y<=SizeY && X>=1 && Y>=1)
    {
        Terrain[X-1][Y-1]=GridContentConvert;
    }
    else  //(X>SizeX || Y>SizeY || X<1 || Y<1 )
    {
        throw "Error : Koordinat Map yang Anda masukkan tidak sesuai.";
    }
}

void Map::SetTerrainArea(int X1, int Y1,int X2,int Y2, string GridContent)
{
    int GridContentConvert;
    int XTemp1, XTemp2, YTemp1, YTemp2;

    if (GridContent=="rumput")
    {
        GridContentConvert = 1;
    }
    else if (GridContent == "air")
    {
        GridContentConvert = 2;
    }
    else if (GridContent == "lumpur")
    {
        GridContentConvert = 3;
    }
    else if (GridContent == "pohon")
    {
        GridContentConvert = 4;
    }
    else
    {
        throw "Error : Daerah Terrain yang tersedia adalah rumput, air, lumpur, dan pohon.";
    }

    if (X1<=X2)
    {
        if (Y1<=Y2)
        {
            XTemp1=X1;
            YTemp1=Y1;
            XTemp2=X2;
            YTemp2=Y2;
        }
        else
        {
            XTemp1=X1;
            YTemp1=Y2;
            XTemp2=X2;
            YTemp2=Y1;
        }
    }
    else
    {
        if (Y1<=Y2)
        {
            XTemp1=X2;
            YTemp1=Y1;
            XTemp2=X1;
            YTemp2=Y2;
        }
        else
        {
            XTemp1=X2;
            YTemp1=Y2;
            XTemp2=X1;
            YTemp2=Y1;
        }
    }

    if (XTemp2<=SizeX && YTemp2<=SizeY && XTemp1>=1 && YTemp1>=1)
    {
        for (int i=XTemp1;i<=XTemp2;++i)
        {
            for (int j=YTemp1;j<=YTemp2;++j)
            {
                Terrain[i-1][j-1]=GridContentConvert;
            }
        }
    }
    else
    {
        throw "Error : Koordinat Map yang Anda masukkan tidak sesuai.";
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

int Map::GetTerrain(int X, int Y)
{
    if (X>SizeX || Y>SizeY || Y<1 || X<1)
    {
        throw "Error : Koordinat yang Anda masukkan tidak sesuai.";
    }
    else
    {
        return Terrain[X-1][Y-1];
    }
}

int Map::GetSizeX()
{
    return SizeX;
}

int Map::GetSizeY()
{
    return SizeY;
}