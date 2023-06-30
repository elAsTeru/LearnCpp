export module Component:SelfIntroduction;
import ComponentSystem;
import <iostream>;

namespace Component
{
	export class SelfIntroduction : public ComponentSystem::Base
	{
	public:
		SelfIntroduction(){}
		~SelfIntroduction(){}

		void Greeting()
		{
			std::cout << "Hello,\n";
		}
	};
}