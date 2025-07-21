#pragma once

namespace AI {

	class CAgntBase
	{
	public:
		virtual string dumpObj() = 0;
		virtual CAgntBase& clone() = 0;
		virtual ~CAgntBase() {}
	};
}