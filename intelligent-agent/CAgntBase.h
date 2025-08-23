#pragma once

namespace AI {

	class CAgntBase
	{
	public:
		CAgntBase() {}
		virtual string serialize() = 0;
		virtual ~CAgntBase() {}
	};
}
