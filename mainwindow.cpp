#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "/root/Source/Permutation/Permutation/Permute.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->processPushButton, SIGNAL(clicked()), this, SLOT(processList()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterPushButton_clicked()
{
    QString word = ui->wordsLineEdit->text();
    if(!word.isEmpty())
    {
        QListWidgetItem *item = new QListWidgetItem(word);
        ui->wordsListWidget->addItem(item);
    }
    ui->wordsLineEdit->clear();

    return;
}

void MainWindow::deletePressed()
{
    qDeleteAll (ui->wordsListWidget->selectedItems());
}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Delete)
    {
        this->deletePressed();
    }
}

void MainWindow::processList()
{
    int count = ui->wordsListWidget->count();
    for( int i = 0; i < count; i++)
    {
        vec.push_back(ui->wordsListWidget->item(i)->text().toStdString());
        qDebug() << "vec: " << ui->wordsListWidget->item(i)->text();
    }

    vector<string> list = Permute::fromVector(vec);
    std::vector<string>::iterator it = list.begin();
    while(it != list.end())
    {
        string a = *it;
        QString str = QString::fromStdString(a);
        ui->outputTextBrowser->append(str);
        it++;
    }
    //delete &it;
    vec.clear();
    list.clear();
}
