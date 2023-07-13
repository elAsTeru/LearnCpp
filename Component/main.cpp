import GameObject;
import Component;
import <memory>;
import <iostream>;

int main()
{
	std::cout << "Component System \n\n";

	// GameObjectの生成(スマートポインタ)
	std::shared_ptr<GameObject>go{ std::make_unique<GameObject>("Player01", "Player") };
	{
		// GameObject用に作られたコンポーネントを付与
		auto comp{ go->AddComp<Component::SelfIntroduction>() };
		comp->Update();

		putchar('\n');

		// GameObjectが持つ指定したコンポーネントを取得
		comp = go->GetComp<Component::SelfIntroduction>();
		comp->Update();

		putchar('\n');
	}

	// GameObjectの生成(生ポインタ)
	GameObject* go2{ new GameObject("Player02", "Player") };
	{
		go2->AddComp<Component::SelfIntroduction>();
		putchar('\n');

		// 複数のコンポーネントを付与
		for (int i{ 0 }; i < 3; ++i)
		{
			go2->AddComp<Component::SelfIntroduction>();
		}
		putchar('\n');
		
		// まとめて更新
		go2->Update();
		putchar('\n');

		// 指定した3番目と先頭のコンポーネントを削除
		go2->RmComp<Component::SelfIntroduction>(2);
		go2->RmComp<Component::SelfIntroduction>();
		putchar('\n');

		// 3番目が消せているか？
		// 指定した3番目のコンポーネントを取得
		auto comp = go2->GetComp<Component::SelfIntroduction>(2);
		if (comp != nullptr)
		{
			comp->Update();
		}
		// 先頭を消したので2番目だったものが先頭になり更新される。
		comp = go2->GetComp<Component::SelfIntroduction>();
		comp->Update();
		putchar('\n');
		
		// よくないがここで解放した場合にコンポーネントの解放処理で停止しないようにしたい。
		comp = nullptr;
	}

	delete go2;
	go2 = nullptr;
	putchar('\n');

	go.reset();
	putchar('\n');

	system("pause");
	return 0;
}