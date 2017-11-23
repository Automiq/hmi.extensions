#pragma once

#include "..\TrendsControl.h"


////////////////////////////////////////////////////////////////////////////////
//		���������� ���� Trends
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(
	// ��� ��������������� ����������������� ����
	aht::TrendsControl,
	// ���������, ����� ������� ����� ����������� ���� Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// ������
	ahtr::Aspect,
	// �����
	aoe::Schema,
	// ��������� ������������, ��� ������� �������������� ���
	AlphaTrends,
	// ������������� UUID
	// {447C3E77-56F5-497C-950C-067DA367AD6A}
	(0x44, 0x7c, 0x3e, 0x77, 0x56, 0xf5, 0x49, 0x7c, 0x95, 0x0c, 0x06, 0x7d, 0xa3, 0x67, 0xad, 0x6a),
	// �������������� ��������
	CLASSINFO
	//AGGREGATEDS
	PROPERTIES
	//SIGNALS
	//METHODS
)


////////////////////////////////////////////////////////////////////////////////
//		���������� ���������� � ����
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_CLASSINFO(
	aht::TrendsControl, ahtr::Aspect, aoe::Schema,
	(
		AR_NSTR(L"������"),
		AR_NSTR(L"��������� ���������� ��������")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aht::TrendsControl, ahtr::Aspect, aoe::Schema)
	AR_PROPERTY(
		(X, Property::None, GetX, SetX),
		(AR_NSTR(L"X"), AR_NSTR(L"���������� X"))
	)
	AR_PROPERTY(
		(Y, Property::None, GetY, SetY),
		(AR_NSTR(L"Y"), AR_NSTR(L"���������� Y"))
	)
	AR_PROPERTY(
		(Rotation, Property::None, GetRotation, SetRotation),
		(AR_NSTR(L"���� ��������"), AR_NSTR(L"���� ��������"))
	)
	AR_PROPERTY(
		(Scale, Property::None, GetScale, SetScale),
		(AR_NSTR(L"�������"), AR_NSTR(L"�������"))
	)
	AR_PROPERTY(
		(Visible, Property::None, GetVisible, SetVisible),
		(AR_NSTR(L"���������"), AR_NSTR(L"���������"))
	)
	AR_PROPERTY(
		(Enabled, Property::None, GetEnabled, SetEnabled),
		(AR_NSTR(L"��������"), AR_NSTR(L"��������"))
	)
	AR_PROPERTY(
		(Tooltip, Property::None, GetTooltip, SetTooltip),
		(AR_NSTR(L"����������� ���������"), AR_NSTR(L"����������� ���������"))
	)
	AR_PROPERTY(
		(Width, Property::None, GetWidth, SetWidth),
		(AR_NSTR(L"������"), AR_NSTR(L"������"))
	)
	AR_PROPERTY(
		(Height, Property::None, GetHeight, SetHeight),
		(AR_NSTR(L"������"), AR_NSTR(L"������"))
	)
AR_END_DECLARE_PROPERTIES
