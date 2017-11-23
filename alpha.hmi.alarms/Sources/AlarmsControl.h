#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "AlarmsInterfaceImpl.h"
#include "Helpers\ReflectionHelpers.h"

namespace Alpha {
	namespace Hmi {
		namespace Alarms {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Алармов.
			////////////////////////////////////////////////////////////////////////////////
			class AlarmsControl
				:	public QGraphicsRectItem
				,	public alarms_binbo_interface_impl<AlarmsControl>
				,	public hmi_features_visual_impl<AlarmsControl>
				,	public hmi_layout_item_impl<AlarmsControl>
				,	public hmi_rect_impl<AlarmsControl>
				,	public Reflection::reflected_visual<AlarmsControl>
				,	public Reflection::reflected_rect<AlarmsControl>
			{
				AR_FRIEND

			public:

				AlarmsControl();
				~AlarmsControl();

				void setNativeParent(QGraphicsItem *parent);

				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);
			};

		}	//namespace Alarms
	}	//namespace Hmi
}	//namespace Alpha
