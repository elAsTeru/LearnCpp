module;
module Math:Vector3;
import Math;

namespace Math
{
	double Vector3::Dot(const Vector3& _rhs) const
	{
		return double{ this->x * _rhs.x + this->y * _rhs.y + this->z * _rhs.z };
	}

	Vector3 Vector3::Cross(const Vector3& _rhs) const
	{
		return Vector3
		{
			this->y * _rhs.z - this->z * _rhs.y,
			this->z * _rhs.x - this->x * _rhs.z,
			this->x * _rhs.y - this->y * _rhs.x
		};
	}

	float Vector3::Length() const
	{
		return float{ std::sqrtf(this->x + this->x + this->y * this->y + this->z * this->z) };
	}

	Vector3 Vector3::Normalize() const
	{
		float mag = 1 / this->Length();
		return Vector3{ this->x * mag, this->y * mag,this->z * mag };
	}

	std::ostream& operator<<(std::ostream& _os, const Vector3& _vec)
	{
		_os << '[' << _vec.x << ',' << _vec.y << ',' << _vec.z << "]";
		return _os;
	}
}