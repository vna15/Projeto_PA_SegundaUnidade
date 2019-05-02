#include <iostream>
#include <fstream>
#include "voxel_sculptor.h"

using namespace std;

Sculptor::Sculptor(int nx, int ny, int nz){
    if(nx<=0 || ny<=0 || nz<=0){
        nx = 0;
        ny = 0;
        nz = 0;
    }

    v = new Voxel**[nx];
    if(v == nullptr){
        cout << "Erro na alocação das linhas do Voxel" << endl;
        exit(0);
    }
    v[0] = new Voxel*[nx*ny];
    if(v[0] == nullptr){
        cout << "Erro na alocação das colunas do Voxel" << endl;
        exit(0);
    }
    v[0][0] = new Voxel[nx*ny*nz];
    if(v[0][0] == nullptr){
        cout << "Erro na alocação dos planos do Voxel" << endl;
        exit(0);
    }

    for(int i=0;i<nx;i++){
        v[i] = v[i] + ny;
    }
    for(int i=0;i<nx*ny;i++){
        for(int j=0;j<nx*ny;j++){
            v[i][j] = v[i][j] + ny;
        }
    }
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                v[i][j][k].isOn = false;
            }
        }
    }
}

Sculptor::~Sculptor(){
    if(nx<=0 || ny<=0 || nz<=0){
        return;
    }
    delete v[0][0];
    delete v[0];
    delete v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    if(r>1){
        r = 1;
    }
    else if(r<0){
        r = 0;
    }
    if(g>1){
        g = 1;
    }
    else if(g<0){
        g = 0;
    }
    if(b>1){
        b = 1;
    }
    else if(b<0){
        b = 0;
    }
    if(alpha>1){
        alpha = 1;
    }
    else if(alpha<0){
        alpha = 0;
    }
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}


