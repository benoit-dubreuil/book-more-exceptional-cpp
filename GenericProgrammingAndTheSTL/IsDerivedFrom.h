#pragma once

template<typename D, typename B>
class IsDerivedFrom
{
	class No { };
	class Yes { No no[2]; };

	static Yes Test(B*); // not defined
	static No Test(...); // not defined

	static void Constraints(D* p) 
	{
		B* pb = p;
		pb = p; 
	}

public:
	enum : bool {
		Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes)
	};

	IsDerivedFrom() 
	{ 
		void(*p)(D*) = Constraints;
	}
};