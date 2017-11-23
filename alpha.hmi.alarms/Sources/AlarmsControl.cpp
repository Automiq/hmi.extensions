#include "stdafx.h"

#include "AlarmsControl.h"

using namespace Alpha::Hmi::Alarms;

////////////////////////////////////////////////////////////////
//	AlarmsControl
////////////////////////////////////////////////////////////////
AlarmsControl::AlarmsControl()
{
	setRect(QRectF(0.0, 0.0, 100.0, 100.0));
	//setPen(Qt::NoPen);
}

AlarmsControl::~AlarmsControl()
{
}

void AlarmsControl::setNativeParent(QGraphicsItem *parent)
{
	// Настроим парентинг
	setParentItem(parent);

	// Если родителя нет, надо убрать элемент со сцены
	if (!parent && scene())
		scene()->removeItem(this);
}

void AlarmsControl::setRect(QRectF const &rc)
{
	QGraphicsRectItem::setRect(rc);
	setTransformOriginPoint(rc.center());
}

QPointF AlarmsControl::centerPos() const
{
	return pos() + rect().center();
}

void AlarmsControl::setCenterPos(QPointF const &pos)
{
	setPos(pos - rect().center());
}
