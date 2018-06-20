#pragma once

#include <QtWidgets\qlistview.h>
#include <QtWidgets\qscrollbar.h>
#include <QtCore\qpointer.h>
#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "AlarmsInterfaceImpl.h"
#include "Helpers\ReflectionHelpers.h"
#include "..\Alarm.h"

namespace Alpha {
	namespace Hmi {
		namespace Alarms {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Алармов.
			////////////////////////////////////////////////////////////////////////////////
			class AlarmsControl
				:	public QGraphicsRectItem
				,	public QObject
				,	public alarms_binbo_interface_impl<AlarmsControl>
				,	public hmi_features_visual_impl<AlarmsControl>
				,	public hmi_layout_item_impl<AlarmsControl>
				,	public hmi_rect_impl<AlarmsControl>
				,	public Reflection::reflected_visual<AlarmsControl>
				,	public Reflection::reflected_rect<AlarmsControl>
			{
				AR_FRIEND

				/// Максимальное количество отображаемых алармов
				size_t maxAlarmsCount_;

				QWidget alarmsControlWidget_;
				QPointer<QGraphicsProxyWidget> alarmsControlProxy_;

				QScrollBar verticalScrollBar_;
				QPointer<QGraphicsProxyWidget> verticalScrollBarProxy_;

				QScrollBar horisontalScrollBar_;
				QPointer<QGraphicsProxyWidget> horisontalScrollBarProxy_;

				size_t alarmHeight_;
				size_t alarmWidth_;

				QList<QSharedPointer<AlarmView>> alarms_;

			public:

				AlarmsControl();
				~AlarmsControl();

				void addAlarm(uint16_t priotity, const Alpha::Binbo::default_string &message);

				void setNativeParent(QGraphicsItem *parent);
				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);

				size_t GetMaxAlarmsCount() const;
				void SetMaxAlarmsCount(size_t maxAlarmsCount);

				size_t GetAlarmHeight() const;
				void SetAlarmHeight(size_t alarmHeight);

				void OnVerticalScrollBarChanged(int value);

				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_OVERRIDE;
				
				QPainterPath shape() const Q_DECL_OVERRIDE
				{
					QPainterPath path;
					path.addRect(this->boundingRect().adjusted(1, 1, -1, -1));
					return path;
				}
			};

		}	//namespace Alarms
	}	//namespace Hmi
}	//namespace Alpha
