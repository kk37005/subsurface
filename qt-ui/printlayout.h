#ifndef PRINTLAYOUT_H
#define PRINTLAYOUT_H

#include <QPrinter>
#include <QStringList>

class PrintDialog;

class PrintLayout : public QObject {
	Q_OBJECT

public:
	PrintLayout(PrintDialog *, QPrinter *, struct options *);
	void print();

private:
	PrintDialog *dialog;
	QPrinter *printer;
	struct options *printOptions;

	QPainter *painter;
	int screenDpiX, screenDpiY, printerDpi;
	qreal scaleX, scaleY;
	QRect pageRect;

	QStringList tableColumnNames;
	QStringList tableColumnWidths;

	void setup();
	void printSixDives();
	void printTwoDives();
	void printTable();
	QString insertTableHeadingRow();
	QString insertTableHeadingCol(int);
	QString insertTableDataRow(struct dive *);
	QString insertTableDataCol(QString);
};

#endif
