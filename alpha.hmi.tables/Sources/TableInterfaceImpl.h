#pragma once

#include "Helpers\mixin.h"

template <typename Implementation>
class alarms_binbo_interface_impl
	:	public HMIObjects::IRect
	,	protected mixin<Implementation>
{
protected:

	// Alpha::Binbo::i_common interface
	ALPHA_BINBO_PUBLISH_INTERFACES(HMIObjects::IRect)

public:

	// HMIFeatures::IBase interface
	BINBO_FUNC get_object_ptr(void **object_ptr) override
	{
		try
		{
			to_impl(this)->get_object_ptr_impl(object_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC notify_child_added(Alpha::Binbo::i_common *child_ptr) override
	{
		try
		{
			to_impl(this)->notify_child_added_impl(child_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC notify_child_removed(Alpha::Binbo::i_common *child_ptr) override
	{
		try
		{
			to_impl(this)->notify_child_removed_impl(child_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// Alpha::Om::Native::IRequiresParent interface
	BINBO_FUNC SetParent(Alpha::Binbo::i_common_ptr const &parentCommon, Alpha::Om::IObjectConstPtr const &parentDefinition) override
	{
		try
		{
			to_impl(this)->SetParent_impl(parentCommon, parentDefinition);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC IsValidParent(bool &isValid, Alpha::Binbo::i_common_ptr const &parentCommon, Alpha::Om::IObjectConstPtr const &parentDefinition) override
	{
		try
		{
			isValid = to_impl(this)->IsValidParent_impl(parentCommon, parentDefinition);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// Alpha::Om::Native::IRequiresResources interface
	BINBO_FUNC SetResourceFolder(Alpha::Binbo::string_val const &resourceFolder) override
	{
		try
		{
			to_impl(this)->SetResourceFolder_impl(resourceFolder);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// Alpha::Om::Native::ISupportsMove interface
	BINBO_FUNC MoveBefore(Alpha::Binbo::i_common_ptr const &visualCommon) final override
	{
		try
		{
			to_impl(this)->MoveBefore_impl(visualCommon);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC MoveAfter(Alpha::Binbo::i_common_ptr const &visualCommon) final override
	{
		try
		{
			to_impl(this)->MoveAfter_impl(visualCommon);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// HMIFeatures::IVisual interface
	BINBO_FUNC set_position(const GraphicsPoint &pt) override
	{
		try
		{
			to_impl(this)->set_position_impl(pt);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_position(GraphicsPoint &pt) override
	{
		try
		{
			pt = to_impl(this)->get_position_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC set_center_position(const GraphicsPoint &ptCenter) override
	{
		try
		{
			to_impl(this)->set_center_position_impl(ptCenter);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_center_position(GraphicsPoint &ptCenter) override
	{
		try
		{
			ptCenter = to_impl(this)->get_center_position_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC set_visible(bool visible) override
	{
		try
		{
			to_impl(this)->set_visible_impl(visible);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_visible(bool &visible) override
	{
		try
		{
			visible = to_impl(this)->get_visible_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC z_order_after(const HMIFeatures::IVisual_ptr &item_ptr) override
	{
		try
		{
			to_impl(this)->z_order_after_impl(item_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC z_order_before(const HMIFeatures::IVisual_ptr &item_ptr) override
	{
		try
		{
			to_impl(this)->z_order_before_impl(item_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC z_order_increase(bool bTopmost) override
	{
		try
		{
			to_impl(this)->z_order_increase_impl(bTopmost);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC z_order_decrease(bool bLowest) override
	{
		try
		{
			to_impl(this)->z_order_decrease_impl(bLowest);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC set_center_rotation(const double &fRotationDegrees) override
	{
		try
		{
			to_impl(this)->set_center_rotation_impl(fRotationDegrees);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_center_rotation(double &fRotationDegrees) override
	{
		try
		{
			fRotationDegrees = to_impl(this)->get_center_rotation_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC add_effect(HMIEffects::IBase *effect_ptr) override
	{
		try
		{
			to_impl(this)->add_effect_impl(effect_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC update_effect(HMIEffects::IBase *effect_ptr) override
	{
		try
		{
			to_impl(this)->update_effect_impl(effect_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC remove_effect(HMIEffects::IBase *effect_ptr) override
	{
		try
		{
			to_impl(this)->remove_effect_impl(effect_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC add_layout(HMILayout::ILayout *layout_ptr) override
	{
		try
		{
			to_impl(this)->add_layout_impl(layout_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC remove_layout(HMILayout::ILayout *layout_ptr) override
	{
		try
		{
			to_impl(this)->remove_layout_impl(layout_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// HMILayout::ILayoutItem interface
	BINBO_FUNC add_layout_feature(HMILayout::ILayoutFeature *layout_feature_ptr) override
	{
		try
		{
			to_impl(this)->add_layout_feature_impl(layout_feature_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC remove_layout_feature(HMILayout::ILayoutFeature *layout_feature_ptr) override
	{
		try
		{
			to_impl(this)->remove_layout_feature_impl(layout_feature_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_layout_feature_cnt(size_t &cnt) override
	{
		try
		{
			cnt = to_impl(this)->get_layout_feature_cnt_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_layout_feature(HMILayout::ILayoutFeature *&feature_ptr, size_t idx) override
	{
		try
		{
			feature_ptr = to_impl(this)->get_layout_feature_impl(idx);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC set_layout(HMILayout::ILayout *layout_ptr) override
	{
		try
		{
			to_impl(this)->set_layout_impl(layout_ptr);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	// HMIFeatures::IRect interface
	BINBO_FUNC set_rect(const GraphicsRect &rc) override
	{
		try
		{
			to_impl(this)->set_rect_impl(rc);
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

	BINBO_FUNC get_rect(GraphicsRect &rc) override
	{
		try
		{
			rc = to_impl(this)->get_rect_impl();
			return BINBO_NO_ERROR;
		}
		ALPHA_BINBO_CATCH_ALL
	}

};	//class alarms_binbo_interface_impl
