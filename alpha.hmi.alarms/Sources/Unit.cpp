#include "stdafx.h"

#include "Unit.h"

#include "Reflection/Reflection.Interface.h"


BINBO_FUNC AlarmsUnit::GetName(Alpha::Binbo::i_string_ref &name) const
{
	return name.set_value(Alpha::Binbo::val("Alarms"));
}

BINBO_FUNC AlarmsUnit::GetUuid(Alpha::interface_id &uuid) const
{
	// {2D2DE93F-3347-4719-B8DA-1054DF8234D7}
	static Alpha::interface_id uuid_ = { 0x2d, 0x2d, 0xe9, 0x3f, 0x33, 0x47, 0x47, 0x19, 0xb8, 0xda, 0x10, 0x54, 0xdf, 0x82, 0x34, 0xd7 };
	uuid = uuid_;
	return BINBO_NO_ERROR;
}

BINBO_FUNC AlarmsUnit::PrepareApiList(ApiList &apiList) const
{
	// Не будем ничего фильтровать, а просто выставим все содержимое таблицы экспорта
	for (const auto *type : AR_EXPORT_TABLE(Alpha::Hmi::Alarms::Reflection::ExportTable))
		apiList.push_back(type);
	return BINBO_NO_ERROR;
}
