#pragma once

#include <QtWidgets\qgraphicsproxywidget.h>
#include <QtCore\qlist.h>
#include <QtGui\qpainter.h>
#include <QtGui\qtextitem>
#include <QtCore\qdatetime.h>

// Информация о событии
struct Alarm
{
	enum Priority : uint16_t
	{
		Low = 0,
		Medium = 400,
		High =  600,
	};

	Alpha::Binbo::default_string message;
	QDateTime date;
	uint16_t priority;

	Alarm(const Alpha::Binbo::default_string &message, const QDateTime &date, uint16_t priority) :
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
	QColor setColor(uint16_t priority)
	{
		if (priority > Alarm::High)
			return Qt::red;
		else if (priority > Alarm::Medium)
			return Qt::yellow;
		else
			return Qt::white;
	}
};
