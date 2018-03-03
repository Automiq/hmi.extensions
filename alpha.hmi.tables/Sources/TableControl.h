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


			class cell : public QGraphicsRectItem {                                                              // ячейка таблицы
				double x, y, w, h;
			public:
				cell() : x(0), y(0), w(50), h(50) {};
				cell(qreal x, qreal y, qreal w, qreal h) : x(x), y(y), w(w), h(h) {};
				~cell() {};
			};

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
				cell* mas;  //!!!!

				TableControl();
				~TableControl();

				void setNativeParent(QGraphicsItem *parent);  // установить прямого родителя

				void setRect(QRectF const &rc);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);


				


				//Alpha::Binbo::default_string GetAxisX() const;   // СВОЕ , ДОБАВЛЯЕМ новую возможность внести абсциссу
				//void SetAxisX(Alpha::Binbo::default_string const &description);
			};

		}	//namespace Tables
	}	//namespace Hmi
}	//namespace Alpha
