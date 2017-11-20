#pragma once


////////////////////////////////////////////////////////////////////////////////
///	@short
///		Фабрика классов модуля.
////////////////////////////////////////////////////////////////////////////////
class AlarmsModuleClassFactory : public Alpha::Binbo::i_class_factory
{
public:

	AlarmsModuleClassFactory();
	virtual ~AlarmsModuleClassFactory();

	virtual BINBO_FUNC create_instance(Alpha::interface_id const &id, Alpha::Binbo::i_common_ptr &interface_ptr) override;

protected:

	ALPHA_BINBO_PUBLISH_INTERFACES(Alpha::Binbo::i_class_factory)

}; // class AlarmsModuleClassFactory


////////////////////////////////////////////////////////////////////////////////
///	@short
///		Модуль компонента Алармы.
////////////////////////////////////////////////////////////////////////////////
class AlarmsModule : public Alpha::Om::IUnitModule
{
public:

	AlarmsModule();
	virtual ~AlarmsModule();

	// i_module
	virtual long BINBO_CALLTYPE add_ref() const override;
	virtual long BINBO_CALLTYPE release() const override;

	// i_module_ex
	virtual BINBO_FUNC get_class_factory(Alpha::Binbo::i_class_factory_ptr &factory_ptr) override;
	virtual BINBO_FUNC get_id(Alpha::interface_id &id) override;

protected:

	virtual BINBO_FUNC init(Alpha::Binbo::IModuleLoaderWeakPtr const &module_loader_ptr) override;
	virtual BINBO_FUNC cleanup() override;

	// i_common
	ALPHA_BINBO_PUBLISH_INTERFACES(Alpha::Om::IUnitModule)

private:

	Alpha::Binbo::i_class_factory_ptr _classFactory;
	mutable Alpha::CAtomicRefCounter<false> _RCB;

};	// class AlarmsModule
