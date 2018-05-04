#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "Helpers\ReflectionHelpers.h"

#include "Helpers\OverrideQRect.h"


#include "TableInterfaceImpl.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Таблица.
			////////////////////////////////////////////////////////////////////////////////
			class TableControl
				:	public MyQGraphicsRectItem                           
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

				//void SetItemText(Alpha::Binbo::default_string const &data, uint32_t column, uint32_t line);
				void SetItemData(Alpha::Binbo::default_variant const &data, uint32_t column, uint32_t line);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);

			};

		}	//namespace Tables
	}	//namespace Hmi
}	//namespace Alpha
