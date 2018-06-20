#pragma once

#include "stdafx.h"
#include "AlarmsControl.h"

namespace Alpha { namespace Hmi { namespace Alarms {

	//_COM_SMARTPTR_TYPEDEF(IOPCEventServer, __uuidof(IOPCEventServer));

	class AlarmSettings
	{
		AR_FRIEND

		/// Значение сигнала
		Alpha::Binbo::default_variant _Value;
		
		/// Необходимое значение сигнала
		Alpha::Binbo::default_variant _RequiredValue;

		/// Сообщение
		const Alpha::Binbo::default_string _Message;

		/// Сигнал, свидетельствующий об изменении значения
		Alpha::Reflection::SignalCore<Alpha::Binbo::default_variant> ValueChanged;

		/// Компонент отображения
		const Alpha::Reflection::ReflectedPtr<AlarmsControl> _AlarmsControl;

		/// Важность
		uint8_t _Priority;

	public:

		AlarmSettings() : _Priority(0) {}

		void SetValue(Alpha::Binbo::default_variant Value)
		{
			_Value = Value;
			ValueChanged.emit(_Value);
			_Value.which();

			if (!_AlarmsControl)
				return;

			auto value = boost::lexical_cast<std::string>(_Value);
			auto requiredValue = boost::lexical_cast<std::string>(_RequiredValue);
			if (value == requiredValue)
				_AlarmsControl->addAlarm(_Priority, _Message);
		}

		Alpha::Binbo::default_variant GetValue()
		{
			return _Value;
		}

		void SetRequiredValue(Alpha::Binbo::default_variant Value)
		{
			_RequiredValue = Value;
		}

		Alpha::Binbo::default_variant GetRequiredValue()
		{
			return _RequiredValue;
		}

		void SetPriority(uint8_t Value)
		{
			_Priority = Value;
		}

		uint8_t GetPriority()
		{
			return _Priority;
		}

		Alpha::Binbo::default_string GetMsg() const
		{
			return _Message;
		}

	};

}
}
}