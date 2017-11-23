#pragma once

#include "..\TrendsControl.h"


////////////////////////////////////////////////////////////////////////////////
//		Объявление типа Trends
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(
	// Имя регистрируемого пользовательского типа
	aht::TrendsControl,
	// Интерфейс, через который будет выполняться каст Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// Аспект
	ahtr::Aspect,
	// Схема
	aoe::Schema,
	// Строковое наименование, под которым регистрируется тип
	AlphaTrends,
	// Идентификатор UUID
	// {447C3E77-56F5-497C-950C-067DA367AD6A}
	(0x44, 0x7c, 0x3e, 0x77, 0x56, 0xf5, 0x49, 0x7c, 0x95, 0x0c, 0x06, 0x7d, 0xa3, 0x67, 0xad, 0x6a),
	// Регистрируемые сущности
	CLASSINFO
	//AGGREGATEDS
	PROPERTIES
	//SIGNALS
	//METHODS
)


////////////////////////////////////////////////////////////////////////////////
//		Объявление информации о типе
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_CLASSINFO(
	aht::TrendsControl, ahtr::Aspect, aoe::Schema,
	(
		AR_NSTR(L"График"),
		AR_NSTR(L"Компонент построения графиков")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		Регистрация свойств
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aht::TrendsControl, ahtr::Aspect, aoe::Schema)
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
AR_END_DECLARE_PROPERTIES
