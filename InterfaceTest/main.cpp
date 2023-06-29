import Immutable;

int main()
{
	Immutable<int> value(10);
	value.Print();

	Immutable<int>(value.Add(20)).Print();
}