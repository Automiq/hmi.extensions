#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "Helpers\ReflectionHelpers.h"

#include "TrendsInterfaceImpl.h"

namespace Alpha {
	namespace Hmi {
		namespace Trends {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Трендов.
			////////////////////////////////////////////////////////////////////////////////
			class TrendsControl
				:	public QGraphicsRectItem
				,	public trends_binbo_interface_impl<TrendsControl>
				,	public hmi_features_visual_impl<TrendsControl>
				,	public hmi_layout_item_impl<TrendsControl>
				,	public hmi_rect_impl<TrendsControl>
				,	public Reflection::reflected_visual<TrendsControl>
				,	public Reflection::reflected_rect<TrendsControl>
			{
				AR_FRIEND

			public:

				TrendsControl();
				~TrendsControl();

				void setNativeParent(QGraphicsItem *parent);

				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);
			};

		}	//namespace Trends
	}	//namespace Hmi
}	//namespace Alpha
