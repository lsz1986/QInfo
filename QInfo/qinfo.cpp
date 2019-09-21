#include "qinfo.h"

#include <QNetworkInterface>
#include <QSettings>


QInfo::QInfo(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::QInfoClass)
{
	ui->setupUi(this);
}


QInfo::~QInfo()
{
	delete ui;
}

void QInfo::on_pushButton_clicked()
{
	//MAC
	QString strMac;
	QList<QNetworkInterface> netList = QNetworkInterface::allInterfaces();
	foreach(QNetworkInterface item, netList)
	{
		if ((QNetworkInterface::IsUp & item.flags()) && (QNetworkInterface::IsRunning & item.flags()))
		{
			if (strMac.isEmpty() || strMac < item.hardwareAddress())
			{
				strMac = item.hardwareAddress();
			}
		}
	}

	//CPU
	QSettings *CPU = new QSettings("HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", QSettings::NativeFormat);
	QString m_cpuDescribe = CPU->value("ProcessorNameString").toString();
	delete CPU;

	ui->textBrowser->clear();
	ui->textBrowser->append(QString(tr("Mac: \n")) + strMac);
	ui->textBrowser->append(QString(tr("CPU ID: \n")) + m_cpuDescribe);
}

