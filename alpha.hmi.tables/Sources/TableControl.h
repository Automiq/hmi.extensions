#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "Helpers\ReflectionHelpers.h"

//!
#include "c:\Users\Aleksey\hmi.extensions\externals\Alpha.Foundation\Reflection\Macro.h"

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
				:	public MyQGraphicsRectItem                           // my add
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

				void setNativeParent(QGraphicsItem *parent);  // установить прямого родителя

				void setRect(QRectF const &rc);

				void SetItemText(Alpha::Binbo::default_string const &text, uint32_t column, uint32_t line);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);


				


				//Alpha::Binbo::default_string GetAxisX() const;   // СВОЕ , ДОБАВЛЯЕМ новую возможность внести абсциссу
				//void SetAxisX(Alpha::Binbo::default_string const &description);
			};

		}	//namespace Tables
	}	//namespace Hmi
}	//namespace Alpha
