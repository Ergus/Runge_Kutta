#include <stdio.h>
#define ecs 2

typedef double (*eqs)(double K, double y, double s, double i);

//Equations in order s, i, r;
inline double f1(double B, double y, double s, double i){
    return -B*s*i;
    }

inline double f2(double B, double y, double s, double i){
    return B*s*i-y*i;
    }

int main(int argc, char** argv){
    
    eqs f[]={f1,f2};               // Funciones in order (s,i,r)

    double K1[ecs], K2[ecs];       // K constants and results
    double sir[ecs+1], sir2[ecs+1];// Solutions

    char vars[]="sir";             // Names of the variables

    const double B=0.24, y=0.08;   // Parametros
    double s=0.999,i=0.001;        // Condiciones Iniciales

    double tf=80.0, h=0.1;          // Time variables
    sir[0]=s; sir[1]=i; sir[2]=1.0-s-i;

    int cont=0;
    for(double t=0; t<=tf; ++cont, t=h*cont){        
        int it;
        for(it=0; it<ecs; ++it){    // Calculate K1
            K1[it]=f[it](B,y,sir[0],sir[1])*h;
            }
        
        for(it=0; it<ecs; ++it){    // Calculate K2
            K2[it]=f[it](B,y,sir[0]+K1[0],sir[1]+K1[1])*h;
            }

        for(it=0; it<ecs; ++it){    // s, i, r
            sir2[it]=sir[it]+(K1[it]+K2[it])*0.5;
            }

        //r+i+r=1
        sir2[2]=1-sir2[0]-sir2[1];
        
        printf("t: %lf\t",t);        
        for(it=0; it<(ecs+1); ++it){// Copy and print results
            sir[it]=sir2[it];
            printf("%c: %lf\t",vars[it],sir2[it]);
            }        
        printf("\n");
        }
    return 0;
    }
