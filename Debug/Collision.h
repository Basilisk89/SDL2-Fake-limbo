#include "VMath.h"
#include "Ball.h"
#pragma once
namespace Game_Lib{
	class Collision
	{
	public:
		Ball *ball1;
			Ball *ball2;
	public:

		void CollisionBalltoBall(Ball *Ball1, Ball *Ball2);
		void CollisionOnPlane(Sphere *Ball, Plane3D *plane);
		void twodVecCollision();
	};
}
