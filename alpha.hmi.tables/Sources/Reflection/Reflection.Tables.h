#pragma once

#include "..\TableControl.h"
#include "Helpers\OverrideQRect.h"


////////////////////////////////////////////////////////////////////////////////
//		���������� ���� Table
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(                                 
	// ��� ��������������� ����������������� ����
	// namespace aht = Alpha::Hmi::Tables;
	aht::TableControl,
	// ���������, ����� ������� ����� ����������� ���� Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// ������
	ahtr::Aspect,
	// �����
	aoe::Schema,
	// ��������� ������������, ��� ������� �������������� ���
	Table,
	// ������������� UUID
	// {10602B67-24BF-4948-9B11-02237A8050B2}
	(0x10, 0x60, 0x2b, 0x67, 0x24, 0xbf, 0x49, 0x48, 0x9b, 0x11, 0x02, 0x23, 0x7a, 0x80, 0x50, 0xb2),
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
	aht::TableControl, ahtr::Aspect, aoe::Schema,
	(
		AR_NSTR(L"�������"),
		AR_NSTR(L"��������� ���������� ������")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aht::TableControl, ahtr::Aspect, aoe::Schema)
	AR_PROPERTY(
		(X, Property::None, GetX, SetX),              // ���, ��� �������� (��������� � �����������), ����� ������.
		(AR_NSTR(L"X"), AR_NSTR(L"���������� X"))   // ������������ � ������� �������� - ������ ���������� �������
	)
	AR_PROPERTY(
		(Y, Property::None, GetY, SetY),                // ����������� � �������� eflected_visual � reflected_rect
		(AR_NSTR(L"Y"), AR_NSTR(L"���������� Y"))
	)
	AR_PROPERTY(
		(Rotation, Property::None, GetRotation, SetRotation),    // � ��� ����
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
	AR_PROPERTY(
		(HorVal, Property::None, GetNumberHorCells, SetNumberHorCells),
			(AR_NSTR(L"���������� ����� �� �����������"), AR_NSTR(L"���������� ����� �� �����������"))
	)
	AR_PROPERTY(
		(VertVal, Property::None, GetNumberVertCells, SetNumberVertCells),
			(AR_NSTR(L"���������� ����� �� ���������"), AR_NSTR(L"���������� ����� �� ���������"))
	)
	
AR_END_DECLARE_PROPERTIES
