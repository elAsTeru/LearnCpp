export module Component:SelfIntroduction;
import ComponentSystem;
import GameObject;
import <iostream>;

namespace Component
{
	export class SelfIntroduction : public ComponentSystem::Base<GameObject>
	{
	public:
		SelfIntroduction(){}
		~SelfIntroduction(){}

		void Greeting()
		{
			std::cout << "Hello, My name is ";
			//std::cout << this->parent->name << '\n';
		}
	};
}