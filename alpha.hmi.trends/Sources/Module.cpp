#include "stdafx.h"

#include "Module.h"

////////////////////////////////////////////////////////////////
//	TrendsModuleClassFactory
////////////////////////////////////////////////////////////////
TrendsModuleClassFactory::TrendsModuleClassFactory()
{
}

TrendsModuleClassFactory::~TrendsModuleClassFactory()
{
}

BINBO_FUNC TrendsModuleClassFactory::create_instance(Alpha::interface_id const &id, Alpha::Binbo::i_common_ptr &interface_ptr)
{
	return BINBO_ERROR(Alpha::Binbo::ET_ERROR, "No interface");
}


////////////////////////////////////////////////////////////////
//	TrendsModule
////////////////////////////////////////////////////////////////
TrendsModule::TrendsModule()
{
	_classFactory = Alpha::aligned_generic_storage<TrendsModuleClassFactory>::construct();
}

TrendsModule::~TrendsModule()
{
}

long BINBO_CALLTYPE TrendsModule::add_ref() const
{
	return _RCB.add_ref();
}

long BINBO_CALLTYPE TrendsModule::release() const
{
	auto nVal = _RCB.release();
	if (nVal == 0)
		delete this;

	return nVal;
}

BINBO_FUNC TrendsModule::get_class_factory(Alpha::Binbo::i_class_factory_ptr &factory_ptr)
{
	if (_classFactory.is_empty())
		return BINBO_ERROR(Alpha::Binbo::ET_FAIL, "Class factory not initialized");

	factory_ptr = _classFactory;
	return BINBO_NO_ERROR;
}

BINBO_FUNC TrendsModule::get_id(Alpha::interface_id &id)
{
	// {B6ACF00C-902A-4C81-85E8-6E56EDB30FA9}
	static const Alpha::interface_id _ThisModuleId = { 0xb6, 0xac, 0xf0, 0x0c, 0x90, 0x2a, 0x4c, 0x81, 0x85, 0xe8, 0x6e, 0x56, 0xed, 0xb3, 0x0f, 0xa9 };
	id = _ThisModuleId;

	return BINBO_NO_ERROR;
}

BINBO_FUNC TrendsModule::init(Alpha::Binbo::IModuleLoaderWeakPtr const &module_loader_ptr)
{
	return BINBO_NO_ERROR;
}

BINBO_FUNC TrendsModule::cleanup()
{
	return BINBO_NO_ERROR;
}
