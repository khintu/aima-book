#pragma once

namespace AI {

	class CThrdAgent: public CThrdBase {
		CSimpleSearching* agent;
	public:
		CThrdAgent(CSimpleSearching* a) : CThrdBase(), agent(a) {}
		virtual ~CThrdAgent() { delete agent; }
		
		// Implementations of the pure virtual methods from CThrdBase
		void thrdInitialize() override ;
		void thrdExecution() override ;
		void thrdFinalize() override ;
	};
}
