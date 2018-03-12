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


void TableControl::SetItemText(Alpha::Binbo::default_string const &text, uint32_t column, uint32_t line)
{
	TableData.push_back(Cell(column, line, Alpha::Binbo::default_string(text)));

	MyQGraphicsRectItem::_UpdateLines();
}





//Alpha::Binbo::default_string TableControl::GetAxisX() const {  // ���� , ��������� ����� ����������� ������ ��������
//	return "�����, ���";
//}  
//void TableControl::SetAxisX(Alpha::Binbo::default_string const &description) {
//	// ����� �� ������
//}
