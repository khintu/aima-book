#pragma once

namespace AI {

	class CAbstractFactory {
	public:
		virtual CThrdBase* CreateThreadObj(CSimpleSearching *) = 0;
		virtual ~CAbstractFactory() {}
	};
}
