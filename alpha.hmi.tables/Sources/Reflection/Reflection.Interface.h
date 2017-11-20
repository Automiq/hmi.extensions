////////////////////////////////////////////////////////////////////////////////
///
///	@file
///
///	@short
///		alpha.hmi.tables. ������ ������.
///		��������� API ������.
///
////////////////////////////////////////////////////////////////////////////////


#pragma once


// ��������� ����������� ������ ����������
#include "Reflection.Common.h"


// �������������� ����
#include "Reflection.Tables.h"


// ������� ������������������ �����
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahtr::ExportTable )
	AR_EXPORT_API(aht::TableControl, ahtr::Aspect)
AR_END_DECLARE_EXPORT_TABLE