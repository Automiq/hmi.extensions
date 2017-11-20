#include "stdafx.h"

#include "Unit.h"

#include "Reflection/Reflection.Interface.h"


BINBO_FUNC TablesUnit::GetName(Alpha::Binbo::i_string_ref &name) const
{
	return name.set_value(Alpha::Binbo::val("Tables"));
}

BINBO_FUNC TablesUnit::GetUuid(Alpha::interface_id &uuid) const
{
	// {675719ED-6AEE-47D4-8EA7-B2AD79E697A0}
	static Alpha::interface_id uuid_ = { 0x67, 0x57, 0x19, 0xed, 0x6a, 0xee, 0x47, 0xd4, 0x8e, 0xa7, 0xb2, 0xad, 0x79, 0xe6, 0x97, 0xa0 };
	uuid = uuid_;
	return BINBO_NO_ERROR;
}

BINBO_FUNC TablesUnit::PrepareApiList(ApiList &apiList) const
{
	// Не будем ничего фильтровать, а просто выставим все содержимое таблицы экспорта
	for (const auto *type : AR_EXPORT_TABLE(Alpha::Hmi::Tables::Reflection::ExportTable))
		apiList.push_back(type);
	return BINBO_NO_ERROR;
}
