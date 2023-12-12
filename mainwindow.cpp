#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "func_pics.h"
#include "func_picm.h"
#include "func_pfcs.h"
#include "func_pfcm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PS_Calcular_clicked()
{
    QString miuString=ui->TXT_Miu->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa->text();
    double landa=landaString.toDouble();
    QString nString=ui->TXT_N->text();
    double n=nString.toDouble();


    if(miu>landa)
    {
        ui->LblCE->setText("Si cumple con la condicion de estabilidad");
    }
    else
    {
        ui->LblCE->setText("No cumple con la condicion de estabilidad");
    }
    char f='G';
    int presc=-1;
    //Mostrar Resultados
    ui->RespuestaRo->setText(QString::number(CalcularRo(miu,landa),f,presc));
    ui->RespuestaPo->setText(QString::number(CalcularPo(miu,landa),f,presc));
    ui->RespuestaPn->setText(QString::number(CalcularPn(miu,landa,n),f,presc));
    ui->RespuestaL->setText(QString::number(CalcularL(miu,landa),f,presc));
    ui->RespuestaLq->setText(QString::number(CalcularLq(miu,landa),f,presc));
    ui->RespuestaLn->setText(QString::number(CalcularLn(miu,landa),f,presc));
    ui->RespuestaW->setText(QString::number(CalcularW(miu,landa),f,presc));
    ui->RespuestaWq->setText(QString::number(CalcularWq(miu,landa),f,presc));
    ui->RespuestaWn->setText(QString::number(CalcularWn(miu,landa),f,presc));
}


void MainWindow::on_pushButton_clicked()
{
    QString miuString=ui->TXT_Miu->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa->text();
    double landa=landaString.toDouble();


    QString horasString=ui->TXT_Horas->text();
    double horas=horasString.toDouble();

    QString cteString=ui->TXT_Cte->text();
    double cte=cteString.toDouble();

    QString ctseString=ui->TXT_Ctse->text();
    double ctse=ctseString.toDouble();

    QString ctsString=ui->TXT_Cts->text();
    double cts=ctsString.toDouble();

    QString csString=ui->TXT_Cs->text();
    double cs=csString.toDouble();

    //Mostrar Resultados
    ui->RespuestaCtte->setText(QString::number(CalcularCtte(miu,landa,horas,cte)));
    ui->RespuestaCtts->setText(QString::number(CalcularCtts(miu,landa,horas,cts)));
    ui->RespuestaCttse->setText(QString::number(CalcularCttse(miu,landa,horas,ctse)));
    ui->RespuestaCts->setText(QString::number(CalcularCTs(cs)));
    ui->RespuestaCt->setText(QString::number(CalcularCT(miu,landa,horas,cte,cts,ctse,cs)));
}


