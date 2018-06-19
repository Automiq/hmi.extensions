#pragma once

#include "stdafx.h"

namespace Alpha { namespace Hmi { namespace Alarms {

	//_COM_SMARTPTR_TYPEDEF(IOPCEventServer, __uuidof(IOPCEventServer));

	class AlarmsSource
	{
		AR_FRIEND

		/// Необходимое значение сигнала
		Alpha::Binbo::default_variant _Value;

		/// Сигнал, свидетельствующий об изменении значения
		Alpha::Reflection::SignalCore<Alpha::Binbo::default_variant> _ValueChanged;

	public:

		void SetValue(Alpha::Binbo::default_variant Value)
		{
			_Value = Value;
			_ValueChanged.emit(_Value);
		}

		Alpha::Binbo::default_variant GetValue()
		{
			return _Value;
		}
	};

}
}
}