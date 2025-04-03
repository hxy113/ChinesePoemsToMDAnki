#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trick.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("古诗文分句");
}

MainWindow::~MainWindow()
{
    delete ui;
}
QStringList a;
//qstr blocklist=QString::fromUtf8(u8"、，,。.；;：:？?");
qstr blocklist;
bool isblock(QChar ch)
{
    for(QChar i:blocklist) if(ch==i) return 1;
    return 0;
}
bool isnull(QChar ch)
{
    return ch==u' '||ch==u'\n';
}
void win::spilt()
{
    a.clear();
    qstr tmp="",in=ui->input->toPlainText();
    int n=in.size()-1;
    for(int i=0;i<=n;++i)
    {
        if(isblock(in[i]))
        {
            a.append(tmp);
            tmp="";
        }
        else if(!isnull(in[i])) tmp+=in[i];
    }
}
void win::trim()
{
    blocklist=ui->sep->text();
    spilt();
    qstr tag=ui->tag->text(),tmp="";
    int n=a.size()-1;

    for(int i=1;i<=n;++i)
    {
        qstr la=a[i-1]+"->",nx="<-"+a[i];
        tmp+="## "+la+"\n";
        tmp+=nx+"\n";
        tmp+=tag+"\n";
        tmp+="## "+nx+"\n";
        tmp+=la+"\n";
        tmp+=tag+"\n";
    }
    ui->preview->setText(tmp);
}

void win::out()
{
    /*QString filePath=QFileDialog::getOpenFileName(
        this,
        "选择数据文件",
        QDir::homePath(),
        "markdown文件(*.md);;文本文件 (*.txt);;所有文件 (*.*)"
    );*/
    QString filePath=QFileDialog::getExistingDirectory(
                this,
                "选择导出目录",
                QDir::homePath()
    );
    filePath+="/";
    filePath+=ui->fname->text();
    if(!filePath.isEmpty())
    {
        QFile file(filePath);
        if(file.open(QIODevice::ReadWrite))
        {
            //QTextStream stream(&file);
            qstr tmp=ui->preview->toPlainText();
            //stream<<tmp;

            //QBiteArray tmpdata=tmp.toUtf8();

            //if(stream.status()==QTextStream::Ok)
            //if(file.write(tmpdata)==tmpdata.size())
            if(file.write(tmp.toUtf8())!=-1)
            {
                QMessageBox::information(
                    this,
                    "导出成功",
                    QString("已成功导出到：\n%1\n字符数量：%2")
                    .arg(filePath).arg(tmp.size())
                );
            }
            else
            {
                QMessageBox::critical(this,"错误","导出失败");
            }
            file.close();
        }
        else
        {
            QMessageBox::critical(this,"错误","无法打开文件");
        }
    }
}
void MainWindow::on_out_clicked()
{
    trim();
    out();
}

void MainWindow::on_previs_clicked()
{
    trim();
}
