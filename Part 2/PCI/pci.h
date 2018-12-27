#ifndef PCI_H
#define PCI_H

#include <QMainWindow>
#include <QRadioButton>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "string"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QLineSeries>
#include <QtCharts>
#include <vector>
#include <QPair>
#include <stdio.h>

namespace Ui {
class PCI;
class mem;
class bus;
}

using namespace QtCharts;

class PCI : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCI(QWidget *parent = 0);
    ~PCI();

private slots:
    void on_arb_clicked();

    void on_devA_clicked();

    void on_devB_clicked();

    void on_devC_clicked();

    void on_R1_clicked();

    void on_R2_clicked();

    void on_arb_2_clicked();

private:
    Ui::PCI *ui;
};


class mem
{

public:
    QString s[11];
    int i=3;
    mem(QString v1,QString v2){
        s[1]=v1;
        s[2]=v2;
        for(int i=3;i<=10;i++)
            s[i]="XXXXXXXX";
    }
    void write(QString v)
    {
        s[i]=v;
        i++;
        if(i>10)
            i--;
        return;
    }
    QString read (int i){
        return s[i];
    }
};

class bus
{

public:
    std::pair <int, int> clk[100]={std::make_pair(24,0)};
    std::pair <int, int> req_a[100]={std::make_pair(22,0)};
    std::pair <int, int> req_b[100]={std::make_pair(20,0)};
    std::pair <int, int> req_c[100]={std::make_pair(18,0)};
    std::pair <int, int> gnt_a[100]={std::make_pair(16,0)};
    std::pair <int, int> gnt_b[100]={std::make_pair(14,0)};
    std::pair <int, int> gnt_c[100]={std::make_pair(12,0)};
    std::pair <int, int> frame[100]={std::make_pair(10,0)};
    std::pair <double,double> AD_1[100]={std::make_pair(8,0)};
    std::pair <double,double> Control_1[100]={std::make_pair(6,0)};
    std::pair <double,double>  AD[100]={std::make_pair(8,0)};
    std::pair <double,double> Control[100]={std::make_pair(6,0)};
    std::pair <int, int> Irdy[100]={std::make_pair(4,0)};
    std::pair <int, int> Trdy[100]={std::make_pair(0,2)};
    std::pair <int, int> Devsel[100]={std::make_pair(0,0)};
    bus(int v2){
        v2=5;
        }
    //==========================
    int write(int trans_no,char init,char second,std::string s)
    {
        int no_of_points;
        int step=1;
        int final,f;
        if(trans_no==3){
            no_of_points=32;
            f=27;
            final=23;
        }
        else if(trans_no==2){
            no_of_points=28;
            f=23;
            final=19;
        }
        else{
            final=15;
            f=19;
            no_of_points=24;
        }
        // clock values of the signal
        int y=24; int x=0;
        for(int i=1;i<no_of_points;i++)
        {
           clk[i]=std::make_pair(y+1,x);
           i++;
           clk[i]=std::make_pair(y+1,x+step);
           i++;
           clk[i]=std::make_pair(y,x+1);
           i++;
           clk[i]=std::make_pair(y,x+step+step);
           x=x+2*step;
        }
        // adress and control values ==============================================
        y=8; x=0; ; int y1=6;
        for(int i=0;i<=11;i++)
        {
            AD_1[i]=std::make_pair(x,y);
            AD[i]=std::make_pair(x,y);
            Control_1[i]=std::make_pair(x,y1);
            Control[i]=std::make_pair(x,y1);
            i++;
            AD_1[i]=std::make_pair(x,y);
            AD[i]=std::make_pair(x,y);
            Control_1[i]=std::make_pair(x,y1);
            Control[i]=std::make_pair(x,y1);
            x=x+step;
        }
        int xo=12;
        AD_1[xo]=std::make_pair(x,(y+.5) );
        AD_1[xo+1]=std::make_pair(x,y+.5);
        AD[xo]=std::make_pair(x,y-.5);
        AD[xo+1]=std::make_pair(x,y-.5);
        Control_1[xo]=std::make_pair(x,y1+.5);
        Control_1[xo+1]=std::make_pair(x,y1+.5);
        Control[xo]=std::make_pair(x,y1-.5);
        Control[xo+1]=std::make_pair(x,y1-.5);
        x=x+step;
        xo+=2;
        AD_1[xo]=std::make_pair(x,y);
        AD_1[xo+1]=std::make_pair(x,y);
        AD[xo]=std::make_pair(x,y);
        AD[xo+1]=std::make_pair(x,y);
        Control_1[xo]=std::make_pair(x,y1);
        Control_1[xo+1]=std::make_pair(x,y1);
        Control[xo]=std::make_pair(x,y1);
        Control[xo+1]=std::make_pair(x,y1);
        x=x+step;
        xo+=2;
        int i=xo;
        for (int num=1;num<=trans_no;num++)
        {
                AD_1[i]=std::make_pair(x,y+.5);
                AD_1[i+1]=std::make_pair(x,y+.5);
                AD[i]=std::make_pair(x,y-.5);
                AD[i+1]=std::make_pair(x,y-.5);
                Control_1[i]=std::make_pair(x,y1+.5);
                Control_1[i+1]=std::make_pair(x,y1+.5);
                Control[i]=std::make_pair(x,y1-.5);
                Control[i+1]=std::make_pair(x,y1-.5);
                x=x+step;
                i=i+2;
                AD_1[i]=std::make_pair(x,y);
                AD_1[i+1]=std::make_pair(x,y);
                AD[i]=std::make_pair(x,y);
                AD[i+1]=std::make_pair(x,y);
                Control_1[i]=std::make_pair(x,y1);
                Control_1[i+1]=std::make_pair(x,y1);
                Control[i]=std::make_pair(x,y1);
                Control[i+1]=std::make_pair(x,y1);
                x=x+step;
                i=i+2;
                xo=i;
        }
        for(int j=i;j<=no_of_points;j++)
        {
            AD_1[j]=std::make_pair(x,y);
            AD[j]=std::make_pair(x,y);
            Control_1[j]=std::make_pair(x,y1);
            Control[j]=std::make_pair(x,y1);
            j++;
            AD_1[j]=std::make_pair(x,y);
            AD[j]=std::make_pair(x,y);
            Control_1[j]=std::make_pair(x,y1);
            Control[j]=std::make_pair(x,y1);
            x=x+step;
        }
        //==============================================================
        //req function
        int y_a=23,y_b=21,y_c=19;
        x=0;
        for(int i=0;i<no_of_points;i++)
        {
            if(init=='A')
            {
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);

                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_a--;
                }
                if(i==f)
                {
                    y_a++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else if (init=='B')
            {

                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_b--;
                }
                if(i==f)
                {
                    y_b++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else
            {

                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_c--;
                }
                if(i==f)
                {
                    y_c++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
        }
        //=====================================================
        y_a=17,y_b=15,y_c=13;
        x=0;
        for(int i=0;i<no_of_points;i++)
        {
            if(init=='A')
            {
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);

                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_a--;
                }
                if(i==f)
                {
                    y_a++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else if (init=='B')
            {

                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_b--;
                }
                if(i==f)
                {
                    y_b++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else
            {

                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_c--;
                }
                if(i==f)
                {
                    y_c++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
        }
        //============================================
        y=11;x=0;
        for(int i=0;i<no_of_points;i++)
        {
            frame[i]=std::make_pair(x,y);
            i++;
            if(i==11)
            {
                y--;
            }
            if(i==final)
            {
                y++;
            }
            frame[i]=std::make_pair(x,y);
            x=x+step;
        }
        //==============================================
        y_a=5;y_b=3;y_c=1;x=0;
        for(int i=0;i<no_of_points;i++)
        {
            Irdy[i]=std::make_pair(x,y_a);
            Trdy[i]=std::make_pair(x,y_b);
            Devsel[i]=std::make_pair(x,y_c);
            i++;
            if(i==15)
            {
                y_a--;
                y_b--;
                y_c--;
            }
            if(i==f)
            {
                y_a++;
                y_b++;
                y_c++;
            }
            Irdy[i]=std::make_pair(x,y_a);
            Trdy[i]=std::make_pair(x,y_b);
            Devsel[i]=std::make_pair(x,y_c);
            x=x+step;
        }
        return no_of_points;
    }
    int Read(int trans_no,char init,char second,int s)
    {
        int no_of_points;
        int step=1;
        int final,f;
        if(trans_no==3){
            no_of_points=36;
            f=31;
            final=27;
        }
        else if(trans_no==2){
            no_of_points=32;
            f=27;
            final=23;
        }
        else{
            final=19;
            f=23;
            no_of_points=28;
        }
        // clock values of the signal
        int y=24; int x=0;
        for(int i=1;i<no_of_points;i++)
        {
           clk[i]=std::make_pair(y+1,x);
           i++;
           clk[i]=std::make_pair(y+1,x+step);
           i++;
           clk[i]=std::make_pair(y,x+1);
           i++;
           clk[i]=std::make_pair(y,x+step+step);
           x=x+2*step;
        }
        // adress and control values ==============================================
                y=8; x=0; ; int y1=6;
                for(int i=0;i<=11;i++)
                {
                    AD_1[i]=std::make_pair(x,y);
                    AD[i]=std::make_pair(x,y);
                    Control_1[i]=std::make_pair(x,y1);
                    Control[i]=std::make_pair(x,y1);
                    i++;
                    AD_1[i]=std::make_pair(x,y);
                    AD[i]=std::make_pair(x,y);
                    Control_1[i]=std::make_pair(x,y1);
                    Control[i]=std::make_pair(x,y1);
                    x=x+step;
                }
                int xo=12;
                AD_1[xo]=std::make_pair(x,(y+.5) );
                AD_1[xo+1]=std::make_pair(x,y+.5);
                AD[xo]=std::make_pair(x,y-.5);
                AD[xo+1]=std::make_pair(x,y-.5);
                Control_1[xo]=std::make_pair(x,y1+.5);
                Control_1[xo+1]=std::make_pair(x,y1+.5);
                Control[xo]=std::make_pair(x,y1-.5);
                Control[xo+1]=std::make_pair(x,y1-.5);
                x=x+step;
                xo+=2;
                AD_1[xo]=std::make_pair(x,y);
                AD_1[xo+1]=std::make_pair(x,y);
                AD[xo]=std::make_pair(x,y);
                AD[xo+1]=std::make_pair(x,y);
                Control_1[xo]=std::make_pair(x,y1);
                Control_1[xo+1]=std::make_pair(x,y1);
                Control[xo]=std::make_pair(x,y1);
                Control[xo+1]=std::make_pair(x,y1);
                x=x+step;
                xo+=2;
                AD_1[xo]=std::make_pair(x,y);
                AD_1[xo+1]=std::make_pair(x,y);
                AD[xo]=std::make_pair(x,y);
                AD[xo+1]=std::make_pair(x,y);
                Control_1[xo]=std::make_pair(x,y1+.5);
                Control_1[xo+1]=std::make_pair(x,y1+.5);
                Control[xo]=std::make_pair(x,y1-.5);
                Control[xo+1]=std::make_pair(x,y1-.5);
                x=x+step;
                xo+=2;
                AD_1[xo]=std::make_pair(x,y);
                AD_1[xo+1]=std::make_pair(x,y);
                AD[xo]=std::make_pair(x,y);
                AD[xo+1]=std::make_pair(x,y);
                Control_1[xo]=std::make_pair(x,y1);
                Control_1[xo+1]=std::make_pair(x,y1);
                Control[xo]=std::make_pair(x,y1);
                Control[xo+1]=std::make_pair(x,y1);
                x=x+step;
                int i=xo+2;
                for (int num=1;num<=trans_no;num++)
                {
                    if(num==trans_no)
                    {
                        AD_1[i]=std::make_pair(x,y+.5);
                        AD_1[i+1]=std::make_pair(x,y+.5);
                        AD[i]=std::make_pair(x,y-.5);
                        AD[i+1]=std::make_pair(x,y-.5);
                        Control_1[i]=std::make_pair(x,y1);
                        Control_1[i+1]=std::make_pair(x,y1);
                        Control[i]=std::make_pair(x,y1);
                        Control[i+1]=std::make_pair(x,y1);
                        x=x+step;
                        i=i+2;
                        AD_1[i]=std::make_pair(x,y);
                        AD_1[i+1]=std::make_pair(x,y);
                        AD[i]=std::make_pair(x,y);
                        AD[i+1]=std::make_pair(x,y);
                        Control_1[i]=std::make_pair(x,y1);
                        Control_1[i+1]=std::make_pair(x,y1);
                        Control[i]=std::make_pair(x,y1);
                        Control[i+1]=std::make_pair(x,y1);
                        x=x+step;
                        i=i+2;
                    }
                    else
                    {
                        AD_1[i]=std::make_pair(x,y+.5);
                        AD_1[i+1]=std::make_pair(x,y+.5);
                        AD[i]=std::make_pair(x,y-.5);
                        AD[i+1]=std::make_pair(x,y-.5);
                        Control_1[i]=std::make_pair(x,y1+.5);
                        Control_1[i+1]=std::make_pair(x,y1+.5);
                        Control[i]=std::make_pair(x,y1-.5);
                        Control[i+1]=std::make_pair(x,y1-.5);
                        x=x+step;
                        i=i+2;
                        AD_1[i]=std::make_pair(x,y);
                        AD_1[i+1]=std::make_pair(x,y);
                        AD[i]=std::make_pair(x,y);
                        AD[i+1]=std::make_pair(x,y);
                        Control_1[i]=std::make_pair(x,y1);
                        Control_1[i+1]=std::make_pair(x,y1);
                        Control[i]=std::make_pair(x,y1);
                        Control[i+1]=std::make_pair(x,y1);
                        x=x+step;
                        i=i+2;
                    }
                }
                for(int j=i;j<=no_of_points;j++)
                {
                    AD_1[j]=std::make_pair(x,y);
                    AD[j]=std::make_pair(x,y);
                    Control_1[j]=std::make_pair(x,y1);
                    Control[j]=std::make_pair(x,y1);
                    j++;
                    AD_1[j]=std::make_pair(x,y);
                    AD[j]=std::make_pair(x,y);
                    Control_1[j]=std::make_pair(x,y1);
                    Control[j]=std::make_pair(x,y1);
                    x=x+step;
                }
        //==============================================================
        //req function
        int y_a=23,y_b=21,y_c=19;
        x=0;
        for(int i=0;i<no_of_points;i++)
        {
            if(init=='A')
            {
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);

                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_a--;
                }
                if(i==f)
                {
                    y_a++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else if (init=='B')
            {

                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_b--;
                }
                if(i==f)
                {
                    y_b++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else
            {

                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                req_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==3)
                {
                    y_c--;
                }
                if(i==f)
                {
                    y_c++;
                }
                req_a[i]=std::make_pair(x,y_a);
                req_b[i]=std::make_pair(x,y_b);
                req_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
        }
        //=====================================================
        y_a=17,y_b=15,y_c=13;
        x=0;
        for(int i=0;i<no_of_points;i++)
        {
            if(init=='A')
            {
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);

                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_a--;
                }
                if(i==f)
                {
                    y_a++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else if (init=='B')
            {

                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_b--;
                }
                if(i==f)
                {
                    y_b++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
            else
            {

                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                gnt_a[i]=std::make_pair(x,y_a);
                i++;
                if(i==7)
                {
                    y_c--;
                }
                if(i==f)
                {
                    y_c++;
                }
                gnt_a[i]=std::make_pair(x,y_a);
                gnt_b[i]=std::make_pair(x,y_b);
                gnt_c[i]=std::make_pair(x,y_c);
                x=x+step;
            }
        }
        //============================================
        y=11;x=0;
        for(int i=0;i<no_of_points;i++)
        {
            frame[i]=std::make_pair(x,y);
            i++;
            if(i==11)
            {
                y--;
            }
            if(i==final)
            {
                y++;
            }
            frame[i]=std::make_pair(x,y);
            x=x+step;
        }
        //==============================================
        y_a=5;y_b=3;y_c=1;x=0;
        for(int i=0;i<no_of_points;i++)
        {
            Irdy[i]=std::make_pair(x,y_a);
            Trdy[i]=std::make_pair(x,y_b);
            Devsel[i]=std::make_pair(x,y_c);
            i++;
            if(i==15)
            {
                y_a--;
                y_c--;
            }
            if(i==19)
            {
                y_b--;
            }
            if(i==f)
            {
                y_a++;
                y_b++;
                y_c++;
            }
            Irdy[i]=std::make_pair(x,y_a);
            Trdy[i]=std::make_pair(x,y_b);
            Devsel[i]=std::make_pair(x,y_c);
            x=x+step;
        }
        return no_of_points;
    }
};


#endif // PCI_H
