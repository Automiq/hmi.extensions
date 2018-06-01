#pragma once

#include "..\AlarmsControl.h"


////////////////////////////////////////////////////////////////////////////////
//		���������� ���� Alarms
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(
	// ��� ��������������� ����������������� ����
	aha::AlarmsControl,
	// ���������, ����� ������� ����� ����������� ���� Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// ������
	ahar::Aspect,
	// �����
	aoe::Schema,
	// ��������� ������������, ��� ������� �������������� ���
	AlphaAlarms,
	// ������������� UUID
	// {C65FF4DC-F22B-47D3-9333-72C4E4E5F662}
	( 0xc6, 0x5f, 0xf4, 0xdc, 0xf2, 0x2b, 0x47, 0xd3, 0x93, 0x33, 0x72, 0xc4, 0xe4, 0xe5, 0xf6, 0x62 ),
	// �������������� ��������
	CLASSINFO
	AGGREGATEDS
	PROPERTIES
	//SIGNALS
	METHODS
)


////////////////////////////////////////////////////////////////////////////////
//		���������� ���������� � ����
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_CLASSINFO(
	aha::AlarmsControl, ahar::Aspect, aoe::Schema,
	(
		AR_NSTR(L"�������"),
		AR_NSTR(L"��������� ����������� ��������������� �������")
	)
)

////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
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
	AR_PROPERTY(
	(maxAlarmsCount_, Property::None, GetMaxAlarmsCount, SetMaxAlarmsCount),
		(AR_NSTR(L"������������ ����� �������"), AR_NSTR(L"������������ ����� �������"))
	)
AR_END_DECLARE_PROPERTIES

////////////////////////////////////////////////////////////////////////////////
//		����������� ��������� ��������
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_AGGREGATEDS(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
	//AR_AGGREGATED(
	//	(location_, Location),
	//	(AR_NSTR(L"����"), AR_NSTR(L"���� OPC DA �������")))
	AR_AGGREGATED(
		(progId_, ProgId),
		(AR_NSTR(L"ProgID"), AR_NSTR(L"ProgID OPC DA �������")))
	AR_AGGREGATED(
		(path_, Path),
		(AR_NSTR(L"����"), AR_NSTR(L"���� ����� ��������")))
	//AR_AGGREGATED(
	//	(parentSource_, ParentSource),
	//	(AR_NSTR(L"������������ ��������"), AR_NSTR(L"������ �� ������������ �������� ��������")))
AR_END_DECLARE_AGGREGATEDS

////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_METHODS(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
	AR_METHOD((addAlarm), (AR_NSTR(L"���������� ������ � �������"), AR_NSTR(L"���������� ������ � �������")))
AR_END_DECLARE_METHODS