#pragma once

namespace AI {
	
	class CVacuumWorld : public CSimpleSearching {

	public:
		CVacuumWorld(): CSimpleSearching() {}
		~CVacuumWorld() {}

		void GoalFormulation() override;
		void ProblemFormulation() override;
		void Search() override;
		void Execution() override;

		string serialize() override;
		CAgntBase* clone() override;
	};
}
