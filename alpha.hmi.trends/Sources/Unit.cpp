#include "stdafx.h"

#include "Unit.h"

#include "Reflection/Reflection.Interface.h"


BINBO_FUNC TrendsUnit::GetName(Alpha::Binbo::i_string_ref &name) const
{
	return name.set_value(Alpha::Binbo::val("Trends"));
}

BINBO_FUNC TrendsUnit::GetUuid(Alpha::interface_id &uuid) const
{
	// {61722B63-22B7-49F8-A8EB-ED004C88B3F2}
	static Alpha::interface_id uuid_ = { 0x61, 0x72, 0x2b, 0x63, 0x22, 0xb7, 0x49, 0xf8, 0xa8, 0xeb, 0xed, 0x00, 0x4c, 0x88, 0xb3, 0xf2 };
	uuid = uuid_;
	return BINBO_NO_ERROR;
}

BINBO_FUNC TrendsUnit::PrepareApiList(ApiList &apiList) const
{
	// Не будем ничего фильтровать, а просто выставим все содержимое таблицы экспорта
	for (const auto *type : AR_EXPORT_TABLE(Alpha::Hmi::Trends::Reflection::ExportTable))
		apiList.push_back(type);
	return BINBO_NO_ERROR;
}
