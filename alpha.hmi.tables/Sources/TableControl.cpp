#include "stdafx.h"

#include "TableControl.h"

#include "Helpers\OverrideQRect.h"

using namespace Alpha::Hmi::Tables;

////////////////////////////////////////////////////////////////
//	TableControl
////////////////////////////////////////////////////////////////
TableControl::TableControl()
	: control(new MyQGraphicsRectItem(this))
{
	setRect(QRectF(0, 0, 500.0, 200.0));

	control->setParentItem(m_pRoot);
}

TableControl::~TableControl()
{
	control->setParentItem(nullptr);
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

	UpdateScrolls();
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
	control->TableData[MyQGraphicsRectItem::Cell(column, line)] = QString::fromStdString(Alpha::Binbo::to_string(data));
	update();
}

void TableControl::SetColumnCaptionData(Alpha::Binbo::default_variant const &data, uint32_t column)
{
	control->CaptionColumnData[column] = QString::fromStdString(Alpha::Binbo::to_string(data));
	update();
}

void TableControl::SetLineCaptionData(Alpha::Binbo::default_variant const &data, uint32_t line)
{
	control->CaptionLineData[line] = QString::fromStdString(Alpha::Binbo::to_string(data));
	update();
}

void TableControl::SetBrushColor(uint32_t const val)
{
	control->SetBrushColor(val);
}

uint32_t TableControl::GetBrushColor() const
{
	return control->GetBrushColor();
}

void TableControl::SetNumberHorCells(uint32_t HorVal)
{
	control->SetNumberHorCells(HorVal);
}

uint32_t TableControl::GetNumberHorCells() const
{
	return control->GetNumberHorCells();
}

void TableControl::SetNumberVertCells(uint32_t VertVal)
{
	control->SetNumberVertCells(VertVal);
}

uint32_t TableControl::GetNumberVertCells() const
{
	return control->GetNumberVertCells();
}

void TableControl::SetCellsWidth(double CellsWidth)
{
	control->SetCellsWidth(CellsWidth);
}

double TableControl::GetCellsWidth() const
{
	return control->GetCellsWidth();
}

void TableControl::SetCellsHeight(double CellsHeight)
{
	control->SetCellsHeight(CellsHeight);
}

double TableControl::GetCellsHeight() const
{
	return control->GetCellsHeight();
}

void TableControl::SetCaption(bool CaptionFlag)
{
	control->SetCaption(CaptionFlag);
}

bool TableControl::GetCaption() const
{
	return control->GetCaption();
}
