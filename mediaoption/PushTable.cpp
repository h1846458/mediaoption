#include "PushTable.h"

PushTable::PushTable(QObject *parent): QTableView(), chkflag(false)
{
	set_table();
}

void PushTable::set_table()
{
    tb_item = new QStandardItemModel(4, 6);
    this->setModel(tb_item);
    //this->horizontalHeader()->hide();                       // 隐藏水平表头
    this->verticalHeader()->hide(); // 隐藏垂直表头
    tabHeader = new HeaderView(Qt::Horizontal);
    
    this->setHorizontalHeader(tabHeader);

    QStringList column;
    column << QString::fromLocal8Bit("") 
        << QString::fromLocal8Bit("设备名称") 
        << QString::fromLocal8Bit("型号") 
        << QString::fromLocal8Bit("设备IP")
        << QString::fromLocal8Bit("开始时间")
        << QString::fromLocal8Bit("启动推流");
    //row << "row 1" << "row 2" << "row 3" << "row 4";
    tb_item->setHorizontalHeaderLabels(column);                  // 设置水平表头标签
    //tb_item->setVerticalHeaderLabels(row);                     // 设置垂直表头标签


    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
           
            if (j == 0)
            {
                //QStandardItem* it = new QStandardItem(QString("%1").arg(i + j));
                //it->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                //tb_item->setItem(i, j, it);
                QCheckBox* chbox = new QCheckBox();
                chbox->setProperty("rwid", i);
                
                checkblist.append(chbox);
                QWidget* wd = new QWidget;
                QHBoxLayout* boxLayout = new QHBoxLayout();
                boxLayout->addWidget(chbox);
                boxLayout->setMargin(0);
                boxLayout->setAlignment(wd, Qt::AlignCenter);
                boxLayout->setContentsMargins(40, 0, 20, 0);
                wd->setLayout(boxLayout);
                // 添加单元格
                this->setIndexWidget(tb_item->index(i, j), wd);
            }
            else if (j == 5)
            {
                QPushButton* bt = new QPushButton();
                bt->setProperty("rowid", i);
                bt->setStyleSheet(QStringLiteral("QPushButton { background-color:transparent}"));
                QIcon icon;
                icon.addFile(QStringLiteral("res/play_button.png"), QSize(), QIcon::Normal, QIcon::Off);
                bt->setIcon(icon);
                bt->setIconSize(QSize(20, 20));
                this->setIndexWidget(tb_item->index(i, j), bt);
            }
            else
            {
                /*
                QStandardItem* it = new QStandardItem(QString("%1").arg(i + j));
                it->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                tb_item->setItem(i, j, it);
                */
            }
        }     
    }

    QList<QCheckBox*>ls = this->findChildren<QCheckBox*>();
    QList<QPushButton*> bls = this->findChildren<QPushButton*>();
    for (auto i = 0; i < bls.size(); i++)
    {
        QStandardItem* it = new QStandardItem();
        it->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        void(QCheckBox:: * pcheck)(int) = &QCheckBox::stateChanged;
        QObject::connect(ls.at(i), pcheck, this, [=](int state) {
            if (state == Qt::Checked) // "选中"
            {
                checkblist.append(ls.at(i));
            }
            });
        QObject::connect(bls.at(i), &QPushButton::clicked, this, [=]() {

            int rwi = bls.at(i)->property("rowid").toInt();
            if (tb_item->item(rwi, 4) != NULL)
            {
                tb_item->takeItem(0, 0);
            }
            
            tb_item->setItem(rwi, 4, it);
            it->setText(getTime());
            btlist.append(bls.at(i));
            //ls.at(i)->setChecked(true);
            //checkblist.append(ls.at(i));
            //tb_item->setItem(rwi, 4, it);
            //tb_item->setData(tb_item->index(rwi, 4), getTime())
            });
        
    }
    void(HeaderView:: * pheader)(bool) = &HeaderView::onChangeclicked;
    QObject::connect(tabHeader, pheader, this, [=](bool ison) {
        if (ison)
        {
            for (auto ct = ls.begin(); ct != ls.end(); ct++)
            {
                QCheckBox* ch = *ct;
                ch->setChecked(true);
            }
            chkflag = true;
        }
        else
        {
            for (auto ct = ls.begin(); ct != ls.end(); ct++)
            {
                QCheckBox* ch = *ct;
                ch->setChecked(false);
            }
            chkflag = false;
            if (!checkblist.isEmpty())
            {
                checkblist.clear();
            }
            
            qDebug() << "dfasdfasdfasd" << ison;
        }
        
        //tabHeader->setisOn(true);
        });
    this->setColumnWidth(0, int(this->width()/12) * 2);
    this->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch); //设置列宽自适应
    this->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    this->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    this->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
    this->setColumnWidth(5, int(this->width()/12) * 3);
    //this->horizontalHeader()->setStretchLastSection();  // 伸缩最后一列
    //this->setShowGrid(false);                               // 隐藏网格线
    this->setFocusPolicy(Qt::NoFocus);                      // 去除当前Cell周边虚线框
    this->setAlternatingRowColors(true);                    // 开启隔行异色  
}

QString PushTable::getTime()
{
    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    return tmp;
}

PushTable::~PushTable()
{

}
