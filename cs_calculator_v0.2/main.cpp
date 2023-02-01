#include <QtCore>
#include <QtGui>
#include <iostream>
 
class MainWindow : public QWidget
{
 private:
   //Funktionen der Buttons
   void AddButton();
   void SubButton();
   void MulButton();
   void DivButton();
   void ClearButton();
   void Button_0();
   void Button_1();
   void Button_2();
   void Button_3();
   void Button_4();
   void Button_5();
   void Button_6();
   void Button_7();
   void Button_8();
   void Button_9();
   void NegButton();
   void DezButton();
   void Change_z1();
   void Change_z2();
   void Change_erg();
   void exe_operation();

   //Erstellung der Textfelder
   //"hist": Textfelder der Rechenhistorie
   QLineEdit *text_erg;
   QLineEdit *text_hist_0;
   QLineEdit *text_hist_1;
   QLineEdit *text_hist_2;
   QLineEdit *text_hist_3;
   QLineEdit *text_hist_4;
   QLineEdit *text_hist_5;

   //Erstellung von Variablen
   double zahl_1 = 0.0;
   double zahl_2 = 0.0;
   char operation = 'x';
   double ergebnis = 0.0;

 public:
   MainWindow();
};

MainWindow::MainWindow()
{
   setMinimumSize(900, 600);

   //Konfiguration der Textfelder
   text_erg = new QLineEdit();
   text_erg->setMinimumSize(200, 35);
   text_erg->setEchoMode(QLineEdit::Normal);
   text_erg->setAlignment(Qt::AlignHCenter);

   text_hist_0 = new QLineEdit();
   text_hist_0->setMinimumSize(200, 35);
   text_hist_0->setEchoMode(QLineEdit::Normal);
   text_hist_0->setAlignment(Qt::AlignHCenter);

   text_hist_1 = new QLineEdit();
   text_hist_1->setMinimumSize(200, 35);
   text_hist_1->setEchoMode(QLineEdit::Normal);
   text_hist_1->setAlignment(Qt::AlignHCenter);

   text_hist_2 = new QLineEdit();
   text_hist_2->setMinimumSize(200, 35);
   text_hist_2->setEchoMode(QLineEdit::Normal);
   text_hist_2->setAlignment(Qt::AlignHCenter);

   text_hist_3 = new QLineEdit();
   text_hist_3->setMinimumSize(200, 35);
   text_hist_3->setEchoMode(QLineEdit::Normal);
   text_hist_3->setAlignment(Qt::AlignHCenter);

   text_hist_4 = new QLineEdit();
   text_hist_4->setMinimumSize(200, 35);
   text_hist_4->setEchoMode(QLineEdit::Normal);
   text_hist_4->setAlignment(Qt::AlignHCenter);

   text_hist_5 = new QLineEdit();
   text_hist_5->setMinimumSize(200, 35);
   text_hist_5->setEchoMode(QLineEdit::Normal);
   text_hist_5->setAlignment(Qt::AlignHCenter);

   //Erstellung und Konfiguration der Buttons
   QPushButton *pb_ex = new QPushButton();
   pb_ex->setText("Close");
   QPushButton *pb_clear = new QPushButton();
   pb_clear->setText("clear");
   QPushButton *pb_add = new QPushButton();
   pb_add->setText("+");
   QPushButton *pb_sub = new QPushButton();
   pb_sub->setText("-");
   QPushButton *pb_mul = new QPushButton();
   pb_mul->setText("*");
   QPushButton *pb_div = new QPushButton();
   pb_div->setText("/");
   QPushButton *pb_exe = new QPushButton();
   pb_exe->setText("=");
   QPushButton *pb_0 = new QPushButton();
   pb_0->setText("0");
   QPushButton *pb_1 = new QPushButton();
   pb_1->setText("1");
   QPushButton *pb_2 = new QPushButton();
   pb_2->setText("2");
   QPushButton *pb_3 = new QPushButton();
   pb_3->setText("3");
   QPushButton *pb_4 = new QPushButton();
   pb_4->setText("4");
   QPushButton *pb_5 = new QPushButton();
   pb_5->setText("5");
   QPushButton *pb_6 = new QPushButton();
   pb_6->setText("6");
   QPushButton *pb_7 = new QPushButton();
   pb_7->setText("7");
   QPushButton *pb_8 = new QPushButton();
   pb_8->setText("8");
   QPushButton *pb_9 = new QPushButton();
   pb_9->setText("9");
   QPushButton *pb_neg = new QPushButton();
   pb_neg->setText("+/-");
   QPushButton *pb_dez = new QPushButton();
   pb_dez->setText(",");

   //Erstellung eines Grids
   QGridLayout *grid = new QGridLayout();
   grid->setContentsMargins(100, 50, 100, 25);
   grid->setHorizontalSpacing(20);
   grid->setVerticalSpacing(45); 

   //Gestaltung des Layouts für die Buttons
   grid->addWidget(pb_0,           4,    1);
   grid->addWidget(pb_1,           3,    0);
   grid->addWidget(pb_2,           3,    1);
   grid->addWidget(pb_3,           3,    2);
   grid->addWidget(pb_4,           2,    0);
   grid->addWidget(pb_5,           2,    1);
   grid->addWidget(pb_6,           2,    2);
   grid->addWidget(pb_7,           1,    0);
   grid->addWidget(pb_8,           1,    1);
   grid->addWidget(pb_9,           1,    2);
   grid->addWidget(pb_neg,         4,    0);
   grid->addWidget(pb_dez,         4,    2);
   grid->addWidget(pb_add,         1,    3);
   grid->addWidget(pb_sub,         2,    3);
   grid->addWidget(pb_mul,         3,    3);
   grid->addWidget(pb_div,         4,    3);
   grid->addWidget(pb_clear,       5,    0,    1,    2);
   grid->addWidget(pb_exe,         5,    2,    1,    2);

   //Gestaltung des Layouts für die Outputs
   grid->addWidget(text_erg,       0,    0,    1,    4);
   grid->addWidget(text_hist_0,    0,    4);
   grid->addWidget(text_hist_1,    1,    4);
   grid->addWidget(text_hist_2,    2,    4);
   grid->addWidget(text_hist_3,    3,    4);
   grid->addWidget(text_hist_4,    4,    4);
   grid->addWidget(text_hist_5,    5,    4);

   //Gestaltung des Exit Layouts
   QHBoxLayout *layout_exit = new QHBoxLayout();
   layout_exit->addStretch();
   layout_exit->addWidget(pb_ex);
   layout_exit->addStretch();
 
   //Gestaltung des Main Layouts aus den einzelnen Layouts
   QVBoxLayout *layoutMain = new QVBoxLayout(this);
   layoutMain->addLayout(grid);
   layoutMain->addSpacing(75);
   layoutMain->addLayout(layout_exit);
 
   //Connecten der Buttons
   connect(pb_0,     &QPushButton::clicked,     this, &MainWindow::Button_0);
   connect(pb_1,     &QPushButton::clicked,     this, &MainWindow::Button_1);
   connect(pb_2,     &QPushButton::clicked,     this, &MainWindow::Button_2);
   connect(pb_3,     &QPushButton::clicked,     this, &MainWindow::Button_3);
   connect(pb_4,     &QPushButton::clicked,     this, &MainWindow::Button_4);
   connect(pb_5,     &QPushButton::clicked,     this, &MainWindow::Button_5);
   connect(pb_6,     &QPushButton::clicked,     this, &MainWindow::Button_6);
   connect(pb_7,     &QPushButton::clicked,     this, &MainWindow::Button_7);
   connect(pb_8,     &QPushButton::clicked,     this, &MainWindow::Button_8);
   connect(pb_9,     &QPushButton::clicked,     this, &MainWindow::Button_9);

   connect(pb_add,   &QPushButton::clicked,     this, &MainWindow::AddButton);
   connect(pb_sub,   &QPushButton::clicked,     this, &MainWindow::SubButton);
   connect(pb_mul,   &QPushButton::clicked,     this, &MainWindow::MulButton);
   connect(pb_div,   &QPushButton::clicked,     this, &MainWindow::DivButton);

   connect(pb_neg,   &QPushButton::clicked,     this, &MainWindow::NegButton);
   connect(pb_dez,   &QPushButton::clicked,     this, &MainWindow::DezButton);
   connect(pb_clear, &QPushButton::clicked,     this, &MainWindow::ClearButton);
   connect(pb_exe,   &QPushButton::clicked,     this, &MainWindow::Change_erg);

   connect(pb_ex,    &QPushButton::clicked,     this, &QWidget::close);
 
}

