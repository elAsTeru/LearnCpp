import GameObject;
import Component;
import <memory>;

int main()
{
	// GameObjectの生成(スマートポインタ)
	std::shared_ptr<GameObject>go{ std::make_unique<GameObject>("Player01", "Player") };
	{
		// GameObject用に作られたコンポーネントを付与
		auto comp{ go->AddComp<Component::SelfIntroduction>() };
		comp->Greeting();

		// GameObjectが持つ指定したコンポーネントを取得
		comp = go->GetComp<Component::SelfIntroduction>();
		comp->Greeting();

		// GameObjectに同じコンポーネント2つ目と3つ目を付与
		comp = go->AddComp<Component::SelfIntroduction>();
		comp = go->AddComp<Component::SelfIntroduction>();

		// GameObjectが持つ指定した2番目のコンポーネントを削除
		go->RmComp<Component::SelfIntroduction>(1);
		// GameObjectが持つ指定した先頭のコンポーネントを削除
		go->RmComp<Component::SelfIntroduction>();

		comp = go->GetComp<Component::SelfIntroduction>();
		if (comp != nullptr)
		{
			comp->Greeting();
		}
	}

	// GameObjectの生成(生ポインタ)
	GameObject* go2{ new GameObject("Player02", "Player") };
	{
		auto comp{ go2->AddComp<Component::SelfIntroduction>() };
		comp->Greeting();

		// 複数のコンポーネントを付与
		for (int i{ 0 }; i < 2; ++i)
		{
			go2->AddComp<Component::SelfIntroduction>();
		}
		
		// 指定した2番目のコンポーネントを取得
		comp = go2->GetComp<Component::SelfIntroduction>(1);
		
		// よくないがここで解放した場合にコンポーネントの解放処理で停止しないようにしたい。
		//delete comp;
	}

	delete go2;
	go2 = nullptr;
	go.reset();
}