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

				/// Адрес подключения
				const Alpha::Binbo::default_string path_;

				/// ProgID
				const Alpha::Binbo::default_string progId_;

				/// Максимальное количество отображаемых алармов
				size_t maxAlarmsCount_;

				QWidget alarmsControlWidget_;
				QPointer<QGraphicsProxyWidget> alarmsControlProxy_;

				QScrollBar verticalScrollBar_;
				QPointer<QGraphicsProxyWidget> verticalScrollBarProxy_;

				QScrollBar horisontalScrollBar_;
				QPointer<QGraphicsProxyWidget> horisontalScrollBarProxy_;

				uint64_t alarmHeight_;
				uint64_t alarmWidth_;

				QList<QSharedPointer<Alarm>> alarms_;

			public:

				AlarmsControl();
				~AlarmsControl();

				void addAlarm(uint8_t priotity);

				void setNativeParent(QGraphicsItem *parent);
				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);

				Alpha::Binbo::default_string location() const;
				Alpha::Binbo::default_string progId() const;

				size_t GetMaxAlarmsCount() const;
				void SetMaxAlarmsCount(size_t maxAlarmsCount);

				void OnVerticalScrollBarChanged(int value);

				void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) Q_DECL_OVERRIDE;
			};

		}	//namespace Alarms
	}	//namespace Hmi
}	//namespace Alpha
