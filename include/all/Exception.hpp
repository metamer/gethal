
#ifndef ALL_EXCEPTION_HPP
#define ALL_EXCEPTION_HPP

namespace all{

	class GameException{};
	class FrontendException: public GameException{};
	class BackendException: public GameException{};
	class UIException: public GameException{};
	class RunnerException: public GameException{};
	class EngineException: public GameException{};
}


#endif


