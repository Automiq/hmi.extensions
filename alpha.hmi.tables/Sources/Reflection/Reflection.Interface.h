////////////////////////////////////////////////////////////////////////////////
///
///	@file
///
///	@short
///		alpha.hmi.tables. Модуль Таблиц.
///		Рефлексия API модуля.
///
////////////////////////////////////////////////////////////////////////////////


#pragma once


// Некоторые определения общего назначения
#include "Reflection.Common.h"


// Регистрируемые типы
#include "Reflection.Tables.h"


// Таблица зарегистрированных типов
AR_BEGIN_DECLARE_EXPORT_TABLE( aoe::Schema, ahtr::ExportTable )
	AR_EXPORT_API(aht::TableControl, ahtr::Aspect)
AR_END_DECLARE_EXPORT_TABLE