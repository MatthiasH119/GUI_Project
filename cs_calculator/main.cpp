#include <QtCore>
#include <QtGui>
#include <iostream>
 
class MainWindow : public QWidget
{
 private:
   void AddButton();
   void SubButton();
   void MulButton();
   void DivButton();
   void ClearButton();
   void Change_z1();
   void Change_z2();
   void Change_erg();

   QLineEdit *text_z1;
   QLineEdit *operator_text;
   QLineEdit *text_z2;
   QLineEdit *text_erg;

   double zahl_1 = 0.0;
   double zahl_2 = 0.0;
   char operation = '+';
   double ergebnis = 0.0;

 public:
   MainWindow();

};

MainWindow::MainWindow()
{
   setMinimumSize(700, 350);
 
   //Erstellen von Überschriften
   QLabel *label_1 = new QLabel(
        "<h3>Zahl 1 eingeben</h3>");
      label_1->setAlignment(Qt::AlignHCenter);
   QLabel *label_2 = new QLabel(
        "<h3>operator auswählen</h3>");
      label_2->setAlignment(Qt::AlignHCenter);
   QLabel *label_3 = new QLabel(
        "<h3>Zahl 2 eingeben</h3>");
      label_3->setAlignment(Qt::AlignHCenter);
   QLabel *label_erg = new QLabel(
        "<h3>Ergebnis</h3>");
      label_3->setAlignment(Qt::AlignHCenter);

   //Textfeld Zahl1
   text_z1 = new QLineEdit();
   text_z1->setMinimumSize(200, 35);
   text_z1->setEchoMode(QLineEdit::Normal);
   text_z1->setAlignment(Qt::AlignHCenter);

   //Textfeld Operator
   operator_text = new QLineEdit();
   operator_text->setMinimumSize(200, 35);
   operator_text->setAlignment(Qt::AlignHCenter);

   //Textfeld Zahl2
   text_z2 = new QLineEdit();
   text_z2->setMinimumSize(200, 35);
   text_z2->setEchoMode(QLineEdit::Normal);
   text_z2->setAlignment(Qt::AlignHCenter);

   //Textfeld Ergebnis
   text_erg = new QLineEdit();
   text_erg->setMinimumSize(200, 35);
   text_erg->setEchoMode(QLineEdit::Normal);
   text_erg->setAlignment(Qt::AlignHCenter);

   //Anlegen der Buttons
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

   //Gestaltung des Layouts für die Inputs
   QGridLayout *grid_input = new QGridLayout();
   grid_input->setContentsMargins(75, 45, 75, 25);
   grid_input->setHorizontalSpacing(20);
   grid_input->setVerticalSpacing(45); 

   grid_input->addWidget(label_1,          0,    0);
   grid_input->addWidget(text_z1,          1,    0);
   grid_input->addWidget(label_2,          0,    1);
   grid_input->addWidget(operator_text,    1,    1);
   grid_input->addWidget(label_3,          0,    2);
   grid_input->addWidget(text_z2,          1,    2);

   //Gestaltung des Layouts für die Outputs
   QGridLayout *grid_output = new QGridLayout();
   grid_output->setContentsMargins(75, 45, 75, 25);
   grid_output->setHorizontalSpacing(20);
   grid_output->setVerticalSpacing(45); 

   grid_output->addWidget(label_erg,        0,    0);
   grid_output->addWidget(text_erg,         1,    0);

   //Gestaltung des Layouts für die Buttons
   QGridLayout *grid_buttons = new QGridLayout();
   grid_buttons->setContentsMargins(75, 45, 75, 25);
   grid_buttons->setHorizontalSpacing(20);
   grid_buttons->setVerticalSpacing(45); 

   grid_buttons->addWidget(pb_add,         0,    0);
   grid_buttons->addWidget(pb_sub,         0,    1);
   grid_buttons->addWidget(pb_mul,         0,    2);
   grid_buttons->addWidget(pb_div,         0,    3);
   grid_buttons->addWidget(pb_clear,       1,    0);
   grid_buttons->addWidget(pb_exe,         1,    3);

   //Gestaltung des Exit Layouts
   QHBoxLayout *layout_exit = new QHBoxLayout();
   layout_exit->addStretch();
   layout_exit->addWidget(pb_ex);
   layout_exit->addStretch();
 
   //Gestaltung des Main Layouts aus den einzelnen Layouts
   QVBoxLayout *layoutMain = new QVBoxLayout(this);
   layoutMain->addLayout(grid_input);
   layoutMain->addSpacing(10);
   layoutMain->addLayout(grid_buttons);
   layoutMain->addSpacing(75);
   layoutMain->addLayout(grid_output);
   layoutMain->addSpacing(75);
   layoutMain->addLayout(layout_exit);
 
   //Connecten der Buttons
   connect(pb_add, &QPushButton::clicked,       this, &MainWindow::AddButton);
   connect(pb_sub, &QPushButton::clicked,       this, &MainWindow::SubButton);
   connect(pb_mul, &QPushButton::clicked,       this, &MainWindow::MulButton);
   connect(pb_div, &QPushButton::clicked,       this, &MainWindow::DivButton);

   connect(pb_clear, &QPushButton::clicked,     this, &MainWindow::ClearButton);
   connect(pb_exe,   &QPushButton::clicked,     this, &MainWindow::Change_erg);

   connect(pb_ex, &QPushButton::clicked,        this, &QWidget::close);
 
}

//Funktionen der Buttons
void MainWindow::AddButton()
{
   operator_text->setText("+");
   operation='+';
}
void MainWindow::SubButton()
{
   operator_text->setText("-");
   operation='-';
}
void MainWindow::MulButton()
{
   operator_text->setText("*");
   operation='*';
}
void MainWindow::DivButton()
{
   operator_text->setText("/");
   operation='/';
}
void MainWindow::ClearButton()
{
   text_z1->setText("");
   zahl_1=0;
   operator_text->setText("");
   operation='+';
   text_z2->setText("");
   zahl_2=0;
}

void MainWindow::Change_erg()
{
   //mit displayText() kann aus QLineEdit heraus gelesen werden.
   //Format bei Auslesen: QString, daher QString zu Double konvertieren und anschließend zurück!
   QString QStr_zahl1 = text_z1->displayText();
   QString QStr_zahl2 = text_z2->displayText();
   zahl_1 = QStr_zahl1.toDouble();
   zahl_2 = QStr_zahl2.toDouble();

   switch (operation)
   {
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
      ergebnis = zahl_1 / zahl_2;
      break;
   
   default:
      ergebnis = 00000;
      break;
   }

   text_erg->setText(QString::number(ergebnis));
}

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
 
   MainWindow *window = new MainWindow();
   window->show();
 
   return app.exec();
}
