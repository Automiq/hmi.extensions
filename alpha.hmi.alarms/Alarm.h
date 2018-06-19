#pragma once

#include <QtWidgets\qgraphicsproxywidget.h>
#include <QtCore\qlist.h>
#include <QtGui\qpainter.h>
#include <QtGui\qtextitem>
#include <QtCore\qdatetime.h>

// Информация о событии
struct Alarm
{
	enum Priority : uint8_t
	{
		Low,
		Medium,
		High,
	};

	Alpha::Binbo::default_string message;
	QDateTime date;
	uint8_t priority;

	Alarm(const Alpha::Binbo::default_string &message, const QDateTime &date, uint8_t priority) :
		message(message), date(date), priority(priority)
	{ }
};

// Отображение события
class AlarmView : public QGraphicsRectItem
{
	std::shared_ptr<Alarm> alarm;

public:

	AlarmView(const Alarm& alarm, const uint64_t alarmHeight, const QPointer<QGraphicsProxyWidget> parent)
	{
		assert(parent);

		for (auto& alarm : parent->childItems())
			alarm->setY(alarm->y() + alarmHeight);

		setParentItem(parent);

		setFlag(ItemClipsChildrenToShape, true);
		setRect(QRectF(0.0, 0.0, 500.0, alarmHeight));

		// Установим цвет фона события в зависмости от его приоритета
		setBrush(setColor(alarm.priority));

		//QGraphicsRectItem* date = new QGraphicsRectItem(0, 0.0, 150.0, alarmHeight, this);
		QGraphicsTextItem* dateItem = new QGraphicsTextItem(alarm.date.toString("dd.MM.yyyy hh:mm:ss.zzz"), this);
		dateItem->boundingRect().setWidth(150);

		QGraphicsTextItem* messageItem = new QGraphicsTextItem(QString::fromStdString(alarm.message));
		messageItem->setPos(childItems().last()->x() + childItems().last()->boundingRect().width(), 0);
		messageItem->setParentItem(this);
	}

	// Костыль
	QColor setColor(uint8_t priority)
	{
		switch (priority)
		{
		case Alarm::Low:
			break;
		case Alarm::Medium:
			return Qt::yellow;
		case Alarm::High:
			return Qt::red;
		default:
			break;
		}
		return Qt::white;
	}

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
	{
		//setRect(this->rect().adjusted(0, 0, parentItem()->boundingRect().width(), 0));
		//auto hz = painter->clipBoundingRect();
		//painter->clipBoundingRect().adjust(1, 1, -1, -1);
		////auto hz2 = parentItem()->boundingRect();
		//painter->clipPath().addRect(parentItem()->boundingRect());
		//auto hz3 = painter->clipBoundingRect();
		//painter->setClipRect(parentItem()->boundingRect().adjusted(0, 0, -1, -1));
		//painter->setClipRect(QRectF(0, 0, 0, 0));
		QGraphicsRectItem::paint(painter, option, widget);
	}
};
