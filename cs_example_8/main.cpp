#include <QtCore>
#include <QtGui>
 
class MainWindow : public QWidget
{
 public:
   MainWindow();
};

MainWindow::MainWindow()
{
   setMinimumSize(700, 350);
 
   QSpinBox *spinBox = new QSpinBox;
   spinBox->setMinimum(0);
   spinBox->setMaximum(100);
 
   QFont font = spinBox->font();
   font.setPointSize(10);
   spinBox->setFont(font);
 
   QProgressBar *progressBar = new QProgressBar;
   progressBar->setMinimum(0);
   progressBar->setMaximum(100);
 
   QSlider *slider = new QSlider;
   slider->setMinimum(0);
   slider->setMaximum(100);
 
   QDial *dial = new QDial;
   dial->setMinimum(0);
   dial->setMaximum(100);
 
   QPushButton *pb_1 = new QPushButton();
   pb_1->setText("Close");
 
   QGridLayout *grid1 = new QGridLayout();
   grid1->setContentsMargins(75, 45, 75, 25);
   grid1->setHorizontalSpacing(20);
   grid1->setVerticalSpacing(45);
 
   grid1->addWidget(spinBox, 0, 0);
   grid1->addWidget(progressBar, 0, 1);
   grid1->addWidget(slider, 1, 0, Qt::AlignHCenter);
   grid1->addWidget(dial, 1, 1, Qt::AlignHCenter);
 
   QHBoxLayout *layout1 = new QHBoxLayout();
   layout1->addStretch();
   layout1->addWidget(pb_1);
   layout1->addStretch();
 
   QVBoxLayout *layoutMain = new QVBoxLayout(this);
   layoutMain->addLayout(grid1);
   layoutMain->addSpacing(75);
   layoutMain->addLayout(layout1);
 
   connect(spinBox, 
         cs_mp_cast<int>(&QSpinBox::valueChanged), 
         progressBar, &QProgressBar::setValue);
 
   connect(progressBar, 
         cs_mp_cast<int>(&QProgressBar::valueChanged), 
         slider, &QSlider::setValue);
 
   connect(slider, 
         cs_mp_cast<int>(&QSlider::valueChanged), 
         dial, &QSlider::setValue);
 
   connect(dial, 
         cs_mp_cast<int>(&QDial::valueChanged), 
         spinBox, &QSpinBox::setValue);
 
   connect(pb_1, &QPushButton::clicked, 
         this, &QWidget::close);
 
   spinBox->setValue(42);
}

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
 
   MainWindow *window = new MainWindow();
   window->show();
 
   return app.exec();
}
