#ifndef CHECKERSPICTURE_H
#define CHECKERSPICTURE_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QResizeEvent>
#include <QPaintEvent>

#include "checkersstate.h"

/*struct drawPoint{
	int x;
	int y;
	int type;
};*/

/*enum {
	end = 1,
	start = 2,
	normal = 3,
	captured = 4
};*/

class CheckersPicture : public QWidget
{
	Q_OBJECT
public:
	CheckersPicture(QWidget * parent = 0);
	~CheckersPicture();
	CheckersState * state();
	void setComputerColor(uint8 color);
public slots:
	void setState(CheckersState *state);
//	void setVector(QVector <SearchTreeList *> & v);
	void setVector(std::vector <point> & v);
	void deleteVector();
	void setSize(int n);
	void clear();
signals:
	void mouseClicked(int, int);
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	void resizeEvent (QResizeEvent * event);
private:
	QRect pixelRect(int i, int j) const;

	CheckersState * curstate;
	std::vector <point> v;
	QPoint p;
	int side;
	int zoom;
	int n;

	// flags
	//bool mouseClickFlag;
    int color;										// 敌方颜色
};

#endif // CHECKERSPICTURE_H
