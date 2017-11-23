#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////
///	@short
///		Примесь, реализующая интерфейс HMIFeatures::IRect
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Implementation>
class hmi_rect_impl
	: protected mixin<Implementation>
{
public:

	void set_rect_impl(const GraphicsRect &rc)
	{
		to_impl(this)->setRect(QRectF(rc.fX, rc.fY, rc.fCx, rc.fCy));
	}

	GraphicsRect get_rect_impl()
	{
		auto rc = to_impl(this)->rect();
		return GraphicsRect(rc.x(), rc.y(), rc.width(), rc.height());
	}
};
