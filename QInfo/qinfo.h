#pragma once

#include <QtWidgets/QWidget>
#include "ui_qinfo.h"




class QInfo : public QWidget
{
	Q_OBJECT

public:
	QInfo(QWidget *parent = Q_NULLPTR);
	~QInfo();

private slots:
	void on_pushButton_clicked();


private:
	Ui::QInfoClass *ui;
};
