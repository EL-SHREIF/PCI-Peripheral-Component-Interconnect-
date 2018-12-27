#include "pci.h"
#include "ui_pci.h"
#include <QVBoxLayout>
extern mem DV_A;
extern mem DV_B;
extern mem DV_C;
extern bus BUS;
//extern QChartView *chartView ;
//extern QChart *chart ;
bool init=false;
bool target=false;
bool read =true;
bool write=true;

#define duration 30000


PCI::PCI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCI)
{
    ui->setupUi(this);


    //==========================================================
    ui->data_enter->setMaxLength(int(24));
    ui->no->setMaxLength(int(1));
    ui->index_enter->setMaxLength(int(2));


    //============================================================
    QLineSeries *series = new QLineSeries();
    QChart *chart = new QChart();
    QFont font;
    font.setPixelSize(15);
    chart->setTitleFont(font);
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("Transaction View");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->chart->addWidget(chartView);
    //==============================================================

    for(int i = 0; i < 10; i++){
            ui->TA->item(i,0)->setText(DV_A.read(i+1));
    }
    for(int i = 0; i < 10; i++){
            ui->TB->item(i,0)->setText(DV_B.read(i+1));
    }
    for(int i = 0; i < 10; i++){
            ui->TC->item(i,0)->setText(DV_C.read(i+1));
    }
    //ui->chart->addWidget(chartView);
}

PCI::~PCI()
{
    delete ui;
}


void PCI::on_arb_clicked()
{

}

void PCI::on_devA_clicked()
{
    if(init==false){
        ui->INIT->setText("A");
        init=true;
    }
    else if(init==true && target==false){
        ui->TARG->setText("A");
        target = true;
    }
    else if(target == true && init==true){
        ui->INIT->setText("A");
        ui->TARG->setText(" ");
        init=true;
        target=false;
    }
}

void PCI::on_devB_clicked()
{
    if(init==false){
        ui->INIT->setText("B");
        init=true;
    }
    else if(init==true && target==false){
        ui->TARG->setText("B");
        target = true;
    }
    else if(target == true && init==true){
        ui->INIT->setText("B");
        ui->TARG->setText(" ");
        init=true;
        target=false;
    }
}

void PCI::on_devC_clicked()
{
    if(init==false){
        ui->INIT->setText("C");
        init=true;
    }
    else if(init==true && target==false){
        ui->TARG->setText("C");
        target = true;
    }
    else if(target == true && init==true){
        ui->INIT->setText("C");
        ui->TARG->setText(" ");
        init=true;
        target=false;
    }
}

void PCI::on_R1_clicked()
{
    if(ui->R1->isChecked())
    {
        read=false;
        write=true;
    }
}


void PCI::on_R2_clicked()
{
    if(ui->R2->isChecked())
    {
        read=true;
        write=false;
    }
}

