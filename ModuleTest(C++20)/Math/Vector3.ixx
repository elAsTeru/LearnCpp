import <iostream>;
export module Math:Vector3;

namespace Math
{
	// 0が計算に入ってきた場合無効値を表すライブラリを使って返却する。
	export struct Vector3
	{
		double x, y, z;

		friend std::ostream& operator<<(std::ostream&, const Vector3&);

		double Dot(const Vector3& _rhs)const;
		Vector3 Cross(const Vector3& _rhs)const;
		float Length()const;
		Vector3 Normalize()const;

		//// 算術演算子のオーバーロード

		//Vector3	operator+	(const Vector3& _rhs)const;
		//Vector3	operator-	(const Vector3& _rhs)const;
		//Vector3 operator*	(const float& _rhs)const;
		//Vector3 operator/	(const float& _rhs)const;

		//void	operator+=	(const Vector3& _rhs);
		//void	operator-=	(const Vector3& _rhs);

		//Vector3	operator+	();
		//Vector3	operator-	();
		//bool	operator<	(const Vector3& _rhs)const;
		//bool	operator>	(const Vector3& _rhs)const;
		//bool	operator==	(const Vector3& _rhs)const;
	};

	// coutのシフト演算子をオーバーロード
	export std::ostream& operator<<(std::ostream& _os, const Vector3& _vec);
}