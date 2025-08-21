#pragma once

namespace AI {

	class CThreadFactory: public CAbstractFactory {

	public:
		CThrdBase* CreateThreadObj(CSimpleSearching *) override;

	};

}
