#ifndef FUNC_PFCS_H
#define FUNC_PFCS_H
#include <math.h>
double Factorial2(double a)
{
    double b = 1;

    for (double num = a; num >= 1; num--)
    {
        b *= num;
    }
    return b;
}
double CalcularPo2(double miu,double landa,double M)
{
    double sumatoria = 0;

    for (int n = 0; n <= M; n++)
    {
        double respuesta = (Factorial2(M) / Factorial2(M - n)) * pow((landa / miu), n);
        sumatoria = sumatoria + respuesta;
    }

    double respuestaPo = 1 / sumatoria;
    return respuestaPo;
}
double CalcularPn2(double miu,double landa,double M,double N)
{
    double respuestaPn = (Factorial2(M) / Factorial2(M - N)) * pow((landa / miu), N) * CalcularPo2(miu,landa,M);
    return respuestaPn;
}
double CalcularL2(double miu,double landa,double M)
{
    double respuestaL = M-(miu/landa)*(1-CalcularPo2(miu,landa,M));
    return respuestaL;
}
double CalcularLq2(double miu,double landa,double M)
{
    double respuestaLq = M - ((landa+miu) / landa) * (1 - CalcularPo2(miu,landa,M));
    return respuestaLq;
}
double CalcularLn2(double miu,double landa,double M)
{
    double respuestaLn = CalcularLq2(miu,landa,M) / (1-CalcularPo2(miu,landa,M));
    return respuestaLn;
}
double CalcularWq2(double miu,double landa,double M)
{
    double Lq=CalcularLq2(miu,landa,M);
    double L=CalcularL2(miu,landa,M);
    double respuestaWq = Lq/((M-L)*landa);
    return respuestaWq;
}
double CalcularW2(double miu,double landa,double M)
{
    double respuestaW = CalcularWq2(miu,landa,M) + (1/miu);
    return respuestaW;
}

double CalcularWn2(double miu,double landa,double M)
{
    double respuestaWn = CalcularWq2(miu,landa,M) / (1 - CalcularPo2(miu,landa,M));
    return respuestaWn;
}
double ComprobarHorasEsCero2(double horas)
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
double CalcularCtte2(double miu,double landa,double M,double horas,double cte)
{
    horas=ComprobarHorasEsCero2(horas);
    double respuestaCtte=(landa*horas*CalcularWq2(miu,landa,M)*cte);
    return respuestaCtte;
}
double CalcularCtts2(double miu,double landa,double M,double horas,double cts)
{
    horas=ComprobarHorasEsCero2(horas);
    double respuestaCtts=(landa*horas*CalcularW2(miu,landa,M)*cts);
    return respuestaCtts;
}
double CalcularCttse2(double miu,double landa,double M,double horas,double ctse)
{
    horas=ComprobarHorasEsCero2(horas);
    double respuestaCttse=(landa*horas*CalcularW2(miu,landa,M)*ctse);
    return respuestaCttse;
}
double CalcularCTs2(double cs)
{
    double respuestaCts=1*cs;
    return respuestaCts;
}
double CalcularCT2(double miu,double landa,double M,double horas,double cte,double cts,double ctse,double cs)
{
    horas=ComprobarHorasEsCero2(horas);
    double respuestaCt=CalcularCtte2(miu,landa,M,horas,cte)+CalcularCtts2(miu,landa,M,horas,cts)+CalcularCttse2(miu,landa,M,horas,ctse)+CalcularCTs2(cs);
    return respuestaCt;
}
#endif // FUNC_PFCS_H