//Funktionen der Buttons
void MainWindow::AddButton()
{
   operation='+';
   exe_operation();
}
void MainWindow::SubButton()
{
   operation='-';
   exe_operation();
}
void MainWindow::MulButton()
{
   operation='*';
   exe_operation();
}
void MainWindow::DivButton()
{
   operation='/';
   exe_operation();
}
void MainWindow::exe_operation()
{
   zahl_1 = text_erg->text().toDouble();
   text_erg->setText("");
   text_hist_0->setText(QString::number(zahl_1));
   text_hist_0->insert(QString(QChar::fromLatin1(operation)));
}
void MainWindow::ClearButton()
{
   text_erg    -> setText("");
   text_hist_0 -> setText("");
   zahl_1=0;
   operation='x';
   zahl_2=0;
}
void MainWindow::NegButton()
{
   double temp  = text_erg->text().toDouble();
   temp = temp * (-1);
   text_erg->setText(QString::number(temp));
   if(operation == 'x') {
      text_hist_0->setText(text_erg->text());
   }
   else {
      text_hist_0->setText(QString::number(zahl_1));
      text_hist_0->insert(QString(QChar::fromLatin1(operation)));
      text_hist_0->insert(text_erg->text());
   }
}
void MainWindow::DezButton()
{
   if(text_erg->text().contains(".")) {}
   else {
      text_erg->insert(".");
      text_hist_0->insert(".");   
   }
}

