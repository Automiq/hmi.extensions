////////////////////////////////////////////////////////////////////////////////
///
///	@file
///
///	@short
///		alpha.hmi.alarms. ������ �������.
///		��������� API ������.
///
////////////////////////////////////////////////////////////////////////////////


#pragma once


// ��������� ����������� ������ ����������
#include "Reflection.Common.h"


// �������������� ����
#include "Reflection.Alarms.h"
#include "../Reflection.AlarmSettings.h"


// ������� ������������������ �����
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahar::ExportTable )
	AR_EXPORT_API(aha::AlarmsControl, ahar::Aspect)
	AR_EXPORT_API(aha::AlarmSettings, ahar::Aspect)
AR_END_DECLARE_EXPORT_TABLE