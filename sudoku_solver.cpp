#include <iostream>

using namespace std;

bool kitoltve(int matrix[][9]){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(matrix[i][j]==0)
                return 0;
    return 1;
}

void kiir(int matrix[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<matrix[i][j]<<" ";
            cout<<"\n";
    }
}

bool sorba_irhato(int sor, int ertek, int matrix[][9]){
    for(int i=0;i<9;i++)
        if(matrix[sor][i]==ertek)
            return 0;
    return 1;
}

bool oszlopba_irhato(int oszlop, int ertek, int matrix[][9]){
    for(int i=0;i<9;i++)
        if(matrix[i][oszlop]==ertek)
            return 0;
    return 1;
}

bool kismatrixba_irhato(int sor, int oszlop, int ertek, int matrix[][9]){
    int bal_felso_i = sor/3*3;
    int bal_felso_j = oszlop/3*3;
    int i,j;
    for(i=bal_felso_i; i<bal_felso_i+3; i++)
        for(j=bal_felso_j; j<bal_felso_j+3; j++)
            if(matrix[i][j]==ertek)
                return 0;
    return 1;
}

bool meghivo(int sor, int oszlop, int ertek, int matrix[][9]){
    return (sorba_irhato(sor,ertek,matrix) && oszlopba_irhato(oszlop,ertek,matrix) && kismatrixba_irhato(sor,oszlop,ertek,matrix));
}

int szamlalo(int sor,int oszlop,int matrix[][9]){
    int db=0;
    for(int i=1;i<=9;i++)
    db+=meghivo(sor,oszlop,i,matrix);
    return db;
}

bool kitolt(int matrix[][9]){
    if(kitoltve(matrix)){
        cout<<"Egy megoldas:\n";
        kiir(matrix);
        return 1;
    }
    int i,j;
    int minim = 10,sor,oszlop;
    bool lv=false;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            if(matrix[i][j]==0){
                cout<<"Nulla: "<<i<<" "<<j<<" "<<szamlalo(i,j,matrix)<<"kulonfele ertek adhato\n";
                if(minim==10 || szamlalo(i,j,matrix)<minim){
                    minim=szamlalo(i,j,matrix);
                    sor=i;
                    oszlop=j;
                }
            }

    if(minim == 10 || minim == 0)
        return 0;
    for(i=1;i<=9;i++){
        if(meghivo(sor,oszlop,i,matrix)){
            matrix[sor][oszlop] = i;
            lv |= kitolt(matrix);
            matrix[sor][oszlop] = 0;
        }
    }
    //kiir(matrix);
    return lv;

}

int main()
{
    char a;
    int m[9][9],i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++){
            cin>>a;
            m[i][j]=a-'0';
        }
    kiir(m);
    if(!kitolt(m))
        cout<<"nincs megoldas";
    return 0;
}
