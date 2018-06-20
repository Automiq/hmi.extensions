#pragma once

#include "AlarmSettings.h"
#include "Helpers\ReflectionHelpers.h"
#include "Reflection\Reflection.Common.h"

AR_DECLARE_API_EX(
	// Имя регистрируемого пользовательского типа
	aha::AlarmSettings,
	// Интерфейс, через который будет выполняться каст Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// Аспект
	ahar::Aspect,
	// Схема
	aoe::Schema,
	// Строковое наименование, под которым регистрируется тип
	AlarmSettings,
	// Идентификатор UUID
	// {E914D5C7-600A-49A8-8562-518C4752859A}
	(0xe9, 0x14, 0xd5, 0xc7, 0x60, 0x0a, 0x49, 0xa8, 0x85, 0x62, 0x51, 0x8c, 0x47, 0x52, 0x85, 0x9a),
	// Регистрируемые сущности
	CLASSINFO
	AGGREGATEDS
	PROPERTIES
	SIGNALS
	//METHODS
)

AR_DECLARE_CLASSINFO(
	aha::AlarmSettings, ahar::Aspect, aoe::Schema,
	(
		AR_NSTR(L"Источник событий"),
		AR_NSTR(L"Источник технологических событий")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		Регистрация вложенных объектов
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_AGGREGATEDS(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_AGGREGATED(
	(_AlarmsControl, ParentSource),
		(AR_NSTR(L"Компонент отображения"), AR_NSTR(L"Ссылка компонент отображения событий")))

	AR_AGGREGATED(
	(_Message, GetMsg),
		(AR_NSTR(L"Сообщение"), AR_NSTR(L"Сообщение")))

AR_END_DECLARE_AGGREGATEDS

AR_DECLARE_SIGNAL(
	aha::AlarmSettings, ahar::Aspect, aoe::Schema,
	(ValueChanged, ValueChanged),
	(AR_NSTR(L"ValueChanged"), AR_NSTR(L"ValueChanged")))

AR_BEGIN_EXPORT_SIGNALS(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_SIGNAL(ValueChanged)
AR_END_EXPORT_SIGNALS

////////////////////////////////////////////////////////////////////////////////
//		Регистрация свойств
////////////////////////////////////////////////////////////////////////////////
AR_BEGIN_DECLARE_PROPERTIES(aha::AlarmSettings, ahar::Aspect, aoe::Schema)
	AR_PROPERTY(
		(_RequiredValue, Property::None, GetRequiredValue, SetRequiredValue),
		(AR_NSTR(L"Необходимое значение"), AR_NSTR(L"Необходимое значение"))
	)

	AR_PROPERTY(
		(_Priority, Property::None, GetPriority, SetPriority),
		(AR_NSTR(L"Важность"), AR_NSTR(L"Важность"))
	)

	AR_NOTIFIED_PROPERTY(
		(_Value, Property::Default, ValueChanged, GetValue, SetValue),
		(AR_NSTR(L"Значение"), AR_NSTR(L"Значение"))
	)

AR_END_DECLARE_PROPERTIES