#pragma once

namespace AI {

	struct IntrntMap {
		struct WLList* intrnt;
		struct Router* gIntfTbl[MAX_INTFTBL_SIZE];
	};

	class CSimpleSearching : public CAgntBase {

		void buildIntrntMap(struct WLList* inet);

	protected:
		IntrntMap inetMap;

	public:
		CSimpleSearching(struct WLList* inet);
		~CSimpleSearching();

		virtual void GoalFormulation() = 0;
		virtual void ProblemFormulation() = 0;
		virtual void Search() = 0;
		virtual void Execution() = 0;
	};
}
