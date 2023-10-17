import TestObject;
import Component;
import <memory>;
import <iostream>;

// Conponent���g�p����TestObject�̗��p
int main()
{
	std::cout << "Component System \n\n";

	// TestObject�̐���(�X�}�[�g�|�C���^)
	std::shared_ptr<TestObject>go{ std::make_unique<TestObject>("Player01", "Player") };
	{
		// TestObject�p�ɍ��ꂽ�R���|�[�l���g��t�^
		auto comp{ go->AddComp<Component::SelfIntroduction>() };
		comp->Update();

		putchar('\n');

		// TestObject�����w�肵���R���|�[�l���g���擾
		comp = go->GetComp<Component::SelfIntroduction>();
		comp->Update();

		putchar('\n');
	}

	// TestObject�̐���(���|�C���^)
	TestObject* go2{ new TestObject("Player02", "Player") };
	{
		go2->AddComp<Component::SelfIntroduction>();
		putchar('\n');

		// �����̃R���|�[�l���g��t�^
		for (int i{ 0 }; i < 3; ++i)
		{
			go2->AddComp<Component::SelfIntroduction>();
		}
		putchar('\n');
		
		// �܂Ƃ߂čX�V
		go2->Update();
		putchar('\n');

		// �w�肵��3�ԖڂƐ擪�̃R���|�[�l���g���폜
		go2->RmComp<Component::SelfIntroduction>(2);
		go2->RmComp<Component::SelfIntroduction>();
		putchar('\n');

		// 3�Ԗڂ������Ă��邩�H
		// �w�肵��3�Ԗڂ̃R���|�[�l���g���擾
		auto comp = go2->GetComp<Component::SelfIntroduction>(2);
		if (comp != nullptr)
		{
			comp->Update();
		}
		// �擪���������̂�2�Ԗڂ��������̂��擪�ɂȂ�X�V�����B
		comp = go2->GetComp<Component::SelfIntroduction>();
		comp->Update();
		putchar('\n');
		
		// �悭�Ȃ��������ŉ�������ꍇ�ɃR���|�[�l���g�̉�������Œ�~���Ȃ��悤�ɂ������B
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