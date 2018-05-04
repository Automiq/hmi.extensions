#include "stdafx.h"

#include "TableControl.h"

#include "Helpers\OverrideQRect.h"

using namespace Alpha::Hmi::Tables;

////////////////////////////////////////////////////////////////
//	TableControl
////////////////////////////////////////////////////////////////
TableControl::TableControl()
{
	setFlag(QGraphicsItem::ItemClipsChildrenToShape,true);
	setRect(QRectF(0.0, 0.0, 500.0, 200.0));
	
	//setPen(Qt::NoPen);
}

TableControl::~TableControl()
{
}

void TableControl::setNativeParent(QGraphicsItem *parent)
{
	// Настроим парентинг
	setParentItem(parent);

	// Если родителя нет, надо убрать элемент со сцены
	if (!parent && scene())
		scene()->removeItem(this);
}

void TableControl::setRect(QRectF const &rc)
{
	QGraphicsRectItem::setRect(rc);
	setTransformOriginPoint(rc.center());
}

QPointF TableControl::centerPos() const
{
	return pos() + rect().center();
}

void TableControl::setCenterPos(QPointF const &pos)
{
	setPos(pos - rect().center());
}


void TableControl::SetItemData(Alpha::Binbo::default_variant const &data, uint32_t column, uint32_t line)
{
	//TableData.push_back(Cell(column, line, QString::fromStdString(Alpha::Binbo::to_string(data))));
	TableData.emplace(Cell(column, line), QString::fromStdString(Alpha::Binbo::to_string(data)));
	update();
}
