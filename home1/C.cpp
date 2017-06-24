#include <cmath>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <iostream>


int main() {
    
    const double max=1.79769e+308;;
    
    double number;
    double x,y;
    
    //положительные
    double pmax=-max;
    double pmin=max;
    
    //отрицательные
    
    double omax=-max;
    double omin=0;
    
    double oymax=0;
    double pymax=0;
    
    double s=0; //площадь
    //вспомогательные площади
    double s1=0;
    double s2=0;
    scanf("%lf", &number);
    
    for (double i=0;i<number;i++){
        scanf("%lf",&x);
        scanf("%lf",&y);
        if (y==0){
            if (x>0){
                pmax=x>pmax ? x:pmax;
                pmin=x<pmin ? x:pmin;
            }
            if (x<0){
                
                omax=x>omax ? x:omax;
                omin=x<omin ? x:omin;
            }
        }
        else{
            if (x>0){
            y=abs(y);
            pymax=y>pymax ? y:pymax;
            }
            if (x<0){
                y=abs(y);
                oymax=y>oymax ? y:oymax;
                    }
        
            }
    };
    

    
    
    
    if ((pmax!=-max)&&(pmin!=max)&&(pmin!=pmax)&&(pymax!=0)) s1=0.5*(pmax-pmin)*pymax;
    if( (omax!=-max) && (omin!=0) &&(omin!=omax)&&(oymax!=0)) s2=0.5*(omax-omin)*oymax;
    
    if (s1!=0 || s2!=0){
        s=s1>s2 ? s1:s2;
        printf("%5.4lf\n",s);
    }
    else cout<<0;
    
    
    return 0;
}
