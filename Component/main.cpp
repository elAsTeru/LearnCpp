import <memory>;
import GameObject;
import Component;

int main()
{
	std::shared_ptr<GameObject>go = std::make_unique<GameObject>("Player01", "Player");

	auto comp = go->AddComp<Component::SelfIntroduction>();
	comp->Greeting();

	//comp = go->GetComp<Component::SelfIntroduction>();
	//comp->Greeting();

	//go->RmComp<Component::SelfIntroduction>();
	//comp = go->GetComp<Component::SelfIntroduction>();
	//if (comp != nullptr)
	//{
	//	comp->Greeting();
	//}

	go.reset();
}