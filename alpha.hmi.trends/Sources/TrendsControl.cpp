#include "stdafx.h"

#include "TrendsControl.h"

using namespace Alpha::Hmi::Trends;

////////////////////////////////////////////////////////////////
//	TrendsControl
////////////////////////////////////////////////////////////////
TrendsControl::TrendsControl()
{
	setRect(QRectF(0.0, 0.0, 100.0, 100.0));
	//setPen(Qt::NoPen);
}

TrendsControl::~TrendsControl()
{
}

void TrendsControl::setNativeParent(QGraphicsItem *parent)
{
	// Настроим парентинг
	setParentItem(parent);

	// Если родителя нет, надо убрать элемент со сцены
	if (!parent && scene())
		scene()->removeItem(this);
}

void TrendsControl::setRect(QRectF const &rc)
{
	QGraphicsRectItem::setRect(rc);
	setTransformOriginPoint(rc.center());
}

QPointF TrendsControl::centerPos() const
{
	return pos() + rect().center();
}

void TrendsControl::setCenterPos(QPointF const &pos)
{
	setPos(pos - rect().center());
}
