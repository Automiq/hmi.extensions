#include "stdafx.h"

#include "Module.h"
#include "Unit.h"

////////////////////////////////////////////////////////////////
//	AlarmsModuleClassFactory
////////////////////////////////////////////////////////////////
AlarmsModuleClassFactory::AlarmsModuleClassFactory()
{
}

AlarmsModuleClassFactory::~AlarmsModuleClassFactory()
{
}

BINBO_FUNC AlarmsModuleClassFactory::create_instance(Alpha::interface_id const &id, Alpha::Binbo::i_common_ptr &interface_ptr)
{
	if (id == uuid_of_type<Alpha::Om::IUnit>::value())
	{
		interface_ptr = Alpha::Binbo::foreign_cast_ex<Alpha::Binbo::i_common, Alpha::Om::IElement> (Alpha::aligned_generic_storage<AlarmsUnit>::construct());
		return BINBO_NO_ERROR;
	}
	return BINBO_ERROR(Alpha::Binbo::ET_ERROR, "No interface");
}


////////////////////////////////////////////////////////////////
//	AlarmsModule
////////////////////////////////////////////////////////////////
AlarmsModule::AlarmsModule()
{
	_classFactory = Alpha::aligned_generic_storage<AlarmsModuleClassFactory>::construct();
}

AlarmsModule::~AlarmsModule()
{
}

long BINBO_CALLTYPE AlarmsModule::add_ref() const
{
	return _RCB.add_ref();
}

long BINBO_CALLTYPE AlarmsModule::release() const
{
	auto nVal = _RCB.release();
	if (nVal == 0)
		delete this;

	return nVal;
}

BINBO_FUNC AlarmsModule::get_class_factory(Alpha::Binbo::i_class_factory_ptr &factory_ptr)
{
	if (_classFactory.is_empty())
		return BINBO_ERROR(Alpha::Binbo::ET_FAIL, "Class factory not initialized");

	factory_ptr = _classFactory;
	return BINBO_NO_ERROR;
}

BINBO_FUNC AlarmsModule::get_id(Alpha::interface_id &id)
{
	// {BD38AFD2-900E-4906-93CE-E3C83B67B8AD}
	static const Alpha::interface_id _ThisModuleId = { 0xbd, 0x38, 0xaf, 0xd2, 0x90, 0x0e, 0x49, 0x06, 0x93, 0xce, 0xe3, 0xc8, 0x3b, 0x67, 0xb8, 0xad };
	id = _ThisModuleId;

	return BINBO_NO_ERROR;
}

BINBO_FUNC AlarmsModule::init(Alpha::Binbo::IModuleLoaderWeakPtr const &module_loader_ptr)
{
	return BINBO_NO_ERROR;
}

BINBO_FUNC AlarmsModule::cleanup()
{
	return BINBO_NO_ERROR;
}
