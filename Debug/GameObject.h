#include "Vec3.h"
#include "Quaternion.h"
namespace Game_Lib{
	class Pickle : public DynamicObject{
	public:
	void pickle();	
	void render();
	protected:
	};
	// inherited from GameObject
	class DynamicObject : public GameObject2D{
		protected:
			Vec3 velocity , acceleration;
			Quaternion rotation;
			float mass;
	};
	class GameObject2D {
		protected:
			Vec3 position;
			Quaternion orientation;
		    void virtual render() = 0;
	};	
}