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
#include "Reflection.Trends.h"


// ������� ������������������ �����
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahtr::ExportTable )
	AR_EXPORT_API(aht::TrendsControl, ahtr::Aspect)
AR_END_DECLARE_EXPORT_TABLE