////////////////////////////////////////////////////////////////////////////////
///
///	@file
///
///	@short
///		alpha.hmi.alarms. Модуль Алармов.
///		Рефлексия API модуля.
///
////////////////////////////////////////////////////////////////////////////////


#pragma once


// Некоторые определения общего назначения
#include "Reflection.Common.h"


// Регистрируемые типы
#include "Reflection.Alarms.h"
#include "../Reflection.AlarmSettings.h"


// Таблица зарегистрированных типов
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahar::ExportTable )
	AR_EXPORT_API(aha::AlarmsControl, ahar::Aspect)
	AR_EXPORT_API(aha::AlarmSettings, ahar::Aspect)
AR_END_DECLARE_EXPORT_TABLE