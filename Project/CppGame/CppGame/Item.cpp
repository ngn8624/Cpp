#include "Item.h"
#include "Consts.h"

#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtWidgets/QGraphicsItemAnimation>
#include <QTimeLine>

Item::Item(EventListener* listener, const std::string& path, int row, int column, QGraphicsItem* parent)
	: QGraphicsPixmapItem(QPixmap(path.c_str()).scaled(Consts::BOARD_ITEM_SIZE, Consts::BOARD_ITEM_SIZE), parent)
	, _listener(listener)
	, _path(path)
	, _row(row)
	, _column(column)
{
	QPixmap pixmap(path.c_str()); // 가져오기만 한다. // R"(C:\PNG\3.png)" : \때문에 R(row string)을 써야지만 \가 제대로 인식, // 두번해도 가능
	QPixmap scaled(pixmap.scaled(Consts::BOARD_ITEM_SIZE, Consts::BOARD_ITEM_SIZE));
}

std::string Item::path() const
{
	return _path;
}

int Item::row() const
{
	return _row;
}

int Item::column() const
{
	return _column;
}

void Item::setRow(int row)
{
	_row = row;
}

void Item::setColumn(int column)
{
	_column = column;
}

void Item::moveTo(double toX, double toY)
{
	double diffX = toX - x();
	double diffY = toY - y();

	double time = 0;
	time += qAbs(diffX) / Consts::BOARD_ITEM_SIZE * Consts::ANIMATION_TIME;
	time += qAbs(diffY) / Consts::BOARD_ITEM_SIZE * Consts::ANIMATION_TIME;

	QTimeLine* timer = new QTimeLine(time);

	QGraphicsItemAnimation* animation = new QGraphicsItemAnimation();
	animation->setTimeLine(timer);
	animation->setItem(this);
	animation->setPosAt(0, pos());
	animation->setPosAt(1, QPointF(toX, toY));

	timer->start();

	connect(timer, &QTimeLine::finished, [this, timer, animation]() {
		delete timer;
		delete animation;
		_listener->itemMoveFinished(this, nullptr);
		});


}

void Item::moveTo(Item* other, bool canRevert)
{
	double toX = other->x();
	double toY = other->y();

	double diffX = toX - x();
	double diffY = toY - y();

	double time = 0;
	time += qAbs(diffX) / Consts::BOARD_ITEM_SIZE * Consts::ANIMATION_TIME;
	time += qAbs(diffY) / Consts::BOARD_ITEM_SIZE * Consts::ANIMATION_TIME;

	QTimeLine* timer = new QTimeLine(time);

	QGraphicsItemAnimation* animation = new QGraphicsItemAnimation();
	animation->setTimeLine(timer);
	animation->setItem(this);
	animation->setPosAt(0, pos());
	animation->setPosAt(1, QPointF(toX, toY));

	timer->start();

	connect(timer, &QTimeLine::finished, [this, other, canRevert,timer, animation]() {
		delete timer;
		delete animation;
		_listener->itemMoveFinished(this, other, canRevert);
		});
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	_pressPos = event->pos();
	
}

void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	// x,y, 좌료 가지고 있음
	QPointF releasePos = event->pos();
	QPointF diff = releasePos - _pressPos;

	Direction dir;

	if (diff.x() == 0 && diff.y() == 0)
	{
		return;
	}


	if (qAbs(diff.x()) > qAbs(diff.y()))
	{
		if (diff.x() > 0)
		{
			dir = Direction::Right;
		}
		else
		{
			dir = Direction::Left;
		}
	}
	else
	{
		if (diff.y() > 0)
		{
			dir = Direction::Down;
		}
		else
		{
			dir = Direction::Up;
		}
	}

	_listener->itemDragEvent(this, dir);
}
