#pragma once

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QApplication>
#include <QDir>
//#include <QList>


class SqliteOperate 
{
public:
	SqliteOperate();
	~SqliteOperate();
public:
	bool openDb();

    //创建数据表（student）
    void createTable(void);

    //在表格中增加新的字段
    void addNewcolumn(QString& columnNameAndproperty);

    //查询和显示结果
    void queryTable(QString& str, QList<QString>& dl);

    //判断数据表是否存在
    bool IsTaBexists(QString& Tabname);

    //插入数据
    void singleinsertdata(const QString& sql);//插入单条数据

    void Moreinsertdata();//插入多条数据

    //删除数据
    void deletedata();

    //修改数据
    void updatedata();

    //关闭数据库
    void closeDb(void);

private:
    QSqlDatabase db;//用于建立和数据库的连接
};
