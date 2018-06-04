#pragma once

#include "AlarmsSource.h"
#include "Helpers\ReflectionHelpers.h"
#include "Reflection\Reflection.Common.h"

AR_DECLARE_API_EX(
	// ��� ��������������� ����������������� ����
	aha::AlarmsSource,
	// ���������, ����� ������� ����� ����������� ���� Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// ������
	ahar::Aspect,
	// �����
	aoe::Schema,
	// ��������� ������������, ��� ������� �������������� ���
	AlarmsSource,
	// ������������� UUID
	// {E914D5C7-600A-49A8-8562-518C4752859A}
	(0xe9, 0x14, 0xd5, 0xc7, 0x60, 0x0a, 0x49, 0xa8, 0x85, 0x62, 0x51, 0x8c, 0x47, 0x52, 0x85, 0x9a),
	// �������������� ��������
	CLASSINFO
	AGGREGATEDS
	PROPERTIES
	//SIGNALS
	//METHODS
)

AR_DECLARE_CLASSINFO(
	aha::AlarmsSource, ahar::Aspect, aoe::Schema,
	(
		AR_NSTR(L"�������� �������"),
		AR_NSTR(L"�������� ��������������� �������")
	)
)

////////////////////////////////////////////////////////////////////////////////
//		����������� ��������� ��������
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_AGGREGATEDS(aha::AlarmsSource, ahar::Aspect, aoe::Schema)
	AR_AGGREGATED(
		(host_, GetHost),
		(AR_NSTR(L"����"), AR_NSTR(L"���� OPC AE �������"))
	)
	AR_AGGREGATED(
		(progId_, GetProgId),
		(AR_NSTR(L"ProgID"), AR_NSTR(L"ProgID OPC AE �������"))
	)
AR_END_DECLARE_AGGREGATEDS

////////////////////////////////////////////////////////////////////////////////
//		����������� �������
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_PROPERTIES(aha::AlarmsSource, ahar::Aspect, aoe::Schema)
	AR_PROPERTY(
		(_Value, Property::None, GetValue, SetValue),
		(AR_NSTR(L"��������"), AR_NSTR(L"��������"))
	)
AR_END_DECLARE_PROPERTIES