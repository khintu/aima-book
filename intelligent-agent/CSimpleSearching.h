#pragma once

namespace AI {

	class CSimpleSearching : public CAgntBase {

	public:
		CSimpleSearching():CAgntBase(){}
		~CSimpleSearching(){}

		virtual void GoalFormulation() = 0;
		virtual void ProblemFormulation() = 0;
		virtual void Search() = 0;
		virtual void Execution() = 0;
	};
}