//Funktionen der Zahlen
void MainWindow::Button_0()
{
   text_erg    ->insert("0");
   text_hist_0 ->insert("0");
}
void MainWindow::Button_1()
{
   text_erg    ->insert("1");
   text_hist_0 ->insert("1");
}
void MainWindow::Button_2()
{
   text_erg    ->insert("2");
   text_hist_0 ->insert("2");
}
void MainWindow::Button_3()
{
   text_erg    ->insert("3");
   text_hist_0 ->insert("3");
}
void MainWindow::Button_4()
{
   text_erg    ->insert("4");
   text_hist_0 ->insert("4");
}
void MainWindow::Button_5()
{
   text_erg    ->insert("5");
   text_hist_0 ->insert("5");
}
void MainWindow::Button_6()
{
   text_erg    ->insert("6");
   text_hist_0 ->insert("6");
}
void MainWindow::Button_7()
{
   text_erg    ->insert("7");
   text_hist_0 ->insert("7");
}
void MainWindow::Button_8()
{
   text_erg    ->insert("8");
   text_hist_0 ->insert("8");
}
void MainWindow::Button_9()
{
   text_erg    ->insert("9");
   text_hist_0 ->insert("9");
}

void MainWindow::Change_erg()
{
   zahl_2 = text_erg->text().toDouble();

   switch (operation)
   {
   case 'x':
      ergebnis = ergebnis;
   case '+':
      ergebnis = zahl_1 + zahl_2;
      break;
   case '-':
      ergebnis = zahl_1 - zahl_2;
      break;
   case '*':
      ergebnis = zahl_1 * zahl_2;
      break;
   case '/':
      if (zahl_2 == 0) {
         break;
         }
      else {
         ergebnis = zahl_1 / zahl_2;
         break;
         }
   
   default:
      ergebnis = 00000;
      break;
   }
   
   if (operation == '/' && zahl_2 == 0){
      text_erg->setText("Syntax Error!");	
      text_hist_0->insert(" -> Syntax Error!");
      }
   else {
      text_erg->setText(QString::number(ergebnis));
      text_hist_0->insert(" = ");
      text_hist_0->insert(QString::number(ergebnis));
      }
   text_hist_5->setText(text_hist_4->text());
   text_hist_4->setText(text_hist_3->text());
   text_hist_3->setText(text_hist_2->text());
   text_hist_2->setText(text_hist_1->text());
   text_hist_1->setText(text_hist_0->text());
   text_hist_0->setText("");
}

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
 
   MainWindow *window = new MainWindow();
   window->show();
 
   return app.exec();
}
