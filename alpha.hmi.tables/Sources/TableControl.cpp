#include "stdafx.h"

#include "TableControl.h"

using namespace Alpha::Hmi::Tables;

////////////////////////////////////////////////////////////////
//	TableControl
////////////////////////////////////////////////////////////////
TableControl::TableControl()
{
	mas = new cell;
	setRect(QRectF(0.0, 0.0, 100.0, 100.0));
	//setPen(Qt::NoPen);
}

TableControl::~TableControl()
{
}

void TableControl::setNativeParent(QGraphicsItem *parent)
{
	// �������� ���������
	setParentItem(parent);

	// ���� �������� ���, ���� ������ ������� �� �����
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

//Alpha::Binbo::default_string TableControl::GetAxisX() const {  // ���� , ��������� ����� ����������� ������ ��������
//	return "�����, ���";
//}  
//void TableControl::SetAxisX(Alpha::Binbo::default_string const &description) {
//	// ����� �� ������
//}