void MainWindow::on_pushButton_2_clicked()
{
    QString miuString=ui->TXT_Miu->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa->text();
    double landa=landaString.toDouble();
    QString numString=ui->TXT_Num->text();
    double num=numString.toDouble();
    double sumatoria=0;
    QString formula ="";
    ui->LblParcial->setText("");

    if(ui->comboBox->currentIndex()==0)
    {
        formula.append("1-(P");
        for(int i=0;i<num;i++)
        {
            double pn=CalcularPn(miu,landa,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i+1==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }
        ui->LblParcial->setText("1-("+(QString::number(sumatoria))+")");
        sumatoria=1-sumatoria;
    }
    else if(ui->comboBox->currentIndex()==1)
    {
        formula.append("(P");
        for(int i=0;i<=num;i++)
        {
            double pn=CalcularPn(miu,landa,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }

    }

    ui->LblFormula->setText(formula);
    ui->RespuestaProbabilidad->setText(QString::number(sumatoria));
}

//PICM
void MainWindow::on_PS_Calcular_2_clicked()
{
    QString miuString=ui->TXT_Miu_2->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_2->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K->text();
    double k=kString.toDouble();
    QString nString=ui->TXT_N_2->text();
    double n=nString.toDouble();

    if((k*miu)>landa)
    {
        ui->LblCE_2->setText("Si cumple con la condicion de estabilidad");
    }
    else
    {
        ui->LblCE_2->setText("No cumple con la condicion de estabilidad");
    }

    //Mostrar Resultados
    ui->RespuestaPo_2->setText(QString::number(CalcularPo1(miu,landa,k)));
    ui->RespuestaPk->setText(QString::number(CalcularPk1(miu,landa,k)));
    ui->RespuestaPne->setText(QString::number(CalcularPne1(miu,landa,k)));
    ui->RespuestaPn_2->setText(QString::number(CalcularPn1(miu,landa,k,n)));
    ui->RespuestaL_2->setText(QString::number(CalcularL1(miu,landa,k)));
    ui->RespuestaLq_2->setText(QString::number(CalcularLq1(miu,landa,k)));
    ui->RespuestaLn_2->setText(QString::number(CalcularLn1(miu,landa,k)));
    ui->RespuestaW_2->setText(QString::number(CalcularW1(miu,landa,k)));
    ui->RespuestaWq_2->setText(QString::number(CalcularWq1(miu,landa,k)));
    ui->RespuestaWn_2->setText(QString::number(CalcularWn1(miu,landa,k)));
}


void MainWindow::on_pushButton_3_clicked()
{
    QString miuString=ui->TXT_Miu_2->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_2->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K->text();
    double k=kString.toDouble();

    QString horasString=ui->TXT_Horas_2->text();
    double horas=horasString.toDouble();

    QString cteString=ui->TXT_Cte_2->text();
    double cte=cteString.toDouble();

    QString ctseString=ui->TXT_Ctse_2->text();
    double ctse=ctseString.toDouble();

    QString ctsString=ui->TXT_Cts_2->text();
    double cts=ctsString.toDouble();

    QString csString=ui->TXT_Cs_2->text();
    double cs=csString.toDouble();

    //Mostrar Resultados

    ui->RespuestaCtte_2->setText(QString::number(CalcularCtte1(miu,landa,k,horas,cte)));
    ui->RespuestaCtts_2->setText(QString::number(CalcularCtts1(miu,landa,k,horas,cts)));
    ui->RespuestaCttse_2->setText(QString::number(CalcularCttse1(miu,landa,k,horas,ctse)));
    ui->RespuestaCts_2->setText(QString::number(CalcularCTs1(k,cs)));
    ui->RespuestaCt_2->setText(QString::number(CalcularCT1(miu,landa,k,horas,cte,cts,ctse,cs)));
}


void MainWindow::on_pushButton_4_clicked()
{
    QString miuString=ui->TXT_Miu_2->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_2->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K->text();
    double k=kString.toDouble();
    QString numString=ui->TXT_Num_2->text();
    double num=numString.toDouble();
    double sumatoria=0;
    QString formula ="";
    ui->LblParcial_2->setText("");

    if(ui->comboBox_2->currentIndex()==0)
    {
        formula.append("1-(P");
        for(int i=0;i<num;i++)
        {
            double pn=CalcularPn1(miu,landa,k,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i+1==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }
        ui->LblParcial_2->setText("1-("+(QString::number(sumatoria))+")");
        sumatoria=1-sumatoria;
    }
    else if(ui->comboBox_2->currentIndex()==1)
    {
        formula.append("(P");
        for(int i=0;i<=num;i++)
        {
            double pn=CalcularPn1(miu,landa,k,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }

    }
    ui->LblFormula_2->setText(formula);
    ui->RespuestaProbabilidad_2->setText(QString::number(sumatoria));
}

//PFCS
void MainWindow::on_pushButton_6_clicked()
{
    QString miuString=ui->TXT_Miu_3->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_3->text();
    double landa=landaString.toDouble();
    QString nString=ui->TXT_N_3->text();
    double N=nString.toDouble();
    QString mString=ui->TXT_M->text();
    double M=mString.toDouble();

    ui->RespuestaPo_3->setText(QString::number(CalcularPo2(miu,landa,M)));
    ui->RespuestaPe->setText(QString::number(1-CalcularPo2(miu,landa,M)));
    ui->RespuestaPn_3->setText(QString::number(CalcularPn2(miu,landa,M,N)));
    ui->RespuestaL_3->setText(QString::number(CalcularL2(miu,landa,M)));
    ui->RespuestaLq_3->setText(QString::number(CalcularLq2(miu,landa,M)));
    ui->RespuestaLn_3->setText(QString::number(CalcularLn2(miu,landa,M)));
    ui->RespuestaW_3->setText(QString::number(CalcularW2(miu,landa,M)));
    ui->RespuestaWq_3->setText(QString::number(CalcularWq2(miu,landa,M)));
    ui->RespuestaWn_3->setText(QString::number(CalcularWn2(miu,landa,M)));
}


void MainWindow::on_pushButton_7_clicked()
{
    QString miuString=ui->TXT_Miu_3->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_3->text();
    double landa=landaString.toDouble();
    QString mString=ui->TXT_M->text();
    double M=mString.toDouble();


    QString horasString=ui->TXT_Horas_3->text();
    double horas=horasString.toDouble();

    QString cteString=ui->TXT_Cte_3->text();
    double cte=cteString.toDouble();

    QString ctseString=ui->TXT_Ctse_3->text();
    double ctse=ctseString.toDouble();

    QString ctsString=ui->TXT_Cts_3->text();
    double cts=ctsString.toDouble();

    QString csString=ui->TXT_Cs_3->text();
    double cs=csString.toDouble();

    //Mostrar Resultados

    ui->RespuestaCtte_3->setText(QString::number(CalcularCtte2(miu,landa,M,horas,cte)));
    ui->RespuestaCtts_3->setText(QString::number(CalcularCtts2(miu,landa,M,horas,cts)));
    ui->RespuestaCttse_3->setText(QString::number(CalcularCttse2(miu,landa,M,horas,ctse)));
    ui->RespuestaCts_3->setText(QString::number(CalcularCTs2(cs)));
    ui->RespuestaCt_3->setText(QString::number(CalcularCT2(miu,landa,M,horas,cte,cts,ctse,cs)));
}


void MainWindow::on_pushButton_5_clicked()
{
    QString miuString=ui->TXT_Miu_3->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_3->text();
    double landa=landaString.toDouble();
    QString mString=ui->TXT_M->text();
    double M=mString.toDouble();

    QString numString=ui->TXT_Num_3->text();
    double num=numString.toDouble();
    double sumatoria=0;
    QString formula ="";
    ui->LblParcial_3->setText("");

    if(ui->comboBox_3->currentIndex()==0)
    {
        formula.append("1-(P");
        for(int i=0;i<num;i++)
        {
            double pn=CalcularPn2(miu,landa,M,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i+1==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }
        ui->LblParcial_3->setText("1-("+(QString::number(sumatoria))+")");
        sumatoria=1-sumatoria;
    }
    else if(ui->comboBox_3->currentIndex()==1)
    {
        formula.append("(P");
        for(int i=0;i<=num;i++)
        {
            double pn=CalcularPn2(miu,landa,M,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }

    }
    ui->LblFormula_3->setText(formula);
    ui->RespuestaProbabilidad_3->setText(QString::number(sumatoria));
}

//PFCM
void MainWindow::on_pushButton_10_clicked()
{
    QString miuString=ui->TXT_Miu_4->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_4->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K_2->text();
    double k=kString.toDouble();
    QString mString=ui->TXT_M_2->text();
    double m=mString.toDouble();
    QString nString=ui->TXT_N_4->text();
    double n=nString.toDouble();

    //Mostrar Resultados
    ui->RespuestaPo_4->setText(QString::number(CalcularPo3(miu,landa,m,k)));
    ui->RespuestaPe_2->setText(QString::number(CalcularPe3(miu,landa,m,k)));
    ui->RespuestaPn_4->setText(QString::number(CalcularPn3(miu,landa,m,k,n)));
    ui->RespuestaL_4->setText(QString::number(CalcularL3(miu,landa,m,k)));
    ui->RespuestaLq_4->setText(QString::number(CalcularLq3(miu,landa,m,k)));
    ui->RespuestaLn_4->setText(QString::number(CalcularLn3(miu,landa,m,k)));
    ui->RespuestaW_4->setText(QString::number(CalcularW3(miu,landa,m,k)));
    ui->RespuestaWq_4->setText(QString::number(CalcularWq3(miu,landa,m,k)));
    ui->RespuestaWn_4->setText(QString::number(CalcularWn3(miu,landa,m,k)));
}


void MainWindow::on_pushButton_9_clicked()
{
    QString miuString=ui->TXT_Miu_4->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_4->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K_2->text();
    double k=kString.toDouble();
    QString mString=ui->TXT_M_2->text();
    double m=mString.toDouble();

    QString horasString=ui->TXT_Horas_4->text();
    double horas=horasString.toDouble();

    QString cteString=ui->TXT_Cte_4->text();
    double cte=cteString.toDouble();

    QString ctseString=ui->TXT_Ctse_4->text();
    double ctse=ctseString.toDouble();

    QString ctsString=ui->TXT_Cts_4->text();
    double cts=ctsString.toDouble();

    QString csString=ui->TXT_Cs_4->text();
    double cs=csString.toDouble();

    //Mostrar Resultados

    ui->RespuestaCtte_4->setText(QString::number(CalcularCtte3(miu,landa,m,k,horas,cte)));
    ui->RespuestaCtts_4->setText(QString::number(CalcularCtts3(miu,landa,m,k,horas,cts)));
    ui->RespuestaCttse_4->setText(QString::number(CalcularCttse3(miu,landa,m,k,horas,ctse)));
    ui->RespuestaCts_4->setText(QString::number(CalcularCTs3(k,cs)));
    ui->RespuestaCt_4->setText(QString::number(CalcularCT3(miu,landa,m,k,horas,cte,cts,ctse,cs)));
}


void MainWindow::on_pushButton_8_clicked()
{
    QString miuString=ui->TXT_Miu_4->text();
    double miu=miuString.toDouble();
    QString landaString=ui->TXT_Landa_4->text();
    double landa=landaString.toDouble();
    QString kString=ui->TXT_K_2->text();
    double k=kString.toDouble();
    QString mString=ui->TXT_M_2->text();
    double m=mString.toDouble();
    QString numString=ui->TXT_Num_4->text();
    double num=numString.toDouble();
    double sumatoria=0;
    QString formula ="";
    ui->LblParcial_4->setText("");

    if(ui->comboBox_4->currentIndex()==0)
    {
        formula.append("1-(P");
        for(int i=0;i<num;i++)
        {
            double pn=CalcularPn3(miu,landa,m,k,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i+1==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }
        ui->LblParcial_4->setText("1-("+(QString::number(sumatoria))+")");
        sumatoria=1-sumatoria;
    }
    else if(ui->comboBox_4->currentIndex()==1)
    {
        formula.append("(P");
        for(int i=0;i<=num;i++)
        {
            double pn=CalcularPn3(miu,landa,m,k,i);
            formula.append(QString::number(i)+": ");
            formula.append(QString::number(pn)+" ");
            if(!(i==num)){
                formula.append("+ P");
            }
            else{
                formula.append(")");
            }
            sumatoria+=pn;
        }

    }
    ui->LblFormula_4->setText(formula);
    ui->RespuestaProbabilidad_4->setText(QString::number(sumatoria));
}

