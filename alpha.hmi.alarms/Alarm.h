#pragma once

#include <QtCore\qabstractitemmodel.h>
#include <QtWidgets\qgraphicsproxywidget.h>
#include <QtCore\qlist.h>
#include <QtGui\qpainter.h>
#include <QtGui\qtextitem>
#include <QtCore\qdatetime.h>

class Alarm : public QGraphicsRectItem
{
	Alpha::Binbo::default_string message_;
	QDateTime date_;

public:
	enum Priority : uint8_t
	{
		Low,
		Medium,
		High,
	};

	enum Column : uint8_t
	{
		Date,
		Message,
		LastColumn = Message,
		ColumnCount = LastColumn + 1,
	};

	Alarm(uint64_t alarmHeight, uint8_t priority, QPointer<QGraphicsProxyWidget> parent)
	{
		for (auto& alarm : parent->childItems())
			alarm->setY(alarm->y() + 20);

		setParentItem(parent);

		setFlag(ItemClipsChildrenToShape, true);
		setRect(QRectF(0.0, 0.0, 500.0, alarmHeight));
		setBrush(setColor(priority));

		// Пока захардкодим
		message_ = "Sdd";
		date_ = QDateTime::currentDateTime();

		//QGraphicsRectItem* date = new QGraphicsRectItem(0, 0.0, 150.0, alarmHeight, this);
		QGraphicsTextItem* txt = new QGraphicsTextItem(date_.toString("dd.MM.yyyy hh:mm:ss.zzz"), this);
		txt->boundingRect().setWidth(150);

		QGraphicsTextItem* txt2 = new QGraphicsTextItem(QString::fromStdString(message_));
		txt2->setPos(childItems().last()->x() + childItems().last()->boundingRect().width(), 0);
		txt2->setParentItem(this);
	}

	// Костыль
	QColor setColor(uint8_t pr)
	{
		switch (pr)
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
};