void PCI::on_arb_2_clicked()
{
    std::string s= ui->data_enter->text().toStdString();

    QString c_1=ui->INIT->text();
    char c1,c2;
    if(c_1=="A")
        c1='A';
    else if (c_1=="B")
        c1='B';
    else
        c1='C';
    QString c_2=ui->TARG->text();
    if(c_2=="A")
        c2='A';
    else if (c_2=="B")
        c2='B';
    else
        c2='C';

    int no=(ui->no->text()).toInt();
    int read_idx=(ui->index_enter->text()).toInt();
    //write mode===================================
    if(ui->R2->isChecked())
    {
        int hello=BUS.write(no,c1,c2,s);
        if ( ui->chart->layout() != NULL )
        {
            QLayoutItem* item;
            while ( ( item = ui->chart->layout()->takeAt( 0 ) ) != NULL )
            {
                delete item->widget();
                delete item;
            }
        }
        QLineSeries *series = new QLineSeries();
        QLineSeries *series1_1 = new QLineSeries();
        QLineSeries *series1_2 = new QLineSeries();
        QLineSeries *series2_1 = new QLineSeries();
        QLineSeries *series2_2 = new QLineSeries();
        QLineSeries *req_1 = new QLineSeries();
        QLineSeries *req_2 = new QLineSeries();
        QLineSeries *req_3 = new QLineSeries();
        QLineSeries *g_1 = new QLineSeries();
        QLineSeries *g_2 = new QLineSeries();
        QLineSeries *g_3 = new QLineSeries();
        QLineSeries *ir = new QLineSeries();
        QLineSeries *tr = new QLineSeries();
        QLineSeries *ds = new QLineSeries();
        QLineSeries *f = new QLineSeries();
        for (int i=0;i<hello;i++)
        {
            series->append(BUS.clk[i].second,BUS.clk[i].first);
            series1_1->append(BUS.AD[i].first,BUS.AD[i].second);
            series1_2->append(BUS.AD_1[i].first,BUS.AD_1[i].second);
            series2_1->append(BUS.Control[i].first,BUS.Control[i].second);
            series2_2->append(BUS.Control_1[i].first,BUS.Control_1[i].second);
            req_1->append(BUS.req_a[i].first,BUS.req_a[i].second);
            req_2->append(BUS.req_b[i].first,BUS.req_b[i].second);
            req_3->append(BUS.req_c[i].first,BUS.req_c[i].second);
            g_1->append(BUS.gnt_a[i].first,BUS.gnt_a[i].second);
            g_2->append(BUS.gnt_b[i].first,BUS.gnt_b[i].second);
            g_3->append(BUS.gnt_c[i].first,BUS.gnt_c[i].second);
            f->append(BUS.frame[i].first,BUS.frame[i].second);
            ir->append(BUS.Irdy[i].first,BUS.Irdy[i].second);
            tr->append(BUS.Trdy[i].first,BUS.Trdy[i].second);
            ds->append(BUS.Devsel[i].first,BUS.Devsel[i].second);
        }
        QChart *chart = new QChart();
        QFont font;
        font.setPixelSize(15);
        chart->setTitleFont(font);
        chart->legend()->hide();
        chart->setAnimationOptions(QChart::AllAnimations);
        chart->setAnimationDuration(duration);
        //***************************
        chart->addSeries(series);
        chart->addSeries(series1_1);
        chart->addSeries(series1_2);
        chart->addSeries(series2_1);
        chart->addSeries(series2_2);
        chart->addSeries(req_1);
        chart->addSeries(req_2);
        chart->addSeries(req_3);
        chart->addSeries(g_1);
        chart->addSeries(g_2);
        chart->addSeries(g_3);
        chart->addSeries(f);
        chart->addSeries(ir);
        chart->addSeries(tr);
        chart->addSeries(ds);
        //****************************
        chart->createDefaultAxes();
        chart->setTitle("Transaction View");
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->chart->addWidget(chartView);
        //==================================
        if(c2=='A')
        {
            if(no==1){
            DV_A.write(ui->data_enter->text());
            for(int i = 0; i < 10; i++){
                    ui->TA->item(i,0)->setText(DV_A.read(i+1));
            }
        }
            else if(no==2)
            {
               QString ss=ui->data_enter->text();
               QString s1= ss.mid(0,8);
               QString s2= ss.mid(8,8);
               DV_A.write(s1);
               DV_A.write(s2);
               for(int i = 0; i < 10; i++){
                       ui->TA->item(i,0)->setText(DV_A.read(i+1));
               }
            }
            else{
                QString ss=ui->data_enter->text();
                QString s1= ss.mid(0,8);
                QString s2= ss.mid(8,8);
                QString s3= ss.mid(16,8);
                DV_A.write(s1);
                DV_A.write(s2);
                DV_A.write(s3);
                for(int i = 0; i < 10; i++){
                        ui->TA->item(i,0)->setText(DV_A.read(i+1));
                }
            }
        }
        else if(c2=='B')
        {
            if(no==1){
            DV_B.write(ui->data_enter->text());
            for(int i = 0; i < 10; i++){
                    ui->TB->item(i,0)->setText(DV_B.read(i+1));
            }
        }
            else if(no==2)
            {
               QString ss=ui->data_enter->text();
               QString s1= ss.mid(0,8);
               QString s2= ss.mid(8,8);
               DV_B.write(s1);
               DV_B.write(s2);
               for(int i = 0; i < 10; i++){
                       ui->TB->item(i,0)->setText(DV_B.read(i+1));
               }
            }
            else{
                QString ss=ui->data_enter->text();
                QString s1= ss.mid(0,8);
                QString s2= ss.mid(8,8);
                QString s3= ss.mid(16,8);
                DV_B.write(s1);
                DV_B.write(s2);
                DV_B.write(s3);
                for(int i = 0; i < 10; i++){
                        ui->TB->item(i,0)->setText(DV_B.read(i+1));
                }
            }
        }
        else
        {
            if(no==1){
            DV_C.write(ui->data_enter->text());
            for(int i = 0; i < 10; i++){
                    ui->TC->item(i,0)->setText(DV_C.read(i+1));
            }
        }
            else if(no==2)
            {
               QString ss=ui->data_enter->text();
               QString s1= ss.mid(0,8);
               QString s2= ss.mid(8,8);
               DV_C.write(s1);
               DV_C.write(s2);
               for(int i = 0; i < 10; i++){
                       ui->TC->item(i,0)->setText(DV_C.read(i+1));
               }
            }
            else{
                QString ss=ui->data_enter->text();
                QString s1= ss.mid(0,8);
                QString s2= ss.mid(8,8);
                QString s3= ss.mid(16,8);
                DV_C.write(s1);
                DV_C.write(s2);
                DV_C.write(s3);
                for(int i = 0; i < 10; i++){
                        ui->TC->item(i,0)->setText(DV_C.read(i+1));
                }
            }
        }
    }

    //read mode here ============>>>>
    else if(ui->R1->isChecked())
    {
        int hello=BUS.Read(no,c1,c2,read_idx);
        if ( ui->chart->layout() != NULL )
        {
            QLayoutItem* item;
            while ( ( item = ui->chart->layout()->takeAt( 0 ) ) != NULL )
            {
                delete item->widget();
                delete item;
            }
        }
        QLineSeries *series = new QLineSeries();
        QLineSeries *series1_1 = new QLineSeries();
        QLineSeries *series1_2 = new QLineSeries();
        QLineSeries *series2_1 = new QLineSeries();
        QLineSeries *series2_2 = new QLineSeries();
        QLineSeries *req_1 = new QLineSeries();
        QLineSeries *req_2 = new QLineSeries();
        QLineSeries *req_3 = new QLineSeries();
        QLineSeries *g_1 = new QLineSeries();
        QLineSeries *g_2 = new QLineSeries();
        QLineSeries *g_3 = new QLineSeries();
        QLineSeries *ir = new QLineSeries();
        QLineSeries *tr = new QLineSeries();
        QLineSeries *ds = new QLineSeries();
        QLineSeries *f = new QLineSeries();
        for (int i=0;i<hello;i++)
        {
            series->append(BUS.clk[i].second,BUS.clk[i].first);
            series1_1->append(BUS.AD[i].first,BUS.AD[i].second);
            series1_2->append(BUS.AD_1[i].first,BUS.AD_1[i].second);
            series2_1->append(BUS.Control[i].first,BUS.Control[i].second);
            series2_2->append(BUS.Control_1[i].first,BUS.Control_1[i].second);
            req_1->append(BUS.req_a[i].first,BUS.req_a[i].second);
            req_2->append(BUS.req_b[i].first,BUS.req_b[i].second);
            req_3->append(BUS.req_c[i].first,BUS.req_c[i].second);
            g_1->append(BUS.gnt_a[i].first,BUS.gnt_a[i].second);
            g_2->append(BUS.gnt_b[i].first,BUS.gnt_b[i].second);
            g_3->append(BUS.gnt_c[i].first,BUS.gnt_c[i].second);
            f->append(BUS.frame[i].first,BUS.frame[i].second);
            ir->append(BUS.Irdy[i].first,BUS.Irdy[i].second);
            tr->append(BUS.Trdy[i].first,BUS.Trdy[i].second);
            ds->append(BUS.Devsel[i].first,BUS.Devsel[i].second);
        }
        QChart *chart = new QChart();
        QFont font;
        font.setPixelSize(15);
        chart->setTitleFont(font);
        chart->legend()->hide();
        chart->setAnimationOptions(QChart::AllAnimations);
        chart->setAnimationDuration(duration);
        //***************************
        chart->addSeries(series);
        chart->addSeries(series1_1);
        chart->addSeries(series1_2);
        chart->addSeries(series2_1);
        chart->addSeries(series2_2);
        chart->addSeries(req_1);
        chart->addSeries(req_2);
        chart->addSeries(req_3);
        chart->addSeries(g_1);
        chart->addSeries(g_2);
        chart->addSeries(g_3);
        chart->addSeries(f);
        chart->addSeries(ir);
        chart->addSeries(tr);
        chart->addSeries(ds);
        //****************************
        chart->createDefaultAxes();
        chart->setTitle("Transaction View");
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        ui->chart->addWidget(chartView);
        //==================================
        if(no==1){
            QString s;
            if(c2=='A')
            {
              s=DV_A.read(read_idx);
            }
            if(c2=='B')
            {
              s=DV_B.read(read_idx);
            }
            if(c2=='C')
            {
              s=DV_C.read(read_idx);
            }
            //========================================
            if(c1=='A')
            {
                DV_A.write(s);
                for(int i = 0; i < 10; i++){
                         ui->TA->item(i,0)->setText(DV_A.read(i+1));
                      }
            }
            if(c1=='B')
            {
                DV_B.write(s);
                for(int i = 0; i < 10; i++){
                         ui->TB->item(i,0)->setText(DV_B.read(i+1));
                }
            }
            if(c1=='C')
            {
                DV_C.write(s);
                for(int i = 0; i < 10; i++){
                         ui->TC->item(i,0)->setText(DV_C.read(i+1));
                }
            }
        }
        else if(no==2){
            QString s_1,s_2;
            if(c2=='A')
            {
              s_1=DV_A.read(read_idx);
              s_2=DV_A.read(read_idx+1);
            }
            if(c2=='B')
            {
              s_1=DV_B.read(read_idx);
              s_2=DV_B.read(read_idx+1);
            }
            if(c2=='C')
            {
              s_1=DV_C.read(read_idx);
              s_2=DV_C.read(read_idx+1);
            }
            //=============================================
            if(c1=='A')
            {
                DV_A.write(s_1);
                DV_A.write(s_2);
                for(int i = 0; i < 10; i++){
                         ui->TA->item(i,0)->setText(DV_A.read(i+1));
                      }
            }
            if(c1=='B')
            {
                DV_B.write(s_1);
                DV_B.write(s_2);
                for(int i = 0; i < 10; i++){
                         ui->TB->item(i,0)->setText(DV_B.read(i+1));
                }
            }
            if(c1=='C')
            {
                DV_C.write(s_1);
                DV_C.write(s_2);
                for(int i = 0; i < 10; i++){
                         ui->TC->item(i,0)->setText(DV_C.read(i+1));
                }
            }
        }
        else if(no==3){
            QString s_1,s_2,s_3;
            if(c2=='A')
            {
              s_1=DV_A.read(read_idx);
              s_2=DV_A.read(read_idx+1);
              s_3=DV_A.read(read_idx+2);
            }
            if(c2=='B')
            {
              s_1=DV_B.read(read_idx);
              s_2=DV_B.read(read_idx+1);
              s_3=DV_B.read(read_idx+2);
            }
            if(c2=='C')
            {
              s_1=DV_C.read(read_idx);
              s_2=DV_C.read(read_idx+1);
              s_3=DV_C.read(read_idx+2);
            }
            //===========================================
            if(c1=='A')
            {
                DV_A.write(s_1);
                DV_A.write(s_2);
                DV_A.write(s_3);
                for(int i = 0; i < 10; i++){
                         ui->TA->item(i,0)->setText(DV_A.read(i+1));
                      }
            }
            if(c1=='B')
            {
                DV_B.write(s_1);
                DV_B.write(s_2);
                DV_B.write(s_3);
                for(int i = 0; i < 10; i++){
                         ui->TB->item(i,0)->setText(DV_B.read(i+1));
                }
            }
            if(c1=='C')
            {
                DV_C.write(s_1);
                DV_C.write(s_2);
                DV_B.write(s_3);
                for(int i = 0; i < 10; i++){
                         ui->TC->item(i,0)->setText(DV_C.read(i+1));
                }
            }
        }

    }
}
