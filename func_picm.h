#ifndef FUNC_PICM_H
#define FUNC_PICM_H
#include <math.h>
double Factorial1(double a)
{
    double b=1;
    for(double num=a;num>=1;num--)
    {
        b*=num;
    }
    return b;
}
double CalcularPo1(double miu,double landa,double k)
{
    double sumatoria=0;
    for(int ni=0;ni<=(k-1);ni++)
    {
        double factor=1/Factorial1(ni);
        double elevado = pow((landa/miu),ni);

        double respuesta = factor*elevado;
        sumatoria=sumatoria+respuesta;
    }

    double segundaparte = 0;
    segundaparte = (1/Factorial1(k))*(pow((landa/miu), (k))*((k*miu)/((k*miu)-landa)));
    double respuestaPo=1/(sumatoria+segundaparte);//Respuesta Po
    return respuestaPo;
}
double CalcularPk1(double miu,double landa,double k)
{
    double parteUno=(1 / Factorial1(k));
    double parteDos = pow((landa / miu), k);
    double parteTres = (k * miu) / ((k * miu) - landa);
    double respuestaPk = parteUno * parteDos * parteTres * CalcularPo1(miu,landa,k);//Respuesta Pk
    return respuestaPk;
}
double CalcularPne1(double miu,double landa,double k)
{
    double respuestaPne=1-CalcularPk1(miu,landa,k); //Respuesta Pne
    return respuestaPne;
}
double CalcularPn1(double miu,double landa,double k,double n)
{
    double respuestaPn=0;
    if (n <= k)
    {
        respuestaPn = (CalcularPo1(miu,landa,k)/ Factorial1(n)) * pow(((landa / miu)), n);
    }
    else if (n > k)
    {
        respuestaPn = (1 / (Factorial1(k) * (pow(k, (n - k)))) * pow((landa / miu), n)*CalcularPo1(miu,landa,k));
    }
    return respuestaPn;
}
double CalcularL1(double miu,double landa,double k)
{
    double arriba = (landa * miu) * pow((landa/miu),k);
    double abajo = Factorial1((k-1))*pow(((k*miu)-landa),2);
    double alado = landa / miu;

    double respuestaL = ((arriba/abajo) * CalcularPo1(miu,landa,k)) + alado; //Respuesta L
    return respuestaL;
}
double CalcularLq1(double miu,double landa,double k)
{
    double arribaLq = (landa * miu) * pow((landa / miu), k)*CalcularPo1(miu,landa,k);
    double abajoLq = Factorial1((k - 1)) * pow(((k * miu) - landa), 2);

    double respuestaLq = arribaLq / abajoLq; //Respuesta Lq
    return respuestaLq;
}
double CalcularLn1(double miu,double landa,double k)
{
    double respuestaLn = CalcularLq1(miu,landa,k) / CalcularPk1(miu,landa,k); //Respuesta Ln
    return respuestaLn;
}
double CalcularW1(double miu,double landa,double k)
{
    double arribaW = miu * pow((landa / miu), k) * CalcularPo1(miu,landa,k);
    double abajoW = Factorial1((k - 1)) * pow(((k * miu) - landa), 2);
    double aladoW = 1 / miu;

    double respuestaW = (arribaW/ abajoW)+aladoW;   //Respuesta W
    return respuestaW;
}
double CalcularWq1(double miu,double landa,double k)
{
    double arribaWq =miu * pow((landa / miu), k) * CalcularPo1(miu,landa,k);
    double abajoWq = Factorial1((k - 1)) * pow(((k * miu) - landa), 2);

    double respuestaWq = arribaWq/ abajoWq;     //Respuesta Wq
    return respuestaWq;
}
double CalcularWn1(double miu,double landa,double k)
{
    double respuestaWn = CalcularWq1(miu,landa,k) / CalcularPk1(miu,landa,k);   //Respuesta Wn
    return respuestaWn;
}
double ComprobarHorasEsCero1(double horas)
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
double CalcularCtte1(double miu,double landa,double k,double horas,double cte)
{
    horas=ComprobarHorasEsCero1(horas);
    double respuestaCtte=(landa*horas*CalcularWq1(miu,landa,k)*cte);
    return respuestaCtte;
}
double CalcularCtts1(double miu,double landa,double k,double horas,double cts)
{
    horas=ComprobarHorasEsCero1(horas);
    double respuestaCtts=(landa*horas*CalcularW1(miu,landa,k)*cts);
    return respuestaCtts;
}
double CalcularCttse1(double miu,double landa,double k,double horas,double ctse)
{
    horas=ComprobarHorasEsCero1(horas);
    double respuestaCttse=(landa*horas*(1/miu)*ctse);
    return respuestaCttse;
}
double CalcularCTs1(double k, double cs)
{
    double respuestaCts=k*cs;
    return respuestaCts;
}
double CalcularCT1(double miu,double landa,double k,double horas,double cte,double cts,double ctse,double cs)
{
    horas=ComprobarHorasEsCero1(horas);
    double respuestaCt=CalcularCtte1(miu,landa,k,horas,cte)+CalcularCtts1(miu,landa,k,horas,cts)+CalcularCttse1(miu,landa,k,horas,ctse)+CalcularCTs1(k,cs);
    return respuestaCt;
}
#endif // FUNC_PICM_H
