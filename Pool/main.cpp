import <iostream>;
import <vector>;
import PoolSystem;

int main()
{
	std::cout << "Pool System \n\n";

	// これをメンバに持たせるだけ
	PoolSystem::Pool<double> pool(UINT16_MAX);

	std::vector<const double*> ref;
	// プールの全要素 + 100を使用
	for (int i = 0; i < UINT16_MAX + 100; ++i)
	{
		auto temp = pool.Get();
		*temp = i;
		ref.emplace_back(temp);
	}

	// 使用中の要素の半分の使用を終了する
	for (int i = 0; i < ref.size() / 2; ++i)
	{
		pool.Rm(ref.back());
		ref.pop_back();
	}

	return 0;
}