#ifndef FUNC_PICS_H
#define FUNC_PICS_H
#include <math.h>

double CalcularRo(double miu,double landa)
{
    double respuestaRo = landa/ miu;
    return respuestaRo;
}
double CalcularPo(double miu,double landa)
{
    double respuestaPo = 1-CalcularRo(miu,landa);
    return respuestaPo;
}
double CalcularPn(double miu,double landa,double n)
{
    double respuestaPn = CalcularPo(miu,landa)*pow((CalcularRo(miu,landa)),n);
    return respuestaPn;
}
double CalcularL(double miu,double landa)
{
    double respuestaL = landa / (miu - landa);
    return respuestaL;
}
double CalcularLq(double miu,double landa)
{
    double respuestaLq = pow(landa, 2) / (miu*(miu - landa));
    return respuestaLq;
}
double CalcularLn(double miu,double landa)
{
    double respuestaLn = landa / (miu - landa);
    return respuestaLn;
}
double CalcularW(double miu,double landa)
{
    double respuestaW = 1 /  (miu - landa);
    return respuestaW;
}
double CalcularWq(double miu,double landa)
{
    double respuestaWq = landa / (miu*(miu - landa));
    return respuestaWq;
}
double CalcularWn(double miu,double landa)
{
    double respuestaWn = 1 / (miu - landa);
    return respuestaWn;
}
double ComprobarHorasEsCero(double horas)
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
double CalcularCtte(double miu,double landa,double horas,double cte)
{
    horas=ComprobarHorasEsCero(horas);
    double respuestaCtte=(landa*horas*CalcularWq(miu,landa)*cte);
    return respuestaCtte;
}
double CalcularCtts(double miu,double landa,double horas,double cts)
{
    horas=ComprobarHorasEsCero(horas);
    double respuestaCtts=(landa*horas*CalcularW(miu,landa)*cts);
    return respuestaCtts;
}
double CalcularCttse(double miu,double landa,double horas,double ctse)
{
    horas=ComprobarHorasEsCero(horas);
    double respuestaCttse=(landa*horas*CalcularW(miu,landa)*ctse);
    return respuestaCttse;
}
double CalcularCTs(double cs)
{
    double respuestaCts=cs;
    return respuestaCts;
}
double CalcularCT(double miu,double landa,double horas,double cte,double cts,double ctse,double cs)
{
    horas=ComprobarHorasEsCero(horas);
    double respuestaCt=CalcularCtte(miu,landa,horas,cte)+CalcularCtts(miu,landa,horas,cts)+CalcularCttse(miu,landa,horas,ctse)+CalcularCTs(cs);
    return respuestaCt;
}
#endif // FUNC_PICS_H
