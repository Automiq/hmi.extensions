#pragma once

#include "Helpers\HMIVisualFeaturesMixin.h"
#include "Helpers\HMILayoutItemMixin.h"
#include "Helpers\HMIRectImplMixin.h"
#include "Helpers\ReflectionHelpers.h"

#include "Helpers\OverrideQRect.h"
#include "Scroll.h"


#include "TableInterfaceImpl.h"

namespace Alpha {
	namespace Hmi {
		namespace Tables {

			////////////////////////////////////////////////////////////////////////////////
			///	@short
			///		Реализация компонента Таблица.
			////////////////////////////////////////////////////////////////////////////////
			class TableControl
				: public Scrolls::CQtGraphicsScrollArea
				, public alarms_binbo_interface_impl<TableControl>
				, public hmi_features_visual_impl<TableControl>
				, public hmi_layout_item_impl<TableControl>
				, public hmi_rect_impl<TableControl>
				, public Reflection::reflected_visual<TableControl>
				, public Reflection::reflected_rect<TableControl>
			{
				AR_FRIEND

					QScopedPointer<MyQGraphicsRectItem> control;

			public:

				TableControl();
				~TableControl();

				void setNativeParent(QGraphicsItem *parent);

				void setRect(QRectF const &rc);

				void SetItemData(Alpha::Binbo::default_variant const &data, uint32_t column, uint32_t line);
				void SetColumnCaptionData(Alpha::Binbo::default_variant const &data, uint32_t column);
				void SetLineCaptionData(Alpha::Binbo::default_variant const &data, uint32_t line);

				QPointF centerPos() const;
				void setCenterPos(QPointF const &pos);

				void SetBrushColor(uint32_t const val);
				uint32_t GetBrushColor() const;

				void SetNumberHorCells(uint32_t HorVal);
				uint32_t GetNumberHorCells() const;

				void SetNumberVertCells(uint32_t VertVal);
				uint32_t GetNumberVertCells() const;

				void SetCellsWidth(double CellsWidth);
				double GetCellsWidth() const;

				void SetCellsHeight(double CellsHeight);
				double GetCellsHeight() const;

				void SetCaption(bool CaptionFlag);
				bool GetCaption() const;

			};

		}	//namespace Tables
	}	//namespace Hmi
}	//namespace Alpha

