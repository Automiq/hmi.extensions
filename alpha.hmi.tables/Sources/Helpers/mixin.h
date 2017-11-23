#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////
///	@file
///
///	@short
///		�������� ��������.
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
///	@short
///		�������
///
///	@details
///		��������� ������ ������� ��������� ������� � ����������
////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Implementation>
class mixin
{
protected:

	template <typename Base>
	Implementation *to_impl(Base *that)
	{
		return static_cast<Implementation *> (that);
	}

	template <typename Base>
	const Implementation *to_const_impl(const Base *that) const
	{
		return static_cast<const Implementation *> (that);
	}
};
