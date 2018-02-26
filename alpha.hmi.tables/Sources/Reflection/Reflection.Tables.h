#pragma once

#include "..\TableControl.h"
#include "Helpers\OverrideQRect.h"


////////////////////////////////////////////////////////////////////////////////
//		Объявление типа Table
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API_EX(                                 
	// Имя регистрируемого пользовательского типа
	// namespace aht = Alpha::Hmi::Tables;
	aht::TableControl,
	// Интерфейс, через который будет выполняться каст Alpha::Binbo::i_common
	HMIFeatures::IBase,
	// Аспект
	ahtr::Aspect,
	// Схема
	aoe::Schema,
	// Строковое наименование, под которым регистрируется тип
	Table,
	// Идентификатор UUID
	// {10602B67-24BF-4948-9B11-02237A8050B2}
	(0x10, 0x60, 0x2b, 0x67, 0x24, 0xbf, 0x49, 0x48, 0x9b, 0x11, 0x02, 0x23, 0x7a, 0x80, 0x50, 0xb2),
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
	aht::TableControl, ahtr::Aspect, aoe::Schema,
	(
		AR_NSTR(L"Таблица"),
		AR_NSTR(L"Компонент построения таблиц")
	)
)


////////////////////////////////////////////////////////////////////////////////
//		Регистрация свойств
////////////////////////////////////////////////////////////////////////////////

AR_BEGIN_DECLARE_PROPERTIES(aht::TableControl, ahtr::Aspect, aoe::Schema)
	AR_PROPERTY(
		(X, Property::None, GetX, SetX),              // имя, тип свойства (дефолтное и рантаймовое), гетер сеттер.
		(AR_NSTR(L"X"), AR_NSTR(L"Координата X"))   // реализованны с помощью ПРИМЕСЕЙ - способ расширения классов
	)
	AR_PROPERTY(
		(Y, Property::None, GetY, SetY),                // реализованы в примесях eflected_visual и reflected_rect
		(AR_NSTR(L"Y"), AR_NSTR(L"Координата Y"))
	)
	AR_PROPERTY(
		(Rotation, Property::None, GetRotation, SetRotation),    // и эти тоже
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
		(HorVal, Property::None, GetNumberHorCells, SetNumberHorCells),
			(AR_NSTR(L"Количество ячеек по горизонтали"), AR_NSTR(L"Количество ячеек по горизонтали"))
	)
	AR_PROPERTY(
		(VertVal, Property::None, GetNumberVertCells, SetNumberVertCells),
			(AR_NSTR(L"Количество ячеек по вертикали"), AR_NSTR(L"Количество ячеек по вертикали"))
	)
	
AR_END_DECLARE_PROPERTIES
