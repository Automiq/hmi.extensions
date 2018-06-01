#pragma once

#include "..\AlarmsControl.h"


////////////////////////////////////////////////////////////////////////////////
//		Объявление типа Alarms
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(
	// Имя регистрируемого пользовательского типа
	aha::AlarmsControl,
	// Интерфейс, через который будет выполняться каст Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// Аспект
	ahar::Aspect,
	// Схема
	aoe::Schema,
	// Строковое наименование, под которым регистрируется тип
	AlphaAlarms,
	// Идентификатор UUID
	// {C65FF4DC-F22B-47D3-9333-72C4E4E5F662}
	( 0xc6, 0x5f, 0xf4, 0xdc, 0xf2, 0x2b, 0x47, 0xd3, 0x93, 0x33, 0x72, 0xc4, 0xe4, 0xe5, 0xf6, 0x62 ),
	// Регистрируемые сущности
	CLASSINFO
	AGGREGATEDS
	PROPERTIES
	//SIGNALS
	METHODS
)


////////////////////////////////////////////////////////////////////////////////
//		Объявление информации о типе
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_CLASSINFO(
	aha::AlarmsControl, ahar::Aspect, aoe::Schema,
	(
		AR_NSTR(L"События"),
		AR_NSTR(L"Компонент отображения технологических событий")
	)
)

////////////////////////////////////////////////////////////////////////////////
//		Регистрация свойств
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
	AR_PROPERTY(
		(X, Property::None, GetX, SetX),
		(AR_NSTR(L"X"), AR_NSTR(L"Координата X"))
	)
	AR_PROPERTY(
		(Y, Property::None, GetY, SetY),
		(AR_NSTR(L"Y"), AR_NSTR(L"Координата Y"))
	)
	AR_PROPERTY(
		(Rotation, Property::None, GetRotation, SetRotation),
		(AR_NSTR(L"Угол поворота"), AR_NSTR(L"Угол поворота"))
	)
	AR_PROPERTY(
		(Scale, Property::None, GetScale, SetScale),
		(AR_NSTR(L"Масштаб"), AR_NSTR(L"Масштаб"))
	)
	AR_PROPERTY(
		(Visible, Property::None, GetVisible, SetVisible),
		(AR_NSTR(L"Видимость"), AR_NSTR(L"Видимость"))
	)
	AR_PROPERTY(
		(Enabled, Property::None, GetEnabled, SetEnabled),
		(AR_NSTR(L"Включено"), AR_NSTR(L"Включено"))
	)
	AR_PROPERTY(
		(Tooltip, Property::None, GetTooltip, SetTooltip),
		(AR_NSTR(L"Всплывающая подсказка"), AR_NSTR(L"Всплывающая подсказка"))
	)
	AR_PROPERTY(
		(Width, Property::None, GetWidth, SetWidth),
		(AR_NSTR(L"Ширина"), AR_NSTR(L"Ширина"))
	)
	AR_PROPERTY(
		(Height, Property::None, GetHeight, SetHeight),
		(AR_NSTR(L"Высота"), AR_NSTR(L"Высота"))
	)
	AR_PROPERTY(
	(maxAlarmsCount_, Property::None, GetMaxAlarmsCount, SetMaxAlarmsCount),
		(AR_NSTR(L"Максимальное число алармов"), AR_NSTR(L"Максимальное число алармов"))
	)
AR_END_DECLARE_PROPERTIES

////////////////////////////////////////////////////////////////////////////////
//		Регистрация вложенных объектов
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_AGGREGATEDS(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
	//AR_AGGREGATED(
	//	(location_, Location),
	//	(AR_NSTR(L"Хост"), AR_NSTR(L"Хост OPC DA сервера")))
	AR_AGGREGATED(
		(progId_, ProgId),
		(AR_NSTR(L"ProgID"), AR_NSTR(L"ProgID OPC DA сервера")))
	AR_AGGREGATED(
		(path_, Path),
		(AR_NSTR(L"Путь"), AR_NSTR(L"Путь ветки сигналов")))
	//AR_AGGREGATED(
	//	(parentSource_, ParentSource),
	//	(AR_NSTR(L"Родительский источник"), AR_NSTR(L"Ссылка на родительский источник сигналов")))
AR_END_DECLARE_AGGREGATEDS

////////////////////////////////////////////////////////////////////////////////
//		Регистрация методов
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_METHODS(aha::AlarmsControl, ahar::Aspect, aoe::Schema)
	AR_METHOD((addAlarm), (AR_NSTR(L"Добавление аларма в таблицу"), AR_NSTR(L"Добавление аларма в таблицу")))
AR_END_DECLARE_METHODS