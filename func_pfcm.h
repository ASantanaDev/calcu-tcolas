#ifndef FUNC_PFCM_H
#define FUNC_PFCM_H
#include "math.h"
double Factorial3(double a)
{
    double b = 1;

    for (double num = a; num >= 1; num--)
    {
        b *= num;
    }
    return b;
}
double CalcularPo3(double miu,double landa, double M, double K)
{
    double sumatoria1 = 0;
    double sumatoria2 = 0;
    // primera parte

    for (int n = 0; n <= (K-1); n++)
    {
        double respuesta1 = (Factorial3(M) / (Factorial3(M - n)*Factorial3(n))) * pow((landa / miu), n);
        sumatoria1 = sumatoria1 + respuesta1;
    }

    // segunda parte
    for (int n = K ; n <= M; n++)
    {
        double respuesta2 = (Factorial3(M) / (Factorial3(M - n) * Factorial3(K) *(pow(K,(n-K))))) * pow((landa / miu), n);
        sumatoria2 = sumatoria2 + respuesta2;
    }
    double respuestaPo = 1 / (sumatoria1+sumatoria2);
    return respuestaPo;
}
double CalcularPn3(double miu,double landa, double M, double K,double N)
{
    double respuestaPn = 0;
    if (N >= 0 && N <= K)
    {
        respuestaPn  = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - N) * Factorial3(N))) * pow((landa / miu), N);
    }
    else
    {
        respuestaPn = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - N) * Factorial3(K) * (pow(K, (N - K))))) * pow((landa / miu), N);
    }
    return respuestaPn;
}
double CalcularL3(double miu,double landa, double M, double K)
{
    double sumatoriaL1 = 0;
    double sumatoriaL2 = 0;
    double sumatoriaL3 = 0;
    double respuestaL = 0;
    for (int n=0; n<= (K-1); n++)
    {
        double PnL1= CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - n) * Factorial3(n))) * pow((landa / miu), n);
        double respuestaL1 = n * PnL1;
        sumatoriaL1 = sumatoriaL1 + respuestaL1;
    }

    for (int n = K; n <= M; n++)
    {
        double PnL2 = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - n) * Factorial3(K) * (pow(K, (n - K))))) * pow((landa / miu), n);
        double respuestaL2 = (n - K) * PnL2;
        sumatoriaL2 = sumatoriaL2 + respuestaL2;
    }



    for (int n=0; n<=(K-1); n++)
    {
        double PnL3 = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - n) * Factorial3(n))) * pow((landa / miu), n);
        sumatoriaL3 = sumatoriaL3 + PnL3;
    }

    respuestaL = sumatoriaL1 + sumatoriaL2 + (K * (1 - sumatoriaL3));
    return respuestaL;

}
double CalcularLq3(double miu,double landa, double M, double K)
{
    double respuestaLq=0;
    double sumatoriaL2 = 0;
    for (int n = K; n <= M; n++)
    {
        double PnL2 = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - n) * Factorial3(K) * (pow(K, (n - K))))) * pow((landa / miu), n);
        double respuestaL2 = (n - K) * PnL2;
        sumatoriaL2 = sumatoriaL2 + respuestaL2;
    }
    respuestaLq = sumatoriaL2;
    return respuestaLq;
}
double CalcularPe3(double miu,double landa, double M, double K)
{
    double respuestaPe=0;
    for (int n = K; n <= M; n++)
    {
        double Pe = CalcularPo3(miu,landa,M,K) * (Factorial3(M) / (Factorial3(M - n) * Factorial3(K) * (pow(K, (n - K))))) * pow((landa / miu), n);
        respuestaPe = respuestaPe + Pe;

    }
    return respuestaPe;
}
double CalcularLn3(double miu,double landa, double M, double K)
{
    double respuestaLn = CalcularLq3(miu,landa,M,K) / CalcularPe3(miu,landa,M,K);
    return respuestaLn;
}
double CalcularWq3(double miu,double landa, double M, double K)
{
    double Lq=CalcularLq3(miu,landa,M,K);
    double L=CalcularL3(miu,landa,M,K);
    double respuestaWq = Lq/((M-L)*landa);
    return respuestaWq;
}
double CalcularW3(double miu,double landa, double M, double K)
{
    double respuestaW = CalcularWq3(miu,landa,M,K)+(1/miu);
    return respuestaW;
}
double CalcularWn3(double miu,double landa, double M, double K)
{
    double respuestaWn =  CalcularWq3(miu,landa,M,K)/ CalcularPe3(miu,landa,M,K);
    return respuestaWn;
}
double ComprobarHorasEsCero3(double horas)
{
    double respuesta=0;
    if(horas==0)
    {
        respuesta=1;
    }
    else {
        respuesta=horas;
    }
    return respuesta;
}
double CalcularCtte3(double miu,double landa,double m,double k,double horas,double cte)
{
    horas=ComprobarHorasEsCero3(horas);
    double respuestaCtte=(landa*horas*CalcularWq3(miu,landa,m,k)*cte);
    return respuestaCtte;
}
double CalcularCtts3(double miu,double landa,double m,double k,double horas,double cts)
{
    horas=ComprobarHorasEsCero3(horas);
    double respuestaCtts=(landa*horas*CalcularW3(miu,landa,m,k)*cts);
    return respuestaCtts;
}
double CalcularCttse3(double miu,double landa,double m,double k,double horas,double ctse)
{
    horas=ComprobarHorasEsCero3(horas);
    double respuestaCttse=(landa*horas*CalcularW3(miu,landa,m,k)*ctse);
    return respuestaCttse;
}
double CalcularCTs3(double k,double cs)
{
    double respuestaCts=k*cs;
    return respuestaCts;
}
double CalcularCT3(double miu,double landa,double M,double K,double horas,double cte,double cts,double ctse,double cs)
{
    horas=ComprobarHorasEsCero3(horas);
    double respuestaCt=CalcularCtte3(miu,landa,M,K,horas,cte)+CalcularCtts3(miu,landa,M,K,horas,cts)+CalcularCttse3(miu,landa,M,K,horas,ctse)+CalcularCTs3(K,cs);
    return respuestaCt;
}
#endif // FUNC_PFCM_H
