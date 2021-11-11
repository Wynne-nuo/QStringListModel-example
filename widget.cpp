#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    QStringList list;
    list << "beijing" << "shanghia" << "guangzhou" << "guangzhou" << "shenzhen" << "hangzhou" << "shenyang" << "daslian";
    model->setStringList(list);
    ui->listView->setModel(model);
//    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

Widget::~Widget()
{
    delete ui;
}

//添加项
void Widget::on_pushButton_clicked()
{
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount() -1 , 0);
    model->setData(index, "new item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

//插入项
void Widget::on_pushButton_2_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->insertRow(index.row());
    model->setData(index, "new insert item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

//删除项
void Widget::on_pushButton_3_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

//清空列表
void Widget::on_pushButton_4_clicked()
{
    model->removeRows(0,model->rowCount());
}

//显示数据模型数据
void Widget::on_pushButton_5_clicked()
{
    QStringList list = model->stringList();
    for(int i = 0; i < model->rowCount(); i++){
        ui->plainTextEdit->appendPlainText(list.at(i));
    }
}
