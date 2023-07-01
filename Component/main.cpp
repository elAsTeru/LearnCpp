import GameObject;
import Component;
import <memory>;

int main()
{
	// GameObject�̐���(�X�}�[�g�|�C���^)
	std::shared_ptr<GameObject>go{ std::make_unique<GameObject>("Player01", "Player") };
	{
		// GameObject�p�ɍ��ꂽ�R���|�[�l���g��t�^
		auto comp{ go->AddComp<Component::SelfIntroduction>() };
		comp->Greeting();

		// GameObject�����w�肵���R���|�[�l���g���擾
		comp = go->GetComp<Component::SelfIntroduction>();
		comp->Greeting();

		// GameObject�ɓ����R���|�[�l���g2�ڂ�3�ڂ�t�^
		comp = go->AddComp<Component::SelfIntroduction>();
		comp = go->AddComp<Component::SelfIntroduction>();

		// GameObject�����w�肵��2�Ԗڂ̃R���|�[�l���g���폜
		go->RmComp<Component::SelfIntroduction>(1);
		// GameObject�����w�肵���擪�̃R���|�[�l���g���폜
		go->RmComp<Component::SelfIntroduction>();

		comp = go->GetComp<Component::SelfIntroduction>();
		if (comp != nullptr)
		{
			comp->Greeting();
		}
	}

	// GameObject�̐���(���|�C���^)
	GameObject* go2{ new GameObject("Player02", "Player") };
	{
		auto comp{ go2->AddComp<Component::SelfIntroduction>() };
		comp->Greeting();

		// �����̃R���|�[�l���g��t�^
		for (int i{ 0 }; i < 2; ++i)
		{
			go2->AddComp<Component::SelfIntroduction>();
		}
		
		// �w�肵��2�Ԗڂ̃R���|�[�l���g���擾
		comp = go2->GetComp<Component::SelfIntroduction>(1);
		
		// �悭�Ȃ��������ŉ�������ꍇ�ɃR���|�[�l���g�̉�������Œ�~���Ȃ��悤�ɂ������B
		//delete comp;
	}

	delete go2;
	go2 = nullptr;
	go.reset();
}