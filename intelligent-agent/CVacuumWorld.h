#pragma once

namespace AI {
	
	class CVacuumWorld : public CSimpleSearching {
		struct WLList* grphList;
		uint32_t src, dst;
	public:
		CVacuumWorld(struct WLList* inet, uint32_t s, uint32_t d): \
								CSimpleSearching(inet), grphList(NULL), src(s), dst(d){}
		~CVacuumWorld() { WDeleteList(grphList); }

		void GoalFormulation() override;
		void ProblemFormulation() override;
		void Search() override;
		void Execution() override;

		string serialize() override;
	};
}
