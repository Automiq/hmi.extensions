#pragma once

#include "AlarmSettings.h"
#include "Helpers\ReflectionHelpers.h"
#include "Reflection\Reflection.Common.h"

AR_DECLARE_API_EX(
	// ��� ��������������� ����������������� ����
	aha::AlarmSettings,
	// ���������, ����� ������� ����� ����������� ���� Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// ������
	ahar::Aspect,
	// �����
	aoe::Schema,
	// ��������� ������������, ��� ������� �������������� ���
	AlarmSettings,
	// ������������� UUID
	// {E914D5C7-600A-49A8-8562-518C4752859A}
	(0xe9, 0x14, 0xd5, 0xc7, 0x60, 0x0a, 0x49, 0xa8, 0x85, 0x62, 0x51, 0x8c, 0x47, 0x52, 0x85, 0x9a),
	// �������������� ��������
	CLASSINFO
	AGGREGATEDS
	PROPERTIES
	SIGNALS
	//METHODS
)

AR_DECLARE_CLASSINFO(
	aha::AlarmSettings, ahar::Aspect, aoe::Schema,
	(
		AR_NSTR(L"�������� �������"),
		AR_NSTR(L"�������� ��������������� �������")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		����������� ��������� ��������
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_AGGREGATEDS(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_AGGREGATED(
	(_AlarmsControl, ParentSource),
		(AR_NSTR(L"��������� �����������"), AR_NSTR(L"������ ��������� ����������� �������")))

	AR_AGGREGATED(
	(_Message, GetMsg),
		(AR_NSTR(L"���������"), AR_NSTR(L"���������")))

AR_END_DECLARE_AGGREGATEDS

AR_DECLARE_SIGNAL(
	aha::AlarmSettings, ahar::Aspect, aoe::Schema,
	(ValueChanged, ValueChanged),
	(AR_NSTR(L"ValueChanged"), AR_NSTR(L"ValueChanged")))

AR_BEGIN_EXPORT_SIGNALS(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_SIGNAL(ValueChanged)
AR_END_EXPORT_SIGNALS

////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_PROPERTIES(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_PROPERTY(
		(_RequiredValue, Property::None, GetRequiredValue, SetRequiredValue),
		(AR_NSTR(L"����������� ��������"), AR_NSTR(L"����������� ��������"))
	)

	AR_PROPERTY(
		(_Priority, Property::None, GetPriority, SetPriority),
		(AR_NSTR(L"��������"), AR_NSTR(L"��������"))
	)

	AR_NOTIFIED_PROPERTY(
		(_Value, Property::Default, ValueChanged, GetValue, SetValue),
		(AR_NSTR(L"��������"), AR_NSTR(L"��������"))
	)

AR_END_DECLARE_PROPERTIES