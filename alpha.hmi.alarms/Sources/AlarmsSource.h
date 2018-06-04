#pragma once

#include "stdafx.h"

namespace Alpha { namespace Hmi { namespace Alarms {

	class AlarmsSource
	{
		AR_FRIEND

		/// Значение сигнала
		Alpha::Binbo::default_variant _Value;

		/// Адрес подключения
		const Alpha::Binbo::default_string host_;

		/// ProgID
		const Alpha::Binbo::default_string progId_;

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

		Alpha::Binbo::default_string GetHost() const
		{
			return host_;
		}

		Alpha::Binbo::default_string GetProgId() const
		{
			return progId_;
		}
	};

}
}
}