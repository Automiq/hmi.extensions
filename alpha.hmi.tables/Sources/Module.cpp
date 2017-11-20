#include "stdafx.h"

#include "Module.h"

////////////////////////////////////////////////////////////////
//	TablesModuleClassFactory
////////////////////////////////////////////////////////////////
TablesModuleClassFactory::TablesModuleClassFactory()
{
}

TablesModuleClassFactory::~TablesModuleClassFactory()
{
}

BINBO_FUNC TablesModuleClassFactory::create_instance(Alpha::interface_id const &id, Alpha::Binbo::i_common_ptr &interface_ptr)
{
	return BINBO_ERROR(Alpha::Binbo::ET_ERROR, "No interface");
}


////////////////////////////////////////////////////////////////
//	TablesModule
////////////////////////////////////////////////////////////////
TablesModule::TablesModule()
{
	_classFactory = Alpha::aligned_generic_storage<TablesModuleClassFactory>::construct();
}

TablesModule::~TablesModule()
{
}

long BINBO_CALLTYPE TablesModule::add_ref() const
{
	return _RCB.add_ref();
}

long BINBO_CALLTYPE TablesModule::release() const
{
	auto nVal = _RCB.release();
	if (nVal == 0)
		delete this;

	return nVal;
}

BINBO_FUNC TablesModule::get_class_factory(Alpha::Binbo::i_class_factory_ptr &factory_ptr)
{
	if (_classFactory.is_empty())
		return BINBO_ERROR(Alpha::Binbo::ET_FAIL, "Class factory not initialized");

	factory_ptr = _classFactory;
	return BINBO_NO_ERROR;
}

BINBO_FUNC TablesModule::get_id(Alpha::interface_id &id)
{
	// {FE6595E3-9035-419C-9A1E-A6F61BD0D9B8}
	static const Alpha::interface_id _ThisModuleId = { 0xfe, 0x65, 0x95, 0xe3, 0x90, 0x35, 0x41, 0x9c, 0x9a, 0x1e, 0xa6, 0xf6, 0x1b, 0xd0, 0xd9, 0xb8 };
	id = _ThisModuleId;

	return BINBO_NO_ERROR;
}

BINBO_FUNC TablesModule::init(Alpha::Binbo::IModuleLoaderWeakPtr const &module_loader_ptr)
{
	return BINBO_NO_ERROR;
}

BINBO_FUNC TablesModule::cleanup()
{
	return BINBO_NO_ERROR;
}
