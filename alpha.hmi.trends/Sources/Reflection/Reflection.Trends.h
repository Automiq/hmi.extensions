#pragma once

#include "..\TrendsControl.h"


////////////////////////////////////////////////////////////////////////////////
//		���������� ���� Trends
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_API(
	aht::TrendsControl, ahtr::Aspect, aoe::Schema,
	AlphaTrends,
	// {447C3E77-56F5-497C-950C-067DA367AD6A}
	( 0x44, 0x7c, 0x3e, 0x77, 0x56, 0xf5, 0x49, 0x7c, 0x95, 0x0c, 0x06, 0x7d, 0xa3, 0x67, 0xad, 0x6a ),
	// �������������� ��������
	CLASSINFO
)


////////////////////////////////////////////////////////////////////////////////
//		���������� ���������� � ����
////////////////////////////////////////////////////////////////////////////////

AR_DECLARE_CLASSINFO(
	aht::TrendsControl, ahtr::Aspect, aoe::Schema,
	(
		AR_NSTR(L"��������� Alpha.Trends"),
		AR_NSTR(L"�������� ��������� Alpha.Trends")
	)
)