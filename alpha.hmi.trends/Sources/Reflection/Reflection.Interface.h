////////////////////////////////////////////////////////////////////////////////
///
///	@file
///
///	@short
///		alpha.hmi.alarms. Модуль Трендов.
///		Рефлексия API модуля.
///
////////////////////////////////////////////////////////////////////////////////


#pragma once


// Некоторые определения общего назначения
#include "Reflection.Common.h"


// Регистрируемые типы
#include "Reflection.Trends.h"


// Таблица зарегистрированных типов
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahtr::ExportTable )
	AR_EXPORT_API(aht::TrendsControl, ahtr::Aspect)
AR_END_DECLARE_EXPORT_TABLE