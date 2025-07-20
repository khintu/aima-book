#pragma once

namespace AI {

	class CAgntBase
	{
	public:
		virtual void dumpObj() = 0;
		virtual CAgntBase& clone() = 0;
		virtual ~CAgntBase() {}
	};
}