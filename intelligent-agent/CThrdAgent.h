#pragma once

namespace AI {

	class CThrdAgent: public CThrdBase {
	public:
		CThrdAgent() : CThrdBase() {}
		virtual ~CThrdAgent() {}
		
		// Implementations of the pure virtual methods from CThrdBase
		void thrdInitialize() override {
			// Initialization code for the agent thread
		}
		void thrdExecution() override {
			// Execution code for the agent thread
			cout << "Hi!, from Thread Agent!" << endl;
		}
		void thrdFinalize() override {
			// Finalization code for the agent thread
		}
	};
}
