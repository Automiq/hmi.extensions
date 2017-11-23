#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "Helpers\ReflectionHelpers.h"

#include "TableInterfaceImpl.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Таблица.
			////////////////////////////////////////////////////////////////////////////////
			class TableControl
				:	public QGraphicsRectItem
				,	public alarms_binbo_interface_impl<TableControl>
				,	public hmi_features_visual_impl<TableControl>
				,	public hmi_layout_item_impl<TableControl>
				,	public hmi_rect_impl<TableControl>
				,	public Reflection::reflected_visual<TableControl>
				,	public Reflection::reflected_rect<TableControl>
			{
				AR_FRIEND

			public:

				TableControl();
				~TableControl();

				void setNativeParent(QGraphicsItem *parent);

				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);
			};

		}	//namespace Tables
	}	//namespace Hmi
}	//namespace Alpha
