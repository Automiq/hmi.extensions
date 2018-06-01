#include "stdafx.h"

#include "AlarmsControl.h"
#include "QtWidgets\qdockwidget.h"
#include <QtWidgets\qgraphicswidget.h>
#include <QtWidgets\qgraphicsproxywidget.h>

using namespace Alpha::Hmi::Alarms;

////////////////////////////////////////////////////////////////
//	AlarmsControl
////////////////////////////////////////////////////////////////
AlarmsControl::AlarmsControl() : verticalScrollBar_(Qt::Vertical), alarmHeight_(20), maxAlarmsCount_(100)
{
	setFlag(ItemClipsChildrenToShape, true);

	alarmsControlProxy_ = new QGraphicsProxyWidget();
	alarmsControlProxy_->setParentItem(this);
	alarmsControlProxy_->setWidget(&alarmsControlWidget_);

	verticalScrollBarProxy_ = new QGraphicsProxyWidget();
	verticalScrollBarProxy_->setParentItem(this);
	verticalScrollBarProxy_->setWidget(&verticalScrollBar_);

	setRect(QRectF(0.0, 0.0, 500.0, 200.0));
	alarmsControlWidget_.resize(0, 0);
	connect(&verticalScrollBar_, &QScrollBar::valueChanged, this, &AlarmsControl::OnVerticalScrollBarChanged);

	verticalScrollBar_.resize(20, this->GetHeight());
	//verticalScrollBar_.setPageStep(200);

	verticalScrollBar_.setEnabled(false);
	//setPen(Qt::NoPen);
}

AlarmsControl::~AlarmsControl()
{
}

void AlarmsControl::addAlarm(uint8_t priotity)
{
	if (alarms_.size() >= maxAlarmsCount_)
	{
		alarms_.first()->hide();
		alarms_.removeFirst();
	}

	alarms_.push_back(QSharedPointer<Alarm>(new Alarm(alarmHeight_, priotity, alarmsControlProxy_)));
}

void AlarmsControl::setNativeParent(QGraphicsItem *parent)
{
	// �������� ���������
	setParentItem(parent);

	// ���� �������� ���, ���� ������ ������� �� �����
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

Alpha::Binbo::default_string AlarmsControl::host() const
{
	return host_;
}

Alpha::Binbo::default_string AlarmsControl::progId() const
{
	return progId_;
}

size_t AlarmsControl::GetMaxAlarmsCount() const
{
	return maxAlarmsCount_;
}

void AlarmsControl::SetMaxAlarmsCount(size_t maxAlarmsCount)
{
	maxAlarmsCount_ = maxAlarmsCount;
}

size_t Alpha::Hmi::Alarms::AlarmsControl::GetAlarmHeight() const
{
	return alarmHeight_;
}

void Alpha::Hmi::Alarms::AlarmsControl::SetAlarmHeight(size_t alarmHeight)
{
	alarmHeight_ = alarmHeight;
}

void AlarmsControl::OnVerticalScrollBarChanged(int value)
{
	auto pos = QPoint(0, -(value));
	alarmsControlWidget_.move(pos);
}

void AlarmsControl::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	verticalScrollBarProxy_->setPos(this->boundingRect().width() - verticalScrollBar_.width(), 0);
	if (alarms_.count() * alarmHeight_ > ceil(this->boundingRect().height()))
		verticalScrollBar_.setEnabled(true);

	verticalScrollBar_.setMaximum(alarms_.count() * alarmHeight_);
	verticalScrollBar_.setFixedHeight(this->rect().height());

	QGraphicsRectItem::paint(painter, option, widget);
}