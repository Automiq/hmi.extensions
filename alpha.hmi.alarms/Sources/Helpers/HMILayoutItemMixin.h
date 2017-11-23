#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////
///	@short
///		Примесь, реализующая интерфейс HMILayout::ILayoutItem
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Implementation, typename Interface = HMIFeatures::IVisual>
class hmi_layout_item_impl
	:	protected mixin<Implementation>
{
	HMILayout::ILayout *_layout;
	std::vector<HMILayout::ILayoutFeature *> _layoutFeatures;

public:

	hmi_layout_item_impl()
		:	_layout(nullptr)
	{
	}

	void add_layout_feature_impl(HMILayout::ILayoutFeature *layout_feature_ptr)
	{
		assert(layout_feature_ptr);

		_layoutFeatures.push_back(layout_feature_ptr);
		Alpha::auto_throw(layout_feature_ptr->set_layout(_layout));
	}

	void remove_layout_feature_impl(HMILayout::ILayoutFeature *layout_feature_ptr)
	{
		assert(layout_feature_ptr);

		auto itRemove = std::remove(_layoutFeatures.begin(), _layoutFeatures.end(), layout_feature_ptr);
		_layoutFeatures.erase(itRemove, _layoutFeatures.end());

		Alpha::auto_throw(layout_feature_ptr->set_layout(nullptr));
	}

	size_t get_layout_feature_cnt_impl()
	{
		return _layoutFeatures.size();
	}

	HMILayout::ILayoutFeature *get_layout_feature_impl(size_t idx)
	{
		if (idx >= _layoutFeatures.size())
			AlphaThrow(Alpha::Error(), nstr(L"Индекс вне границ диапазона"));

		return _layoutFeatures[idx];
	}

	void set_layout_impl(HMILayout::ILayout *layout_ptr)
	{
		_layout = layout_ptr;
		for (auto const &feature : _layoutFeatures)
			Alpha::auto_throw(feature->set_layout(layout_ptr));
	}
};