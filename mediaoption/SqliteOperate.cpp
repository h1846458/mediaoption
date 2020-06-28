#include "SqliteOperate.h"

SqliteOperate::SqliteOperate()
{

	
}
bool SqliteOperate::openDb()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("vms.db"); //QApplication::applicationDirPath() +
	if (!db.open())
	{
		qDebug() << "open lose";
		return false;
	}
	return true;
}

void SqliteOperate::createTable(void)
{
	QSqlQuery query;
	bool ok1 = query.exec("CREATE TABLE IF NOT EXISTS  rtspserver (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(30) NOT NULL, deviceid INTEGER NULL, ipaddr VARCHAR(15) NOT NULL, port INT NOT NULL)");
	bool ok2 = query.exec("CREATE TABLE IF NOT EXITS devicetab (id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(30) NOT NULL, devicetype VARCHAR(30) NOT NULL, deviceid INTEGER NULL, username VARCHAR(30) NOT NULL, passwd VARCHAR(30) NOT NULL, ipaddr VARCHAR(15) NOT NULL, port INT NOT NULL)");
	bool ok3 = query.exec();
	if (ok1)
	{
		qDebug() << "ceate table partition success/n";
	}
	else
	{
		qDebug() << "ceate table partition failed/n";
	}
}

void SqliteOperate::addNewcolumn(QString& columnNameAndproperty)
{

}

void SqliteOperate::queryTable(QString& str)
{

}

bool SqliteOperate::IsTaBexists(QString& Tabname)
{
	return true;
}

void SqliteOperate::singleinsertdata()
{

}

void SqliteOperate::Moreinsertdata()
{

}

void SqliteOperate::deletedata()
{

}

void SqliteOperate::updatedata()
{

}

void SqliteOperate::closeDb(void)
{

}


SqliteOperate::~SqliteOperate()
{
}
